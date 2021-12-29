#include<iostream>
#include<cstring>
#include<string>
#include <algorithm>


using namespace std;

int hammingDistance(int n1, int n2)
{
    int x = n1 ^ n2;
    //cout << x;
    int setBits = 0;
 
    while (x > 0) {
        setBits += x & 1;
        x = x >> 1;
        cout << x;
    }

 
    return setBits;
}
// int *noDuplicates(int *arr,int n)
// {
// 	sort(arr,arr+n);
// 	int a = n;
//   	for(int i =0 ;i < n;i++)
//   	{
//   		int h = count(arr,arr+n,arr[i]);
//   		if(h>1)
//   		{	
//   			int x = i+1;
//   			for(int j = i+h;j < n;j++)
//   			{	
//   				arr[x] = arr[j];
//   				x++;
//   			}

//   			n -= h-1;
//   		}
//   	}
//   	arr[a-1] =n; 

//   	return arr;
// }
// int houses[7] = {1,9,4,3,5,7,6};
// 	int S[7],max1 = 0;
// 	for(int i =0; i < 7;i++)
// 	{	
// 		//int max =  *max_element(S,S+i-2)
// 		if(i < 2)
// 		{
// 			max1 = 0;
// 		}else{
// 			max1 = *max_element(S,S+i-1);
// 		}
// 		S[i] = houses[i] + max1;

// 		//max1 = 
// 	}
// 	cout << *max_element(S,S+7);

int main()
{	
	int a[4] = {1,2,3,4} , k=3;
	int b[4];
	for(int i =0;i < 4;i++)
	{
		b[i] = a[i] %3;
		//cout << b[i] << " ";
	}
	for(int i = 0;i< 4;i++)
	{
		for(int j = i+1;j<4;j++)
		{
			if(b[j] < b[i])
			{
				int x = a[i];
				a[i] = a[j];
				a[j] = x;
				int y = b[i];
				b[i] = b[j];
				b[j] = y;
			}
		}
	}
	for(int i =0;i < 4; i++)
	{
		cout << a[i] << " ";
	}
}
