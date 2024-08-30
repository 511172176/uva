#include<iostream>
using namespace std;

int gcd(int a, int b){

    while(a%=b)swap(a, b);
    return b;
}
int main(){

    int i, j, n, gl[501]={};
    for(i=1; i<501; i++){
        gl[i] = gl[i-1];

        for(j=1; j<i; j++)
            gl[i] += gcd(i, j);
    }

    while(scanf("%d", &n) && (n!= 0)){
        printf("%d\n", gl[n]);
    }
    return 0;
}
