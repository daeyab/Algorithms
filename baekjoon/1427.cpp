#include<iostream>
#include<string>

using namespace std;

int arr[1000001];
int tmp[1000001];

void merge(int l, int m, int r) { // 좌측과 우측 중에서 큰 것을 
	int i = l;
	int j = m + 1;
	int cnt = 0;
	while (i <= m && j <= r) {
		if (arr[i] < arr[j])
			tmp[cnt++] = arr[j++];
		else
			tmp[cnt++] = arr[i++];
	}
	while (i <= m)
		tmp[cnt++] = arr[i++];
	while (j <= r)
		tmp[cnt++] = arr[j++];
	cnt = 0;
	for (int k = l; k <= r; k++) {
		arr[k] = tmp[cnt++];
	}
}

void mergesort(int s, int e) { //반 쪼개서 중간 중간 그리고 합침 ㅇㅈ?
	if (s < e) {
		int mid = (s + e) / 2;
	//	cout << arr[s] << "와 " << arr[e] << "이 호출됨 :" <<arr[mid]<< endl;
		mergesort(s, mid);
		mergesort(mid + 1, e);
		merge(s, mid, e);
	}
}

int main() {
	string s;
	cin >> s;
	int si;
	
	for (int i = 0; i < s.length(); i++) {
	//	cout << s.at(i) << ";";
		arr[i] = s.at(i)-48;
	}
mergesort(0, s.length() - 1);
	for (int i = 0; i < s.length(); i++)
		cout << arr[i] ;
	cout << endl;

	return 0;
}