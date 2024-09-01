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
    if(a.cnt != b.cnt)
        return a.cnt < b.cnt;
    else
        return a.charasc > b.charasc;
}

void print(const vector<charpair> &data){
    int i;
    for(i = 0; i < 95; i++){
        if(data[i].cnt != 0)
            printf("%d %d\n", data[i].charasc, data[i].cnt);
    }
}

int main(){

    vector<charpair> data(95);
    char gc;
    string c;
    int i, flag = 0;

    while(scanf("%c", &gc) == 1){

        if(gc == '\n'){

            if(flag)
                printf("\n");
            flag = 1;

            for(i = 0; i < 95; i++){
                data[i].charasc = i + 32;
                data[i].cnt = 0;
            }

            for(i = 0; i < c.length(); i++){
                    data[c[i] - 32].cnt++;
            }

            sort(data.begin(), data.end(), compare);
            print(data);

            c.clear();
        } else {
            c.push_back(gc);
        }
    }

    return 0;
}
