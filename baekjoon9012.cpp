#include<iostream>
#include<stack>
#include<string>
using namespace std;
int T;
stack<char> stk;

int main() {
	cin >> T;
	while (T--) {
		string str;
		cin >> str;
		while (!stk.empty()) {
			stk.pop();
	}
		for (int i = 0; i < (int)str.length(); i++) {
			char ch = str.at(i);

			if (str.at(i) == '(') {
	//			cout << "push" << endl;
				stk.push('(');
			}
			else if (str.at(i) == ')') {
				if (!stk.empty()) {
					stk.pop();
				}
				else
				{
					stk.push('.');
					break;
				}
//				cout << "pop" << endl;
			}

		}
		if (stk.empty())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		
	}
	return 0;
}