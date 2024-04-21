#include<iostream>
#include<cstring>

using namespace std;

#define maxn 100000*2+5

int s, len, seq[maxn], cnt[maxn];
bool front[maxn], back[maxn];

int solve()
{
	memset(cnt, 0, sizeof cnt);
	memset(front, 0, sizeof front);
	memset(back, 0, sizeof back);
	int diffnum=0, ans=0;
	for(int i=0; i<len+s; i++)
	{
		if(i-s+1>=0 && diffnum==s)
			back[i-s]=true;
		if(i-s>=0)
		{
			cnt[seq[i-s]]--;
			if(cnt[seq[i-s]]==0) diffnum--;
		}
		if(i>=len) diffnum++;
		else
		{
			if(cnt[seq[i]]==0) diffnum++;
			cnt[seq[i]]++;
		}
		if(i<s && diffnum==i+1)
			front[i]=true;
	}
	
	for(int i=0; i<s; i++)
	{
		int ok=1;
		if(i!=0 && !front[i-1]) continue;
		for(int j=i; j<len && ok; j+=s)
		{
			if(!back[j]) ok = 0;
		}
		ans += ok;
	}
	return ans;
}

int main()
{
	int cas;
	scanf("%d", &cas);
	while(cas--)
	{
		scanf("%d%d", &s, &len);
		for(int i=0; i<len; i++)
		{
			scanf("%d", &seq[i]);
		}
		printf("%d\n", solve());
	}
	return 0;
}
