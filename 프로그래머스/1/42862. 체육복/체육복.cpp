#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<bool> check;
    queue<int> lost_stu;
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    check.assign(n+1, false);
    
    for(int i=0;i<lost.size();i++){
        lost_stu.push(lost[i]);
    }
    
    // 여벌 있는 학생이 도난 당했을 경우 
    for(int i=0;i<lost.size();i++){
        int cur_lost = lost_stu.front();
        lost_stu.pop();
        
        int flag = false;
        for(int r:reserve){
            if(!check[r]){
                if(cur_lost == r){
                    flag = true;
                    check[r] = true;
                    break;
                }
            }
        }
        
        if(!flag) lost_stu.push(cur_lost);
    }
    
    // 앞,뒤 번호 학생에게 빌릴 수 있는 경우
    int l_size = lost_stu.size();
    for(int i=0;i<l_size;i++){
        int cur_lost = lost_stu.front();
        lost_stu.pop();
        
        int flag = false;
        for(int r:reserve){
            if(!check[r]){
                if(cur_lost == r-1 || cur_lost == r+1){
                    flag = true;
                    check[r] = true;
                    break;
                }
            }
        }
        
        if(!flag) lost_stu.push(cur_lost);
    }
    
    return  (n-lost_stu.size());
}