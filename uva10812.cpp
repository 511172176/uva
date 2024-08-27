#include<iostream>

int main(){

    int n, s, d, a, b;
    scanf("%d", &n);
    while(n--){

        scanf("%d%d", &s, &d);
        a = s+d;
        if(a%2!=0){

            printf("impossible\n");
            continue;
        }
        a = (s+d)/2;
        b = s-a;
        if(b<0){

            printf("impossible\n");
            continue;
        }
        printf("%d %d\n", a, b);
    }
    return 0;
}
