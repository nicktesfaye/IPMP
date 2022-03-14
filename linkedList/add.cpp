#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	vector<int> findSum(vector<int> &a, vector<int> &b) {
	    int carry=0;
	    vector<int> v;
	    auto aa=a.rbegin();
	    auto bb=b.rbegin();
        while(aa!=a.rend() && bb!=b.rend()){
             v.insert(v.begin(),(*aa + *bb +carry )%10);
            carry=(*aa + *bb + carry)/10;
            aa++;
            bb++;
           
        }
        while(aa!=a.rend()){
            v.insert(v.begin(),(*aa +carry )%10);
            carry=(*aa + carry)/10;
            aa++;
             
        }
        while(bb!=b.rend()){
            v.insert(v.begin(),(*bb +carry )%10); 
            carry=(*bb + carry)/10;
            bb++;
            
        }
        if(carry>0)
        v.insert(v.begin(),carry);
        return v;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        Solution ob;
        auto ans = ob.findSum(a, b);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends
