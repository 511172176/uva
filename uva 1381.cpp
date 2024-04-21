#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

#define maxm 12000
#define maxn (1<<16)

int x[16], num[16], cnt[maxn];
vector<int> state[maxm];

bool judge(int s)
{
	int count=0;
	for(int i=0; i<16; i++)
	{
		if(s & 1<<i) x[count++] = num[i];
	}
	return count==4;
}
void init()
{
	sort(num, num+16);
	memset(cnt, 0, sizeof cnt);
	for(int i=0; i<maxm; i++) state[i].clear();
}

long long solve()
{
	
	long long ans = 0;
	for(int i=0; i<maxn; i++)
	{
		if(judge(i))
		{
			do{
				int t = x[0]*4+x[1]*3+x[2]*2+x[3];
				for(int j=0; j<state[t].size(); j++)
				{
					if((state[t][j]&i)==0)
						cnt[state[t][j]|i]++;
				}
				state[t].push_back(i);
			}while(next_permutation(x, x+4));
		}
	}
	for(int i=0; i<maxn; i++) ans+=cnt[i]*cnt[i^(maxn-1)];
	return ans/2;
}

int main()
{
	int cas=1;
	while(scanf("%d", &num[0])==1&&num[0])
	{
		for(int i=1; i<16; i++)
			scanf("%d", &num[i]);
		init();
		printf("Case %d: %lld\n", cas++, solve());
	}
	return 0;
}

