#include<iostream>
#include<stack>
#include<string>
#include <stdlib.h>

using namespace std;

stack <char> stk;
int main() {
	char ch;
		string str;
		cin >> str;
		int result = 0;
		int tmp = 1;
		for (int i = 0; i < str.length(); i++) {
			ch = str.at(i);
			if (ch == '(') {
				stk.push(ch);
				tmp *= 2;
				if (i + 1 < str.length() && str[i + 1] == ')')
					result += tmp;
			} //얘가 들어오면 안에 *2
			else if (ch == '[') {
				stk.push(ch);
				tmp *= 3;
				if (i + 1 < str.length() && str[i + 1] == ']')
					result += tmp;
			}
			if (!stk.empty()) {
				if (ch == ')') {
					tmp /= 2;
					if (stk.top() == '(')
						stk.pop();
				}
				else if (ch == ']') {
					tmp /= 3;
					if (stk.top() == '[')
						stk.pop();
				}
			}
		}
		if (!stk.empty())
			result = 0;
		cout << result << endl;
	return 0;
}