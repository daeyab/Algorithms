#include<iostream>
#include<string>
#include<math.h>
#include<memory.h>

using namespace std;

int main() {
	string str;
	int num = 0,res=0;
	int temp[5] = { 0, };
	int tempAt=0;
	bool numChangeTime = true;
	bool itsMinus = true;
	int resNum;
	cin >> str;
	str += " ";
	if (!str.length())
		return -1;
	else {
		for (int at = 0; at < str.length(); at++) {
		//	cout << str.at(at) << "차례 -" << endl;
			if (str[at] >= '0' && str[at] <= '9') {
		//		cout << "숫자!" << endl;
				temp[tempAt++] = str.at(at) - 48;
		//		cout << "해당 숫자:" << str.at(at) - 48 << endl;
			}
			else {
				//문자일 때
				if (numChangeTime) {
		//			cout << "숫자 정산 타임";
					//일단 숫자 정산하세요
					resNum = 0;
					for (int i = 0; i < tempAt; i++) {
						resNum += temp[i] * (int)pow(10, tempAt - i-1);
					}
		//			cout << "정산된 숫자는 " << resNum << "입니다. tempAt->" << tempAt<<endl;
					numChangeTime = false;
				
				}

				if (itsMinus) {
					res += resNum;
					if (str.at(at) == '-') {
						itsMinus = false;
			//			cout << "앞으로 뺌" << endl;
					}
				}
				else {
					res -= resNum;
		//			cout << "뺌" << endl;
				}
		//		cout << "계산중인 res 값 : " << res << endl;
			
				tempAt = 0;
				memset(temp, 0, sizeof(temp));
				resNum = 0;
				numChangeTime = true;
			}
		}
		cout << res << endl;
		return 0;
	}
}