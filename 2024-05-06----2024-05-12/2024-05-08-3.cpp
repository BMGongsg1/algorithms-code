#include <stdio.h>
void show(int a,int n)
{
    int i;
    int msk = 1;
    for(i=0; i<n-1; i++) msk = msk << 1;
    for(i=0; i<n; i++){
        printf((a & msk)? "1" : "0");
        msk = msk >> 1;
    }
    printf("\n");
} 

void f(int n)
{
    int i;
    int num = 1;
    for(i=0; i<n; i++) num = num<<1;
    
    int a = 0;
    for(i=0; i<num; i++){
        show(a,n);
        
        if(i%2==0){
            a = a ^ 1;
        }
        else{
            a =  a^((a<<1)&(-a<<1)); //填空
        }
    }
}

int main()
{
    int a;
    scanf("%d",&a);
    f(a);
    return 0;
}