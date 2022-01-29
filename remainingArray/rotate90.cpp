// C++ program to turn an
// image by 90 Degree
#include <bits/stdc++.h>
using namespace std;

					

			
void displayMatrix(int const *arr,int r,int c)
{

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			cout << * (arr + i * c + j) << "\t";
		cout << "\n";
	}

	cout << "\n\n";
}

void rotate(int *pS,int *pD,int row,int col)
{
	int r, c;
	for (r = 0; r < row; r++)
		for (c = 0; c < col; c++)
			*(pD + c * row + (row - r - 1)) = *(pS + r * col + c);
}

 main()
{
	
	int image[][4] = {{1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12}};
	int *img,*ptr;
	int m, n;
a

	m = 3, n = 4, img = (int *)image;
	ptr = (int *)malloc(sizeof(int) * m * n);

	// process each buffer
	displayMatrix(img, m, n);

	rotate(img, ptr, m, n);

	displayMatrix(ptr, n, m);

	free(ptr);

}

// This code is contributed by rathbhupendra
