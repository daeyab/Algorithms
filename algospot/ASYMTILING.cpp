#include<stdio.h>
#include<memory.h>

const int MOD = 1000000007;

int tc,n;

int dp[101];

int solve(int len){
	if(len<=1)
		return 1;
	int &ret=dp[len];
	if(ret!=-1)
		return ret;
	return ret=(solve(len-1)+solve(len-2)) % MOD;
}

int asymetric(int len){
	if(len%2==1)
		return (solve(n)-solve(n/2)+MOD)%MOD;

		int total=solve(n);
		total=(total-solve(n/2)+MOD) % MOD;
		total=(total-solve(n/2-1)+MOD)%MOD;
		return total;
}


int main(){
	scanf("%d",&tc);
	while(tc--){
		memset(dp,-1,sizeof(dp));
		scanf("%d",&n);
		printf("%d\n",asymetric(n));
	}
}
