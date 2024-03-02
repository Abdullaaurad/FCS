#include<stdlib.h>
#include<stdio.h>

int larger(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}

int Max(int Arr[],int start,int last){
    if(start==last) {
        return Arr[start];
    }else{
        
        int maxLeft=Max(Arr,start,mid);

        return (maxLeft>maxRight) ? maxLeft : maxRight;
    }
}

int main(){
    int Array[7]={4,9,21,5,99,10,1};
    int max=Max(Array,0,6);
    printf("%d",max);
    return 0;
}