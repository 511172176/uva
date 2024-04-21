#include<iostream>

using namespace std;

#define maxn 150000+5

struct state
{
	int sum, id, key;
}s[maxn], c[maxn];

int n, p, ans, cnt;
char a[maxn], b[maxn];

int find(int key)
{
	int l=0, r=cnt-1;
	while(l<r)
	{
		int m = (l+r)/2;
		if(c[m].key<=key)
			r = m;
		else
			l = m+1;
	}
	return c[l].id;
}

int solve()
{
	c[0].id=c[0].sum=c[0].key=0;
	s[0]=c[0];
	ans = 0, cnt=1;
	for(int i=1; i<=n; i++)
	{
		s[i].sum = s[i-1].sum+(a[i-1]!=b[i-1]);
		s[i].id = i;
		s[i].key = i*p-100*s[i].sum;
		if(s[i].key<c[cnt-1].key)
			c[cnt++]=s[i];
		else
		{
			int t = find(s[i].key);
			ans = max(ans, s[i].id-t);
		}
	}
	if(ans) return true;
	return false;
}

int main()
{
	while(scanf("%d%d", &n, &p)==2 && n+p)
	{
		scanf("%s%s", a, b);
		if(solve())
			printf("%d\n", ans);
		else
			printf("No solution.\n");
	}
	return 0;
}
