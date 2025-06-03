#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

// 비교 함수: 포인터 기반 비교
bool cmp(const string* a, const string* b) {
    if (a->length() == b->length()) {
        return *a < *b; // 사전 순
    }
    return a->length() < b->length(); // 길이 순
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    unordered_set<string> unique_strings;
    string str;

    // 1. 중복 제거 (O(1) 시간 복잡도)
    while (N--) {
        cin >> str;
        unique_strings.insert(move(str)); // 이동 생성자로 효율성 향상
    }

    // 2. 포인터 벡터 생성
    vector<const string*> ptr_vec;
    ptr_vec.reserve(unique_strings.size()); // 메모리 사전 할당

    for (const auto& s : unique_strings) {
        ptr_vec.push_back(&s); // 실제 데이터 복제 없이 주소만 저장
    }

    // 3. 포인터 기반 정렬
    sort(ptr_vec.begin(), ptr_vec.end(), cmp);

    // 4. 결과 출력
    for (const auto& ptr : ptr_vec) {
        cout << *ptr << '\n'; // 포인터 역참조 출력
    }

    return 0;
}
