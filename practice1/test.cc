#include "stdFile.h"
using namespace std;
int main()
{
	uLL n, m;
	while( cin >> n >> m){
		if(n == 0 && m == 0) break;
		if (n > m) swap(n, m);
		cout << n*m*(m+n-2)+2*n*(n-1)*(3*m-n-1)/3 << endl;
	}
}
