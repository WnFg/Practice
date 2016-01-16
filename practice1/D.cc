#include "stdFile.h"
using namespace std;
#define mod 1000000000
LL d[301][301];
string s;
LL solve(int i, int j)
{
	if(d[i][j] != -1)
		return d[i][j];
	if( i == j ){
		d[i][j] = 1;
		return d[i][j];
	}
	if( s[i] != s[j] ){
		d[i][j] = 0;
		return d[i][j];
	}
	
	d[i][j] = solve(i + 1, j - 1);
	d[i][j] %= mod; 
	for(int k = i + 2; k < j - 1; k++){
		if(s[i] == s[k]){
			d[i][j] += solve(i + 1, k - 1) * solve(k, j) % mod;
			d[i][j] %= mod;
		}
	}
	return d[i][j];
}
int main()
{
	while( cin >> s ){
		memset(d, -1, sizeof(d));
		cout << solve(0, s.size() - 1) << endl;
	//	cout << d[0][6] << "  " << d[1][5] << "  " << d[2][4] << "  " << "  " << d[3][3] << endl;
	}
	return 0;
}

