#include<iostream>
#include<queue>
#include<vector>

using namespace std;
typedef long long ll;

priority_queue<ll, vector<ll>, greater<ll> > pq;

int n;

int main()
{
	while(scanf("%d", &n)==1&&n)
	{
		while(!pq.empty()) pq.pop();
		while(n--)
		{
			int x;
			scanf("%d", &x);
			pq.push(x);
		}
		ll sum = 0;
		while(true)
		{
			ll a = pq.top(); pq.pop();
			ll b = pq.top(); pq.pop();
			sum += a + b;
			if(!pq.empty())
				pq.push(a+b);
			else
				break;
		}
		printf("%d\n", sum);
	}
	return 0;
}
