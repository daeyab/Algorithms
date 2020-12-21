#include<iostream>
#include<math.h>
#include<algorithm>

using namespace std;
int n;
int arr[1000000];
const int MAX = pow(2, 31) - 1;
int tmp[1000001];

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void selectionSort() { //최소 값을 가장 앞으로!!
	int minval;
	int tmp;
	for (int i = 0; i < n; i++) {
		minval = arr[i];
		tmp = i;
		//	cout << minval << "!"<<endl;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < minval) {
				minval = arr[j];
				tmp = j;
			}
		}
		//	cout <<i<<"에서 "<< minval << "이 최소값"<<endl;
		swap(arr[tmp], arr[i]);
	}
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void insertionSort() { //앞에서 부터 내가 찾아갈 자리를 가는 것
	for (int i = 1; i < n; i++) {
		int j = i - 1;//삽입 정렬은 2번째 인자로부터 시작
		int cmp = arr[i];
		//	cout << "cmp:" << cmp;
		while (j >= 0 && cmp < arr[j]) {
			cout << "arr[i]:" << arr[i] << " " << endl;
			//		cout << " arr[j]:" << arr[j]<<"  -";
			if (cmp < arr[j]) {
				swap(arr[i], arr[j]);
				i = j;
			}
			j--;

		}
		for (int k = 0; k < n; k++)
			cout << arr[k] << " ";
		cout << endl;

	}
}

void bubbleSort() { //2개씩 비교하면서 제일 큰것을 뒤로
	for (int i = n; i > 0; i--) {
		for (int j = 0; j < i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
	for (int k = 0; k < n; k++)
		cout << arr[k] << " ";
	cout << endl;

}

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

void quickSort(int left, int right) {
	if (left >= right)
		return;
	if (right - left == 1) {
		if (arr[right] < arr[left])
			swap(arr[right], arr[left]);

		return;
	}

		int pivot = arr[left];
		int i = left;
		int j = right;
		cout << "p:" << pivot<<endl;
		while (i < j) {
			while (arr[j] >= pivot && i < j) //
				j--; 
			cout << "j: " << j;
			while (arr[i] <= pivot && i<j)
				i++;
			cout << "i: " << i << endl;

			if (i < j) {
				swap(arr[i], arr[j]);
				cout << arr[i] << "랑 "<<arr[j] << " 바뀜" << endl;
			}
			for (int k = 0; k < n; k++)
				cout << arr[k] << " ";
			cout << endl;
		}
		cout << "일단 끝 i:" << i << " j:" << j << endl;
			cout << arr[i] << "가 바뀌어야 해" << endl;
			if (pivot < arr[i]) {
				swap(arr[left], arr[i - 1]);
				quickSort(left, i - 2);
				quickSort(i, right);

			}
			else {
				cout << arr[left] << "랑 " << arr[i] << " 바뀜" << endl;
				swap(arr[left], arr[i]);
				quickSort(left, i - 1);
				quickSort(i + 1, right);
			}
			for (int k = 0; k < n; k++)
				cout << arr[k] << " ";
			cout << endl;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	//n = 5;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	//	selectionSort();
	//	insertionSort();
	//	bubbleSort();
//	mergeSort(0, n - 1);
	quickSort(0, n - 1);
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << "\n";
}