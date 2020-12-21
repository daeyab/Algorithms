#include<stdio.h>
#include<cstring>
//CodeForce 1003C Intense Heat
//201411194 Daeyeop Kim
//2020-03-30

int tc;
int n;

long long prefix[100001];
long long suffix[100001];
int arr[100001];

int i, j;
int main() {

	scanf("%d", &tc);
	while (tc--) {

		//테스트케이스 마다 초기화 시킴
		memset(prefix, 0, sizeof(prefix));
		memset(suffix, 0, sizeof(suffix));
		memset(arr, 0, sizeof(arr));

		scanf("%d", &n);

		//배열값 입력
		for (i = 1; i <= n; i++) {
			scanf("%d", &arr[i]);
		}

		bool negativecheck = false;

		for (i = 1; i <= n; i++) {
			//뒤에서 보는 부분합을 구함
			suffix[n - i + 1] = suffix[n - i + 2] + arr[n - i + 1];
			//앞에서 보는 부분합을 구함
			prefix[i] = prefix[i - 1] + arr[i];
			//앞부분이나 뒷부분 중에서 음수가 하나라도 있으면 안됨
			//음수만 안되는 경우에는 이유가 7, -4, 5 같은 경우가 있음
			if (suffix[n - i + 1] <= 0 || prefix[i] <= 0) {
				printf("NO\n");
				negativecheck = true;
				break;
			}
		}
		if (negativecheck == false) {
			printf("YES\n");
		}
	}

}