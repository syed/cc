#include <cmath>
#include<iostream>
#include <vector>
//#include<algoritm>
using namespace std;

/*primes is a list of primes, n is all the primes you want to generate.. from 2 to n*/
void genPrimes(vector<long long>&primes ,long long n){
	long long root;
	bool found;
	for(long long i=2;i<=n;i++){
		root=long((sqrt(i))+1);    /*remember the square root*/
		found=false;            /*prime found?*/
		for(long long j=0;j<primes.size()&& primes[j]<root;j++){
			if(i%primes[j]==0){found=true;break;} /*this is not prime*/
		}
		if(!found)primes.push_back(i); /*this is a prime*/
	}
}

int inprimes(vector<long long> primes , long long num )
{
	for( long long i =0 ; i< primes.size() ; i++)
	{
		if ( num == primes[i] )
			return 1;
	}
	return 0;
}
int main()
{
	vector<long long> primes ;
	vector<bool> nums;
	long long a , b;
	int cases;
	cin>>cases;
        while(cases--)
	{
		cin>>a>>b;
		long long  sieve_max = long ( sqrt(b) + 1  );
		genPrimes(primes , sieve_max  );
		
		//push the nums 
		//for ( int i = 0 ; i < primes.size() ; i++ )
		//	cout<<"prime "<<primes[i]<<endl;	

		for( long long  i = a ; i<=b ; i++)
		{
/*			if ( a%2 == 0 )
			{
				i++;
				continue ;
			}*/
			nums.push_back(true);
		}
		if ( a == 1 ) 
		{
			nums[0] = false;
		}
		//run the sizeve 
		for ( long long  i = 0 ; i< primes.size() && primes[i]*primes[i] <=b ; i++ )
		{
			long long val = long ( a%primes[i]);
		
			long long offset = val?primes[i]-val:0;

		//	cout<<"looking "<<primes[i]<<"offset is "<<offset<<endl ;
			for ( long long j = offset ; j <= b-a ; j+=primes[i] )
			{
				//cout<<"marking "<<j<<" non prime"<<endl;
				nums[j] = false ;
			}
		}
		//get the primes now 
		for ( long long i = 0 ; i<primes.size() ; i++)
		{
			if ( primes[i] >= a )
				cout<<primes[i]<<endl;
		}
		for ( long long i = 0 ; i < nums.size() ; i++ )
		{
			if( nums[i]  && ! (inprimes(primes , i+a ))  )
			{
				cout<<i+a<<endl;
			}
		}	
		primes.clear();
		nums.clear();
	}
	
		
}
