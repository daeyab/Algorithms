#include <string>
#include <vector>
#include <cmath>

using namespace std;

char num[3]={'1','2','4'};

string solution(int n) {
    if(!n--)return "";
    return solution(n/3) + num[n%3];
}

