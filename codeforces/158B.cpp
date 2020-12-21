#include<stdio.h>
#include<cstring>
//CodeForce 158B Taxi
//201411194 Daeyeop Kim
//2020-03-30

#define MIN(a, b) a < b ? a : b

int cnt2 = 0, cnt3 = 0, cnt5 = 0, cnt6 = 0;
int main() {
	int groups;
	scanf("%d", &groups);
	int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
	while (groups--) {
		int howmany;
		scanf("%d", &howmany);
		//그룹 수 정하기
		switch (howmany)
		{
		case 1: cnt1++;
			break;
		case 2: cnt2++;
			break;
		case 3: cnt3++;
			break;
		case 4: cnt4++;
		default:
			break;
		}
	}
	
	int ans = 0;
	//4명은 한대에 다 태울 수 있음 정답처리
	ans += cnt4;
	//3명은 한대에 다 태움
	ans += cnt3;
	//3명 탄 차 중에 1이 들어갈 수 있음 가고 남은 1애들만 관리함
	cnt1 = cnt1 - cnt3;
	//2명씩 일단 태움
	ans += cnt2 / 2;
	//남았으면 일단 차 하나 더 배정
	if (cnt2 % 2 == 1) {
		ans++;
		cnt1 -= 2;
		//1애들 두명 껴 넣어줌
	}
	if (cnt1 > 0) {
		//그래도 1애들 남았으면 4명씩 묶어서 태움
		ans += cnt1 / 4;
		//남은 애들 택시 태워서 보냄
		if (cnt1 % 4 != 0)
			ans++;
	}
	printf("%d\n", ans);


}
