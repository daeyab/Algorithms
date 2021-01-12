#include <string>

using namespace std;

int solution(string s) {
    int answer = s.size();
    //1글자에서 n/2 글자 길이로 탐색
    for(int i=1; i<=s.size()/2;i++){
        string convert, temp;
        int cnt=1;
        //시작점과 자를 길이
        temp=s.substr(0,i);
        //i번째 부터 즉 2번째 파트부터 뭉태기씩 보는것
        for(int j=i; j<s.size();j+=i){
            if(temp==s.substr(j,i))
                cnt++;
            else{
                if(cnt>1)
                    convert+=to_string(cnt);
                convert+=temp;
                temp=s.substr(j,i);
                cnt=1;
            }
        }
        if(cnt>1)
            convert+=to_string(cnt);
        convert+=temp;
        if(answer>convert.size())
            answer=convert.size();
    }
    return answer;
}
