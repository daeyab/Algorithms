#include <string>
#include <vector>
#include <set>
#include <math.h>
using namespace std;

int solution(int N, int number) {
    int answer = 0;
    vector<set<int>> arr(8);
    for(int i=0 ;i<8;i++){
        int n = 0;
        int digit = i+1;
        while(digit >0){
            digit--;
            n+= N*pow(10,digit);
        }
        
        arr[i].insert(n);
    }  //[DP] 사칙연산으로 가능한 숫자 모두 확인
    for(int i = 1; i < 8; i++){
        for(int j = 0; j<i; j++){
            for(auto &x : arr[j]){
                for(auto &y : arr[i-j-1]){
                    arr[i].insert(x+y);
                    arr[i].insert(x*y);
                    arr[i].insert(x-y);
                    if(y!=0) arr[i].insert(x/y);
                }
            }
        }
        //number가 있는지 확인
        if(arr[i].find(number) != arr[i].end()){
            return i+1;
        }
    }
    //1부터 8까지 중에 return 없을시 -1 return
    return -1;
}
