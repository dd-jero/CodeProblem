#include <bits/stdc++.h>

using namespace std;

int people1[5] = {1,2,3,4,5}; // 5개 반복
int people2[8] = {2,1,2,3,2,4,2,5}; // 8개 반복
int people3[10] = {3,3,1,1,2,2,4,4,5,5}; // 10개 반복
int cnt[3] = {0,0,0}; // 각 수포자가 맞춘 수 

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    for(int i=0;i<answers.size();i++){
        // 수포자 1이 맞추면
        if(answers[i] == people1[i%5]) cnt[0]++;
        
        // 수포자 2가 맞추면
        if(answers[i] == people2[i%8]) cnt[1]++;
        
        // 수포자 3이 맞추면 
        if(answers[i] == people3[i%10]) cnt[2]++;
    }
    
    // 최대 점수 구하기
    int max_cnt = 0;
    for(int i=0;i<3;i++){
        max_cnt = max_cnt < cnt[i] ? cnt[i] : max_cnt;
    }
    
    // 최대 점수와 같은 인덱스 삽입
    for(int i=0;i<3;i++){
        if(cnt[i] == max_cnt) answer.push_back(i+1);
    }
    
    return answer;
}