// Helpful link for understanding C++ iterators: 
// http://www.cs.northwestern.edu/~riesbeck/programming/c++/stl-iterators.html

// List iterator: 
// Note: "auto" automatically grabs the correct iterator type 
for(auto it = my_list.begin(); it != my_list.end(); ++it) {
    // You can grab whatever is at the current index with *it
    pair<int,int> current = *it;
}

// Map iterator
// From start to end
map<int, int>::iterator it;
for(it = my_map.begin(); it != my_map.end(); it++) {
	int key = it->first;
	int value = it->second;
}
// From end to start
map<int, int>::reverse_iterator it;
for(it = my_map.rbegin(); it != my_map.rend(); it++) {
	int key = it->first;
	int value = it->second;
}