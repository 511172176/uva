#include<iostream>

int main(){

    int n, m, tof, i, f[40]={0, 1};
    for(i=2; i<40; i++)
        f[i] = f[i-1]+f[i-2];

    scanf("%d", &n);

    while(n--){

        scanf("%d", &m);
        printf("%d = ", m);
        tof = 0;

        for(i=39; i>=2; i--){
            if(m>=f[i]){
                printf("1");
                m -= f[i];
                tof=1;
            }
            else if(tof){
                printf("0");
            }
        }
        printf(" (fib)\n");
    }
    return 0;
}
