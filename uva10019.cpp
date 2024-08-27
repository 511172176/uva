#include<iostream>

int main(){

    int n, m, i, b1, b2;
    scanf("%d", &n);

    while(n--){
        b1=b2=0;
        scanf("%d", &m);

        for(i=m; i; i/=2)
            b1 += i%2;
        for(; m; m/=10){
            for(i=m%10; i; i/=2)
                b2 += i%2;
        }
        printf("%d %d\n", b1, b2);
    }
    return 0;
}
