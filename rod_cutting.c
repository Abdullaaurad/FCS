#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int rod_recursive(int value[], int n) {
    if (n <= 0) {
        return 0;
    }
    int Max = INT_MIN;
    for (int i = 0; i < n; i++) {
        Max = max(Max, value[i] + rod_recursive(value, n - i-1));
    }
    return Max;
}

int rod_dynamic(int value[], int n) {
    int profit[n + 1];
    profit[0] = 0;
    if (n <= 0) {
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        int maxVal = INT_MIN;
        for (int j = 0; j < i; j++) {
            maxVal = max(maxVal, value[j] + profit[i - j -1]);
        }
        profit[i] = maxVal;
    }
    return (profit[n]);
}

int main() {
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(price) / sizeof(price[0]);

    printf("Maximum obtainable value (Dynamic Programming): %d\n", rod_dynamic(price, 8));
    printf("Maximum obtainable value (Recursive): %d\n", rod_recursive(price, 8));
    return 0;
}
