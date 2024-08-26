#include<iostream>

int main(){

    char week[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    int mon[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i, w, n, m, d;
    scanf("%d", &n);
    while(n--){
        w=5;
        scanf("%d %d", &m, &d);
        for(i=1; i<m; i++)
            w+=mon[i-1];
        w=(w+d)%7;

        printf("%s\n", week[w]);
    }
    return 0;
}
