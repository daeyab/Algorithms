#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int main() {
	int N, M;
	vector<int> trees;
	int MAXHeight = 0;
	
	//cout << "!!!" << endl;

	scanf("%d %d", &N, &M);
	int tmp;
	//	cout << "!!!" << endl;
	for (int i = 0; i < N; i++) {
		scanf("%d",&tmp);
		trees.push_back(tmp);
		if (MAXHeight < trees[i])
			MAXHeight = trees[i];
	}

	int h, base = 0;

	while (base+1 < MAXHeight) {
	//	cout << "21312" << endl;
		h = (base + MAXHeight) / 2;
		long long total = 0;
		for (int i = 0; i < N; i++) {
			if (trees[i] > h) {
				total += trees[i] - h;
			}
		}
		if (total < M) {
			MAXHeight = h; //높이 나추는 것
		}
		else {
			base = h;
		}
	}

	cout << base  << endl;
	return 0;
}