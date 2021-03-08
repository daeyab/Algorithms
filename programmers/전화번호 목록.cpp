#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) { 
    sort(phone_book.begin(),phone_book.end());
    for(int i=0;i<phone_book.size();i++){
        for(int j=i+1;j<phone_book.size();j++){
            string cur = phone_book[i];
            string com = phone_book[j];
            if(cur.length()<com.length())
                com=com.substr(0,cur.length());
            else
                cur= cur.substr(0,com.length());
            if(com==cur)
                return false;
        }
    }
    return true;
}
