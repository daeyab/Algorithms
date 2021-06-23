#include <string>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define NUM 8

using namespace std;
vector<char> v;
string friends;;
bool chosen[NUM];
int answer=0;
int getIndex(char ch){
   for (int i=0;i<v.size();i++){
       if(v[i]==ch)
           return i;
   }
    return -1;
}
void printVector(){
    for (auto a : v)
        printf("%c",a);
    printf("\n");
}
void search(int n, vector<string> data){
    if(v.size()==NUM){
        // printVector(); 
        bool isCorrect = true;
        for(const auto& s : data) {
            int a = getIndex(s[0]);
            int b = getIndex(s[2]);
            int dist = s[4]-'0'+1;
            //  printf("%s a:%d b:%d K:%d c:%c abs:%d dist:%d\n", s.c_str(),a ,b,s[4]-'0', s[3], abs(a-b), dist);
            if(s[3]=='=' && abs(a-b)!=dist){
                // return;
                    // printf("1\n");
                isCorrect =false;
                break;
                }
            
            else if(s[3]=='<' && abs(a-b)>=dist){
                // return;
                    // printf("2\n");
                isCorrect =false;
                break;
                }
            
            else if(s[3]=='>' &&abs(a-b)<=dist){
                // return;
                    // printf("3\n");
                isCorrect =false;
                break;
            }
        }
        if(isCorrect){
        //   printf("CORRECT\n");        
           answer++;
        }
    }
    else{
        for(int i=0; i<friends.size(); i++) {
            if(chosen[i])
                continue;
            chosen[i] = true;
            v.push_back(friends[i]);
            search(n, data);
            chosen[i] = false;
            v.pop_back();
        }
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    friends = "ACFJMNRT";
    answer = 0 ;
    search(n, data);
    return answer;
}
