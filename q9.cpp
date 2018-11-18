/*
Assignment : 3 section B
question : 9
Submitted by: vashudev(41)
*/

#include<iostream>

using namespace std;

struct participant 
{
	int swim_time, bike_time, run_time, p_number;
};

void equate(participant &p1, participant &p2)
{
	/*
	objective: To equates all fields of structure p1 to structure p2.
	Input variables: p1- object in which values have to be stored, p2- object from which values have to be copied
	Return value:none
	*/

	p1.p_number = p2.p_number;
	p1.swim_time = p2.swim_time;
	p1.bike_time = p2.bike_time;
	p1.run_time = p2.run_time;	
}

bool isGreater(participant p1, participant p2)
{
	/*
	objective: To compare completion time of two possible sceratios.
	Input variables: p1- , p2- object of type participant 
	Return value: boolean value
	*/

	int s1  = p1.swim_time;
	int br1 = p1.bike_time + p1.run_time;
	int s2  = p2.swim_time;
	int br2 = p2.bike_time + p2.run_time;
	if( s1 + max(br1, s2 + br2) > s2 + max(br2, s1 + br1))
		return true;
	else
		return false;
}

void sort(participant p[], int n)
{
	/*
	objective: To  performs insertion sort based on a special greater than operation.
	Input variables: p- array of objects of type participant, n- number of participants.
	Return value: none
	*/
	
	int i,j;
	participant key;
	for(i=1; i<n; i++)
	{
		equate(key,p[i]);
		j=i-1;
		while(j>=0 && isGreater(p[j],key))
		{
			equate(p[j+1],p[j]);
			j=j-1;
		}
		equate(p[j+1], key);
	}
}

//main function

int main()
{
	int n;
	while(true){
		cout<<"\nEnter number of participants : ";
		cin>>n;
		if(n>=1)
			break;
		cout<<"\nNumber of participants should be atleast 1!\n";
	}
	participant *p = new participant[n];
	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter expected swim-time, bike-time and run-time of participant "<<i+1<<": \n";
		cin>>p[i].swim_time>>p[i].bike_time>>p[i].run_time;
		p[i].p_number=i+1;
	}
	sort(p,n);
	cout<<"\n\nOrder of sending out participants is \n\n";
	for(int j=0; j<n; j++)
		cout<<p[j].p_number<<" ";
	return 0;
}