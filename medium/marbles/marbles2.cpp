#include<iostream>
#include<vector>
using namespace std;


typedef unsigned long long int UL;

double optimized_double_C(UL n,UL k){
    double answer = 1.0;
    UL i;
    if(k > (n/2))
        k = n-k;
    for(i = 0; i < k; i++){
         answer = answer * ((double)(n-i)/(double)(i+1));
      }
    return answer;
}

int main()
{
	long long int n,k ;
	int cases;
	cin>>cases;
	double ans;
	vector<long long> up  , down ;
	while( cases-- )
	{
		cin>>n>>k;
		printf("%.0lf\n" , optimized_double_C(n-1,k-1));
				 	
	}
}

