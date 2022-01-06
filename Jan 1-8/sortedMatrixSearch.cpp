//Initial Template for C

#include <stdio.h>


 // } Driver Code Ends
//User function Template for C

int matSearch (int N, int M, int matrix[][M], int x)
{
   int i=0,j=M-1;
   
   if (x < matrix[0][0] || x > matrix[N-1][M-1])
        return 0;
        
   while(i<N && j>=0){
       if(matrix[i][j]==x)
            return 1;
        else if(matrix[i][j]<x)
            i++;
        else if(matrix[i][j]>x)
            j--;
   }
   return 0;
}

// { Driver Code Starts.

int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--)
	{
        int n, m;
		scanf("%d", &n);
		scanf("%d", &m);
		int matrix[n][m];
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				scanf("%d", &matrix[i][j]);
			}
		}
		   
		int x;
		scanf("%d", &x);
		
        int result = matSearch (n, m, matrix, x);
        printf("%d", result);
		printf("\n");
    }
    return 0;
}
  // } Driver Code Ends
