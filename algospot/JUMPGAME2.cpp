#include<stdio.h>
#include<memory.h>

int tc, size, i, j, ans;
int map[102][102];
bool dp[102][102];

void solve(int y, int x) {
   dp[y][x] = true;
   int value = map[y][x];
   if(y==size-1 && x==size-1)
      return;
      if (y + value < size) {
         solve(y + value, x);
      }
      if (x + value < size) {
         solve(y, x + value);
      }
}
   int main() {
      scanf("%d", &tc);
      while (tc--) {
         memset(dp,false,sizeof(dp));
         scanf("%d", &size);
         for (i = 0;i < size;i++) {
            for (j = 0; j < size; j++) {
               scanf("%d", &map[i][j]);
            }
         }
         solve(0, 0);
         if (dp[size - 1][size - 1])
            printf("YES\n");
         else
            printf("NO\n");
      }
   }