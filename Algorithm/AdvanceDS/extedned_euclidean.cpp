#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a,long long b,long long &x,long long &y)
{
	if(a==0){
		x=0;
		y=1;
		return b;
	}

	long long x1,y1;
	long long g=gcd(b%a,a,x1,y1);
	x=y1-(b/a)*x1;
	y=x1;
	return g;
}

int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long xx,yy;

		long long a,n;
		cin>>a>>n;
		long long g=gcd(a,n,xx,yy);
		if(g==1)
		{
 
			xx=((xx+n)%n);
			if(xx==0)
				xx+=n;
			cout<<xx<<endl;
		}
		else cout<<-1<<endl;
	}
    return 0;
}



