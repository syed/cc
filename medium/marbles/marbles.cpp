#include<iostream>

using namespace std;

int main()
{
	long long int n,k ;
	int cases;
	cin>>cases;
	long long ans;
	while( cases-- )
	{
		cin>>n>>k;
//		cout<<fact(n-1)/(fact(k-1)*fact(n-k))<<endl;
		n=n-1;
		k=k-1;
		ans = 1 ;
		long long j;
	        j = 2;	
		for(long long i = n-k+1 ; i<= n ; i++)
		{
			ans=ans*i;

			for ( ;ans%j==0&&j<=k;j++)
			{
				ans=ans/j;
			}
		}
		cout<<ans<<endl;
				 	
	}
}

