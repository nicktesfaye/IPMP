// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{

    public:
        int closestToZero(int arr[], int n)
        {
        	sort (arr, arr + n);
        	int l = 0, r = n - 1;
        	int sum = arr[l] + arr[r]; 
        	int diff = abs (sum);
        
        	while (l < r)
        	{
        		if (arr[l] + arr[r] == 0) 
        			return 0;
        		if (abs (arr[l] + arr[r]) < abs (diff))
        		{
        			diff = (arr[l] + arr[r]);
        			sum = arr[l] + arr[r];
        		}
        		else if(abs (arr[l] + arr[r]) == abs (diff))
                {
                    sum=max(sum,arr[l]+arr[r]);
                }

        		if (arr[l] + arr[r] > 0)
        			r--;
        		else
        			l++;
        	}
        	return sum;
        }
};

// { Driver Code Starts.
int main ()
{
    int t; 
    cin >> t;
    while (t--)
    {
        int n; 
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.closestToZero(arr, n) << endl;
    }
}  // } Driver Code Ends
