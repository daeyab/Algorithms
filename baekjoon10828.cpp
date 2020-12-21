#include<iostream>
#include<string>
using namespace std;

int stack[100000] = { NULL, };
int sp=0; // 비어있는 가장 앞 index

void print() {
	for (int i = 0; i < sp; i++)
		cout << stack[i] << " ";
	cout << "[" << sp << "]" << endl;
}

void push(int X) {
	sp++;
	for (int i = sp-1; i >0; i--)
		stack[i] = stack[i-1];

	
	stack[0] = X;
//	cout << X << endl;
}

void pop(){
	if (sp) {
		cout << stack[0] << endl;
		for (int i = 0; i < sp - 1; i++)
			stack[i] = stack[i + 1];
		stack[sp--] = NULL;
	}
	else
		cout << -1 << endl;
}
void size() {
	cout << sp << endl;
}

void empty() {
	if (!sp)
		cout << 1 << endl;
	else cout << 0<<endl;
}

void top() {
	if (sp)
		cout << stack[0] << endl;
	else
		cout << -1 << endl;
}

int main() {
	int N; cin >> N;
	int num;
	while (N--) {
		string str; cin >> str;
		if (str.compare("push") == 0) {
			cin >> num;
			push(num);
		//	print();
		}
		else if (str.compare("pop") == 0) {
			pop();
		//	print();
		}
		else if (str.compare("size") == 0) {
			size();
		//	print();
		}
		else if (str.compare("empty") == 0) {
			empty();
		//	print();
		}
		else if (str.compare("top") == 0) {
			top();
			//print();
		}
	}
}