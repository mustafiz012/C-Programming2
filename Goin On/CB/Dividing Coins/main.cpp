//permutation

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
using namespace std;

#define SIZE 10
int N, permu[SIZE], A[SIZE];
void readCase()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> permu[i];
}
int Used[SIZE];

void initUsed()
{
    for (int i = 0; i < N; i++)
        Used[i] = 0;
}
void print()
{
    for (int i = 0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");
}
int solve(int i)
{
    int j;
    if (i == N)
    {
        print();
        return 0;
    }
    for (j = 0; j < N; j++) if(0==Used[j])
        {
            Used[j] = 1;
            A[i] = permu[j];
            solve(i + 1);
            Used[j] = 0;
        }
}

int main()
{
    int T;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> T;
    while (T--)
    {
        readCase();
        initUsed();
        solve(0);
    }
    return 0;
}
