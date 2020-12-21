#include<iostream>
#include<stack>
#include<vector>
#include<math.h>
#include<memory.h>

struct tower {
	int x, y, r;
	bool visited;
};
using namespace std;

vector<tower> vec;

int testcase, N, x, y, r, mapsize, cnt = 0;

bool checkNear(tower t1, tower t2) {
	if (sqrt(pow((t1.x - t2.x), 2) + pow((t1.y - t2.y), 2)) <= t1.r + t2.r) 
		return true;
	
	else
		return false;
}

void dfs(int x) {
	//cout << cnt<<endl;
	tower tw = vec.at(x);
	if (tw.visited)
		return;
	vec.at(x).visited = true;
	cnt++;
	for (int i = 0; i < vec.size(); i++) {
		tower check = vec.at(i);
		if (!check.visited && checkNear(tw, check)) {
			cnt--;	
			dfs(i);
		}
	}
	
}
int main() {
	cin >> testcase;
	while (testcase--) {
		cnt = 0;
		cin >> N;
		while (N--) {
			cin >> x >> y>>r;
			if (x > y)
				mapsize = x;
			else
				mapsize = y;

			tower t = { x,y,r,false};
			vec.push_back(t);
		}
		for(int i=0;i<vec.size();i++)
			dfs(i);
	//	cout << vec.size() << endl;
	//	cout << checkNear(vec.at(0), vec.at(1)) << endl;
		
		cout << cnt << endl;

		vec.clear();
	}
	return 0;
}