#include<bits/stdc++.h>

using namespace std;

int n;

bool visited[200005];
vector<int> edges[200005];
vector<int> fromChild[200005]; //child에서 받은 것들 

class Node{
	public:
	int bw;
	int upMax, fromP,ans;
}node[200005];

int dfs(int pos){
	int thisChild;
	visited[pos]=true;
	node[pos].upMax=0;
	for(int i=0;i<edges[pos].size();i++){
		if(visited[edges[pos][i]]==false){ //no parent
			//node[edges[pos][i]].depth=node[pos].depth;
			thisChild=dfs(edges[pos][i]);
			fromChild[pos][i]=thisChild;
			if(thisChild!=-1)
				node[pos].upMax+=thisChild;
		}
	}
	if(node[pos].bw)
		node[pos].upMax++;
	else
		node[pos].upMax--;
	//자기껄 포함시킨 값을 반환
	return node[pos].upMax;
}

void dfs2(int pos,int fromParent){
	visited[pos]=true;
	if(fromParent!=-1)
		node[pos].ans=node[pos].upMax+fromParent;
	else
		node[pos].ans=node[pos].upMax;
	
	for(int i=0;i<edges[pos].size();i++){
		if(visited[edges[pos][i]]==false){ //no parent
			if(fromChild[pos][i]==-1)
				dfs2(edges[pos][i],node[pos].ans);
			else
				dfs2(edges[pos][i],node[pos].ans-fromChild[pos][i]);		
		}
	}
	//자기껄 포함시킨 값을 반환
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&node[i].bw);
	}
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		edges[a].push_back(b);
		edges[b].push_back(a);
		//몇번째 child에서 받았는지 확인하는 것 
		fromChild[a].push_back(0);
		fromChild[b].push_back(0);
	}
	dfs(1); //
	for(int i=0;i<=n;i++){
		visited[i]=0;
	}
	dfs2(1,0);
	for(int i=1;i<=n;i++){
		printf("%d",node[i].ans);
	} 
	printf("\n");
}