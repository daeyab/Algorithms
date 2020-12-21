#include<algorithm>
#include<iostream>
#include<math.h>
#include<vector>

int arr[1000001];
int tmp[1000001];
int countNum[8001] = { 0, };
int sum = 0;
using namespace std;

void merge(int left, int mid, int right) {

	int i = left;
	int j = mid + 1;
	int cnt = 0;
	while (i <= mid && j <= right) {
		if (arr[i] < arr[j])
			tmp[cnt++] = arr[i++];
		else
			tmp[cnt++] = arr[j++];
	}
	while (i <= mid)
		tmp[cnt++] = arr[i++];
	while (j <= right)
		tmp[cnt++] = arr[j++];

	cnt = 0;
	for (int k = left; k <= right; k++) {
		arr[k] = tmp[cnt++];
	}
}

void mergeSort(int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(left, mid);
		mergeSort(mid + 1, right);
		merge(left, mid, right);

	}
}
int n;

int findfrequent() {
	int maxnum = -4001;
	bool onemoremax = 0;
	vector<int>maxindex;
	for (int i = 0; i <= 8000; i++) { //최빈 값 구하는 알고리즘 가장 많이 나온 값 중 2번째로 작은 값 max를 찾고
	//	cout << maxnum << endl;
		if (countNum[i] >= maxnum) {
			if (maxnum < countNum[i]) {
				maxnum = countNum[i]; // //최고로 많이 나오는 값을 찾음 // 이게 중복이 있는지 찾아야 함
				onemoremax = false;
				maxindex.clear();
				maxindex.push_back(i - 4000);
			}
			else if (maxnum == countNum[i]) {
				onemoremax = true;
				maxindex.push_back(i - 4000);
			}
		}
	}
	if (!onemoremax)//하나라면
		return maxindex.at(0);
	else
		return maxindex.at(1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	int maxval = -4001;
	int minval = 4001;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
		countNum[arr[i] + 4000]++;
		if (arr[i] > maxval)
			maxval = arr[i];
		if (arr[i] < minval)
			minval = arr[i];
	}

	mergeSort(0, n - 1);

	//for(int i=0;i<=)

	//for (int i = 0; i < n; i++)
	//	cout << arr[i] << endl;
	//	cout<<sum<<":"<<n<<endl;
	// cout << endl;
	float ans = (float)sum / (float)n;
	//cout << ans << endl;
	cout <<round(ans)<< endl;
	cout << arr[n / 2] << endl;
	cout << findfrequent() << endl;
	cout << maxval - minval << endl;

	//cout <<"최빈"<< maxcount << endl; 최빈은 그 값에 자료구조를 하나 더 만들을까 8000짜리 배열을 만들어서 값 + 4000 이 인덱스이고 , val : 횟수 ㅇㅋ?
	//범위

	return 0;
}