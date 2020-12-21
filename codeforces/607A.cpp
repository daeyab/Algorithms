#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int n;
pair<int, int> info[100001];
//내가 죽이는 비콘의 개수를 저장
int killedByMe[100001];


int bs(int x)
{
	int l = 1, r = n; //이분탐색을 통하여
	while (l < r)
	{
		int mid = (l + r) / 2;
		if (info[mid].first >= x) r = mid;
		else l = mid + 1;
	}
	return l; //x를 기준으로 왼쪽으로 붙은 애
}
int main()
{

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &info[i].first, &info[i].second);

	//위치에 대하여 모두 정렬
	sort(info + 1, info + n + 1);

	killedByMe[0] = 0;
	for (int me = 1; me <= n; me++) {
		//모든 비컨들을 보면서 내가 죽이는 범위외에 가장 가까이 있는 비컨을 nextB
		int nextB = bs(info[me].first - info[me].second);
		killedByMe[me] = killedByMe[nextB - 1] + me - nextB; 
		//nextB는 사니까 내가 죽이는 건 다음 애가 죽이는 거 + 나와 next B 인덱스 사이에 있는 비컨
	}

	//다 살아있다 가정
	int result = n;
	

	//모든 비컨들에 대하여 뒤에서 부터 하나씩 죽여갈 때의 최소 죽어가는 애들 값
	for (int i = 1; i <= n; i++)
		result = min(result, killedByMe[i] + n - i);

	cout << result << endl;

}