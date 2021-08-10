#include<stdio.h>

int hcf(int,int); // Function declaration

int main(){
    int x,y, result;
    scanf("%d %d",&x,&y);
    //printf("%d,%d",x,y);
    result = hcf(x,y);
    printf("HCF(%d,%d) = %d",x,y,result);
    return 0;
}
int hcf(int a,int b){
    int small = a>b?b:a;
    int big = a>b?a:b;
    int rem = big%small;
    if (rem == 0){
        return small;
    }else{
        return hcf(big,small);
    }
}