#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
        vector <int> rotate (int n, int d)
        {   unsigned short int y = 1<<15,temp,num=n;
            vector<int>v;
            for(int i=0;i<d;i++){
                temp = (num & y);
                num<<=1;
                if(temp)
                num|=1;
            }
            v.push_back(num);
            num=n;
            for(int i=0;i<d;i++){
                temp = (num & 1);
                num>>=1;
                if(temp)
                num|=y;
            }
            v.push_back(num);
            
            return v;
        }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends
