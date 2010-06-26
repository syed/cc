#include<iostream>
#include<cmath>
using namespace std;

int graph[26][26];
int ind[26],outd[26];
int vis[26],got[26];

void dfs(int e )
{
	for( int i = 0 ;i<26;i++)
	{
		if( ( graph[e][i] || graph[i][e] ) &&  ! vis[i])
		{
			vis[i] = 1;
			dfs(i);
		}
	}
}
			

int main()
{
        int cases;
        cin>>cases;

        while(cases--)
        {
                int num ;
                cin>>num;
		for(int i = 0 ; i < 26;i++)
		{
			for(int j = 0 ;j < 26; j++)
			{
				graph[i][j] = 0 ;
			}
			ind[i] = 0;
			outd[i] = 0;
			got[i] = 0;
			vis[i] = 0;
		}
                while(num--)
                {
                        string tmp ;
                        cin>>tmp ;
			char l,r;
                        l = tmp[0];
                        r = tmp[tmp.size()-1];
			graph[l-'a'][r-'a'] = 1;
			ind[l-'a']++;
			outd[r-'a']++;
			got[l-'a']=1;
			got[r-'a']=1;
                }
		int start = 0 ;
		for( int i = 0 ;i<26;i++)
		{
			if(got[i])
			{
				start = i;
				break;
			}
		}

	
		vis[start] = 1;
		dfs(start);
		int ans = 1;
		for(int i=0;i<26;i++)
		{
				if( got[i] && !vis[i] )
				{
					ans = 0;
					break;
				}
		}

		int deg = 0 ;

		for( int i =  0 ;i<26;i++)
		{
			int diff = (ind[i] - outd[i] );
			if (diff<0)
			{
				diff=diff*-1;
			}
			if( diff <= 1 )
			{
				deg+=diff;
			}
			else 	
			{
				ans = 0;
				break;
			}
		}
		if(ans !=0 )
		{

			if ( deg == 0 || deg ==  2 ) 
				ans = 1;
			else ans = 0 ;
		}
		
		if ( ans )
			cout<<"Ordering is possible."<<endl;
		else
			cout<<"The door cannot be opened."<<endl;
	}
}


