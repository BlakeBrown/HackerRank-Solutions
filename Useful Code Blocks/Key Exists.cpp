// Check if key exists in map

// Iterator
map<int,int>::iterator it;
map<int,int> m;
it = m.find(variable);
if(it == m.end()) {
	// Not found
} else {
	int found_key = it->first;
	int found_value = it->second;
}

// Count
if(m.count(variable) == 0) {
	// Not found
}