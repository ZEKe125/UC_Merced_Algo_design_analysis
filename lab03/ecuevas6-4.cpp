#include <iostream>

#define MAX_INT 2147483647

using namespace std;


int
MaxCrossSubArrSum (int *A, int low, int middle, int high)
{

  int leftSum = -1 * MAX_INT;
  int sum = 0;
  int maxLeft;

  for (int i = middle; i >= low; i--)
    {
      // cout << "A[" << i << "] = " << A[i] << endl ;
      sum = sum + A[i];
      //cout << "sum " << sum << endl ;
      //cout << "leftSum " << leftSum << endl ;

      if (sum > leftSum)
	{
	  leftSum = sum;
	  //  cout << "leftSum " << leftSum << endl ;
	  maxLeft = i;

	}

    }

  int rightSum = -1 * MAX_INT;
  int maxRight;
  sum = 0;

  for (int j = middle + 1; j <= high; j++)
    {
      // cout << "A[" << j << "] = " << A[j] << endl ;
      sum = sum + A[j];
      //    cout << "sum " << sum << endl ;
      //  cout << "rightSum " << rightSum << endl ;

      if (sum > rightSum)
	{

	  rightSum = sum;
	  //cout << "rightSum " << rightSum << endl ;
	  maxRight = j;
	}

    }
  //cout << "leftSum " << leftSum << endl ;
  // cout << "rightSum " << rightSum << endl ;

  return leftSum + rightSum;

}



int
MaxSubArrSum (int *A, int low, int high)
{


  if (high == low)
    {
      return A[low];
    }
  else
    {
      int middle;
      int rightSum;
      int leftSum;
      int crossSum;
      middle = (low + high - 1) / 2;
      rightSum = MaxSubArrSum (A, low, middle);
      leftSum = MaxSubArrSum (A, middle + 1, high);
      crossSum = MaxCrossSubArrSum (A, low, middle, high);
      if (leftSum >= rightSum && leftSum >= crossSum)
	{
	  return leftSum;
	}
      else if (rightSum >= leftSum && rightSum >= crossSum)
	{
	  return rightSum;
	}
      else
	return crossSum;
    }

}


int
main (int argc, char **argv)
{

  int *Sequence;
  int arraySize = 1;
  int result;

  // Get the size of the sequence
  cin >> arraySize;
  Sequence = new int[arraySize];

  // Read the sequence
  for (int i = 0; i < arraySize; i++)
    {
      cin >> Sequence[i];
    }


  result = MaxSubArrSum (Sequence, 0, arraySize - 1);

  // output
  cout << result ;



  // Free allocated space
  delete[]Sequence;

  return 0;

}
