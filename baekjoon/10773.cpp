#include<iostream>
#include<stack>

using namespace std;


int main() {
	stack<int>stk;
	int n,num,sum=0;
	cin >> n;
	while (n--) {
		cin >> num;
		if (num == 0) {
			if(stk.size())
				stk.pop();
		}
		else {
			stk.push(num);
		}
	}
	//cout << "size:" << stk.size() << endl;
	int size = stk.size();
	for (int i = 0; i < size; i++) {
	//	cout << "top:" << stk.top() << endl;
		sum += stk.top();
		stk.pop();
	}
	cout << sum<<endl;
}