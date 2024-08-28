#include<iostream>
#include<stack>
using namespace std;

int main(){

    int n, b, p, i;
    stack<int> st;
    while(scanf("%d", &n) == 1){

        while(!st.empty())
            st.pop();
        if(n==0)
            break;
        b=0;
        printf("The parity of ");
        for(; n; n/=2){

            st.push(n%2);
            b+=n%2;
        }
        while(!st.empty()){

            printf("%d", st.top());
            st.pop();
        }
        printf(" is %d (mod 2).\n", b);
    }
    return 0;
}
