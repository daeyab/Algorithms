#include<bits/stdc++.h>

#define inf 9000000000000000000
using namespace std;


/*문제 정의
사전 순으로 정렬할 건데 문자열을 앞뒤로 바꾸기만 가능->비용 최소화
-해결 DP-
해당 문제를 정렬하여 풀었는지, 안 풀었는지 저장
전체 정렬이 가능한 경우 최소값 불가 시 -1
*/
int n;
string words[100001];
int cost[100001];
long long sum[100001];
long long dp[100001][2];
long long ans;

int main() {

	//cout << inf<<endl;
	bool isminus = false;
	//	strcmp("bca", "ba") -> 앞이 크면 1 뒤가 크면 -1 
	scanf("%d", &n);
	//	reverse(b.begin(), b.end()) -> 문자열 뒤집기

	for (int i = 1; i <= n; i++) {
		scanf("%d", &cost[i]); 
	}
	for (int i = 1; i <= n; i++) {
		cin >> words[i]; 
	}
	dp[1][0] = 0; dp[1][1] = cost[1];

	for (int i = 2; i <= n; i++) {
		//현재 단어와 이전 단어 비교
		//어떻게든 정렬이 가능하면 현재 값은 바뀜
		dp[i][0] = dp[i][1] = inf;
		string before = words[i - 1]; 
		string before_rev = before;
		reverse(before_rev.begin(), before_rev.end());
		string now = words[i];
		string now_rev = now;
		reverse(now_rev.begin(), now_rev.end());

		//strcmp값이 양수면 현재 값이 더 크다는 것 == 정렬 되었다는 것
		//위 두개는 내가 정렬하지 않고도 가능한 경우-> 이전 것을 뒤집 은 것에 대한 최소 값
		if (dp[i - 1][0] != inf && strcmp(now.c_str(), before.c_str()) >= 0)
			dp[i][0] = dp[i - 1][0];

		if (dp[i - 1][1] != inf && strcmp(now.c_str(), before_rev.c_str()) >= 0)
			dp[i][0] = min(dp[i][0], dp[i - 1][1]);

		if (dp[i - 1][0] != inf && strcmp(now_rev.c_str(), before.c_str()) >= 0)
			dp[i][1] = dp[i - 1][0] + cost[i];

		if (dp[i - 1][1] != inf && strcmp(now_rev.c_str(), before_rev.c_str()) >= 0)
			dp[i][1] = min(dp[i][1], dp[i - 1][1] + cost[i]);

		//정렬이 안된다면 실패
		if (dp[i][0] == inf && dp[i][1] == inf) {
			ans = -1;
			isminus = true;
			break;
		}
	}

	if (!isminus) {
		ans = min(dp[n][1], dp[n][0]);
	}
	if (ans == inf) {
		ans = -1;
	}

	cout << ans << endl;



	return 0;

}