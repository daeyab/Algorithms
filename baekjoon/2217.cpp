#include<iostream>
#include<algorithm>

using namespace std; 

int N, rope[100000];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> rope[i];
	}
	sort(rope, rope + N,greater<int>());//내림차순 정렬
	int compare,result = rope[0];
	//cout << "!!";
	for(int i=0;i<N;i++){
		compare = rope[i] * (i + 1);
		if (result <= compare)
			result = compare;
		//else
		//	break;
	//	cout << "result:" << result<<endl;
	}
	
	cout << result ;

}