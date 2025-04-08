#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    // 2명 => 투 포인터로 
    int answer = 0;
    sort(people.begin(), people.end());
    
    int left = 0, right = people.size()-1;
    
    while(left <= right){
        
        if((people[left] + people[right]) > limit){
            right--;
        }else{
            right--;
            left++;
        }
        answer++;
    }
    
    return answer;
}