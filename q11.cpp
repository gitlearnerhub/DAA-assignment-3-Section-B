/*
Assignment : 3 section B
question : 11
Submitted by: vashudev(41)
*/

#include<iostream>

using namespace std;

int **table;

int anti_squad(int n, int m, int k){
	
	/*
	objecive:
	This function calculates no. of partitions possible of 'n' people in such a way that each group in a partition 
	has atmost 'm' and atleast 'k' number of people.  
	
	Input variables:
	- n : total number of people to be partitioned  
	- m : maximum number of people allowed in each group
	- k : minimum number of people required in each group(this value remains same for each recursive call)
	Return value:Possible no. of partitions.
	Approach: Recursion and dynamic programming.	
	*/
	
	//when there are zero people, only one partiton is possible that is {}
	if(n == 0)
		return 1;
	//when the total no. of people is less than minimum count required for each group
	if(n < k )
		return 0;
	//when value of maximum people allowed is less than minimum people required.
	if(m < k)
		return 0;

	
	//when the value is not already present in the table
	if(memoize_table[n][m] == -1)
			memoize_table[n][m] = anti_squad(n-m, m, k) + anti_squad(n,m-1, k);	
				
	return memoize_table[n][m];
}
// main function

int main(){
	int n,k;
	
	while(true){
		cout<<"\n\nEnter total number of people : ";
		cin>>n;
		if(n>0)
			break;
		cout<<"\n\nNumber of people cannot be less than 1!!";
	}
	while(true){
		cout<<"\n\nEnter minimum count of people required in each group : ";
		cin>>k;
		if(k>0)
			break;
		cout<<"\n\nMinimum count cannot be less than 1!!";
	}

	memoize_table = new int*[n+1];
	for(int i=0;i<=n;i++)
		memoize_table[i] = new int[n+1];

	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			memoize_table[i][j] = -1;
	cout<<"\n\nNo. of ways in which anti sqauds can be formed is : "<<anti_squad(n,n,k);
	return 0;
}