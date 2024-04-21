#include<stdio.h>
#include<string.h>
#include<math.h>

long long x, y;

long long ex(long long a, long long b)
{
	if(b==0)
	{
		x = 1;
		y = 0;
		return a;
	}
	else
	{
		long long ans = ex(b, a%b);
		long long tmp = y;
		y = x - a/b * y;
		x = tmp;
		return ans;
	}
}

long long c1, n1, c2, n2, n;
int main()
{
	while(~scanf("%lld", &n)&&n)
	{
		scanf("%lld%lld%lld%lld", &c1, &n1, &c2, &n2);
		
		long long d = ex(n1, n2);
		long long dounk = ceil(-1.0 * n * x / n2);
		long long upk = floor(1.0 * n * y / n1);
		if(n%d || dounk > upk)
		{
			printf("falied\n");
			continue;
		}
		if(c1 * n2 > c2 * n1)
		{
			x = x * n/d + n2/d * dounk;
			y = y * n/d - n1/d * dounk;
			printf("%lld %lld\n", x, y);
		}
		else
		{
			x = x * n/d + n2/d * upk;
			y = y * n/d - n1/d * upk;
				printf("%lld %lld\n", x, y);
		}
	}
	return 0;
}

