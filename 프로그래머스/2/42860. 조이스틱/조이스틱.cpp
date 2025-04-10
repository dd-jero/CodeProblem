#include <string>
#include <vector>
#include <iostream>

using namespace std;

int MinUpDown(); // 이전 또는 다음 알파벳 이동 시 최소 수
int MinLeftRight(); // 커서 이동 시 최소 수 

vector<int> target;

int solution(string name) {
    int answer = 0;
    target.resize(name.length()); 
    
    for(int i=0;i<target.size();i++){
        target[i] = name[i] - 'A'; // A는 0 ~ Z는 25
    }
    
    answer += MinUpDown();
    answer += MinLeftRight();
    
    return answer;
}

int MinUpDown(){
    
    int cnt_sum = 0;
    
    for(int i=0;i<target.size();i++){
        if(target[i] > (26-target[i])) cnt_sum += (26-target[i]);
        else cnt_sum += target[i];
    }
    
    return cnt_sum;
}

int MinLeftRight(){
    // 쭉 오른쪽으로 가는 경우
    int target_size = target.size();
    int min_cnt = target_size-1;    
    
     for(int i = 0; i < target_size; i++) {
         int endA = i+1; // 현재 위치는 이미 확인 되어서
            
        while(endA < target_size && target[endA] == 0) {
            endA++; // 연속되는 i의 개수 확인
        }

        min_cnt = min(min_cnt, i * 2 + (target_size - endA));// 오른쪽으로 갔다 다시 왼쪽으로 꺾기
        min_cnt = min(min_cnt, i + (target_size - endA) * 2);// 왼쪽으로 갔다 다시 오른쪽으로 꺾기
    }
    
    return min_cnt;
}