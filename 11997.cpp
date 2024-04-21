#include <iostream>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;
const int maxn=768;
int A[maxn];
int B[maxn];

struct Item
{
    int sum, b;
    Item(int sum, int b) : sum(sum), b(b) {}
    bool operator < (const Item& r) const
    {
        return sum > r.sum;
    }
};

void merge(int* A, int* B, int* C, int k)
{
    priority_queue<Item> q;

    for (int i=0; i<k; i++)
        q.push(Item(A[i]+B[0], 0));

    for (int i=0; i<k; i++)
    {
        Item item=q.top(); q.pop();
        C[i]=item.sum;
        int b=item.b;
        if (b+1<k) q.push(Item(item.sum-B[b]+B[b+1], b+1));
    }
}

int main()
{
    int k,first;
    first=1;
    while (scanf("%d", &k) == 1)
    {
        for (int i=1; i<k; i++)
        {
            if (first)
            {
                for (int i=0; i<k; i++)
                    scanf("%d", &A[i]);
                sort(A, A+k);
                first=0;
            }
            for (int j=0; j<k; j++)
                scanf("%d", &B[j]);
            sort(B, B+k);
            merge(A, B, A, k);
        }
        printf("%d", A[0]);
        for (int i=1; i<k; i++)
            printf(" %d", A[i]);
        printf("\n");
        first=1;
    }
    return 0;
}

