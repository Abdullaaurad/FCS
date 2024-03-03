#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int lcs(int X[], int Y[], int m, int n) {
    int L[m + 1][n + 1];
 
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                L[i][j] = 0;
            } else if (X[i - 1] == Y[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
            } else {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }
    return L[m][n];
}

int lcs_recursive(int x[],int y[],int m,int n){
    if((n==0)||(m==0)){
        return 0;
    }
    else if(x[m-1]==y[n-1]){
        return (1+lcs_recursive(x,y,m-1,n-1));
    }
    else{
        return max(lcs_recursive(x,y,m,n-1),lcs_recursive(x,y,m-1,n));
    }
}

int main() {
    int X[] = {1, 2, 3, 4, 1};
    int Y[] = {3, 4, 1, 2, 1, 3};
    int m = sizeof(X) / sizeof(X[0]);
    int n = sizeof(Y) / sizeof(Y[0]);

    printf("Length of LCS is %d\n", lcs(X, Y, m, n));
    printf("Length of LCS is %d\n", lcs_recursive(X, Y, m, n));

    return 0;
}
