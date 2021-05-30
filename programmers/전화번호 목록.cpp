#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    for(int i = 0; i < phone_book.size()-1;i++){
        string cur = phone_book[i];
        string compare = phone_book[i+1];
        if(cur.length() > compare.length()) cur = cur.substr(0, compare.length());
        else compare = compare.substr(0, cur.length());
        if(cur == compare) return false;
    }
    return true;
}
