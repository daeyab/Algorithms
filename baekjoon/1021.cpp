#include<iostream>

#include<deque>


using namespace std; 


int search(deque<int> &dq,int x) {
	int result=0;
	

	while (1) {
		if (x == dq.front()) {
			dq.pop_front();
			return result;
		}
		int index;
		//index search
		for (int i = 0; i < dq.size(); i++) {
			if (dq.at(i) == x) {
				index = i;
				break;
			}
		}
		int mid = dq.size() / 2; // 가운데 인덱스 번호

		//자 중간 초반일 때 
		if (index <= mid) {
			result++;
			int tmp = dq.front();
			dq.pop_front();
			dq.push_back(tmp);
		}
		//가운데 보다 더 갈 때
		else {
			result++;
			int tmp = dq.back();
			dq.pop_back();
			dq.push_front(tmp);
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	int n; cin >> n;
	int sum = 0;
	deque<int> dq; //처음 꺼는 수, 두번 째 꺼는 인덱스

	
	for (int i = 1; i <= n; i++)
		dq.push_back(i);

		

	int m; cin >> m;
	while (m--) {
		int num; cin >> num;
		int returnval = search(dq, num);
		//cout << num << " return val :" << returnval << endl;;
		sum+=returnval;
	}
	cout << sum << endl;
	return 0;

}