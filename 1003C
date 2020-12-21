#include<stdio.h>


int arr[5001];
int prefix[5001];
int n, k;
int i, j;
int main() {
	scanf("%d", &n);
	scanf("%d", &k);
	prefix[0] = arr[0] = 0;

	//부분합 정렬하기
	for (i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		prefix[i] = prefix[i - 1] + arr[i];
	}

	double avg = 0;
	double max = 0;

	//1~n 까지 k개씩 보는거
	//최소 k연속적인 날들의 평균의 최대값이 결과임
	for (i = 1; i <= n - k + 1; i++) {
		int tmpk = k;
		
		while (i + tmpk - 1 <= n) {
			//부분합을 구하는 거니까 부분합을 빼면 구간합을 구할 수 있음
			avg = (double)(prefix[i + tmpk - 1] - prefix[i - 1]) / tmpk;
			if (avg > max)
				max = avg;
			//평균이 크면 비교하고 아니면 tmpk값 올리면 됨
			tmpk++;
		}
	}
	printf("%.10f\n", max);
}
//최소 k 연속적인 날들의 평균 중 최대값을 구하기
//구하기 위해서 부분합 차를 통해 구간합을 구해서 평균을 구한다.