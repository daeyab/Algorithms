#include<stdio.h>
#include<memory.h>

int tc,n,m;

double dp[1001][2005];

double solve(int days,int meter){
	//n일 동안 m미터에 갈 확률
	if(days==m)
		return meter>=n ? 1.0:0.0;
	double &ret=dp[days][meter];
	if(ret!=-1.0)
		return ret;
	return ret=0.75*solve(days+1, meter+2)+0.25*solve(days+1,meter+1);
}
int main(){
	scanf("%d",&tc);
	while(tc--){
		int i,j;
		for(i=0;i<1001;i++){
			for(j=0;j<2010;j++)
				dp[i][j]=-1;
				//실수는 memset으로 초기화하면 안된다! 
		}
		scanf("%d %d",&n,&m);
		printf("%.8f\n",solve(0,0));
	}
}
