#include<iostream>
#include<cstring>

int main(){

    char c[100][101];
    int len[100], i, j, M=0, n=0;
    memset(c, 0, sizeof(c));
    memset(len, 0, sizeof(len));


    while(scanf("%[^\n]", &c[n]) != EOF){
        getchar();
        len[n] = strlen(c[n]);
        if(len[n]>M)
            M = len[n];
        for(i=len[n]; i<M; i++){
            c[n][i] = ' ';
            len[n]++;
        }
        n++;
    }
    for(j=0; j<M; j++){
        for(i=n-1; i>=0; i--)
            if(j<len[i])
                printf("%c", c[i][j]);
        printf("\n");
    }

    return 0;
}
