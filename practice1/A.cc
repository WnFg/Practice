#include "stdFile.h"
using namespace std;
uLL S[1000001];
uLL solve(uLL n, uLL m)
{
	if( n < 1 ) return 0;
	if( n == 1 ) return m * (m - 1);
	uLL ans = 0;
	ans += 2 * S[n - 1];
	ans += n*(n - 1)*(m - n + 1);
	ans *= 2;
	ans += n*(m - 1)*m + m*(n - 1)*n;
	return ans;
}

int main()
{
	int n, m;
	S[2] = 2;
	for(uLL i = 3; i < 1000001; i++){
		S[i] = (i - 1) * i + S[i - 1];
	}
	while(scanf("%d %d", &n, &m)){
		if(n == 0 && m == 0)
			break;
		if(n > m) swap(n, m);
		cout << solve(n, m) << endl;
	}
	return 0;
}
