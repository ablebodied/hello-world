//Problem in Tencent interview
//a series of coin,coin value pow of 2,each value has two coin, 
//give a number ,calculate the number of the combination that sum equals the number
//Sample:  Input:6  Output:3
//         Input:8  Output:4

#include <iostream>
using namespace std;

int main()
{
    int count=1,numPart=0;
	int n=21;
	int i=0;
	int numZero=0,numOne=0;
	while(i<32){
	    numZero=i;
	    while(((n>>i)&1)!=0&&i<32)
			numZero=++i;
		if(numZero==32)
			break;
		cout<<"Zero:  "<<numZero<<endl;
		numOne=i;
		while(((n>>i)&1)!=1&&i<32)
			numOne=++i;
		if(numOne==32)
			break;
		cout<<"One:  "<<numOne<<endl;
		numZero=numOne-numZero;
		int zeroOne=i;
		while(((n>>i)&1)!=0&&i<32)
			zeroOne=++i;
		numOne=zeroOne-numOne;
		numPart++;
		count=count*(numZero*numOne+1);
		
	}
	if(numPart>0)
		count+=numPart-1;
	
	cout<<count;
	
   return 0;
}
