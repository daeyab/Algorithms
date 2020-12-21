#include <stdio.h>

//Codeforces 768-B
//Code For 1
//201411194

long long n, l, r, lenofAns = 1, ans = 0;

void solve(long long a, long long b, long long l, long long r, long long d) {
	//a:시작길이 b:끝길이 
	if (a > b || l > r) return;
	else {
		long long mid = (a + b) / 2;
		if (r < mid) solve(a, mid - 1, l, r, d / 2);
		else if (mid<l) solve(mid + 1, b, l, r, d / 2);
		else { //mid가 [l,r] 사이에 갇혀있을 때
			ans += d % 2; //d로 나눈 나머지 =이게 사실 mid값이다!
			solve(a, mid - 1, l, mid - 1, d / 2);
			solve(mid + 1, b, mid + 1, r, d / 2);
		}
	}

}

int main(void) {
	scanf("%lld %lld %lld", &n, &l, &r);

	//자리수 구하기
	long long tmp = n;
	while (tmp >= 2) {
		tmp /= 2;
		lenofAns = lenofAns * 2 + 1;
	}
	//ans = 1;
	solve(1, lenofAns, l, r, n);

	printf("%lld", ans);
	return 0;

}
 #include<bits/stdc++.h>

using namespace std; 

long long  n, len = 0, l, r;
vector<int> binary;
vector<long long>ans;
int i;

//x:들어온 실제 인덱스 값
long long solve(long long x) {
	//결과 
	long long result=0;
	while (x >=1 ) {
		// 실제 인덱스에 로그값을 취하여 가져올 수 있는 prefix 값을 가져옴
		// 그 값과 마지막 값, 즉 이진수의 끝값을 가져옴.
		// 그 값을 지우면 앞에서 또한 반복되는 값이므로 무한 반복함
		int idx = log2(x);
//		if (idx > 1)
		result += ans[idx] + binary[idx+1];
		x = x - pow(2, idx);
	}

	//cout << "결과 " << result << endl;
	return result;
}

int main() {
	scanf("%lld %lld %lld", &n,&l,&r);
	long long tmp = n;
	if (n == 0) {
		printf("0\n");
		return 0;
	}
	//2진수로 변환, 길이를 구함
	while (tmp > 0) {
		binary.push_back(tmp % 2);
		tmp /= 2;
		len = len * 2 + 1;
	}
	binary.push_back(0);
	//2진수 구하기
	reverse(binary.begin(), binary.end());
	//1,3,7,반복되는 구간의 prefix sum 구하기
	ans.push_back(0);
	

//	ans.push_back(binary[0]);	
	for (i = 1; i < binary.size(); i++) {
		ans.push_back(ans[i - 1] * 2 + binary[i]);
	}
/*	
	for (i = 0; i < binary.size(); i++)
		cout << binary[i] << " ";
	cout << endl;

	for (i = 0; i < ans.size(); i++)
		cout << ans[i]<<" ";
	cout << endl<<endl;*/
	//prefix sum을 통해 정답 구하기
	long long ans=solve(r)-solve(l-1);
	printf("%lld", ans);
//	printf("%lld", solve(1));

	return 0;
}