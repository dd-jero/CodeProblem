#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

int solution(vector<int> nums)
{
    unordered_set<int>s (nums.begin(), nums.end());
    
    return min(s.size(), nums.size()/2); // 중복되지 않는 폰켓몬 수, N/2 중 작은 값
}