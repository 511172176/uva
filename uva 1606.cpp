#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>

using namespace std;

#define maxn 1000+5

struct point
{
	int x, y;
	double rad;
	bool operator < (const point &rhs) const
	{
		return rad < rhs.rad;
	}
}op[maxn], p[maxn];

int n, color[maxn];

bool left(point a, point b)
{
	return a.x*b.y- a.y*b.x>=0;
}

int solve()
{
	
	int ans=0;
	for(int i=0; i<n; i++)
	{
		int k=0;
		for(int j=0; j<n; j++)
		{
			if(i!=j){
				p[k].x=op[j].x-op[i].x;
				p[k].y=op[j].y-op[i].y;
				if(color[j])
				{
					p[k].x = -p[k].x;
					p[k].y = -p[k].y;
				}
				p[k].rad = atan2(p[k].y, p[k].x);
			k++;
			}
		}
		sort(p, p+k);
		int l=0, r=0, cnt=2;
		while(l<k)
		{
			if(l==r)
			{
				r = (r+1)%k;
				cnt++;
			}
			while(l!=r && left(p[l], p[r]))
			{
				r = (r+1)%k;
				cnt++;
			}
			cnt--;
			l++;
			ans = max(ans, cnt);
		}
	}
	return ans;
}

int main()
{
	while(scanf("%d", &n)==1&&n)
	{
		for(int i=0; i<n; i++)
		{
			scanf("%d%d%d", &op[i].x, &op[i].y, &color[i]);
		}
		printf("%d\n", solve());
	}
	return 0;
}
