#include<iostream>
#include<cmath>
#include<cstring>
#define pi 2*acos(0.0)

int main(){

    double arc, chord, s, a;
    char c[4];
    while(scanf("%lf%lf%s", &s, &a, &c) == 3){
        if(strcmp(c, "min") == 0)
            a/=60;

        if(a>180)
            a = fabs(360-a);

        arc = 2*pi*(6440+s)*a/360.0;
        chord = (6440+s)*sin(a*pi/2/180)*2;

        printf("%.6lf %.6lf\n", arc, chord);
    }
    return 0;
}
