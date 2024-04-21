#include<iostream>

#define INF 0x3f3f3f3f
#define maxn 500*4+5

using namespace std;

int maxtree[maxn][maxn], mintree[maxn][maxn], N;
int xo, v, vmax, vmin, x, y, x1, x2, y1, y2, xleaf;

void query_y(int o, int l, int r)
{
	if(y1<=l && r<=y2)
	{
		vmax = max(vmax, maxtree[xo][o]);
		vmin = min(vmin, mintree[xo][o]);
	}
	else
	{
		int mid = (l+r)/2;
		if(y1<=mid)
			query_y(o*2, l, mid);
		if(mid<y2)
			query_y(o*2+1, mid+1, r);
	}
}

void query_x(int o, int l, int r)
{
	if(x1<=l && r<=x2)
	{
		xo = o;
		query_y(1, 1, N);
	}
	else
	{
		int mid = (l+r)/2;
		if(x1<=mid)
			query_x(o*2, l, mid);
		if(mid<x2)
			query_x(o*2+1, mid+1, r);
	}
}

void modify_y(int o, int l, int r)
{
	if(l==r)
	{
		if(xleaf)
		{
			maxtree[xo][o] = mintree[xo][o] = v;
			return;
		}
		maxtree[xo][o] = max(maxtree[xo*2][o], maxtree[xo*2+1][o]);
		mintree[xo][o] = min(mintree[xo*2][o], mintree[xo*2+1][o]);
	}
	else
	{
		int mid = (l+r)/2;
		if(y<=mid)
			modify_y(o*2, l, mid);
		else
			modify_y(o*2+1, mid+1, r);
			
		maxtree[xo][o] = max(maxtree[xo][o*2], maxtree[xo][o*2+1]);
		mintree[xo][o] = min(mintree[xo][o*2], mintree[xo][o*2+1]);
	}
}

void modify_x(int o, int l, int r)
{
	if(l==r)
	{
		xo = o;
		xleaf = 1;
		modify_y(1, 1, N);	
	}
	else
	{
		int mid = (l+r)/2;
		if(x<=mid)
			modify_x(o*2, l, mid);
		else
			modify_x(o*2+1, mid+1, r);
		
		xo = o;	
		xleaf = 0;
		modify_y(1, 1, N);
	}
	
}

int main()
{
	while(scanf("%d", &N) != EOF)
	{
		for(int i=1; i<=N; i++)
		{
			for(int j=1; j<=N; j++)
			{
				scanf("%d", &v);
				x = i;
				y = j;
				modify_x(1, 1, N);
			}
		}
		
		int Q;
		char op[10];
		
		scanf("%d", &Q);
		while(Q--)
		{
			scanf("%s", &op);
			if(op[0]=='q')
			{
				scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
				vmax = -INF, vmin = INF;
				query_x(1, 1, N);
				printf("%d %d\n", vmax, vmin);
			}
			else
			{
				scanf("%d %d %d", &x, &y, &v);
				modify_x(1, 1, N);
			}
		}
	}
	return 0; 
}
