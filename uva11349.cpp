#include<iostream>
#include<cstring>

int main(){

    long long cas, n, ar[100][100], i, j, tof, cnt=0;

    scanf("%lld", &cas);

    while(cas--){

        memset(ar, 0, sizeof(ar));
        scanf(" N = %lld", &n);
        tof=1;
        for(i=0; i<n; i++){

            for(j=0; j<n; j++){

                scanf("%lld", &ar[i][j]);
                if(ar[i][j]<0)
                    tof=0;
            }
        }
        if(tof){
            for(i=0; i<n; i++){
                for(j=0; j<n; j++){
                    if(ar[i][j] != ar[n-1-i][n-1-j]){

                        tof=0;
                        break;
                    }
                }
            }
        }

        if(tof)
            printf("Test #%lld: Symmetric.\n", ++cnt);
        else
            printf("Test #%lld: Non-symmetric.\n", ++cnt);

    }
    return 0;
}
