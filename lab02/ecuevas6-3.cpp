#include <iostream>

#define MAX_INT 2147483647

using namespace std;


void
Merge (int *A, int first, int middle, int last)
{


//int first, middle, last;
// first = 0; 
// middle = (arraySize/2);
// if (arraySize%2 != 0){
//     middle++;
// }
// last = arraySize - 1;

  int n1 = middle - first + 1;
  int n2 = last - middle;
  int *L;
  int *R;
  L = new int[n1];
  R = new int[n2];
  int i, j, k;

  //cout << n1 << "  = n1 ]" << endl ;  
  //cout << n2 << " = n2 " << endl ;



  // input values for LEFT array

  for (i = 0; i < n1; i++)
    {

      L[i] = A[first + i];
      //cout << L[i] << " = L[ " << i << " ]" << endl ;

    }



  // input values for RIGHT array

  for (j = 0; j < n2; j++)
    {

      R[j] = A[j + (middle + 1)];
      //cout << R[j] << " = R[ " << j << " ]" << endl ;

    }


  k = 0;
  i = 0;
  j = 0;

  // Sort Left and right arrays into final array
  for (k = first; i < n1 && j < n2 && k < last; k++)
    {

      if (L[i] <= R[j])
	{
	  A[k] = L[i];
	  i++;
	}
      else
	{
	  A[k] = R[j];
	  j++;
	}
    }

  // loops to handle leftover element
  while (i < n1)
    {
      A[k] = L[i];
      i++;
      k++;
    }
  while (j < n2)
    {
      A[k] = R[j];
      j++;
      k++;
    }

}



void
MergeSort (int *A, int first, int last)
{

  int middle;
  if (first < last)
    {

      middle = (first + (last - 1)) / 2;
      MergeSort (A, first, middle);
      MergeSort (A, middle + 1, last);
      Merge (A, first, middle, last);

    }


}





int
main (int argc, char **argv)
{

  int *Sequence;
  int arraySize = 1;

  // Get the size of the sequence
  cin >> arraySize;
  Sequence = new int[arraySize];

  // Read the sequence
  for (int i = 0; i < arraySize; i++)
    cin >> Sequence[i];


  // Call Merge Sort

  MergeSort (Sequence, 0, arraySize - 1);


  // output
  for (int x = 0; x < arraySize; x++)
    {
      cout << Sequence[x] << ";";

    }
  //cout << endl;



  // Free allocated space
  delete[]Sequence;

  return 0;

}

