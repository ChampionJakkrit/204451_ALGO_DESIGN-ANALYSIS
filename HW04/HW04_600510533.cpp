#include <bits/stdc++.h>
using namespace std;
int T[5000];
int input[5000];

int calculate(int i) {
    int answer; 
    if (i == -1) // ยังไม่ถูกจำ
        return 0;
    if (T[i] != -1) // ถูกจำ
        return T[i];

    // find answer
    answer = input[i]; // ถ้าไม่มีใครต่อได้ก็ตอบค่ามันเอง
    for (int k = 0; k <= i-1; k++) {
        int partial_answer = 0;
        if (input[k] < input[i]) { // มีใครมาต่อตัวที่ i ได้ไหม
            partial_answer = calculate(k);
            if (partial_answer + input[i] > answer) {
                answer = partial_answer + input[i];
            }
        }
    }

    T[i] = answer; // จำคำตอบไว้ที่ตน.นั้นๆ
    return answer;
}

int main() {
    // freopen("input.txt", "r", stdin);
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &input[i]);
        T[i] = -1; // ให้ทุกตัวยังไม่ถูกจำ
    }
    int mx = 0;
    for (int i = 0; i < N; i++) {
        int patial = calculate(i);
        if (patial > mx)
            mx = patial;
    }
    printf("%d", mx);
    return 0;
}