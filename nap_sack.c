#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}

int nap_recursive(int value[],int limit){
    if(limit<=0){
        return 0;
    }
    int MaxValue = INT_MIN;
    for(int i=0;i<limit;i++){
        MaxValue = max(MaxValue, value[i] + nap_recursive(value, limit - i - 1));
    }
    return MaxValue;
}

int nap_dynamic(int value[], int n) {
    int price[n + 1];
    price[0] = 0;

    if (n <= 0) {
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        price[i] = INT_MIN;
        for (int j = 1; j <= i; j++) {
            price[i] = max(price[i], value[j - 1] + price[i - j]);
        }
    }

    return price[n];
}



int main() {
    int values[] = {60, 100, 120, 180, 200, 250, 320, 400};
    int n = sizeof(values) / sizeof(values[0]);

    printf("Maximum value (Dynamic): %d\n", nap_dynamic(values, n));
    printf("Maximum value (recursive): %d\n", nap_recursive(values, n));
    return 0;
}
