#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int n, a, b, c;
	scanf("%d %d %d %d", &n, &a, &b, &c);

	int arr[4005];
	arr[0] = 0;
	//모든 리본 길이에 대하여 (총 4000 까지 길이를 가질 수 있음)
	//길이 n에 대하여 가질 수 있는 최대의 리본 수를 갖고 있음
	//해당 길이를 가질 수 있을 때 값을 비교하여 최대값을 선정함
	for (int i = 1; i <= n; i++) {
		arr[i] = -1;
		//내가 보는 길이가 a보다 크고 a 전의 값이 -1이 아니면 내 값과 비교해보는 것
		if (i - a >= 0 && arr[i - a] != -1)
			arr[i] = max(arr[i], arr[i - a] + 1);
		if (i - b >= 0 && arr[i - b] != -1)
			arr[i] = max(arr[i], arr[i - b] + 1);
		if (i - c >= 0 && arr[i - c] != -1)
			arr[i] = max(arr[i], arr[i - c] + 1);
		//	printf("%d ", arr[i]);
	}
	if (arr[n] == -1)
		arr[n] = 0;

	printf("%d", arr[n]);
	return 0;
}