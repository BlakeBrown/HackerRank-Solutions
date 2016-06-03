#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <string.h>
using namespace std;

// Can't believe I wrote 200+ lines of code for a single question in a coding competition...
// #noshame, passes 1/3rd of the test cases

// Returns the path from source to destination
vector<int> Path(int s, int d, int **next) {
	if(next[s][d] == -1) {
	    return {}; // return empty vector
	}
	vector<int> path;
	path.push_back(s);
	while(s != d) {
	    s = next[s][d];
	    path.push_back(s);
	}
	return path;
}

int main() {
	int V, E, K;
	cin>>V>>E>>K;
	// citiesWithFish[i] = list of cities containing fish i
	// fishInCity[i] = list of fish sold at city i
	vector<int> citiesWithFish[K+1];
	vector<int> fishInCity[V];

	// In this problem, we'll make use of Floyd-Warshall to find the shortest path between all points
	// dist[i][j] represents the shortest distance from vertex i to vertex j
	// next[][] can be used to reconstruct the path from vertex i to vertex j
	int **dist = new int*[V];
	int **next = new int*[V];
	for(int i = 0; i < V; i++) {
	    dist[i] = new int[V];
		next[i] = new int[V];
	    for(int j = 0; j < V; j++) {
	        if(i != j) {
	            dist[i][j] = INT_MAX;
	        } else {
	            dist[i][j] = 0;
	        }
	        next[i][j] = -1;
	    }
	}

	for(int i = 0; i < V; i++) {
		int T, fish;
		cin>>T;
		for(int j = 0; j < T; j++) {
			cin>>fish;
			citiesWithFish[fish].push_back(i);
			fishInCity[i].push_back(fish);
		}
	}

	// Insert E edges
	for (int i = 0; i < E; ++i) {
	    int s, d, w;
	    cin>>s>>d>>w;
	    dist[s-1][d-1] = w;
	    dist[d-1][s-1] = w;
	    next[s-1][d-1] = d-1;
	    next[d-1][s-1] = s-1;
	}

	// Perform Floyd-Warshall Algorithm
	for(int i = 0; i < V; i++) {
	    for(int j = 0; j < V; j++) {
	        for (int k = 0; k < V; ++k) {
	            if(dist[j][i] == INT_MAX || dist[i][k] == INT_MAX) {
	                continue; // We only want to compare non-infinite paths
	            }
	            if(dist[j][k] > dist[j][i] + dist[i][k]) {
	                dist[j][k] = dist[j][i] + dist[i][k]; // Update dist since we've found a shorter path
	                next[j][k] = next[j][i];
	           }
	        }
	    }
	}

	// Enough setup, let's solve the problem :P

	// Check if we can go straight to the destination
	int cat1 = INT_MAX, cat2 = INT_MAX;
	bool *fishFound = new bool[K+1];
	memset(fishFound, false, sizeof(fishFound));
	bool allFishFound = false;

	vector<int> cat1Path = Path(0, V-1, next);
	cat1 = dist[0][V-1];
	for(auto it = cat1Path.begin(); it != cat1Path.end(); ++it) {
	    vector<int> availableFish = fishInCity[*it];
	    for(auto it2 = availableFish.begin(); it2 != availableFish.end(); ++it2) {
	    	fishFound[*it2] = true;
	    }
	}

	// Check if all fish have been found
	allFishFound = true;
	for(int i = 1; i <= K; i++) {
		if(!fishFound[i]) {
			allFishFound = false;
		}
	}

	// We're done! :) Both cats just go straight to dest
	if(allFishFound) {
		cout<<cat1;
		return 0;
	}

	// Otherwise assign cat2 to grab a missing fish
	int missingFish;
	for(int i = 1; i <= K; i++) {
		if(!fishFound[i]) {
			missingFish = i;
			break;
		}
	}

	vector<int> fishCities = citiesWithFish[missingFish];
	int closestCity;
	for(int i = 0; i < fishCities.size(); i++) {
		if(dist[0][fishCities[i]] + dist[fishCities[i]][V-1] < cat2) {
			cat2 = dist[0][fishCities[i]] + dist[fishCities[i]][V-1];
			closestCity = fishCities[i];
		}
	}

	// Update which fish have been found
	vector<int> cat2Path = Path(0, closestCity, next);
	vector<int> pathToAdd = Path(closestCity, V-1, next);
	cat2Path.insert(cat2Path.end(), pathToAdd.begin()+1, pathToAdd.end());
	cat2 = dist[0][closestCity] + dist[closestCity][V-1];
	for(auto it = cat2Path.begin(); it != cat2Path.end(); ++it) {
	    vector<int> availableFish = fishInCity[*it];
	    for(auto it2 = availableFish.begin(); it2 != availableFish.end(); ++it2) {
	    	fishFound[*it2] = true;
	    }
	}

	// Check again if all fish have been found
	allFishFound = true;
	for(int i = 1; i <= K; i++) {
		if(!fishFound[i]) {
			allFishFound = false;
		}
	}

	// We're done! :) Time is max{cat1, cat2}
	if(allFishFound) {
		if(cat1 > cat2) {
			cout<<cat1;
		} else {
			cout<<cat2;
		}
		return 0;
	}

	// Still not done? :( Main algorithm below
	while(!allFishFound) {
		// Assign one cat to get a missing fish
		int cat = 2;
		if(cat1 < cat2) {
			cat = 1;
		}

		for(int i = 1; i <= K; i++) {
			if(!fishFound[i]) {
				missingFish = i;
				break;
			}
		}

		// Find the city with the missing fish that adds the least distance to the cats current path
		vector<int> updatedPath;
		int updatedPathLength;
		if(cat == 1) {
			updatedPath = cat1Path;
			updatedPathLength = cat1;
		} else {
			updatedPath = cat2Path;
			updatedPathLength = cat2;
		}
		int overallDistance = INT_MAX, overallClosestCity, overallIndex;
		fishCities = citiesWithFish[missingFish];
		for(int i = 0; i < updatedPath.size(); i++) {
			int distance = INT_MAX, index;
			for(int k = 0; k < fishCities.size(); k++) {
				int test;
				if(updatedPath[i] == V-1) {
					// If we're at the end of path, check going away from dest and back
					test = dist[V-1][fishCities[k]] + dist[fishCities[k]][V-1];
				} else {
					// Check the distance added to the middle of the path
					test = dist[updatedPath[i]][fishCities[k]] + dist[fishCities[k]][updatedPath[i+1]];
				}
				if(test < distance) {
					distance = test;
					closestCity = fishCities[k];
					index = i;
				}
			}
			if(distance < overallDistance) {
				overallDistance = distance;
				overallClosestCity = closestCity;
				overallIndex = index;
			}
		}

		// Add the city to the cats path
		pathToAdd = Path(updatedPath[overallIndex], overallClosestCity, next);
		vector<int> pathToAdd2;
		if(updatedPath[overallIndex] == V-1) {
			pathToAdd2 = Path(overallClosestCity, V-1, next);
		} else {
			pathToAdd2 = Path(overallClosestCity, updatedPath[overallIndex+1], next);
		}
		pathToAdd.insert(pathToAdd.end(), pathToAdd2.begin()+1, pathToAdd2.end());
		for(int i = 0; i < pathToAdd.size(); i++) {
		}
		for(int i = 0; i < updatedPath.size(); i++) {
		}
		updatedPath.insert(updatedPath.begin()+overallIndex+1, pathToAdd.begin()+1, pathToAdd.end());
		if(cat == 1) {
			cat1Path = updatedPath;
			cat1 += overallDistance;
		} else if(cat == 2) {
			cat2Path = updatedPath;
			cat2 += overallDistance;
		}
	
		// Update fish found
		for(auto it = updatedPath.begin(); it != updatedPath.end(); ++it) {
		    vector<int> availableFish = fishInCity[*it];
		    for(auto it2 = availableFish.begin(); it2 != availableFish.end(); ++it2) {
		    	fishFound[*it2] = true;
		    }
		}

		// Check if all fish have been found
		allFishFound = true;
		for(int i = 1; i <= K; i++) {
			if(!fishFound[i]) {
				allFishFound = false;
			}
		}
	}

	if(cat1 > cat2) {
		cout<<cat1;
	} else {
		cout<<cat2;
	}
	// and we're done!
    return 0;
}