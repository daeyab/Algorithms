#include<iostream>
#include<memory.h>
#include<algorithm>

using namespace std;

int main() {
	int tc; cin >> tc;
	while (tc--) {
		int russian[101];
		int korean[101];
		int times; cin >> times;
		for (int i = 0; i < times; i++) {
			cin >> russian[i];
		}
		sort(russian, russian + times);
		for (int i = 0; i < times; i++) {
			cin >> korean[i];
		}
		sort(korean , korean + times);
		/*
		코드의 핵심 - 둘다 정렬한 상태에서
		러시아 학생 기준
		같거나 조금이라도 더 큰 한국인을 택함
		*/

		int result=0;
		int j = 0;
		for (int rus = 0; rus < times; rus++) {
			int rusPlayer = russian[rus];
			for (int kor = j; kor < times; kor++) {
				if (korean[kor] >= russian[rus]) {
					result++;
					korean[kor] = -1;
					j = kor;
					break;
				}
			}
		}
		cout << result<<endl;
	}
	return 0;
}