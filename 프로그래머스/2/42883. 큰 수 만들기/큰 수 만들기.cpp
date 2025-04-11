#include <bits/stdc++.h>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    stack<char> s;
    
    // 첫 번째 숫자 
    s.push(number[0]);
    
    for(int i=1; i<number.length();i++){
        
        while(!s.empty() && s.top() < number[i] && k>0){ // 스택 top이 현재 숫자보다 작고, 스택이 비어 있지 않으면
            // 해당 숫자 제거
            s.pop();
            k--;
        }
        s.push(number[i]);
        
    }
    
    while(!s.empty()){
        char n = s.top();
        answer += n;
        s.pop();
    }
    
    reverse(answer.begin(), answer.end());
    
    while(k > 0)
    {
        answer.pop_back();
        k--;
    }
    
    return answer;
}