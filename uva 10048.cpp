#include<iostream>
#include<cstring>

using namespace std;

#define maxc 100+5
#define INF 0x3f3f3f3f

int r[maxc][maxc];
int c, s, q;

void floyd()
{
	for(int k=1; k<=c; k++)
		for(int i=1; i<=c; i++)
			for(int j=1; j<=c; j++)
				r[i][j]=min(r[i][j], max(r[i][k], r[k][j]));
}

int main()
{
	int cnt=0;
	while(scanf("%d%d%d", &c, &s, &q)==3&&c+s+q)
	{
		if(cnt++)
			printf("\n");
		printf("Case #%d\n", cnt);
		
		memset(r, INF, sizeof r);
		for(int i=0; i<s; i++)
		{
			int x, y, v;
			scanf("%d%d%d", &x, &y, &v);
			r[x][y]=r[y][x]=v;
		}
		floyd();
		for(int i=0; i<q; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			if(r[x][y]!=INF)
				printf("%d\n", r[x][y]);
			else
				printf("no path\n");
		}
	}
	return 0;
}
