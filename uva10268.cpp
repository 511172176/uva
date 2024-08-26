#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(){

    long long x, n, t, s, i, sum, exp;

    while(scanf("%lld", &x) != EOF){

        vector<int> vc;
        vc.clear();
        while(scanf("%lld", &n) == 1){

            vc.push_back(n);
            if(getchar() == '\n')
                break;
        }
        s = vc.size()-1;
        sum = 0;
        exp=1;
        for(i=s-1; i>=0; i--){

            sum += vc[i]*(s-i)*exp;
            exp *= x;
        }
        printf("%lld\n", sum);
    }
    return 0;
}
