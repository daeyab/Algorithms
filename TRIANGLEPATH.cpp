#include<stdio.h>

int c, n, map[101][101], dp[101][101], i, j,ans;

int max(int a, int b) { return a > b ? a : b; }


int main() {
	scanf("%d", &c);
	while (c--)
	{
		scanf("%d", &n);
		for (i = 0;i < n;i++) {
			for (j = 0;j <= i;j++) {
				scanf("%d", &map[i][j]);
				dp[i][j] = map[i][j];
			}
		}
		for (i = 1;i < n;i++) {
			dp[i][0] += dp[i - 1][0];
			for (j = 1;j <= i;j++) {
				dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
			}
		}
		ans = 0;
		for (i = 0;i < n;i++)
			ans = max(ans, dp[n - 1][i]);
		printf("%d\n", ans);
	}
	return 0;
}
