#include <bits/stdc++.h>
using namespace std;

void check(int input[], int N) {
    int low = 1;
    int high = N;
    while (low <= high) {
        int mid = (int)ceil(double(high + low) / 2);
        if (input[mid] > mid) {
            high = mid-1;
        }
        else if (input[mid] < mid) {
            low = mid+1;
        }
        else if (input[mid] == mid) {
            printf("yes\n");
            return;
        }
    }
    printf("no\n");
}

int main() {
    int N;
    scanf("%d", &N);
    int input[N+5];
    for (int i = 1; i <= N; i++) {
        scanf("%d", &input[i]);
    }
    check(input, N);

    return 0;
}