#include<iostream>

int main(){

    int s;
    long long  i, d, dd;
    while(scanf("%lld %lld", &s, &d) == 2){

        for(i=0;; i++){

            dd = (s+(s+i))*(i+1)/2;
            if(dd>=d){

                printf("%lld\n", s+i);
                break;
            }
        }
    }

    return 0;
}
