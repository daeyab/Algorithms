#include<iostream>
#include<algorithm>

using namespace std;

int num[1000001];
int cache[1000001] = { -1, 0, 1 ,1,0, };

int n;
int cnt=0;

int dp(int x) {
	if (x == 1) {
		return cnt;
	}
	int a = 100001, b = 100001, c = 100001;

	if (x % 3 == 0) 
			a= cache[x / 3];
	if (x % 2 == 0) 
			b = cache[x / 2];
	
	c=cache[x - 1];
	
//	cout << a<<", "<<b<<", "<<c<<" | "<<x<<"의 최소 값:"<<min(min(a, b), c)+1<<" "<<endl;
	return 1 + min(min(a, b), c);
}

int main() {
	cin >> n;
	cache[1] = 0;
	for (int i = 4; i <= n; i++) {
		cache[i]=dp(i);
	}
	cout <<cache[n]<<endl;


}
