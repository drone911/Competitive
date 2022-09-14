#include <bits/stdc++.h>
using namespace std;

string stringify(int num1, int num2) {
    return to_string(num1)+to_string(num2);
}
void BFS(int jug1, int jug2, int target){
    queue<pair<int, int>> Q;
    unordered_set<string> visited;
    visited.insert(stringify(0, 0));
    Q.push(make_pair(0, 0));
    while (!Q.empty())
    {
        pair<int, int> curr = Q.front();
        Q.pop();
        cout<<"("<<curr.first<<", "<<curr.second<<")"<<endl;
        if(curr.first == target && curr.first == 0) {
            return;
        }
        if(curr.second == target && curr.first == 0) {
            return;
        }
        
        if(visited.find(stringify(curr.first, jug2))==visited.end()) {
            visited.insert(stringify(curr.first, jug2));
            Q.push(make_pair(curr.first, jug2));
        }
        if(visited.find(stringify(jug1, curr.second))==visited.end()) {
            visited.insert(stringify(jug1, curr.second));
            Q.push(make_pair(jug1, curr.second));
        }
        if(visited.find(stringify(0, jug2))==visited.end()) {
            visited.insert(stringify(0, jug2));
            
            Q.push(make_pair(0, jug2));
        }
        if(visited.find(stringify(jug1, 0))==visited.end()) {
            visited.insert(stringify(jug1, 0));
            
            Q.push(make_pair(jug1, 0));
        }
        pair<int, int> temp = curr;
        if(temp.first>=jug2-temp.second){
            temp.first -= jug2 - temp.second;
            temp.second = jug2;

        }else{
            temp.second = temp.second + temp.first;
            temp.first = 0;
        }
        if(visited.find(stringify(temp.first, temp.second))==visited.end()){
            visited.insert(stringify(temp.first, temp.second));
            
            Q.push(temp);
        }
        temp = curr;
        if(temp.second>=jug1-temp.first){
            temp.second -= jug1 - temp.first;
            temp.first = jug1;

        }else{
            temp.first = temp.first + temp.second;
            temp.second = 0;
        }
        if(visited.find(stringify(temp.first, temp.second))==visited.end()){
            visited.insert(stringify(temp.first, temp.second));
            
            Q.push(temp);
        }
    }
}  
int main() 
{ 
    int Jug1 = 4, Jug2 = 3, target = 2; 
    cout << "Path from initial state "
            "to solution state :\n"; 
    BFS(Jug1, Jug2, target); 
    return 0; 
} 