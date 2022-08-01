// Check if a key exists in a map

// Method 1: Iterator
map<int,int>::iterator it;
map<int,int> m;
it = m.find(variable);
if(it == m.end()) {
	// Not found
} else {
	int found_key = it->first;
	int found_value = it->second;
}

// Method 2: Count
if(m.count(variable) == 0) {
	// Not found
}