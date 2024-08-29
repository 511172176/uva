#include<iostream>
#include<cstring>
using namespace std;

int strtoi(string s){
    int i, sum=0;
    for(i=0; i<s.length(); i++){
        sum*=2;
        if(s[i]=='1')
            sum+=1;
    }
    return sum;
}

int gcd(int n1, int n2){
    if(n2>n1) return gcd(n2, n1);
    if(n2==0) return(n1);
    return gcd(n2, n1%n2);
}
int main(){

    char s1[31], s2[31];
    int n, n1, n2, gcdn, cnt=0;
    scanf("%d", &n);
    while(n--){
        memset(s1, '\0', sizeof(s1));
        memset(s2, '\0', sizeof(s2));
        scanf("%s%s", &s1, &s2);
        n1 = strtoi(s1);
        n2 = strtoi(s2);

        gcdn = gcd(n1, n2);
        if(gcdn>1)
            printf("Pair #%d: All you need is love!\n", ++cnt);
        else
            printf("Pair #%d: Love is not all you need!\n", ++cnt);
    }
    return 0;
}
