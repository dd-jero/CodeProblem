#include <string>
#include <vector>
#include <queue>

using namespace std;

int BFS(string begin, string target, vector<string> words); 
bool Check(string cur, string w); // 하나의 알파벳만 다르면 true

int solution(string begin, string target, vector<string> words) {
    
    int answer = BFS(begin, target, words);
    return answer;
}

int BFS(string begin, string target, vector<string> words){
    // <변환횟수, 단어>를 요소로 가지며 변환 횟수 기준 오름차순 
    
    vector<bool> checked;
    checked.resize(words.size());
    
    priority_queue<pair<int,string>, vector<pair<int,string>>, greater<pair<int,string>>> pq;
    pq.push({0, begin});
    
    while(!pq.empty()){
        auto cur = pq.top();
        
        // 종료 조건: target와 현재 top의 단어가 같으면 
        if(cur.second == target){
            return cur.first;
        }
        
        pq.pop();
        
        for(int i=0;i<words.size();i++){
            if(Check(cur.second, words[i]) && !checked[i]){ // 하나의 알파벳만 다르고 해당 단어를 처음 확인한 경우만
                pq.push({cur.first+1, words[i]});
                checked[i] = true;
            }
        }
    }
    
    // 변환할 수 없으면
    return 0;
}

bool Check(string cur, string w){
    
    int cnt = 0;
    
    for(int i=0;i<cur.length();i++){
        if(cur[i] != w[i]){
            cnt++;
            
            if(cnt > 1) return false; // 둘 이상 다르면 
        }
    }
    
    // 하나의 알파벳만 다르면
    return true;
}