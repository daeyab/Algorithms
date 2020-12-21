#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

struct dic {
	int len;
	string word;
};

dic dictionary[20001];
int n;
dic tmp[20001];

bool cmp(dic a, dic b) {
	if (a.len != b.len)
		return a.len < b.len;
	else {
		for (int i = 0; i < a.len; i++) {
			if (a.word.at(i) != b.word.at(i))
				return a.word.at(i) < b.word.at(i);
		}
		return false;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		dictionary[i].len = str.length();
		dictionary[i].word = str;
	}
	
	sort(dictionary,dictionary+n,cmp);
	for (int i = 0; i < n; i++) {
		if(dictionary[i].word.compare(dictionary[i + 1].word))
			cout << dictionary[i].word<<endl;
	}
	
}