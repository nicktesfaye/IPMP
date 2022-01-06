#include <iostream>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    // Here we define two pointers to the array -> start =
    // 0, end = n-1 Two variables to take care of sum ->
    // left_sum = 0, right_sum = 0
    int i = 0, start = 0, end = n - 1;
    long long left_sum = 0,right_sum = 0;

    for (i = 0; i < n; i++) {

        if (start == end && right_sum == left_sum)
            return start+1;

        if (start == end)
            return -1;

        if (left_sum > right_sum) {
            right_sum += a[end];
            end--;
        }

        else if (right_sum > left_sum) {
            left_sum += a[start];
            start++;
        }

        else {
            right_sum += a[end];
            end--;
        }
    }

    if (!i) {
        return 1;
    }
}

};

// { Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
