#include <iostream>
#include <cmath>
using namespace std;


int digitAtIndex(int index){
    
	
	
	if(index<=0)
		return 0;;
	
	int sum=0,digit=0,preSum;
	while(sum<index){
	    digit++;
		preSum=sum;
		sum+=digit*((int)(pow(10,digit)-pow(10,digit-1)));
	}
	sum=preSum+1;
	//cout<<"digit is: "<<digit<<endl;
	//cout<<"sum is: "<<sum<<endl;
	int temp=index-sum;
	//cout<<"temp is: "<<temp<<endl;
	int tempModel=temp%digit;
	
	int tempNum=(int)pow(10,digit-1)+temp/digit;
	//cout<<"number is: "<<tempNum<<endl;
	
	int i=0;
	
	
	for(i=0;i<tempModel;i++){
	    tempNum%=(int)pow(10,digit-i-1);
	}
	//cout<<tempNum/((int)pow(10,digit-1-i))<<endl;
	return tempNum/((int)pow(10,digit-i-1));
	

}

void test(const char* testName, int inputIndex, int expectedOutput)
{
	if(digitAtIndex(inputIndex) == expectedOutput)
		cout << testName << " passed." << endl;
	else
		cout << testName << " FAILED." << endl;
}


int main()
{
	test("Test1", 0, 0);
	test("Test2", 1, 1);
	test("Test3", 9, 9);
	test("Test4", 10, 1);
	test("Test5", 189, 9);  // 数字99的最后一位，9
	test("Test6", 190, 1);  // 数字100的第一位，1
	test("Test7", 1000, 3); // 数字370的第一位，3
	test("Test8", 1001, 7); // 数字370的第二位，7
	test("Test9", 1002, 0);
	test("Test10", 5681, 7); 
	test("Test11", 2890, 1); 
	test("Test12", 2891, 0); 
	test("Test13", 2892, 0); 
	test("Test14", 2893, 0); 
	return 0;
}
