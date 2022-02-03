#include <bits/stdc++.h>
using namespace std;

void printKMax(int *arr,int n,int k)
{
	int i,maxA=INT_MIN,maxB=INT_MIN,maxC=INT_MIN;
	//base condition
	//if no subarrays needs to be formed
	if(k==1||k==n)
	{
		for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
		return;
	}
	//traverse k elements to find
	//find second and third largest elements
	for(i=0;i<k;i++){
		if(maxA<arr[i])
		{
			maxC=maxB;
			maxB=maxA;
			maxA=arr[i];
		}
		else if(maxB<arr[i])
		{
			maxC=maxB;
		maxB=arr[i];
		}
		else if(maxC<arr[i])
		maxC=arr[i];
	}
	cout<<maxA<<" ";
	
	//traverse from remaining elements
	for(i=k;i<n;i++)
	{
		//reset first second and third largest elements
		//in response to new incoming elements
		if(maxA<arr[i])
		{
			maxC=maxB;
			maxB=maxA;
			maxA=arr[i];
		}
		else if(maxB<arr[i])
		{
			maxC=maxB;
		maxB=arr[i];
		}
		else if(maxC<arr[i])
		maxC=arr[i];
		
		//if the first biggest we earlier found
		//is matching from the element that
		//needs to be removed from the subarray
			if(arr[i-k]==maxA)
			{
				//reset first biggest to second and second to third
				maxA=maxB;
				maxB=maxC;
				}
				cout<<maxA<<" ";
		}
}

//drivers code
int main()
{
	int arr[]={1,5,2,7,8,4,7,2};
	int k=3;
	int n=sizeof(arr)/sizeof(arr[0]);
	printKMax(arr,n,k);
	return 0;
}
