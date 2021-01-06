#include<stdio.h>
#include<memory.h>
#define MOD 1000000007

int tc, num;
int dp[101];

int solve(int n){
	//마지막 하나 남은 경우 
	if(n<=1)
		return 1;
	int &ret=dp[n];
	if(ret!=-1)
		return ret;
	return ret=(solve(n-1)+solve(n-2)) % MOD;
}

int main(){
	scanf("%d",&tc);
	while(tc--){
		memset(dp,-1,sizeof(dp));
		scanf("%d",&num);
		printf("%d\n",solve(num));
	}
}
