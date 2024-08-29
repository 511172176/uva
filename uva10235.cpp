#include<iostream>
int p[1000000];
int main(){

    int i, j;
    for(i=2; i*i<1000000;i++){
        if(p[i])
            continue;
        for(j=i+i; j<1000000; j+=i)
            p[j] = 1;
    }

    int n, rn, tmp;
    while(scanf("%d", &n) == 1){
        tmp = n;
        for(rn=0; tmp; tmp/=10)
            rn = rn*10 + (tmp%10);
        if(p[n])
            printf("%d is not prime.\n", n);
        else if(p[rn])
            printf("%d is prime.\n", n);
        else if(n==rn)
            printf("%d is prime.\n");
        else
            printf("%d is emirp.\n", n);
    }
    return 0;
}
