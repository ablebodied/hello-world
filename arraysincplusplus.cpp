#include <stdio.h>  
#include <memory.h>  
#define size1 2  
#define size2 3  
#define size3 4  
int main()  
{  
       int *** arr;  
       int i,j,k;  
       /////////////////// 动态开辟 相当于arr[size1][size2][size3]  
       arr = new int**[size1];  
       for (i = 0; i < size1; i ++) {  
              arr[i] = new int*[size2];  
              for (j = 0; j < size2; j ++) {  
                     arr[i][j] = new int[size3];  
              }  
       }  
       /////////////////// 用for循环初始化  
       for (i = 0; i < size1; i ++) {  
              for (j = 0; j < size2; j ++) {  
                     for (k = 0; k < size3; k ++) {  
                            arr[i][j][k] = i * j * k;  
                     }  
              }  
       }  
       for (i = 0; i < size1; i ++) {  
              for (j = 0; j < size2; j ++) {  
                     for (k = 0; k < size3; k ++) {  
                            printf("i*j*k=%d*%d*%d=%d\n",i,j,k,arr[i][j][k]);  
                     }  
              }  
       }  
       /////////////////// 用memset，如果是静态int arr[][][]的话，直接memset(arr,0,sizeof(arr));数组初始化为0  
       for (i = 0; i < size1; i ++) {  
              for (j = 0; j < size2; j ++) {  
                     memset(arr[i][j],-1,sizeof(int) * size3);  
              }  
       }  
       for (i = 0; i < size1; i ++) {  
              for (j = 0; j < size2; j ++) {  
                     for (k = 0; k < size3; k ++) {  
                            printf("i,j,k=%d,%d,%d=%d\n",i,j,k,arr[i][j][k]);  
                     }  
              }  
       }  
       ///////////////////// 释放内存  
       for (i = 0; i < size1; i ++) {  
              for (j = 0; j < size2; j ++) {  
                     delete[] arr[i][j];  
              }  
              delete[] arr[i];  
       }  
       delete[] arr;  
       return 0;  
}  
