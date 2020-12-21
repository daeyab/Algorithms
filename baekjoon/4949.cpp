#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main() {

	
	while (1) {
	
		stack<char> stk;
		string result = "yes";
		string str="";
		char ch=NULL;


		while (ch != '.') {
			scanf("%c", &ch);
			if (ch != '\n')
					str += ch;
		}
	//	cout << "길이:" << str.length()<<"str:"<<str<<"끝"<<endl;

		if (!str.compare("\n.") || !str.compare(".") ){ //이거 엔터만 잡으면 될텐데
		//	cout << str << " 로 끝" << endl;
			return 0;
		}
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '[' || str[i] == '(')
				stk.push(str[i]);
			
			else if (str[i] == ']' || str[i] == ')') {
				if (stk.size() == 0) {
					result = "no";
				}
				else if ((str[i] == ')' && stk.top() == '(') || (str[i] == ']'&&stk.top() == '['))
					stk.pop();
				else {
					result = "no";
								}
			}

			else if (str[i] == '.') {
				if (stk.size() > 0)
					result = "no";
			}

		}
		cout << result << endl;

	}
	return 0;
}
