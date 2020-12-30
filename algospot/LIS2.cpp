#include<stdio.h>
#include<algorithm>

int c, n, i, j, sub[100001], dp[100001];

using namespace std;

int lis(int start) {
	int& ret = dp[start];
	// 초기화한 적이 있다면 바로 반환
	if (ret != -1)
		return ret;
	// 최소값 : 1
	ret = 1;
	// 뒤 원소들 보면서 나보다 큰 경우 재귀로 값 더해서 내 값이랑 비교
	for (int next = start + 1; next < n;next++){
		if (sub[start] < sub[next])
			ret = max(ret, lis(next) + 1);
	}
	return ret;
	
}


int main() {
	scanf("%d", &c);
	while (c--) {
		scanf("%d", &n);
		for (i = 0;i < n;i++) {
			scanf("%d", &sub[i]);
			dp[i] = -1;
		}
		int ans = 0;
		for (i = 0;i < n;i++) {
			ans = max(ans, lis(i));
		}

		printf("%d\n", ans);
	}
	return 0;
}
