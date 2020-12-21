//버전 1 무식하게 풀기
#include<bits/stdc++.h>

using namespace std;

int n, i, j;
int num[105];
int ans;

int main() {
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &num[i]);
	}


	for (i = 1; i <= n; i++) {
		for (j = i; j <= n; j++) {
			int tmp = 0;
			for (int k = 1; k <= n; k++) {
				if (i <= k && k <= j) {
					if (num[k] == 0)
						tmp++;
				}
				else {
					if (num[k] == 1)
						tmp++;
				}
			//	printf("%d!!", num[k]);
			}
			if (ans < tmp)
				ans = tmp;
		//	printf("%d,%d : %d\n",i,j, tmp);
		}
	}

	printf("%d\n", ans);


	return 0;
}
 //버전2 prefix 로 n^2
#include<bits/stdc++.h>

using namespace std;

int n, i, j;
int num[105];
int prefix[105];
int startVal, endVal;
int ans;

int main() {
	prefix[0] = 0;
	scanf("%d", &n);
	bool allone = true;
	for (i = 1; i <= n; i++) {
		scanf("%d", &num[i]);
		if (num[i] == 0)
			allone = false;
		prefix[i] += num[i] + prefix[i - 1];
	}
	if (n == 1) {
		if (num[1] == 1)
			printf("0\n");
		else
			printf("1\n");
		return 0;
	}
	else if (allone) {
		printf("%d", n-1);
		return 0;
	}

	for (i = 1; i <= n; i++) {
		for (j = i; j <= n; j++) {
			int tmp = 0;
			//전 1 중간 0 후 1 값 구하면 돼
			tmp = prefix[i - 1] + j - prefix[j] - i+1 + prefix[i - 1] + prefix[n] - prefix[j - 1];
			if (ans < tmp)
				ans = tmp;
			//printf("%d,%d : %d\n",i,j, tmp);
		}
	}
	printf("%d\n", ans);


	return 0;
}
 //버전 3 DP
#include<bits/stdc++.h>

using namespace std;

int n, i, j;
int num[105];
int dp[105][3]; // 0: 이전에 아무일도 없었음, 1: 반드시 뒤집는 중, 2: 반드시 안뒤집음(이미 끝남)
int ans;
bool allone = true;
int rev(int i){
	if (num[i] == 1)
		return 0;
	else return 1;
}

int main() {
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &num[i]);
		if (num[i] == 0)
			allone = false;
	}
	if (n == 1) {
		printf("%d", rev(1));
		return 0;
	}
	else if(allone){
		printf("%d", n - 1);
		return 0;
	}

	dp[1][0] = num[1];
	dp[1][1] = rev(1);
	dp[1][2] = -1;

	for (i = 2; i <= n; i++) {
//이전에 아무일이 없었던 것에 대해 쭉 아무일이 없어야 한다
		dp[i][0] = dp[i - 1][0] + num[i];
//내가 뒤집히는 것은 계속 뒤집히거나 이전에 아무것도 없었던 일에 대해 최대값
		dp[i][1] = max(dp[i - 1][1], dp[i - 1][0])+rev(i);
//이전에 닫힌 값은 방금 전 뒤집혔거나 애초에 이미 뒤집혔거나
		dp[i][2] = max(dp[i - 1][2] + num[i], dp[i - 1][1] + num[i]);
	}

	for (i = 0; i <= n; i++) {
	//	printf("%d %d %d\n", dp[i][0], dp[i][1], dp[i][2]);
	}
	ans = max(dp[n][0], max(dp[n][1], dp[n][2]));
	printf("%d", ans);

	return 0;
}
 //수학적으로 풀기

#include<iostream>

using namespace std;

int main() {
	int n;
	int cntarr[101];
	int cnt1 = 0, max0=-1;
	scanf("%d", &n);
	int val;
	cntarr[0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &val);
	
		if (val == 1) {
			cnt1++;
			if (cntarr[i - 1] > 0) {
				cntarr[i] = cntarr[i - 1] - 1;
			}
			else {
				cntarr[i] = cntarr[i - 1];
			}
		}
		else {
				cntarr[i] = cntarr[i - 1] + 1;
		}
		if (cntarr[i] > max0)
			max0 = cntarr[i];
		
		//printf("%d!", cntarr[i]);
	}
	//printf("\n%d %d\n", max0, cnt1);
	if (n == cnt1)
		printf("%d",n-1);
	else
		printf("%d", max0 + cnt1);
	return 0;
}