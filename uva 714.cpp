#include<iostream>
#include<cstring>

using namespace std;

#define maxm 500+5

int m, k, p[maxm], last[maxm];

void print(long long ans)
{
	memset(last, 0, sizeof last);
	long long done=0;
	int remain = k;
	for(int i=m-1; i>=0; i--)
	{
		if(done+p[i]>ans || i+1<remain)
		{
			remain--;
			last[i]=1;
			done=p[i];
		}
		else
			done+=p[i];
	}
	for(int i=0; i<m-1; i++)
	{
		printf("%d ", p[i]);
		if(last[i])
			printf("/ ");
	}
	printf("%d\n", p[m-1]);
}

long long solve(long long maxp)
{
	long long done=0;
	int cnt=1;
	for(int i=0; i<m; i++)
	{
		if(done+p[i]<maxp)
			done+=p[i];
		else
		{
			done=p[i];
			cnt++;
		}
	}
	return cnt;
}

int main()
{
	int cas;
	scanf("%d", &cas);
	while(cas--)
	{
		long long tot = 0;
		int maxp = -1;
		scanf("%d%d", &m, &k);
		for(int i=0; i<m; i++)
		{
			scanf("%d", &p[i]);
			tot+=p[i];
			maxp = max(maxp, p[i]);
		}
		long long l=maxp, r=tot;
		while(l<r)
		{
			long long m = l + (r-l)/2;
			if(solve(m)<=k)
				r = m;
			else
				l = m+1;
		}
		print(l);
	}
	return 0;
}
