#include<iostream>
#include<math.h>

using namespace std;
int n;
int arr[1001];
const int MAX=pow(2, 31) - 1;

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
		int j = i-1;//삽입 정렬은 2번째 인자로부터 시작
		int cmp = arr[i];
	//	cout << "cmp:" << cmp;
		while (j >= 0 && cmp < arr[j]) {
			cout << "arr[i]:" << arr[i] << " "<<endl;
	//		cout << " arr[j]:" << arr[j]<<"  -";
			if (cmp < arr[j]){
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
		for (int j = 0; j < i-1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
	for (int k = 0; k < n; k++)
		cout << arr[k] << " ";
	cout << endl;

}
int main() {
	cin >> n;
	//n = 5;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
//	selectionSort();
//	insertionSort();
	bubbleSort();
}