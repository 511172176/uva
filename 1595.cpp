#include<iostream>
#include<set>
//#include<algorithm>

using namespace std;

#define N 1000+5

struct Point
{
	int x, y;
	Point(int x=0,int y=0): x(x), y(y){}
	bool operator < (const Point &tmp) const
	{
		return x < tmp.x || (x == tmp.x && y < tmp.y);
	}
};

Point p[N];

int main()
{
	int T, n;
	set<Point> sp;
	
	scanf("%d", &T);
	while(T--)
	{
		
		int maxn, minn, m;
		sp.clear();
		
		scanf("%d", &n);
		for(int i=0; i<n; i++)
		{
			scanf("%d%d", &p[i].x, &p[i].y);
			p[i].x *= 2; 
			
			if(i==0)
			{
				minn = p[0].x;
				maxn = p[0].x;
			}
			else 
			{
				minn = min(minn, p[i].x);
				maxn = max(maxn, p[i].x);
			}
			sp.insert(p[i]);
		}
		m = (maxn + minn) / 2;
		bool ok = true;

		for(int i=0; i<n; i++)
		{
			Point t(2*m-p[i].x, p[i].y);
			
			if(!sp.count(t))
			{
				ok = false;
				break;
			}
		}
		printf("%s\n", ok? "YES": "NO"); 
	}
	return 0;
}
