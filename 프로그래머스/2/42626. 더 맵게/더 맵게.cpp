#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq; // 오름차순 우선순위 큐
    
    // 우선 순위 큐에 초기 스코빌 지수 삽입
    for(int i=0;i<scoville.size();i++){
        pq.push(scoville[i]);
    }
    
    
    while(!pq.empty()){
        
        int min_sco = pq.top();
        
        if(pq.size() == 1){ // 스코빌 지수가 하나 남으면
            if(min_sco >= K) return answer; // K 이상 일때
            else return -1; // 만들 수 없는 경우
        }else{
             // 가장 작은 스코빌 지수가 K 이상이면 섞은 횟수 반환
            if(min_sco >= K){
                return answer;    
            }

            pq.pop();
            // 두 번째로 맵지 않은 음식
            int min_sco_2 = pq.top();
            pq.pop();

            // 섞은 스코빌 지수 삽입
            pq.push(min_sco + min_sco_2*2);
            answer++; // 섞은 횟수 증가     
        }
        
    }
    
    return -1;
}