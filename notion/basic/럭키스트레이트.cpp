#include<stdio.h>
#include<math.h>
int main(){
	int n;
	int head=0,tail=0,i;
	scanf("%d",&n);
	int len=log10(n)+1;
	for(i=0;i<len/2;i++){
		tail+=n%10;
		n/=10;
	}
	for(i=0;i<len/2;i++){
		head+=n%10;
		n/=10;
	}
//	printf("%d %d\n",head, tail);
	if(head==tail)
		printf("LUCKY\n");
	else
		printf("READY\n");
	
}
