#include<iostream>
#include<stdio.h>

using namespace std; 

int LineNum, needLines;
long long myLines[10001] = { 0, };

/*
bool check(int len) {
	int totalLines = 0;
	for (int i = 0; i < LineNum; i++) {
		totalLines += myLines[i] / len;
		if (totalLines >= needLines)
			return true;
	}
//	printf("len: %d 실패 \n", len);
	return false;
}*/

/*
int CUTLINES(int start, int end) {
//	printf("%d ~ %d \n", start, end);
	//len 길이로 짤랐을 때 가능

		//자른게 니드 라인보다 부족하다면 len을 절반으로

		//자른게 많다면 len을 절반 가운데 
	if (start == end )
		return start;
	if (end - start == 1) {
		if (check(end))
			return end;
		return start;
	}

	int mid = (start + end) / 2;
	if(check(mid))
		CUTLINES(mid+1,end);
	else
		CUTLINES(start,mid-1);

}*/


int main() {
	int maxLine = 0;

	scanf("%d %d", &LineNum, &needLines);

	for (int i = 0; i < LineNum; i++) {
		scanf("%d", &myLines[i]);
		if (myLines[i] > maxLine)
			maxLine = myLines[i];
	}

	long long  start = 1, end = maxLine, ans = 0;

	while (start<=end) {
	//	printf("%d ~ %d \n", start, end);
		long long sum = 0;
		long long mid = (start + end) / 2;
		for (int i = 0; i < LineNum; i++) {
			sum += myLines[i] / mid;
		}

		if (sum >= needLines)
			start = mid + 1;
		else
			end = mid - 1;
	}
	
//	printf("%d", CUTLINES(1, maxLine));
	printf("%d", end);



	return 0;

}