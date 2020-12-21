[ 코드 ]

#include<iostream>
#include<string>

using namespace std; 



class Deque {
	
private:
	
public:
	int s = 0; //배열의 시작지점
	int e = 0; //배열 빈공간의 시작지점
	int arr[20001];
	void push_front(int X) {
		for (int i = e-1; i >=s; i--)
			arr[i + 1] = arr[i];
		arr[s] = X;
		e++;
	}
	void push_back(int X) {
		arr[e++] = X; 
	}
	int pop_front() { 
		if (s == e)
			return -1;
		int res = arr[s];
		s++;
		return res;
	}
	int pop_back() {
		if (s == e)
			return -1;
		int res = arr[e-1];
		e--;
		return res; }
	int size() { return e - s; }

	bool empty() { 
		if (e - s == 0)return true;
		else 
			return false; 
	}

	int front(){
		if (e == s)
			return -1;
		return arr[s]; 
	}
	int back() {
		if (e == s)
			return -1;
		return arr[e-1];
	}
};

int main() {
	ios::sync_with_stdio(false);

	Deque d = Deque();
	int n;
	int num;
	cin >> n;
	while (n--) {
		string str;
		cin >> str; 
		if (!str.compare( "push_back")) {
			cin >> num;
			d.push_back(num);
		}
		else if (!str.compare("push_front")) {
			cin>>num;
			d.push_front(num);
		}
		else if (!str.compare("pop_front"))
			printf("%d\n", d.pop_front());
		else if (!str.compare("pop_back"))
			printf("%d\n", d.pop_back());
		else if (!str.compare("size"))
			printf("%d\n", d.size());
		else if (!str.compare("empty"))
			printf("%d\n", d.empty());
		else if (!str.compare("front"))
			printf("%d\n", d.front());
		else if (!str.compare("back"))
			printf("%d\n", d.back());


/*		for (int i = 0; i < 10; i++)
			cout << d.arr[i] << " ";
		cout <<"s:"<<d.s<<" e:"<<d.e<< endl;*/

	}

	return 0;

}