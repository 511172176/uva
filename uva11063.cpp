#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int main(){

    int n, tmp, tof, i, j, cnt[20005], cnti=0;
    vector<int> vc;
    while(scanf("%d", &n) !=EOF){
        vc.clear();
        tof = 1;
        for(i=0; i<n; i++){
            scanf("%d", &tmp);
            vc.push_back(tmp);
            if(tmp<1 || (i>0 && vc[i]<=vc[i-1]))
                tof = 0;
        }
        memset(cnt, 0, sizeof(cnt));
        if(tof){
            for(i=0; i<n; i++){
                for(j=i; j<n; j++){

                    if(cnt[vc[i]+vc[j]]!=0){
                        tof=0;
                        break;
                    }
                    cnt[vc[i]+vc[j]] = 1;
                }
            }
        }
        if(tof)
            printf("Case #%d: It is a B2-Sequence.\n\n", ++cnti);
        else
            printf("Case #%d: It is not a B2-Sequence.\n\n", ++cnti);
    }
    return 0;
}
