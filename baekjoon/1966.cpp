#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

class Node
{
public:
	int index=-1;
	int value=-1;
	Node(int index, int value)
	{
		this->index = index;
		this->value = value;
	}
	~Node() {}
	int getVal() {
		return value;
	}
	int getindex() {
		return index;
	}
};

int T, N, M;
int main() {
	cin >> T;
	while (T--) {
		cin >> N >> M;

		queue<Node> q;
		vector<int> vec;
		
		int val;
		int ind=0;
		int cnt = 1;
		for (int i = 0; i < N; i++) {
			cin >> val;
			Node node(ind++,val);
			q.push(node);
			vec.push_back(val);
		}
		
		while (true) {
			sort(vec.begin(), vec.end(),greater<int>());
			// cout <<"MAX:"<<vec[0]<< " index:" << q.front().getindex() <<" VAL:"<<q.front().getVal()<<" M:"<<M<< endl;

			//cout << q.front().getVal() <<"!"<< endl;
			if (q.front().getVal()!=vec[0]) { //최고가 아닐 때잖어 그치
				Node tmpNode = q.front();
				q.pop();
				q.push(tmpNode);
		//		cout << "최고가 아닌 pop" << endl;
			}
			else {
				if (q.front().getindex() == M) {
					q.pop();
			//		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
					cout << cnt << endl;

					break;
				}
				else {
			//		cout << "최고인데 원하는게 아님" << endl;
					q.pop();
					vec.erase(vec.begin());
					cnt++;
				}
			}
		}
	}
}
