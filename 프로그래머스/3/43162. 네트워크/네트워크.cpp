#include <bits/stdc++.h>

using namespace std;

vector<bool> visited; 
int answer = 0;

void BFS(int n, int cur, vector<vector<int>> coms);

int solution(int n, vector<vector<int>> computers) {
    visited.resize(n);
    
    for(int i=0;i<n;i++){
        if(visited[i]) continue;
        answer++;
        BFS(n, i, computers);
    }
    
    return answer;
}

void BFS(int n, int cur, vector<vector<int>> coms){
    queue<int> q;
    q.push(cur);
    visited[cur] = true;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(int i=0;i<n;i++){
            if(node == i) continue; // 현재 컴퓨터와 동일하면 무시
            
            if(coms[node][i] == 1){ // 해당 컴퓨터와 연결되어 있으면
                if(visited[i]) continue;
                q.push(i);
                visited[i] = true;
            }
        }
    }
}