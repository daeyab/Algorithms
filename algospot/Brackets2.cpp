#include<iostream>
#include<stack>
#include<string>

using namespace std; 

int vec[500001];


 

 void solve(string str) {
	 stack<char> stk;
	 for (int i = 0; i < str.length(); i++) {
		 if (str.at(i) == '[' || str.at(i) == '(' || str.at(i) == '{') stk.push(str.at(i));
		 
		 else if (stk.empty()) {
			 cout << "NO" << endl;
			 return;
		 }
			 
		 else if (str.at(i) == ']') {
			 if (stk.top() == '[')
				 stk.pop();
			 else {
				 cout << "NO" << endl;
				 return;
			 }
		 }
		 else if (str.at(i) == ')') {
			 if (stk.top() == '(')
				 stk.pop();
			 else {
				 cout << "NO" << endl;
				 return;
			 }
		 }
		 else if (str.at(i) == '}') {
			 if (stk.top() == '{')
				 stk.pop();
			 else {
				 cout << "NO" << endl;
				 return;
			 }
		 }
	 }
	 if (stk.empty())
		 cout << "YES" << endl;
	 else
		 cout << "NO" << endl;
 }
int main() {
	
	ios::sync_with_stdio(false);
	int n; cin >> n;
	string str;
	while (n--) {
		cin >> str;
		solve(str);
	}

	return 0;
}
