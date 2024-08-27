#include<iostream>

int main(){

    int a, b, i, l[100001]={};
    for(i=1; i*i<100001; i++)
        l[i*i] = 1;
    for(i=1; i<100001; i++)
        l[i] += l[i-1];

    while(scanf("%d %d", &a, &b) == 2){
        if(!a && !b)
            break;
        printf("%d\n", l[b]-l[a-1]);
    }
    return 0;
}
