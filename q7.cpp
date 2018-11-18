/*
Assignment : 3 section B
question: 7
Submitted by: vashudev(41)
*/

#include<iostream>

using namespace std; 

struct transD 
{
	int buy_day;
	int sell_day;
}t;

transD calcDates(float p[], int n)
{
	/*
	objective: To calculates the buy date and sell date for which profit is maximum.
	Input variables: p- array of prices, n- total no of days
	Return value: a tuple with max profit dates , otherwise -1
	*/

	float min=p[0];
	float max_diff=p[1]-p[0];
	int temp=0;
	if(max_diff>0)
		t.sell_day=1;
	for(int i=0; i<n; i++)
	{
		if((p[i]-min) > max_diff)	
		{
			max_diff=p[i]-min;
			t.buy_day = temp;	
			t.sell_day = i;		//save buy day and sell day with max price difference
		}	
		if(p[i]<min) 			
		{
			min=p[i];
			temp=i;			
		}
	}	
	if(max_diff<=0) { //if no such dates possible where profit can be made
		t.buy_day = -1;
		t.sell_day = -1;
	}					
	return t;				//return dates yielding max profit	
}		

//main function

int main()
{
	int n;
	while(true){
		cout<<"\nEnter number of days: ";
		cin>>n;
		if(n>=2)
			break;
		cout<<"\nNumber of days should be atleast 2!\n";
	}
	//Input price
	float *p = new float[n];
	for(int i=0; i<n; i++)	
	{	
		cout<<"\nEnter price on day "<<i+1<<" : ";	
		cin>>p[i];
		if(p[i]<=0){
			cout<<"\nPrice cannot be negative or zero! Enter again!\n";
			i--;
		}
	}
	
	transD max_profit_days = calcDates(p,n);
	
	if(max_profit_days.buy_day == -1)
		cout<<"\nSorry not possible! ";
	else
		cout<<"\nBuy on day "<<max_profit_days.buy_day+1<<" and sell on day "<<max_profit_days.sell_day+1<<"\n";	
	return 0;
}