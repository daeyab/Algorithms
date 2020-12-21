#include <stdio.h>

int a[5005];

/*
해결 방법

*/
int solve(int start, int end) {
	int i = 0, vans, hans, mini, left, right;
	vans = end - start + 1;
	mini = a[start];
	//최소값을 정한다 최소값 까지는 가로로 쭉 그을 수 있으니깐
	for (i = start + 1; i <= end; i++) {
		if (mini > a[i])
			mini = a[i];
	}
	//최소값을 뺀 나머지의 상단 애들의 구간을 다시 재귀로 구한다.
	for (i = start; i <= end; i++)
		a[i] -= mini;
	//최소값은 가로로 칠할 수 있는 정답이다.
	hans = mini;
	//시작서부터 끝까지 i번째 울타리가 있는지 확인
	for (i = start; i <= end;) {
		//해당 울타리를 다 칠했거나 모든 울타리를 다 보았다면 끝내기
		if (a[i] <= 0 && i <= end)i++;
		else {
			//해당 울타리에서 오른쪽으로 가면서 이어진 울타리가 있는지 확인
			left = i;
			right = left;
			while (a[right] > 0 && right <= end)
				right++;
			//해당 구간 재귀적으로 돌림
			hans += solve(left, right - 1);
			//재귀적으로 돌려서 나중에 받아버리고 일단 오른쪽까지는 해결된 상태임
			i = right;
		}
	}
	//전체 n개의 울타리를 가로로 칠한 것 보다 많으면 그냥 가로 수를 출력하렴
	if (vans < hans) return vans;
	else return hans;
}

int main(void) {
	int n;
	int ans;
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	ans = solve(1, n);
	printf("%d\n", ans);

	return 0;
}