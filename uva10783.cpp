#include<iostream>

int main(){

    int n, a, b, cnt=0;
    scanf("%d", &n);
    while(n--){

        scanf("%d%d", &a, &b);
        if(a%2==0)
            a++;
        if(b%2==0)
            b--;
        printf("Case %d: %d\n", ++cnt, (a+b)*((b-a)/2+1)/2);
    }
    return 0;
}
