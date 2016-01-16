#include "stdFile.h"
using namespace std;
#define mod 1000007
LL C[405][405];
void init()
{
	C[0][0] = 1;
	for(int i = 1; i < 401; i++){
		C[i][0] = 1;
		for(int j = 1; j <= i; j++){
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
			C[i][j] %= mod;
		}
	}
}

LL solve(int n, int m, int k){
	LL ret1 = C[n*(m - 1)][k],
	   ret2 = C[m*(n - 1)][k],
	   ret3 = C[(n - 1)*(m - 1)][k],
	   ret4 = C[(n - 2)*m][k],
	   ret5 = C[(m - 2)*n][k],
	   ret6 = C[n*m - n - 2*(m - 1)][k],
	   ret7 = C[n*m - m - 2*(n - 1)][k],
	   ret8 = C[(n - 2)*(m - 2)][k];
	LL ret = 2*(ret1 + ret2) - ret3*4 - ret4 - ret5 + ret6*2 +ret7*2 - ret8;
//	cout << C[n*m][k] << "  " << ret << endl;
	return (C[n*m][k] - ret%mod + mod) % mod;
}
int main()
{
	int T;

	init();
	cin >> T;
	int t = 0;
	while(T--)
	{
		t++;
		int n, m, k;
		cin >> n >> m >> k;
		cout << "Case " << t << ": " << solve(n, m, k) << endl;
	}
	return 0;
}
