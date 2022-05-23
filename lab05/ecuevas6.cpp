
#include <iostream>

#define MAX_INT 2147483647

using namespace std;



void print(int ** Sequence, int numberOfVectors) {
     
     for (int x = 0; x < numberOfVectors; x++){
          for (int j = 0; j < 10; j++){
               cout << Sequence[x][j] << ";";
          }
          cout << endl;
          
     }
}
// get max value in array
int getK (int ** A, int numberOfVectors, int col)
{
      //initialize temp_arr
          int temp_arr[numberOfVectors];
          for (int i = 0; i < numberOfVectors; i++){
               temp_arr[i] = 0;
          }
           // load up temp_arr with A's values
          for (int row = 0; row < numberOfVectors; row++){
               temp_arr[row] = A[row][col];
               
          }
          // print temp_arr
          // cout << "temp_arr[] = col " << col << endl;
          // for (int i = 0; i < numberOfVectors; i++){
          //     cout << temp_arr[i] << ";";
          // }
          // cout << endl;
          
    int max = A[0][col];
    for (int i = 1; i < numberOfVectors; i++)
        if (A[i][col] > max)
            max = A[i][col];
    return max;
}


void
CountingSort (int **A, int col, int k, int numberOfVectors)
{
   // initialize new 2d array to work    
  int **B;
  B = new int *[numberOfVectors];
  for (int i = 0; i < numberOfVectors; i++){
      B[i] = new int[10];
    }
    
  //cout << "CountingSort call1: " << endl;
  
  // initialize C[k] array
  
  int *C;
  C = new int[k + 1];
  for (int i = 0; i <= k; i++){
      C[i] = 0;
    }
    
  //cout << "CountingSort call2: " << endl;
  
  for (int j = 0; j < numberOfVectors; j++){
      C[A[j][col]] = C[A[j][col]] + 1;
      //cout << " C[A[j][col]] = " << C[A[j][col]] << endl;
      //cout << " A[j][col] = " << A[j][col] << endl;
  }
  
  //cout << "CountingSort call3: " << endl;
  
  //C[i] now contains the number of elements equal to i
  
  for (int i = 0; i <= k; i++){
      C[i] = C[i] + C[i - 1];
      
    }

  //C[i] now contains the number of elements less than or equal to i
  
    
     for (int row = numberOfVectors - 1 ; row >= 0; row--){  
          
          for (int col_num = 9; col_num >= 0; col_num--){
               //cout << " C[ A[row][col]] = " << C[A[row][col]] << endl;
               //offset index for B
               int index = C[A[row][col]] - 1 ;
               B[index][col_num] = A[row][col_num];
               

          }
          C[A[row][col]] = C[A[row][col]] - 1;
          
          
     }
     // copying B into A;
     for ( int row = 0; row < numberOfVectors; row++){
          for (int column = 0; column < 10; column++){
               A[row][column] = B[row][column];
          }
     }
     

}

void radixSort ( int **A, int elements, int numberOfVectors ) {
     
     for (int col = elements - 1; col >= 0; col--){
         
          
         // cout << "CountingSort call: " << endl;
          int k = getK(A,numberOfVectors, col);
         // cout << "printink k = " << k << " in col " << col << endl; 
          CountingSort (A, col, k, numberOfVectors);
        //  cout << "after CountingSort call: " << endl;
     }
}




int main (int argc, char **argv) {

// initialize helpful variable

  int numberOfVectors = 0;
  int elements = 10;

// Get the size of the sequence

  cin >> numberOfVectors;
  int **Sequence;

  Sequence = new int *[numberOfVectors];
  for (int i = 0; i < numberOfVectors; i++)
    {
      Sequence[i] = new int[elements];
    }


// Read the sequence

  for (int i = 0; i < numberOfVectors; i++)
    {

      for (int j = 0; j < elements; j++)
	{
	  cin >> Sequence[i][j];
	  if (!(Sequence[i][j] <= 3 && Sequence[i][j] >= 0))
	    {
	      Sequence[i][j] = 0;
	      j--;
	    }
	}
    }
  // Call radix Sort
  //  cout << "radixSortgSort call: " << endl;
  radixSort (Sequence, elements, numberOfVectors);
  //  cout << "after radixSortgSort call: " << endl;
  // output

 print(Sequence, numberOfVectors);



// Free allocated space

  delete[]Sequence;

  return 0;

}



