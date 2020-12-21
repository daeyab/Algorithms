#include<iostream>
#include<vector>
#include<algorithm>

using namespace std; 


int main() {
	int tc; cin >> tc;

	while (tc--) {
		int heating[10001], eating[10001];
		int boxes; cin >> boxes;
		for (int i = 0; i < boxes; i++)
			cin >> heating[i];
		for (int i = 0; i < boxes; i++)
			cin >> eating[i];

		vector<pair<int, int>> order;
		for (int i = 0; i < boxes; i++) 
			order.push_back(make_pair(-eating[i], i));

		sort(order.begin(), order.end());
		int result = 0, beginEat = 0;
		for (int i = 0; i < boxes; i++) {
			int box = order[i].second;
			beginEat += heating[box];
			result = max(result, beginEat + eating[box]);
		}
		cout << result << endl;

	}
}