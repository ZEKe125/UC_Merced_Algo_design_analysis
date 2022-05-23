#include <iostream>

#define MAX_INT 2147483647

using namespace std;


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

  // implemet insertion sort
  
  
  int num;
  int j = 0;
  for (int i = 1; i < arraySize; i++)
    {
        num = Sequence[i];
        j = i;
        while(j >= 0 && Sequence[j-1] > num){
            
            Sequence[j] = Sequence[j-1];
            j--;
            
        }
         Sequence[j] = num;
        
        
          // output
        for ( int x = 0; x <= i; x++) {
        cout << Sequence[x] << ";" ;
        
        }
        cout << endl;
    }

  


  // Free allocated space
  delete[]Sequence;

}

