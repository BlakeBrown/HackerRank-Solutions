/*
 * Complete the function below.
 */
vector < string > Braces(vector < string > values) {
    vector<string> answer;
    answer.resize(values.size());
    for(int i = 0; i < values.size(); i++) {
        list<char> queue;
        bool valid = true;
        for(int j = 0; j < values[i].length(); j++) {
            char bracket = values[i][j]; 
            if(bracket == '{' || bracket == '(' || bracket == '[') {
                queue.push_back(bracket);
            } else if(bracket == '}' && queue.front() == '{') {
                queue.pop_front();
            } else if(bracket == ')' && queue.front() == '(') {
                queue.pop_front();
            } else if(bracket == ']' && queue.front() == '[') {
                queue.pop_front();
            } else {
                valid = false;
            }
        }
        if(valid) {
            answer[i] = "YES";
        } else {
            answer[i] = "NO";
        }
    }
    return answer;
}

