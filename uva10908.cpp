#include<iostream>
#include<cstring>
char cr[101][101];

int main(){

    int t, m, n, q, i, ans, r, c, flag, a, b;
    scanf("%d", &t);
    while(t--){
        memset(cr, '\0', sizeof(cr));
        scanf("%d%d%d", &m, &n, &q);
        printf("%d %d %d\n", m, n, q);
        for(i=0; i<m; i++)
            scanf("%s", cr[i]);

        while(q--){
            scanf("%d%d", &r, &c);
            ans = 1;
            for(i=1; i<m || i<n; i++){
                flag = 0;
                for(a=r-i; a<=r+i; a++){
                    for(b=c-i; b<=c+i; b++){
                        if(a<0 || b<0 || a>m || b>n){
                            flag=1;
                            break;
                        }
                        if(cr[a][b] != cr[r][c]){
                            flag=1;
                            break;
                        }
                    }
                }
                if(!flag)
                    ans+=2;
                else
                   break;
            }
            printf("%d\n", ans);
        }


    }
    return 0;
}
