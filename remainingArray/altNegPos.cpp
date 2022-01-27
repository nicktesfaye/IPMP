#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    vector<int> p,ne;
	    
	    for(int i=0;i<n;i++)
	        if(arr[i]<0)
	            ne.push_back(arr[i]);
	        else
	            p.push_back(arr[i]);
	            
	   auto a=p.begin(),b=ne.begin();
	   int i=0;
	   while(a!=p.end() && b!= ne.end() && i<n){
            if(i%2==0){
                arr[i++]=*a;
                a++;
            }
            else{
                arr[i++]=*b;
                b++;
            }
                
	   }
	   
	   while(a!=p.end()){
	       arr[i++]=*a;
	       a++;
	   }
	   	   while(b!=ne.end()){
	       arr[i++]=*b;
	       b++;
	   }
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends
