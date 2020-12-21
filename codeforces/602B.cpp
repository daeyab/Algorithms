#include<iostream>
#include<algorithm>
 
using namespace std;
 
int n;
int arr[100005];
int seq[100005];
int ans;
int smaller, smallCnt, larger, largeCnt;
int i, j, k;
 
int solve() {
	if (n == 1) {
		ans = 1; return 1;
	}
	for (k = 2; k <= n; k++) {
		if (arr[k] != arr[k - 1])
			break; //다른경우 k값 전달
	}
	if (k == n + 1) {
		ans = n;
		return n;
	}
		
	i = 1; j = k+1; //j-1까지 값을 썻음
	smaller = min(arr[k - 1], arr[k]);
	larger = max(arr[k - 1], arr[k]);
	seq[k] = k;
	if (larger == arr[k]) {
		largeCnt = 1;
		smallCnt = k - 1;
	}
	else {
		smallCnt = 1;
		largeCnt = k - 1;
	}
 
	while (1) {
		while (j <= n) {
			if (arr[j] == smaller) {
				smallCnt++;
				seq[j] = j - i + 1;
				j++;
			}
			else if (arr[j] == larger) {
				largeCnt++;
				seq[j] = j - i + 1;
				j++;
			}
			else { //못쓰는 경우
				break;
			}
 
		}
		if (j == n + 1) break;
		if (arr[j] == smaller - 1) { //더 작은 경우 -2
			while (largeCnt > 0) { //큰것 찾는거야
				if (arr[i] == smaller) {
					smallCnt--;
					i++;
				}
				else {
					largeCnt--;
					i++;
				}
			}
			larger = smaller;
			largeCnt = smallCnt;
			smaller--;
			smallCnt = 0;
		}
		else { //더 큰 경우 +2
			while (smallCnt > 0) {
				if (arr[i] == smaller) {
					smallCnt--;
					i++;
				}
				else {
					largeCnt--;
					i++;
				}
			}
			smaller = larger;
			smallCnt = largeCnt;
			larger++;
			largeCnt = 0;
		}
	}
	ans = seq[1];
	for (int l = 2; l <= n; l++) {
		ans = max(ans, seq[l]);
	}
}
 
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	solve();
	printf("%d", ans);
}
 #include<bits/stdc++.h>

using namespace std;

int n;
int arr[100001];
int dp[100001]; //sliding window 기법을 사용할 예정 == 투포인터 알고리즘
int i, j;
int ans = 0;
int main() {
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	int s = 1, e = 2;
	int status = 0; //1:증가 0:보존 -1:감소
	dp[1] = 1;

	int startNum = arr[s];
	int endNum = arr[e];
	int holdingNum = startNum;
	int diffIdx = e;

	while (e <= n) {
		int dist = arr[e] - startNum;
		//	cout << "arr:" << arr[e] << " dist:" << dist << " status:" << status << " startNum:" << startNum<<endl ;
		if (abs(dist) > 1 || (dist == -status && status!=0)) {
			//슬라이딩 윈도우 맞춰주기
			if (abs(arr[diffIdx] - arr[e]) <= 1) {
				//차이가 1인 경우
				startNum = arr[diffIdx];
				status = arr[e] - startNum;
				dp[e] = e - diffIdx + 1;
				diffIdx = e;
			}
			else {
				//너무 달라서 아예 초기화
				dp[e] = 1;
				status = 0;
				startNum = arr[e];
				diffIdx = e;
			}
				
			e++;
			continue;
		}
		if (dist == 1 && status >= 0) {
			status = 1;
			dp[e] = dp[e - 1] + 1;
			if (arr[diffIdx] != arr[e])
				diffIdx = e;
			e++;
		}
		else if (dist == -1 && status <= 0) {
			status = -1;
			dp[e] = dp[e - 1] + 1;
			if (arr[diffIdx] != arr[e])
				diffIdx = e;
			e++;
		}
		else { //dist==0ss
			dp[e] = dp[e - 1] + 1;
			if(status!=0 && arr[e-1]!=startNum)
				diffIdx = e;
			e++;

		}
	}



	for (i = 1; i <= n; i++) {
		//	printf("%d ", dp[i]);
		ans = max(ans, dp[i]);
	}
	/*
	cout << endl << endl;
	for (i = 1; i <= n; i++)
		cout << arr[i] << " ";
	cout << endl;
	for (i = 1; i <= n; i++)
		cout << dp[i] << " ";
	cout << endl;
		*/
	printf("%d", ans);
}