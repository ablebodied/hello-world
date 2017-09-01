// 面试题51：数组中的逆序对
// 题目：在数组中的两个数字如果前面一个数字大于后面的数字，则这两个数字组
// 成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。



#include <cstdio>
#include <string>
#include <iostream>

int InversePairsCore(int* data, int* copy, int start, int end);

int InversePairs(int* data, int length)
{
    if(data == nullptr || length < 0)
        return 0;

    int* copy = new int[length];
    for(int i=0;i<length;i++)
		copy[i]=data[i];
	int* copyData = new int[length];
    for(int i=0;i<length;i++)
		copyData[i]=data[i];
    int count = InversePairsCore( copy,copyData, 0, length - 1);
    delete[] copy;
    for(int i=0;i<length;i++)
		printf("%d    ",copyData[i]);
	//printf("\n");
    delete[] copyData;
	return count;
}

int InversePairsCore(int* dataCopy,  int* data, int start, int end)
{
     if(start==end){
	     data[start]=dataCopy[start];
		 return 0;
	 
	 }
	int halfLength=(end-start)/2;
	int middle=start+halfLength;
	int left=InversePairsCore(data,dataCopy,start,middle);
	int right=InversePairsCore(data,dataCopy,middle+1,end);
	int i=middle,j=end,count=0,k=end;
	while(i>=start&&j>=middle+1){
	    if(dataCopy[i]>dataCopy[j]){
			count+=j-middle;
			data[k--]=dataCopy[i--];
		}
		else{
		    data[k--]=dataCopy[j--];
		}
	}
	while(i>=start)
		   data[k--]=dataCopy[i--];
    while(j>middle)
		   data[k--]=dataCopy[j--];
		   
    return left+right+count;
}
//方法二 直接统计的方法 时间复杂度O（n2）
// 数组在方法一中已然被改变，所以方法二出错了！！！修改方法一 使得原数组不变
int PairReverseDirect(int* data,int length){
    int count=0;
	for(int i=0;i<length;i++)
		for(int j=i+1;j<length;j++){
		    if(data[i]>data[j]){
				count++;
				//std::cout<<"nihao  ";
			}
			//std::cout<<"buhao  ";
		}
	std::cout<<count<<std::endl;
	return count;
}

// ====================测试代码====================
void Test(std::string testName, int* data, int length, int expected)
{
    if(!testName.empty())
        printf("%s begins: ", testName.c_str());

    if(InversePairs(data, length) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
	if(PairReverseDirect(data, length) == expected)
        printf("Solution 2 passed.\n");
    else
        printf("Solution 2 failed.\n");
}

void Test1()
{
    int data[] = { 1, 2, 3, 4, 7, 6, 5 };
    int expected = 3;

    Test("Test1", data, sizeof(data) / sizeof(int), expected);
}

// 递减排序数组
void Test2()
{
    int data[] = { 6, 5, 4, 3, 2, 1 };
    int expected = 15;

    Test("Test2", data, sizeof(data) / sizeof(int), expected);
}

// 递增排序数组
void Test3()
{
    int data[] = { 1, 2, 3, 4, 5, 6 };
    int expected = 0;

    Test("Test3", data, sizeof(data) / sizeof(int), expected);
}

// 数组中只有一个数字
void Test4()
{
    int data[] = { 1 };
    int expected = 0;

    Test("Test4", data, sizeof(data) / sizeof(int), expected);
}


// 数组中只有两个数字，递增排序
void Test5()
{
    int data[] = { 1, 2 };
    int expected = 0;

    Test("Test5", data, sizeof(data) / sizeof(int), expected);
}

// 数组中只有两个数字，递减排序
void Test6()
{
    int data[] = { 2, 1 };
    int expected = 1;

    Test("Test6", data, sizeof(data) / sizeof(int), expected);
}

// 数组中有相等的数字
void Test7()
{
    int data[] = { 1, 2, 1, 2, 1 };
    int expected = 3;

    Test("Test7", data, sizeof(data) / sizeof(int), expected);
}

void Test8()
{
    int expected = 0;

    Test("Test8", nullptr, 0, expected);
}
void Test9()
{
    int expected = 5;
    int data[] = { 7,5,6,4 };
    Test("Test9", data, 4, expected);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
	Test9();

    return 0;
}
