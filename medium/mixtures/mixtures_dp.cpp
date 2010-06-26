#include<iostream>
#include<vector>
using namespace std;
int dp[100][100][100];
typedef struct cost_val {
	int cost;
	int val ;
} Pval ;

Pval cost(vector<int> mix , int i , int j )
{
	Pval ret;
	if ( i > j ) 
	{
		ret.cost = -1;
		ret.val=mix[i];
		return ret;
	}
	if ( i == j )
	{
		ret.val=mix[i];
		ret.cost=0;
		return ret;
	}
	ret.cost = 99999999;
	ret.val = 99;	
	for( int k = i ; k<j ; k++)
	{
		Pval c1,c2;
		c1 =  cost(mix , i,k) ;
		c2 =  cost(mix ,k+1,j) ;
		if( c1.cost+c2.cost+c1.val*c2.val < ret.cost )
		{
			ret.cost= c1.cost+c2.cost+c1.val*c2.val;
			ret.val=(c1.val+c2.val)%100;
		}
	}
	//cout<<"Returning "<<ret.cost<<" "<<ret.val<<"i "<<i<<" j"<<j<<endl;
	return ret;
}
int main()
{
        int len ;
	Pval ans ;
        while(cin>>len)
        {
                vector<int> mix;
                for( int i = 0 ; i< len ; i++ )
                {
                        int v ;
                        cin>>v;
                        mix.push_back(v); 
		}
		cout<<cost(mix , 0 , mix.size()-1).cost<<endl;
	}
}

