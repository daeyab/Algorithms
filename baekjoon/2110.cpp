include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

int home[200001];
int cnt = 0;
int devices = 0;

bool possible(int dist) {
	//cout << dist << "시도" << endl;
	int possibleCnt=1;
	int priviousHome = home[0];
	for (int i = 1; i < cnt; i++) {
		if (home[i] - priviousHome >= dist) {
			priviousHome = home[i];
			possibleCnt++;
		}
	}
	if (possibleCnt >= devices)
		return true;
	else
		return false; 
}

int main() {

	scanf("%d %d", &cnt, &devices);
	for (int i = 0; i < cnt; i++)
		scanf("%d", &home[i]);

	sort(home, home + cnt);
	
	int low = 1, high = home[cnt - 1] - home[0], mid, result = 0;

	
	while (low <= high) {
		mid = (low+high) / 2;
		if (possible(mid)) {
			low = mid + 1;
			result = max(result, mid);
		}
		else high = mid - 1;
	}

	printf("%d \n", result);
	return 0;
}