#include<stdio.h>

long long prefix[500005];//부분합
long long  totheRight[500005];
int n;
int i, j, k, tmp;
int main() {
   prefix[0] = 0;
   totheRight[0] = 0;
   scanf("%d", &n);
   for (i = 1; i <= n; i++) {
      scanf("%d", &tmp);
      //부분 합 구하기
      prefix[i] = tmp + prefix[i - 1];
      totheRight[i] = 0;
   }

   long long sum = prefix[n];
   long long ans = 0;
   
   //답이 나올 수 없는 경우
   if (n < 3 || sum % 3 != 0) {
      printf("0\n");
      return ans;
   }
   //각 부분의 합
   long long partSum = sum / 3;
   int k = 0;
   //뒤에서부터 보면서 해당 값을 갖는 자리를 누작 값을 적어줌
   for (j = n - 1; j >= 2; j--) {
      if (prefix[j] == partSum * 2)k++;
      totheRight[j] = k;
   
   }
   //얘도 뒤에서 부터 보면서 
   for (i = n - 2; i >= 1; i--) {
      if (prefix[i] == partSum)
         ans += totheRight[i + 1];
   }
   printf("%lld", ans);
   return 0;
}