#include<stdio.h>
#include<stdlib.h>

int polynomial(int n){
    if(n==1){
        return 1;
    }
    return (n*polynomial(n-1));
}

int main(){
    int n;
    printf("Enter the number to find polynomial =");
    scanf("%d",&n);
    int value=polynomial(n);
    printf("The value is =%d",value);
    return 0;
}