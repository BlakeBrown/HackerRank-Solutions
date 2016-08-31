#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <math.h>
using namespace std;

unordered_map<string,bool>::iterator it2;

double degree2radians(double radians) {
    return radians * (M_PI / 180.0);
}

double distance_between(pair<double, double> point1, pair<double, double> point2) {
    double EARTH_RADIUS = 6371;//in km
    double point1_lat_in_radians  = degree2radians( point1.first );
    double point2_lat_in_radians  = degree2radians( point2.first );
    double point1_long_in_radians  = degree2radians( point1.second );
    double point2_long_in_radians  = degree2radians( point2.second );
    return acos( sin( point1_lat_in_radians ) * sin( point2_lat_in_radians ) + cos( point1_lat_in_radians ) * cos( point2_lat_in_radians ) * cos( point2_long_in_radians - point1_long_in_radians) ) * EARTH_RADIUS;
}


int main() {
	// Read guest data
	int numGuests;
	cin>>numGuests;
	unordered_map<string,bool> passions; // use a map to quickly check if a guest has certain interest
	for(int i = 0; i < numGuests; i++) {
		int numInterests;
		cin>>numInterests;
		for(int j = 0; j < numInterests; j++) {
			string interest;
			cin>>interest;
			passions[interest] = true;
		}
	}

	// Read city data using two vectors:
	// city[i] contains city name and longitude/latitude for city i
	// activity[i] contains a list of activities for city i
	vector<pair<string,pair<double,double> > > city;
	vector<vector<string> > activities;
	int numCities;
	cin>>numCities;
	for(int i = 0; i < numCities; i++) {
		string cityName;
		double latitude;
		double longitude;
		int numInterests;
		vector<string> interests;
		cin>>cityName>>latitude>>longitude>>numInterests;
		for(int i = 0; i < numInterests; i++) {
			string interest;
			cin>>interest;
			interests.push_back(interest);
		}
		city.push_back(pair<string,pair<double,double> >(cityName, pair<double, double>(latitude, longitude)));
		activities.push_back(interests);
	}
	
	// Find the pairs of cities with the maximum possible score
	// Score = the # of activities the guests are interested in
	int maxScore = 0;
	vector<pair<int,int> > candidates;
	for(int i = 0; i < numCities; i++) {
		for(int j = i+1; j < numCities; j++) {
			// Find the score for each pair of cities 
			int score = 0;
			unordered_map<string,bool> combinedInterests;
			for(int k = 0; k < activities[i].size(); k++) {
				combinedInterests[activities[i][k]] = true;
			}
			for(int k = 0; k < activities[j].size(); k++) {
				combinedInterests[activities[j][k]] = true;
			}
			for(auto it = combinedInterests.begin(); it != combinedInterests.end(); it++) {
				it2 = passions.find(it->first);
				if(it2 != passions.end()) {
					// Activity at one of the cities is also one of the guests passions, increment score
					score++;
				}
			}
			if(score > maxScore) {
				// We've beaten the max score, create a new list starting with the current pair of cities
				maxScore = score;
				vector<pair<int,int> > newCandidate;
				newCandidate.push_back(pair<int,int>(i, j));
				candidates = newCandidate;
			} else if(score == maxScore) {
				// We've tied with the max score, add pair of cities to the list of candidates
				candidates.push_back(pair<int,int>(i, j));
			}
		}
	}

	// Out of the candidates, find the pair of cities with the shortest distance 
	double shortestDistance = std::numeric_limits<double>::max();
	pair<int, int> bestPair;  
	for(int i = 0; i < candidates.size(); i++) {
		double distance = distance_between(city[candidates[i].first].second, city[candidates[i].second].second);
		if(distance < shortestDistance) {
			shortestDistance = distance;
			bestPair = pair<int,int>(candidates[i].first, candidates[i].second);
		}
	}
	// Finished! Output the pair of cities in alphabetical order
	string city1 = city[bestPair.first].first;
	string city2 = city[bestPair.second].first;
	if(city1 < city2) {
		cout<<city1<<" "<<city2<<"\n";
	} else {
		cout<<city2<<" "<<city1<<"\n";
	}
    return 0;
}
