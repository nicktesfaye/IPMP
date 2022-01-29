#include<iostream>
#include<vector>
using namespace std;



main(){
	int n,m;
	bool col=false;
	cin>>n>>m;
	
	int arr[n][m];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>arr[i][j];
			
	for(int i=0;i<n;i++){
		if(arr[i][0]){
			col=true;
			break;}
	}

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(arr[i][j]==1){
				arr[i][0]=1;
				arr[0][j]=1;
			}
	
	for (int i = 1; i < n; i++) {
      	for (int j = 1; j < m; j++) {
        	if (arr[i][0] == 1 || arr[0][j] == 1) {
          		arr[i][j] = 1;
        	}
      	}
    }
    
    if (arr[0][0] == 1) {
    	for (int j = 0; j < m; j++) {
        	arr[0][j] = 1;
      	}
    }

    if (col) {
      for (int i = 0; i < n; i++) {
        arr[i][0] = 1;
      }
    }

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cout<<arr[i][j]<<" ";
		cout<<endl;
}
}
