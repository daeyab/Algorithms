#include<iostream>
#include<algorithm>

using namespace std;

int arr[100001];
int findNum;

int bs(int start, int end) {
	if (start <= end) {
		int mid = (start + end) / 2;
		//같으면 찾았다
		if (findNum == arr[mid]) {
		//	cout << "같아서 찾았어요" << endl;
			return 1;
		}
		//범위나눠서 재귀
		else if (findNum < arr[mid]) {
		//	cout << "작은 쪽으로 분기" << endl;
			bs(start, mid-1);
		}
		else if (findNum > arr[mid]) {
			//cout << "큰쪽으로 분기" << endl;
			bs(mid + 1, end);
		}
	}
	else
		return 0;

}
int main() {
	int n, m;
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
		scanf("%d",&arr[i]);
	sort(arr, arr+n);
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &findNum);
	//	cout << "start" << endl;
		printf("%d \n", bs(0, n - 1));
	}
}