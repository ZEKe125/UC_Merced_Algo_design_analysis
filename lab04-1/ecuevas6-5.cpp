
#include <iostream>
  
#define MAX_INT 2147483647
  
using namespace std;

 
 
 
void MaxHeapify (int *A, int i, int heapSize){
  /*Root:A[1]
Parent of A[i] :        A[ i / 2 ]
Left Child of A[i] :    A[ 2i ]
Right Child of A[i] :   A[ 2i + 1 ]
*/
 
    int largest = i;
    int temp;
    int l = 2 * i;
    int r = 2 * i + 1;
  
 
 
    if (l < heapSize && A[l] > A[i]){
        largest = l;
    }
    else{
        largest = i;
        
    }
    if (r < heapSize && A[r] > A[largest]){
        largest = r;
        
    }
    if (largest != i){
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        MaxHeapify (A, largest, heapSize);
    }

} 
 
    
    void BuildMaxHeap (int *A, int heapSize) {

        for (int i = heapSize / 2; i >= 0; i--){
            MaxHeapify (A, i, heapSize);
        
        } 
    } 
    
 

 
void HeapSort( int* A, int arraySize ){
    
    int heapSize; 
    heapSize = arraySize - 1;

    BuildMaxHeap(A, heapSize );
    for( int i = arraySize - 1 ; i >= 0 ; i--){
        
        int temp = A[i];
        A[i] = A[0];
        A[0] = temp;
        heapSize--;
        MaxHeapify (A, 0, heapSize); 
        
    }
    
} 
 
 
 
 
int main (int argc, char **argv) {
  
    int *Sequence;
    int arraySize = 1;
  
// Get the size of the sequence

    cin >> arraySize;
    Sequence = new int[arraySize];

// Read the sequence

    for (int i = 0; i < arraySize; i++)
        cin >> Sequence[i];
  
 // Call HEAP Sort
    
    HeapSort (Sequence, arraySize);
  
 // output
    
    for (int x = 0; x < arraySize; x++){
        cout << Sequence[x] << ";";
    } 

//cout << endl;
    
 
// Free allocated space
    
    delete[]Sequence;
  
return 0;

}


 
 
 
