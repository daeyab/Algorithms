#include<iostream>
#include<algorithm>

using namespace std;

//2309
//https://www.acmicpc.net/problem/2309
//Daeyeop Kim

int height[9];
int check[9];
int sum = 0;

int main() {
	for (int i = 0; i < 9; i++) {
		cin >> height[i];
		sum += height[i];
	}
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			sum = sum - height[i] - height[j];
			if (sum == 100) {
				//여기서 부터 정렬하여 출력
				height[i] = height[j] = 100000;
				sort(height, height + 9);
				for (int i = 0; i < 7; i++) {
					cout << height[i] << endl;
				}
			}
			else {//여기서 부턴 복구 과정
				sum = sum + height[i] + height[j];
			}
		}
	}
}