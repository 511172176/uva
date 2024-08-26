#include<iostream>
#include<set>
using namespace std;

int main(){

    int n, i, a, b, d;

    while(scanf("%d", &n) != EOF){

        set<int> jj;
        scanf("%d", &a);
        for(i=1; i<n; i++){

            scanf("%d", &b);
            d = abs(a-b);
            if(d && d<n)
                jj.insert(d);
            a = b;
        }
        if(jj.size() == n-1)
            printf("Jolly\n");
        else
            printf("Not jolly\n");
    }
    return 0;
}
