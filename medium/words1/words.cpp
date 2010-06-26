#include<iostream>
#include<map>

using namespace std;

int main()
{
	int cases;
	cin>>cases;
	map<char,int> left ;
	map<char,int> right ;

	while(cases--)
	{
		int num ;
		cin>>num;
		while(num--)
		{
			string tmp ;
			cin>>tmp ;
			left[tmp[0]]++;
			right[tmp[tmp.size()-1]]++;
		}
		int ls=0,rs=0;
		for( int i=0 ;i<26;i++)
		{
			char v='a'+i;
			int lval = left[v];
			int rval = right[v];
			int diff = lval-rval;
			if ( diff < 0 )
				rs+=(-1)*diff;
			else
				ls+=diff;
		}
		cout<<"L "<<ls<<" R "<<rs;
		if( ls>1 || rs>1 )
			cout<<"The door cannot be opened."<<endl;
		else if ( ls > 0 && rs == 0 )
			cout<<"The door cannot be opened."<<endl;
		else if ( rs > 0 && ls == 0 )
			cout<<"The door cannot be opened."<<endl;
		else 
			cout<<"Ordering is possible."<<endl;
		
		left.clear();
		right.clear();
	}
}	

