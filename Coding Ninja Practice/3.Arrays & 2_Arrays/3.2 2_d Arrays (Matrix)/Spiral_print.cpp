/*Spiral Print
Send Feedback
For a given two-dimensional integer array/list of size (N x M), print it in a spiral form. That is, you need to print in the order followed for every iteration:
a. First row(left to right)
b. Last column(top to bottom)
c. Last row(right to left)
d. First column(bottom to top)
 Mind that every element will be printed only once.
 
 Sample Input 1:
1
4 4 
1 2 3 4 
5 6 7 8 
9 10 11 12 
13 14 15 16
Sample Output 1:
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10 
*/
#include <iostream>
using namespace std;



int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int row, col;
        cin >> row >> col;
        int **matrix = new int *[row];

        for (int i = 0; i < row; i++)
        {
            matrix[i] = new int[col];
            for (int j = 0; j < col; j++)
            {
                cin >> matrix[i][j];
            }
        }
        spiralPrint(matrix, row, col);

        for (int i = 0; i < row; ++i)
        {
            delete[] matrix[i];
        }
        delete[] matrix;

        cout << endl;
    }
}

void spiralPrint(int **input, int nRows, int nCols)
{	int col_start = 0;
 	int col_end = nCols;
 	int row_start =0;
    int row_end = nRows;
   
 	
 	
 	while(row_start<row_end && col_start<col_end){
	 	
 		/* Print the first row from
               the remaining rows */
 		for(int count=col_start;count<col_end;count++){
        	cout<<input[row_start][count]<<" ";
	    }
		row_start++;
 
 		/* Print the last column
         from the remaining columns */
	 	for(int count=row_start;count<row_end;count++){
    	    cout<<input[count][col_end-1]<<" ";
    	}
 		col_end--;
 	
         /* Print the last row from
                the remaining rows */
 		if(row_start<row_end){
 			for(int count=col_end-1;count>=col_start;count--){
        		cout<<input[row_end-1][count]<<" ";
    		}
 			row_end--;
        }
 		
         /* Print the first column from
        		the remaining columns */
	 	if(col_start<col_end){
 			for(int count=row_end-1; count>=row_start ; count--){
        		cout<<input[count][col_start]<<" ";
	    	}
 			col_start++;
        }
	}
}
