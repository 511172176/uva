#include<iostream>
int main()
{

    int n, len=0, cr[256]={};
    char c;
    scanf(" %d", &n);
    getchar();
    while(n--){
        while(scanf("%c", &c) == 1 && c!= '\n'){
            cr[toupper(c)]++;
            len++;
        }
    }
    while(--len){
        for(c='A'; c<='Z'; c++){
            if(cr[c] == len)
                printf("%c %d\n", c, cr[c]);
        }
    }
    return 0;
}
