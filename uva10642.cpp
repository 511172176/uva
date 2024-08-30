#include<iostream>

int main(){

    int n, x1, y1, x2, y2, p1, p2, cnt=0;
    scanf("%d", &n);
    while(n--){
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        p1 = (x1+y1+1)*(x1+y1)/2+x1;
        p2 = (x2+y2+1)*(x2+y2)/2+x2;
        printf("Case %d: %d\n", ++cnt, p2-p1);
    }
    return 0;
}
