#include<iostream>
#include<cstring>

using namespace std;

int main(){

    char n[1001];
    int i, sum, tmp, dg;
    while(scanf("%s", &n) && (n[0]!='0')){
        printf("%s is ", n);
        tmp=0, dg = 1;

        for(i=0; i<strlen(n); i++)
            tmp += n[i]-'0';

        while(tmp%9==0 && tmp!=9){
            sum=0;
            for(; tmp; tmp/=10)
                sum += tmp%10;
            tmp = sum;
            dg++;
        }

        if(tmp%9)
            printf("not a multiple of 9.\n");
        else
            printf("a multiple of 9 and has 9-degree %d.\n", dg);
    }
    return 0;
}
