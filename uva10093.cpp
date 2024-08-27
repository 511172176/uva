#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main(){

    int i, rsd;
    char tmp[1005];
    string r, num = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    while(scanf("%s", &tmp) != EOF){

        r = tmp;
        for(i=0; i<r.size(); i++){

            r[i] = num.find(r[i]);
            r[i] = max(0, (int)r[i]);
        }
        int n = *max_element(r.begin(), r.end())+1;
        n = max(2, n);
        for(; n<=62; n++){

            rsd = 0;
            for(i=0; i<r.size(); i++){

                rsd = rsd*n+r[i];
                rsd %= (n-1);
            }
            if(!rsd)
                break;
        }
        if(n<=62)
            printf("%d\n", n);
        else
            printf("such number is impossible!\n");
    }
    return 0;
}
