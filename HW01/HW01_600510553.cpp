#include <bits/stdc++.h>
using namespace std;

int check(int input[], int N) {
    int low = 0;
    int high = N-1;
    int mid = (int)ceil(double(high + low) / 2);
    int mx;
    while (low < high) {
        mid = (int)ceil(double(high + low) / 2);
        if (input[mid] < input[low]) {
            high = mid-1;
        }
        else {
            low = mid;
        }
    }
    mx = input[low];

    return mx;
}

int main() {
    int N;
    scanf("%d", &N);
    int input[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &input[i]);
    }
    printf("%d\n", check(input, N));
}