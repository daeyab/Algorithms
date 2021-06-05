#include <math.h>
#include <stdio.h>

#include <algorithm>
#include <vector>

using namespace std;

struct posi {
    int y, x;
};

int n, m, tp, res = 0x7fffffff;
vector<posi> store, home, picked;
posi p;

void pick_store(int idx) {
    if (picked.size() == m) {
        // 다 채워진 경우
        // for (auto a : ls) printf("-> %d %d \n", a.x, a.y);
        // printf("\n");
        int sum = 0;
        for (auto h : home) {
            int minVal = 100000;
            for (auto s : picked) {
                minVal = min(minVal, abs(h.x - s.x) + abs(h.y - s.y));
            }
            sum += minVal;
        }
        res = min(sum, res);
        return;
    }

    for (int i = idx; i < store.size(); i++) {
        picked.push_back(store[i]);
        pick_store(i + 1);
        picked.pop_back();
    }
}
int main() {
    scanf("%d %d", &n, &m);
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            scanf("%d", &tp);
            if (tp == 1) {
                p.x = x, p.y = y;
                home.push_back(p);
            } else if (tp == 2) {
                p.x = x, p.y = y;
                store.push_back(p);
            }
        }
    }
    pick_store(0);
    printf("%d\n", res);
}