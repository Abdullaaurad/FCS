#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int n, int w[], int v[]) {
    int knapsack[n + 1][W + 1];
    for (int item = 0; item <= n; item++) {
        for (int capacity = 0; capacity <= W; capacity++) {
            if(item==0 || capacity==0){
                knapsack[item][capacity]=0;
            }
            else if (w[item] > capacity) {
                knapsack[item][capacity] = knapsack[item - 1][capacity];
            }
            else {
                knapsack[item][capacity] = max(knapsack[item - 1][capacity], knapsack[item - 1][capacity - w[item]] + v[item]);
            }
        }
    }
    return knapsack[n][W];
}

int main() {
    int W = 10; 
    int n = 4;  

    int w[] = {0, 5, 4, 6, 3};
    int v[] = {0, 10, 40, 30, 50};

    printf("Maximum value that can be obtained: %d\n", knapsack(W, n, w, v));
    
    return 0;
}
