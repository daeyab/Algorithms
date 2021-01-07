#include<stdio.h>
#include<memory.h>

int tri[101][101];
int dp[101][101];
int dp2[101][101];
int tc, size;
	
int max (int a, int b) { return a>b ? a : b;}

int solve(int y, int x){
	int &ret = dp[y][x];
	if(y==size-1)
		return ret=tri[y][x];
	if(ret!=-1)
		return ret;
	return ret=tri[y][x]+max(solve(y+1, x+1), solve(y+1,x));	
}

int solve2(int y, int x){
	int &ret = dp2[y][x];
	if(y==size-1)
		return ret=1;
	if(ret!=-1)
		return ret;

	int sameVal=-1, small=-1, big=-1;	
	if(dp[y+1][x+1]==dp[y+1][x])
		sameVal=solve2(y+1,x+1)+solve2(y+1,x);
	else if ((dp[y+1][x+1]>dp[y+1][x]))
		big = solve2(y+1,x+1);
	else
		small = solve2(y+1,x);	
	return
		ret=max(sameVal, max(small,big));

}

int main(){
	scanf("%d",&tc);
	while(tc--){
		memset(dp,-1,sizeof(dp));
		memset(dp2,-1,sizeof(dp2));
		scanf("%d",&size);
		int x,y;
		for(y=0;y<size;y++){
			for(x=0;x<=y;x++){
				scanf("%d",&tri[y][x]);
			}
		}	
		solve(0,0);		
	//	solve2(0,0);
		printf("%d\n",solve2(0,0));

//		for(y=0;y<size;y++){
//			for(x=0;x<=y;x++){
//				printf("%d  ",dp[y][x]);
//			}
//			printf("\n");
//		}	

	}

}
