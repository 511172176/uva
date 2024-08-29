#include<iostream>

int main(){

    int n, m, tmp;
    while(scanf("%d%d", &n, &m) == 2){
        if((n<2) || (m<2)){
            printf("Boring!\n");
            continue;
        }
        tmp = n;

        while(tmp%m==0 && tmp>1){
            tmp/=m;
        }

        if(tmp!=1)
            printf("Boring!\n");
        else{
            printf("%d", n);
            while(n%m==0 && n>1)
                printf(" %d", n/=m);
            printf("\n");
        }
    }
    return 0;
}
