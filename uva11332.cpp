#include<iostream>
#include<cstring>

int main(){

    char n[11];
    while(scanf("%s", n) != EOF && n[0] != '0' ){
        while(strlen(n) != 1){
            int i, F=0;
            for(i=0; i<strlen(n); i++)
                F += (n[i]-'0');
            //memset(n, '\0', sizeof(n));
            sprintf(n, "%d", F);
        }
        printf("%s\n", n);

    }
    return 0;
}
