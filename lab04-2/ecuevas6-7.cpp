
#include <iostream>

#define MAX_INT 2147483647

using namespace std;


int
partition (int *A, int first, int last)
{
  //pivot
  int x = A[last];
  int i = first - 1;
  int temp;

  for (int j = first; j < last; j++)
    {
      if (A[j] <= x)
	{
	  i++;
	  // swap
	  temp = A[j];
	  A[j] = A[i];
	  A[i] = temp;

	}

    }
  // swap
  int var = A[last];
  A[last] = A[i + 1];
  A[i + 1] = var;

  return i + 1;


}

int
RandPartition (int *A, int first, int last)
{
  // randon int in the range first to last
  int rand_i = rand () % (last - first) + first;
  // swap
  int var = A[last];
  A[last] = A[rand_i];
  A[rand_i] = var;

  return partition (A, first, last);

}






void
RandQuickSort (int *A, int first, int last)
{
  int q;
  if (first < last)
    {
      // RandPartition
      q = RandPartition (A, first, last);
      RandQuickSort (A, first, q - 1);
      RandQuickSort (A, q + 1, last);

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

  // Call RandQuickSort

  RandQuickSort (Sequence, 0, arraySize - 1);

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
