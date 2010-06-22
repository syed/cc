#include<iostream>
#include<string>
using namespace std;


int main()
{
	int cases;
	cin>>cases;
	while(cases--)
	{
		string num_str ;
		cin>>num_str;
		long long len  = num_str.size();
		long long j,k;
		string ans ;
		j=len/2-1,k=len/2;
		if(len%2 == 0 )
		{
			while( num_str[j] == num_str[k] && j>=0 )
			{
				j--,k++ ;
			}
			if(num_str[j] > num_str[k] )
			{
				//make left = right 
				ans.append(num_str,0,len/2);
				ans.append(num_str.rbegin()+len/2,num_str.rend());
				
			}
			else //increment left part 
			{
				int carry = 1 ;
				for(long long i = len/2-1; i>=0 ; i--)
				{
					char tmp ;
					tmp = num_str[i] + carry ;
				        if ( tmp > '9' )
					{
						tmp='0';carry=1 ;
						num_str[i] = tmp ;
					}
					else
					{
						carry=0;
						num_str[i] = tmp ;
						break;
					}
				}	
				if(carry)
				{
					ans.push_back('1');
				}
				ans.append(num_str.begin() , num_str.begin()+len/2);
			
				if(carry)
				{
					ans.append(num_str.rbegin()+len/2+1,num_str.rend());
					ans.push_back('1');
				}
				else 
				{
					ans.append(num_str.rbegin()+len/2,num_str.rend());
				}
			}
		}
		else //odd  length 
		{
			k++;
			while( num_str[j] == num_str[k] && j>=0 )
			{
				j--,k++ ;
			}
			if( num_str[j] > num_str[k] )
			{
				ans.append(num_str,0,len/2);
				ans.push_back(num_str[len/2]);
				ans.append(num_str.rbegin()+len/2+1,num_str.rend()); 
			}
			else
			{

				char cen = num_str[len/2];
				cen++;
				int carry = 0 ;
				if ( cen > '9' )
				{
					cen='0';
					carry = 1 ;
				}
				if(carry) 
				{
					for(long long i = len/2-1; i>=0 ; i--)
					{
						char tmp ;
						tmp = num_str[i] + carry ;
						if ( tmp > '9' )
						{
							tmp='0';carry=1 ;
							num_str[i] = tmp ;
						}
						else
						{
							carry=0;
							num_str[i] = tmp ;
							break;
						}
					}
				}
				if(carry)
				{
					ans.push_back('1');
				}
				ans.append(num_str.begin() , num_str.begin()+len/2);
				ans.push_back(cen);	
				if(carry)
				{
					ans.append(num_str.rbegin()+len/2+2,num_str.rend());
					ans.push_back('1');
				}
				else 
				{
					ans.append(num_str.rbegin()+len/2+1,num_str.rend());
				}
			   }
		}
				

		cout<<ans<<endl;

	}
}

