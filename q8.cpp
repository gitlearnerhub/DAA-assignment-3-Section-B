/*
Assignment : 3 section B
question :8
Submitted by: vashudev(41)
*/

#include<iostream>
#include<math.h>
using namespace std;

struct license{
	//structure to store license no. along with rate of growth of its price
	int license_no;
	float rate_of_growth;
};

int find_max(license l_arr[], int n){
	
	/*
	objective: To find the license_no of software having maximum rate of growth value.
	Input variables:l_arr- array of licence objects, n- number of objects in array
	Return value: max growth rate license number
	*/

	int max = 0;			

	for(int i=1;i<n;i++){
		if(l_arr[i].rate_of_growth > l_arr[max].rate_of_growth)
			max = i;
	}
	
	swap(l_arr[0].rate_of_growth, l_arr[max].rate_of_growth);
	swap(l_arr[0].license_no, l_arr[max].license_no);	
	
	//return the license of first license object in array l_arr
	return l_arr[0].license_no;	
}

void print_order(license l_arr[], int n){
	/*
	objective: To find and prints the order of buying license.
	input variables: l_arr- array of licence objects, n- number of objects in array
	return value: none
	*/
	
	for(int i=0; i<n; i++){
		//call to find maximum from the remaining array l[i..n-1]
		cout<<"License "<<find_max((l_arr+i), n-i);
		cout<<"  : Rate "<<l_arr[i].rate_of_growth<<endl;
	}
}

float amount(license l_arr[], int n){

	/*
	objective: To calculate the minimized amount spend to buy license.
	Input variables: l_arr - array of license objects, n- number of objects in array
	Return value:none
	*/
	
	float amount  = 0;
	for(int i=0; i<n; i++){
		amount += pow(l_arr[i].rate_of_growth, i); 
	}
	return amount*100;
}

//main function

int main(){

	int n;
	while(true){
		cout<<"\n\nEnter number of  softwares : ";
		cin>>n;	
		if(n>=1)	
			break;
		else
			cout<<"\nNo. of softwares should be atleast 1!";
	}
	license *lic = new license[n];
	//input rate
	for(int i=0; i<n; i++){
		
		float temp;
		cout<<"\nEnter rate of growth for license "<<i+1<<" : ";
		cin>>temp;
		if(temp <= 1){
			cout<<"\nrate must be greater than 1!";
			i--;
			continue;
		}
		lic[i].license_no = i+1;
		lic[i].rate_of_growth = temp;
	}
	
	cout<<"\nOrder of buying license is \n\n";
	print_order(l, n);

	cout<<"\n\nMinimized amount is : $"<<amount(l, n);
}