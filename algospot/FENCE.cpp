#include<stdio.h>
#include <algorithm>

using namespace std;

int fence[200005];

int solve(int left, int right) {

    // 1개일 경우  기저사례 1 
    if (left == right)
        return fence[left];

    //2개일 경우 기저사례 2 
    if (right == left + 1) {
        int minH = min(fence[left], fence[right]);
        int maxH = max(fence[left], fence[right]); 
        return max(minH * 2, maxH);
    }

    int mid = (left + right) / 2;

    //가운데 기준 왼쪽 부분
    int lMax = solve(left, mid);

    //가운데 기준 오른쪽 부분
    int rMax = solve(mid + 1, right);

    //가운데 기준 포함 부분
    int mLeft = mid, mRight = mid + 1;
    int width = 2;
    int height = min(fence[mLeft], fence[mRight]);
    int result = height * width;;
    for (;height > 0;height--) {
        while (left < mLeft && fence[mLeft - 1] >= height) {
            mLeft--;
            width++;
        }
        while (mRight < right && fence[mRight + 1] >= height) {
            mRight++;
            width++;
        }
        if (width * height > result)
            result = width * height;
    }
    result = max(result, max(rMax, lMax));
    return result;

}

int main() {
    int n, i, len;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &len);
        for (i = 0;i < len;i++)
            scanf("%d", &fence[i]);
        printf("%d\n", solve(0, len - 1));
    }
    return 0;
}
