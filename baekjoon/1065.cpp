#include <iostream>

using namespace std;
 
int X;
 
int arithmeticSequence(void) {
        int cnt = 0;
        int digit[4]; //1000보다 같거나 작으므로
        for (int num = 1; num <= X; num++) {
                 bool han=true; //한수
                 int idx = 0;
                 int copy = num; //num에 대해 계산하기 위해 복사
                 while (copy) {
                         digit[idx++] = copy % 10;
                         copy /= 10;
                 }
                 //세자리 수여야 한수 판별 가능
                 if (idx > 1) {
                         //십의 자리수와 일의 자리 수 차를 저장
                         int difference = digit[1] - digit[0];
                         //한수 판별
                         for(int i=2; i<idx; i++)
                                 if (digit[i] - digit[i - 1] != difference) {
                                          han = false;
                                          break;
                                 }
                 }
                 if (han) //한수일 경우 센다
                         cnt++;
        }
        return cnt;
}
 
int main(void) {
        cin >> X; 
        cout << arithmeticSequence() << endl;
        return 0;
}