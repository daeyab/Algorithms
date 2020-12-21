#include<iostream>
#include<algorithm>

using namespace std;
int n;

long long cnt[100001] = { 0, };
long long ans[100001][2];
int maxnum = -1;
//1 : 선택했을 시 , 0 : 선택하지 않았을 시

/*
방법 : 숫자 개수를 적립함->최대 번호까지
해당 숫자를 사용하고 안 사용했을 시의 값을 저장
*/

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		cnt[num]++;
		if (maxnum < num)
			maxnum = num;
	}
	//1을 쓰게 되면 1의 개수만큼
	ans[1][1] = cnt[1];
	//2를 안쓰게 되면 1은 무조건 씀
	ans[2][0] = cnt[1];
	//2를 쓰게 되면 1은 안쓰고 2만 씀
	ans[2][1] = cnt[2] * 2;

	//3부터 비교) 안쓴다면 전 값에서 가장 큰 값을 가져옴
	//쓴다면 전 값을 빼고 전전 값 중 가장 큰 값에다 내 값을 더함
	for (int i = 3; i <= maxnum; i++) {
		ans[i][0] = max(ans[i - 1][0], ans[i - 1][1]);
		ans[i][1] = max(ans[i - 2][0], ans[i - 2][1]) + i * cnt[i];
	}

	//최대값 정답 선택
	printf("%lld", max(ans[maxnum][0], ans[maxnum][1]));
	return 0;
}
 #include<bits/stdc++.h>

using namespace std;

long long  dp[100005][2];
long long card[100005] = { 0, };

int main() {
	int n,i;
	int tmp;
	long long ans = 0;
	scanf("%d", &n);
	int maxnum = -1;
	for (i = 1; i <= n; i++) {
		scanf("%d", &tmp);
		card[tmp]++;
		maxnum = max(maxnum, tmp);
	}

//	cout << maxnum << endl;
	dp[1][1] = card[1];
	dp[2][0] = card[1];
	dp[2][1] = card[2] * 2;
	for (i = 3; i <= maxnum; i++) {
		dp[i][1] = dp[i - 1][0] + card[i] * i;
		dp[i][0] = max(dp[i - 1][1],dp[i-1][0]);
	}
	ans = max(dp[maxnum][0], dp[maxnum][1]);
	printf("%lld", ans);
	return 0;
}