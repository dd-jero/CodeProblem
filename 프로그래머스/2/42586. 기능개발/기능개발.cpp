#include <bits/stdc++.h>

using namespace std;
vector<bool> done; // 해당 기능 배포 여부 
int idx = 0;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int p_size = progresses.size();
    done.resize(p_size); 
    
    while(1){
        if(done[p_size-1]) break; // 마지막 기능까지 배포 했으면 종료 
        
        // 각 기능의 작업 진행
        for(int i=0;i<p_size;i++){
            if(done[i]) continue; // 해당 작업은 완료했으면
            progresses[i] += speeds[i];
        }
        
        // 배포 가능한 지 확인 (앞의 기능들이 배포 되어있어야됨.)
        int done_cnt = 0;
        for(int i=idx;i<p_size;i++){
            if(progresses[i] >= 100){ // 완료했고, 이전에 배포되지 않은 기능이면
                done[i] = true;
                done_cnt++;
            }else{ // 앞에서 부터 완료해야됨.
                break; 
            }
        }
        idx += done_cnt;
        
        if(done_cnt != 0) answer.push_back(done_cnt);
    }
    
    return answer;
}