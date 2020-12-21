#include<iostream>
#include<math.h>

using namespace std;


void Hanoi(int n, int from, int by, int to){
	if (n == 1) {
		printf("%d %d \n", from, to);
		return;
	}
	else {
		Hanoi(n - 1, from, to, by);	
		printf("%d %d \n", from, to);
		Hanoi(n - 1, by, from, to);
	}

}

int GetHanoiResult(int n){
	if (n == 1)
		return 1;
	else
		return pow(2, n) - 1;
}

int main() {
	ios::sync_with_stdio(false);
	int i;
	cin >> i;
	printf("%d \n",GetHanoiResult(i));

	Hanoi(i, 1, 2, 3);
	
}