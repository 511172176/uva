#include<iostream>
#include<cstring>

int main(){

    char c;
    char s[] = "1234567890-=qwertyuiop[]asdfghjkl;'zxcvbnm,./";
    while(scanf("%c", &c) != EOF){
        c = tolower(c);
        char *p = strchr(s, c);
        if(p)
            printf("%c", *(p-2));
        else
            printf("%c", c);
    }

    return 0;
}
