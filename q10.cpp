/*
Assignment : 3 section B
question : 10
Submitted by: vashudev(41)
*/

#include<iostream>

using namespace std;

bool **a_mat;
bool *isPotential;

int countknown(int n, int person_x)
{
	/*
	objective: To calculates number of people that a person_x knows.
	Input variables: n- size of array isPotential, person_x - person for which number of his/ her acquaintances has to be calculated.
	Return value: no of people that person_x knows
	*/
	
	int count=0;
	for(int i=1; i<=n; i++){
		// test whether person i is a potenital invitee and also if person i and person_x know each other 
		if(isPotential[i] && a_mat[i][person_x])
			count++;
	}
	return count;
}	

void plan_party(int n){
	
	/*
	objective: To computes all persons who can be invitated for a party out of n people based on following conditions:
	Input variable: n - number of people to choose from
	Return value: none
	*/
	
	int potential_count = n;
	for(int j=1; j<=n; j++)
	{
			//stores the number of people j knows
			int known = countknown(n,j);
			//stores the number of people j does not know
			int unknown = potential_count - known - 1;
			
			//if a potenital invitee disqualifies any of condition 1 or 2, make him invalid and start checking from person 1 again
			if( isPotential[j] && (known < 5 || unknown < 5) )
			{
				isPotential[j]=false;
				potential_count--;
				j = 0;
				//if number of potenital invitee become less than 11, there is no way we can find a person who know 5 person and does not know 5 person
				if(potential_count < 11){
					for(int i=1;i<=n;i++)
						isPotential[i] = false;
					break;
				}
			}	
	}//the loop ends when every potential invitee satisfy both condition 1 and 2 or everyone become impotential
	
}

void print_invitees(int n){
	
	/*Description
	  -----------
	  objective: To print the final invitees and the count of invitees.
	*/ 
	int count = 0;
	cout<<"\n\nAlice can invite following people\n\n";
	for(int i=1; i<=n; i++){
		if(isPotential[i]){
			cout<<i<<"\t";
			count++;
		}
	}
	if(count == 0)
		cout<<"\n\nNo one can be invited.";
	else
		cout<<"\n\nMaximum number of people who can be invited is : "<<count;			
	
}
// main function

int main()
{
	int n;
	while(true){
		cout<<"\nEnter value of n: ";
		cin>>n;
		if(n>=11)
			break;
	}
	
	a_mat = new bool*[n+1];
	for(int i=0;i<=n;i++)
		a_mat[i] = new bool[n+1];

	isPotential = new bool[n+1];
	

	for(int i=1; i<=n; i++)
	{
		isPotential[i] = true;
		for(int j=1; j<=n; j++)
		{
			a_mat[i][j] = false;
		}
	}
	
	char choice;
	
	//input pairs
	while(true) 
	{
		int x, y;
		cout<<"\nEnter pair (x,y) who know each other \n";
		cout<<"\n Person x : ";
		cin>>x;
		if(x<1 || x>n){
			cout<<"\nInvald pair!Enter again!\n";
			continue;
		}
		cout<<"\n Person y : ";
		cin>>y;
		if(y<1 || y>n || y == x){
			cout<<"\nInvald pair!Enter again!\n";
			continue;
		}
		//update adjacency matrix
		a_mat[x][y] = true;
		a_mat[y][x] = true;
		cout<<"\nAre there any more pairs who know each other?(y/n): ";
		cin>>choice;
		if(choice=='n')
			break;
		x++; 
		y++;
	}
	plan_party(n);
	print_invitees(n);
	return 0;
}