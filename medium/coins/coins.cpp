#include<iostream>
#include<map>
using namespace std;
map<long long , long long > table ;
long long count(long long num ) ;
main()
{
	long long num ;
	while(cin>>num)
	{	
		cout<<count(num)<<endl;
		table.clear();
	}
}


long long count( long long num ) 
{
	long long res;
	if( table[num] ) 
	{
		//cout<<"value for "<<num<<" in table is  "<<table[num]<<endl;
		return table[num] ;
	}
	else 
	{
		if ( num < 12 )
		{
			table[num]=num;
			//cout<<"value for "<<num<<" is  "<<num<<endl;
			return num ;
		}
		else
		{
			long long val,ans,curr,x;
			val = num ; 
			//cout<<"Calling for "<<val<<endl;
			curr = count(val/2) + count(val/3) + count(val/4);
			//cout<<"GOt "<<curr<<endl;	
			if ( curr > num ) 
			{
				ans = curr;
			}
			else
			{
				ans = num ;
			}
			//cout<<"ans for "<<num<<" : "<<ans<<endl;
			table[num]=ans;
			return ans;
		}

	}
}
