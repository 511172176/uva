#include<iostream>

int main(){

    double x[4], y[4], xa, ya;
    while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &x[0], &y[0], &x[1], &y[1], &x[2], &y[2], &x[3], &y[3]) == 8){

        if(x[0]==x[2]&&y[0]==y[2]){
            xa = x[3]+x[1]-x[0];
            ya = y[3]+y[1]-y[0];
        }

        else if(x[0]==x[3]&&y[0]==y[3]){
            xa = x[1]+x[2]-x[0];
            ya = y[1]+y[2]-y[0];
        }

        else if(x[1]==x[3]&&y[1]==y[3]){
            xa = x[2]+x[0]-x[1];
            ya = y[2]+y[0]-y[1];
        }

        else if(x[1]==x[2]&&y[1]==y[2]){
            xa = x[3]+x[0]-x[1];
            ya = y[3]+y[0]-y[1];
        }


        printf("%.3lf %.3lf\n", xa, ya);
    }
    return 0;
}
