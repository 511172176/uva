#include<iostream>
#include<algorithm>
#define Maxn 1000000+5
int nr[Maxn];

using namespace std;

/*int cmp(const void *a, const void *b){
    return (*(int *)a) - (*(int *)b);
}*/

bool cmp(int a, int b){
    return a<b;
}
void findmind(int *nr, int n){
    int max, min, cnt, cntt, i;
    //qsort(nr, n, sizeof(int), cmp);
    sort(nr, nr+n);
    if(n%2!=0){
        min = nr[n/2];
        for(cnt=0, i=0; i<n; i++){
            if(nr[i]==min)
                cnt++;
        }
        cntt=1;
    }
    else{
        min = nr[n/2-1];
        max = nr[n/2];
        for(cnt=0, i=0; i<n; i++){
            if(nr[i]>=min && nr[i]<=max)
                cnt++;
        }
        cntt = max-min+1;
    }
    printf("%d %d %d\n", min, cnt, cntt);
}

int main(){

    int n, i;
    while(scanf("%d", &n) == 1){
        for(i=0; i<n; i++)
            scanf("%d", &nr[i]);

        findmind(nr, n);
    }
    return 0;
}
