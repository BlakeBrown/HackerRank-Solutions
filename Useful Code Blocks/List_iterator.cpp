// auto automatically grabs the correct iterator type 
for(auto it = my_list.begin(); it != my_list.end(); ++it) {
    pair<int,int> current = *it; // You can grab whatever is at the current index with *it
}