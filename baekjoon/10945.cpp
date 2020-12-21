#include<iostream>
#include<string>
using namespace std;

int queue[100000] = { NULL, };
int rear = 0; // 비어있는 가장 앞 index
int tail = 0;

void print() {
	for ( int i=rear ; i < tail; i++)
		cout << queue[i] << " ";
	cout << "[" << tail << "]" << endl;
}

void push(int X) {
	queue[tail++]=X;
	//	cout << X << endl;
}

void pop() {
	if (rear!=tail) {
		cout << queue[rear] << endl;
		for (int i = 0; i < tail - rear + 1; i++)
			queue[i] = queue[i + 1];
		queue[tail-- ] = NULL;
	}
	else
		cout << -1 << endl;
}
void size() {
	cout << tail-rear << endl;
}

void empty() {
	if (tail==rear)
		cout << 1 << endl;
	else cout << 0 << endl;
}
void front() {
	if (rear != tail)
		cout << queue[rear] << endl;
	else
		cout << -1 << endl;
}
void back() {
	if (rear != tail)
		cout << queue[tail-1] << endl;
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
		//		print();
		}
		else if (str.compare("pop") == 0) {
			pop();
		//		print();
		}
		else if (str.compare("size") == 0) {
			size();
		//		print();
		}
		else if (str.compare("empty") == 0) {
			empty();
		//		print();
		}
		else if (str.compare("front") == 0) {
			front();
		//	print();
		}
		else if (str.compare("back") == 0) {
			back();
		//	print();
		}
	}
}