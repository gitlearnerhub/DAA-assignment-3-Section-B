/*
Assignment : 3 section B
Submitted by: vashudev(41)
*/

#include<iostream>
#include<math.h>

using namespace std; 

bool testEquiv(int x, int y)
{
	/*
	objective: to check whether two cards belong to same account.
	
	Input variables: x- account no for card 1, y- account no for card 2
	
	Return value: boolean value
	*/

	if(x==y) 
		return true;
	else
		return false;
}

int frequency(int card, int cards[], int n)
{
	/*
	objective: To calculates the number of cards associated to same account.
	Input variables: card, account no of card, cards: array of cards
	Return value: same account cards iated to same account as that of the card passed to this function.
	*/

	int count=0;
	for(int i=0; i<n; i++)
	{
		if(testEquiv(cards[i],card))
			count++;
	}
	return count;
}

int majority_card(int cards[], int n) 
{
	/*
	objective:  account which has more than n/2 cards asociated to it.
	Input variables: cards- array of cards, n - total no of cards
	Return value: account no of majority of cards or -1 otherwisey card	
	*/

	// if there is only one card, it is majority in itself
	if(n==1) 				
		return cards[0];
	int left_majority_freq;
	int right_majority_freq;
	int left_majority_card;
	int right_majority_card;
	int mid = floor(n/2);	
	int *left_subcards = new int[mid];
	int *right_subcards = new int[n - mid];

	for(int i = 0; i < mid; i++)
		left_subcards[i] = cards[i];
	int j = 0;
	for(int i = mid; i < n; i++)
		right_subcards[j++] = cards[i];
	
	//recursive calls
	left_majority_card = majority_card(left_subcards,mid);
	right_majority_card = majority_card(right_subcards,n-mid);
	
	if(equivalenceTester(left_majority_card, right_majority_card)) 
		return left_majority_card;
	
	left_majority_freq = frequency(left_majority_card, cards, n);
	right_majority_freq = frequency(right_majority_card, cards, n);

	if(left_majority_freq > mid) 
		return left_majority_card;
	if(right_majority_freq > mid) 
		return right_majority_card; 
	return -1;
}

//main function
int main() 
{
	int *bankcards, no_cards;
	while(true){	
		cout<<"\nEnter number of cards: ";
		cin>>no_cards;
		if(no_cards>=1)
			break;
		cout<<"\nNumber of card should be atleast 1!";
	}

	bankcards = new int[no_cards];
	
	for(int i=0; i<no_cards; i++)	
	{	
		cout<<"\n\nEnter account number for card "<<i+1<<" : ";
		cin>>bankcards[i];
	}

	//test whether there is a majority card in given bankcards
	if(majority_card(bankcards, no_cards) != -1)
		cout<<"\n\nThere is a majority card. \n";
	else		
		cout<<"\n\nThere is not any majority card. \n";	
	return 0;
}