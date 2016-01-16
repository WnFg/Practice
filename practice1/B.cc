#include "stdFile.h"
using namespace std;
uLL S[1000001];
uLL f(uLL n){
	uLL ret = n - ((n + 1)/2 + 1);
	return ret*ret + n%2*ret;
}
int main()
{
	uLL n;
	S[3] = 0;
	for(int i = 4; i < 1000001; i++){
		S[i] = S[i - 1] + f(i);
	}
	while( cin >> n ){
		if( n < 3 ) break;
		if( n == 3 ) { cout << 0 << endl; continue; }
		cout << S[n] << endl;
	}
	return 0;
}
