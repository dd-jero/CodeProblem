#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> dist;
int max_dist = 0;

// 거리에 따른 오름차순 우선순위 큐
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

void BFS();

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    adj.resize(n+1);
    visited.resize(n+1);
    dist.resize(n+1);
    
    for(int i=0;i<edge.size();i++){
        
        // 양방향
        adj[edge[i][0]].push_back(edge[i][1]);
        adj[edge[i][1]].push_back(edge[i][0]);
    }
    
    // 1번 노드 부터 시작
    BFS();
    
    for(int i=1;i<n+1;i++){
        if(dist[i] == max_dist) answer++;
    }
    return answer;
}

void BFS(){
    pq.push({0,1});
    visited[1] = true;
    
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        
        for(int i=0;i<adj[cur.second].size();i++){
            if(!visited[adj[cur.second][i]]){ // 해당 노드 아직 방문 안했으면 
                pq.push({cur.first+1, adj[cur.second][i]});
                visited[adj[cur.second][i]] = true;
                dist[adj[cur.second][i]] = cur.first+1;
                
                max_dist = max_dist < cur.first+1 ? cur.first+1 : max_dist;
            }
        }
    }
}