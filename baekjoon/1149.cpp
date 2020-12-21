#include<iostream>
#include<algorithm>

using namespace std; 

int street[1001][3];
int mem[1001][3];

int n;

void dp(int y,int x) {
	if (x == 0) {
		mem[y][x] = street[y][x] + min(mem[y - 1][1], mem[y - 1][2]);
	}
	else if (x == 1) {
		mem[y][x] = street[y][x] + min(mem[y - 1][0], mem[y - 1][2]);
	}
	else {
		mem[y][x] = street[y][x] + min(mem[y - 1][0], mem[y - 1][1]);
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> street[i][0] >> street[i][1] >> street[i][2];
		dp(i, 0); dp(i, 1); dp(i, 2);
	}
	//cout << endl;
	
	sort(mem[n], mem[n]+3);
	cout << mem[n][0] << endl;

}