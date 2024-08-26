#include<iostream>
#include<cmath>

int main(){

    int s, n, i;
    float p;
    scanf("%d", &s);
    while(s--){

        scanf("%d %f %d", &n, &p, &i);
        if(p<0.00001)
            printf("0.0000\n");
        else
            printf("%.4f\n", (pow(1-p, i-1)*p/(1-pow(1-p, n))));
    }
    return 0;
}
