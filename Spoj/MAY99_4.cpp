#include <cstdio>
#define MAX 100
long long triangle[MAX + 1][MAX + 1];

void makeTriangle() {
    int i, j;

    // initialize the first row
    triangle[0][0] = 1; // C(0, 0) = 1

    for(i = 1; i < MAX; i++) {
        triangle[i][0] = 1; // C(i, 0) = 1
        for(j = 1; j <= i; j++) {
            triangle[i][j] = (triangle[i - 1][j - 1] + triangle[i - 1][j])%10000007;
        }
    }
}

long long C(int n, int r) {
    return triangle[n][r];
}
int main()
{
	int n,r;
	makeTriangle();
	scanf("%d%d",&n,&r);
	if(n<r)
		printf("-1\n");
	else if(n==r || r==1)
		printf("1\n");
	else
	{
		printf("%lld\n",triangle[n-1][r-1]%10000007);
	}
	return 0;
}
