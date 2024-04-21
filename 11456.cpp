#include<iostream>
//#include<algorithm>

using namespace std;

int t, n, m, ans;
int lis[2000+5], lds[2000+5], r[2000+5];

int main()
{
	scanf("%d", &t);
	
		while(t--)
		{
			scanf("%d", &n);
			ans = 0;
		
			for(int i=0; i<n; i++)
				scanf("%d", &r[i]);
			
			for(int i=n-1; i>=0; i--)
			{
				lis[i] = 1;
				lds[i] = 1;
				
				for(int j=n-1; j>i; j--)
				{
					if(r[j]<r[i])
						lis[i] = max(lis[i], lis[j]+1);
					if(r[j]>r[i])
						lds[i] = max(lds[i], lds[j]+1);
				}
				ans = max(ans, lis[i]+lds[i]-1);
			}
			printf("%d\n", ans);
		}
	
	return 0;
}
