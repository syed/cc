#include<iostream>
#include<vector>
using namespace std;
int dp[100][100];
int sum[100][100];
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
	if( dp[i][j] && dp[i][j] !=99999999 )
	{	
		ret.cost=dp[i][j];
		ret.val=  sum[i][j];
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
	dp[i][j] = ret.cost;
	sum[i][j] = ret.val;
	return ret;
}
int main()
{
        int len ;
	Pval ans ;
	for(int i =0 ; i<100 ;i++)
			dp[i][i]=0;

        while(cin>>len)
        {
                vector<int> mix;
                for( int i = 0 ; i< len ; i++ )
                {
                        int v ;
                        cin>>v;
                        mix.push_back(v); 
		}
		for(int i =0;i<100;i++)
			for(int j=0;j<100;j++)
				dp[i][j]=99999999;

		cout<<cost(mix , 0 , mix.size()-1).cost<<endl;
	}
	return 0;
}

