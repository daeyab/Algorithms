#include<stdio.h>
#include<cstring>
//CodeForce734B Anton and Digits
//201411194 Daeyeop Kim
//2020-03-30


#define MIN(a, b) ((a < b) ? a : b)

int findMin(int a, int b, int c) {
	int min = MIN(MIN(a, b), c);
	if (min < 0) min = 0;
	return min;
}

int findMin(int a, int b) {
	int min = a < b ? a : b;
	if (min < 0)
		min = 0;
	return min;
}

int cnt2 = 0, cnt3 = 0, cnt5 = 0, cnt6 = 0;
// 아이디어 : 256 최대한 -> 32 만들기
/*증명 : 내가 고른 답이 아니라고 가정
256 개수가 맞지 않음 그럼 안 쓰인 2가
32에 사용됨
근데 빠진 개수만큼 32가 생긴다 해도 커지지 않음
그럼 나은 답이 없음
*/
int main() {
	scanf("%d %d %d %d", &cnt2, &cnt3, &cnt5, &cnt6);
	int cnt256 = findMin(cnt2, cnt5, cnt6);
	long long ans = cnt256 * 256;
	int cnt32 = findMin(cnt2 - cnt256, cnt3);
	ans += cnt32 * 32;
	printf("%d\n", ans);
}