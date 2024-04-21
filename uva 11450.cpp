#include<iostream>
#include<cstring>

using namespace std;

#define maxm 200+5
#define maxc 20+5

bool dp[maxm][maxc];
int p[maxc][maxc];

int main()
{
	int cas, m, c;
	scanf("%d", &cas);
	while(cas--)
	{
		memset(dp, 0, sizeof dp);
		scanf("%d%d", &m, &c);
		for(int i=0; i<c; i++)
		{
			scanf("%d", &p[i][0]);
			for(int j=1; j<=p[i][0]; j++)
			{
				scanf("%d", &p[i][j]);
			}
		}
		
		for(int i=1; i<=p[0][0]; i++)
		{
			if(m-p[0][i]>=0) 
				dp[m-p[0][i]][0]=true;
		}
		
		for(int j=1; j<c; j++)
		{
			for(int i=0; i<m; i++)
			{
				if(dp[i][j-1])
				{
					for(int k=1; k<=p[j][0]; k++)
					{
						if(i-p[j][k]>=0) 
							dp[i-p[j][k]][j] = true;
					}
				}
			}
		}
		int x;
		for(x=0; x<=m && !dp[x][c-1]; x++);
		if(x==m+1)
			printf("no solution\n");
		else
			printf("%d\n", m-x);
	}
	return 0;
}
