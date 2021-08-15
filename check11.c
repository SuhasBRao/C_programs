#include<stdio.h>

int check11(int n1 ,int n2){
    int u1,u2;
    int g_sum = 0,l_sum;
    int carry = 0;
    int itr = 1;
    if (n1==10 && n2==1){
        l_sum = 15;
        return l_sum;
    }

    while (n1>0 || n2>0){
        
        if (n1 +n2 +carry== 11){
            n1 = 15;
            g_sum += (n1*itr); 
            break;
        }
        if(n1<=10 && n2<=10){
            g_sum+= (n1+n2+carry)*itr;
        }
        else{
            u1 = n1%10 +carry;
            u2 = n2%10;

            l_sum = u1 + u2;

            if (l_sum==11){ l_sum = 15; }
            
            g_sum += ((l_sum % 10)*itr);
        }
        //g_sum += ((l_sum % 10)*itr);
            
        carry = (int)(l_sum/10);
        n1 = (int)(n1/10 );
        n2 = (int)(n2/10);
        itr= itr*10;

    }
    return g_sum;
}


//Driver code
int main(){
    int n1,n2;
    int sum;
    printf("Enter numbers:\n");
    scanf("%d",&n1);
    scanf("%d",&n2);
    sum = check11(n1,n2);
    printf("%d",sum);
    return 0;
}
