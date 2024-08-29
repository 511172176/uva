#include<iostream>
#include<cstring>

int main(){

    int cnt, i, j, T, N, P, d[3651], h[101];
    scanf("%d", &T);

    while(T--){
        memset(d, 0, sizeof(d));
        memset(h, 0, sizeof(d));
        scanf("%d%d", &N, &P);

        for(i=0; i<P; i++){
            scanf("%d", &h[i]);

            for(j=h[i]; j<=N; j+=h[i]){
                d[j] = 1;
            }
        }
        cnt=0;

        for(i=1; i<=N; i++){

            if(i%7==0 || i%7==6)
                continue;
            if(d[i])
                cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
