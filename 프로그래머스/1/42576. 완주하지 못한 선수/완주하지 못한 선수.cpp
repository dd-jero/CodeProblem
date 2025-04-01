#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> parti;
    
    for(int i=0;i<participant.size();i++){
        if(parti.count(participant[i]) == 0){
            parti.insert({participant[i], 1});
        }else{
            parti[participant[i]]++;
        }
    }
    
    for(int i=0;i<completion.size();i++){
        parti[completion[i]]--;
    }
    
    for(auto n: parti){
        if(n.second == 1){
            return n.first;
        }
    }
    
}