#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int M = 36;

int main(){

    int i, n, m, o, w[M], cnt[M+1], tmp, minn, c=0, tof=0;
    scanf("%d", &n);
    while(n--){
        if(tof)
            printf("\n");
        tof=1;
        printf("Case %d:\n", ++c);

        memset(w, 0, sizeof(w));


        for(i=0; i<36; i++)
            scanf("%d", &w[i]);

        scanf("%d", &m);
        while(m--){
            memset(cnt, 0, sizeof(cnt));
            scanf("%d",&o);
            for(i=2; i<M+1; i++){
                tmp = o;
                do{
                    cnt[i] += w[tmp%i];
                    tmp/=i;
                }while(tmp);
            }

            minn = *min_element(cnt+2, cnt+M+1);

            printf("Cheapest base(s) for number %d:", o);

            for(i=2; i<M+1; i++){
                if(cnt[i]==minn)
                    printf(" %d", i);
            }
            printf("\n");
        }
    }
    return 0;
}
