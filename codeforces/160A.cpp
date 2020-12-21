#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>

//CodeForce734B Anton and Digits
//201411194 Daeyeop Kim
//2020-03-30

using namespace std;

#define MIN(a, b) a < b ? a : b

/*
아이디어 : 많은 것 먼저 가져가고 평균을 넘으면 그만
*/
int main() {

	vector<int> coins;
	int i;
	int cnt;
	int sum = 0;
	int tmp;
	scanf("%d", &cnt);
	while (cnt--) {
		scanf("%d", &tmp);
		coins.push_back(tmp);
		sum += tmp;
	}
	sort(coins.begin(), coins.end(), greater<int>());
	int ans = 0;
	int mysum = 0;
	for (i = 0; i < coins.size(); i++) {
		mysum += coins.at(i);
		ans++;
		if (mysum > sum / 2)
			break;
	}
	printf("%d", ans);

}