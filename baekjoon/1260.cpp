//기본적인 DFS 연습
#include<stdio.h>
#include<iostream>
#include<stack>
#include<queue>

using namespace std;

int map[1001][1001];
int X, Y, node, edge, root;

stack<int> stk;
queue<int> que;

int cnt = 0;
bool visited[1001] = { 0, };
//전체 노드를 방문하였다는 사실을 알아야 함

bool checkVisited() {
	for (int i = 1; i <= node; i++) {
		if (!visited[i])
			return false;
	}
	return true;
}

void recursive_dfs(int n) {

	if (checkVisited()) {
		cout << "난 다 찾음!" << endl;
		return ;
	}
	//	return 1;
	//다 찾았으면 내가 방문한 것 서부터 순서대로
	cout << n << " ";
	visited[n] = 1;
	for (int i = 1; i <= node; i++) {
		if (map[n][i] == 1 && visited[i] == 0) {
			recursive_dfs(i);
		}
	}
}

void stack_dfs(int n) {
	visited[n] = true;
	cout << n << " ";
	if (checkVisited()) {
		return;
	}
		stk.push(n);
			for (int i = 1; i <= node; i++) {
				if (map[n][i] == 1 && visited[i] == 0) {
				
					stack_dfs(i);
				}
		}
	}

void bfs(int n) {
	visited[n] = true;
	que.push(n);
	while (!que.empty()) {
		for (int i = 1; i <= node; i++) {
			if (map[que.front()][i] == 1 && visited[i] == 0) {
				visited[i] = true;
				que.push(i);
			}
		}
	//	cout << "size : " << que.size()<<endl;
		cout << que.front() << " ";
		que.pop();
	//	cout << "size after pop: " << que.size() << endl;

	}
}


int main() {
	cin >> node >> edge >> root;
	for (int i = 0; i < edge; i++) { // map 설정
		cin >> Y >> X ;
		map[Y][X] = map[X][Y] = 1;
	}
	//경로 출력하기
	//recursive_dfs(root);
	stack_dfs(root);
	cout << endl;
	for (int i = 1; i <= node; i++) {
		visited[i] = false;
	}
	bfs(root);
	return 0;

}