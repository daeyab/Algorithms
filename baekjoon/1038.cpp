#include<iostream>
#include<math.h>

using namespace std; 

long long x=1;
int cnt = 0;

long long decresingNum(long long n) {
	int len, cur, past = 99;
	len = log10(n) + 1;

	while (len--) {
		cur = n / pow(10, len); 
			
		n = n % (int)pow(10, len);

		if (cur >= past) { //비교하는 수가 더 커지면 멈춰라{
		//	cout <<"x가 "<<x<<"일 때 len : "<< len<<endl;
			return len+1;
		}

			past = cur;		
	}
	return -1; // -1을 반환하면 감소하는 수

}

int main() {
	int n;
	int flag;
	cin >> n;
	if (n == 0) {
		cout << 0 << endl;
		return 0;
	}
		
	while (1) {
		if (x > 9876543210) {
			cout << -1 << endl;
			return 0;
		}
//		cout <<x<<" : "<< decresingNum(x) << endl;
		
		flag = decresingNum(x); //flag가 -1이면 감소하는 수가 맞음

		if (flag==-1) { //x는 감소하는 수
			cnt++;
		//	cout << x << "는" << cnt << " 번 째 감소하는 수" << " : " << decresingNum(x)<< endl;

		}
	//	else
		//	cout << x << "는" << cnt << " 번 째 감소하는 수가 아님!!!" << " : " << decresingNum(x)<< endl;

		

		if (n == cnt)
			break;

		//예외처리하는 방법을 찾아야지!
		if (flag ==-1) { //감소하는 수면 체크
			x++;//단순히 더하는 것이 아닐 수도
			//cout << "!!!";
		}
		else {
		//	int len = log10(x) + 1;
			x+=pow(10, flag);
			int nam = x % (int) pow(10, flag);
			x =x-nam;
		}

	}
	cout<<x<<endl;

	return 0;
}