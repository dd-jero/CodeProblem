# 최장 증가 부분 수열

- 어떠한 수열에서 오름차순으로 증가하는 가장 긴 부분 수열
- 이 때, 부분 수열의 각 수는 연속일 필요 없음.

# 1. 다이나믹 프로그래밍 활용: O(N^2)

![LIS_DP](https://github.com/user-attachments/assets/aca90cc6-e95d-41a9-aa18-ef8d921e7945)


- 수열의 한 원소에 대해, 그 원소에서 끝나는 최장 증가 수열을 생각
- k 앞의 순서에 있는 모든 원소들 중 값이 k보다 작은 원소에 대해, 그 각각의 원소에서 끝나는 최장 증가 수열의 길이를 알고 있다면, k에서 끝나는 최장 증가 수열의 길이도 구할 수 있음.
- 즉, 앞 순서의 모든 원소에서 끝나는 최장 증가 수열들의 길이 중 가장 긴 것을 골라 1을 더한 것이 곧 현재 수에서 끝나는 최장 증가 수열의 길이
- dp[i] = i번째 인덱스에서 끝나는 최장 증가 수열의 길이

  

```cpp
void LIS() {

	for (int i = 0;i < n;i++) {
		dp[i] = 1; // 해당 원소에서 끝나는 LIS 길이의 최솟 값 = 자기 자신만 고려함

		for (int j = 0;j < i;j++) {
			// i번째 이전의 모든 원소에 대해, 그 원소에서 끝나는 LIS 길이를 확인
			if (arr[i] > arr[j]) {
				// 현재 수가 그 원소보다 클 때만 확인
				dp[i] = max(dp[i], dp[j] + 1); // 이전 원소에서 끝나는 LIS에 현재 수를 붙인 새 LIS 길이 
			}
		}
	}
}
```

# 2. 이분 탐색 활용: O(NlogN)

![LIS_BS](https://github.com/user-attachments/assets/208ffbc2-a717-4db0-8fee-ade0624497b4)

- LIS를 기록하는 배열을 하나 더 두고, 원래 수열에서의 각 원소에 대해 LIS 배열 내에서의 위치를 찾는다.
- 현재 원소를 LIS 배열에 넣어 LIS를 유지하려고 할 때, 최적의 위치를 찾는 것

```cpp
void binary_search(vector<int> vec, int start, int end, int element) {
	// 이분 탐색으로 벡터 내에서 element의 위치를 반환 
	while (start < end) {
		int mid = (start + end) / 2;
		if (element > vec[mid]) start = mid + 1;
		else end = mid;
	}

	return end;
}

int LIS() {
	int res = 0;
	vector<int> vec;
	vec.push_back(arr[0]);

	for (int i = 1;i < n;i++) {
		// 만약 벡터의 마지막 수보다 i번째 수가 크다면, 그냥 뒤에 붙임.
		if (arr[i] > vec.back()) {
			vec.push_back(arr[i]);
			res = vec.size() - 1;
		}

		// i번째 수에 대해 벡터 내에서 그 수의 위치를 찾는다. 
		int idx = binary_search(vec, 0, res, arr[i]);
		vec[idx] = arr[i];
	}

	return res + 1;
}
```

---

출처: https://4legs-study.tistory.com/106
