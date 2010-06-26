#include<iostream>
#include<vector>

using namespace std;



int merge_count(vector<int> val , int start , int mid , int end )
{
	int left , right;
	left=start,right=mid+1;
	int tmp[end-start+1];
	int count=0;
	int i = 0 ;
	while(left<=mid&&right<=end)
	{
		if(val[left]<val[right])
		{
			tmp[i] = val[left];
			left++;
		}
		else
		{
			count+=(mid-left+1);
			tmp[i]=val[right];
			right++;
		}
		i++;
	}
	//remaining
	if(left!=mid)
	{
		while( left<=mid )
		{
			tmp[i]=val[left];
			i++;
		}
	}
	if(right!=end)
	{
		while( right<=end )
		{
			tmp[i]=val[right];
			i++;
		}
	}
	for(int i=start,j=0;i<=end;i++,j++)
	{
		val[i] = tmp[j];
	}
			
	return count;
}


int merge_and_solve( vector<int> arr , int start , int end )
{
	cout<<"ST :"<<start<<" END : "<<end<<endl;
	
	if( start==end)
		return 0;
	else
	{
		int count=0;
		int mid=(end+start)/2;
		count+=merge_and_solve(arr , start , mid );
		count+=merge_and_solve(arr , mid+1 ,end );
		count+=merge_count(arr , start , mid , end );
		return count;
	}
}


int main()
{
	vector<int> val;
	int num;
	cin>>num;
	
	while(num--)
	{
		int n;
		cin>>n;
		val.push_back(n);
	}
	for(int i = 0 ; i<val.size();i++)
	{
		cout<<"val "<<val[i]<<endl;
	}
	cout<<merge_and_solve(val,0,val.size()-1)<<endl;
}
