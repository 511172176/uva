#include<iostream>

using namespace std;

#define maxn 500+5
#define INF 0x3f3f3f3f

int maxtree[maxn][maxn], mintree[maxn][maxn], vmax, vmin;
int v, x, x1, x2, xleaf, y, y1, y2, xo, n;

void query_y(int o, int l, int r)
{
	if(y1<=l&&r<=y2)
	{
		vmax=max(vmax, maxtree[xo][o]);
		vmin=min(vmin, mintree[xo][o]);
	}
	else
	{
		int m=(l+r)/2;
		if(y1<=m)
			query_y(o*2, l, m);
		if(m<y2)
			query_y(o*2+1, m+1, r);
	}
}

void query_x(int o, int l, int r)
{
	if(x1<=l && r<=x2)
	{
		xo=o;
		query_y(1, 1, n);
	}
	else
	{
		int m=(l+r)/2;
		if(x1<=m)
			query_x(o*2, l, m);
		if(m<x2)
			query_x(o*2+1, m+1, r);
	}
}

void modify_y(int o, int l, int r)
{
	if(l==r)
	{
		if(xleaf)
		{
			maxtree[xo][o]=mintree[xo][o]=v;
			return;
		}
		maxtree[xo][o]=max(maxtree[xo*2][o], maxtree[xo*2+1][o]);
		mintree[xo][o]=min(mintree[xo*2][o], mintree[xo*2+1][o]);
	}
	else
	{
		int m=(l+r)/2;
		if(y<=m)
			modify_y(o*2, l, m);
		else
			modify_y(o*2+1, m+1, r);
		maxtree[xo][o]=max(maxtree[xo][o*2], maxtree[xo][o*2+1]);
		mintree[xo][o]=min(mintree[xo][o*2], mintree[xo][o*2+1]);
	}
}

void modify_x(int o, int l, int r)
{
	if(l==r)
	{
		xleaf=1;
		xo=o;
		modify_y(1, 1, n);
	}
	else
	{
		int m=(l+r)/2;
		if(x<=m)
			modify_x(o*2, l, m);
		else
			modify_x(o*2+1, m+1, r);
		xo = o;
		xleaf=0;
		modify_y(1, 1, n); 
	}
}

int main()
{
	while(scanf("%d", &n)==1&&n)
	{
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				scanf("%d", &v);
				x = i;
				y = j;
				modify_x(1, 1, n);
			}
		}
		int q;
		char op[10];
		scanf("%d", &q);
		while(q--)
		{
			scanf("%s", op);
			if(op[0]=='q')
			{
				scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
				vmax=-INF, vmin=INF;
				query_x(1, 1, n);
				printf("%d %d\n", vmax, vmin);
			}
			else
			{
				scanf("%d%d%d", &x, &y, &v);
				modify_x(1, 1, n);
			}
		}
	}
	return 0;
}
