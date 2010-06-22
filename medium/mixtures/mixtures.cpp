#include<iostream>
#include<vector>


using namespace std;

int main()
{
	int len ;
	while(cin>>len)
	{
		vector<int> mix;
		for( int i = 0 ; i< len ; i++ )
		{
			int v ;
			cin>>v;
			mix.push_back(v);
		}
		int pa,pb,a,b,smoke,min;
		smoke=0;
		while( mix.size() > 1 ) 	
		{
			min=99999;
			for(int j=0;j<mix.size()-1;j++)
			{
				a = mix[j];
				b = mix[j+1];
				if ( (a+b)%100 < min )
				{
					min = (a+b)%100;
					pa = j;
					pb = j+1;
				}
			}
			//we got the minimum in this iteration 
			//replace it with the new val 
			smoke+=mix[pa]*mix[pb];
			mix[pa] = (mix[pa]+mix[pb])%100 ;
//			cout<<"pos "<<pa<<" "<<pb<<endl;
			mix.erase(mix.begin()+pb) ;
//			cout<<"new vector"<<endl;
			/*for ( int k = 0 ;k<mix.size();k++)
			{
				cout<<mix[k]<<endl;
			} */
		}
		cout<<smoke<<endl;
	}
}
				

