#include <vector>
using namespace std;

int ponketmon[200001]; // 폰켓몬의 종류 번호 1~200001

int solution(vector<int> nums)
{
    int answer = 0;
    
    for(int i=0;i<nums.size();i++)
    {
        if(nums.size()/2 == answer) break; // 최대 가능 마리 도달
        if(ponketmon[nums[i]] != 0) continue;
       
        answer++;
        ponketmon[nums[i]]++;
    }
    
    return answer;
}