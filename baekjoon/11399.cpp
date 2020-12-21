#include<iostream>
#include<algorithm>

using namespace std; 

int main() {
	int N, P[1000], sum[1000] = { 0 ,},total;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}
	sort(P, P + N);
	sum[0] = P[0];
	total = sum[0];
	for (int i = 1; i < N; i++) {
		sum[i] = P[i] + sum[i - 1];
		total += sum[i];
	}
	cout << total << endl;
	
}