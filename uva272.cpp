#include<iostream>

int main(){

    char str;
    int cnt=0;

    while(scanf("%c", &str) != EOF){
        if(str!='"')
            printf("%c", str);
        else if(++cnt%2)
            printf("``");
        else
            printf("''");
    }
    return 0;
}
