#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

struct charpair{
    char charasc;
    int cnt;
};

bool compare(const charpair &a, const charpair &b){
    if(a.cnt!=b.cnt)
        return a.cnt<b.cnt;
    else
        return a.charasc>b.charasc;
}

void print(const vector<charpair> &data){
    int i;
    for(i=0; i<95; i++){
        if(data[i].cnt!=0)
            printf("%d %d\n", data[i].charasc, data[i].cnt);
    }
}

int main(){

    vector<charpair> data(95);
    char c[9999];
    int i, len, flag=0;
    while(fgets(c, sizeof(c), stdin) != 0){
        c[strcspn(c, "\n")] = '\0';
        for(i=0; i<95; i++){
            data[i].charasc = i+32;
            data[i].cnt = 0;
        }

        if(flag)
            printf("\n");
        flag = 1;

        for(i=0; i<strlen(c); i++){
            if(c[i]>=32 && c[i]<=126)
                data[c[i]-32].cnt++;
        }
        sort(data.begin(), data.end(), compare);
        print(data);
    }
    return 0;
}
