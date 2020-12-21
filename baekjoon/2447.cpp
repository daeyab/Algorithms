#include<iostream>

using namespace std;

bool map[3000][3000];

void star(int y, int x,int N) {
	if (N == 3) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == 0 || i == 2 || j == 0 || j == 2)
					map[y+i][x+j]=true;

			}
		}
	}
	else {
		int N1 = N / 3;
		//cout << N1 << endl;
		star(y, x, N1);
		star(y + N1, x, N1);
		star(y + 2*N1, x, N1);
		star(y, N1+ x , N1);
		star(y + 2*N1, x + N1, N1);
		star(y, x + 2 * N1, N1);
		star(y + N1, x + 2 * N1, N1);
		star(y + 2 * N1, x + 2 * N1, N1);
	}

}
int main() {
	ios::sync_with_stdio(false);
	int N;
	cin >> N;

	star(0, 0, N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
		//	cout << j;
			if (map[i][j])
				cout << "*";
			else
				cout << " ";

		}
		cout << endl;
	}
}