

#include <stdio.h>
#include <iostream>
#define MAX_INT 2147483647
using namespace std;


// made m and s global to avoid too much pointer passing confusion.
int** m;
int** s;


void PrintOptimalParents(int i, int j){
    
    if( i == j){
        cout << 'A' << i - 1;
        
    }
    else{
        cout << '(' ;
        PrintOptimalParents(i, s[i][j]);
        PrintOptimalParents(s[i][j] + 1, j);
        cout << ')';
        
    }
    
}
void MatrixChainOrder( int N, int* p){
    
     //cout << "made it " << endl;
    int n = N;
    // initialize m
    
    m = new int*[n];
    for (int i = 0; i < n; i++){
      m[i] = new int[n];
    }
    //cout << "made it " << endl;
    for(int i = 1; i < n; i++ ){
        m[i][i] = 0;
    }
    //cout << "made it " << endl;
    // initialize s
    s = new int*[n];
    for (int i = 0; i < n; i++){
      s[i] = new int[n];
    }
    
    //cout << "made it " << endl;
     int j, q;
     for(int l = 2; l < n; l++){
          //cout << "made it loop 1" << endl;
        
          for( int i = 1; i < n - l + 1 ; i++ ){
               
               //cout << "made it loop 2" << endl;
             
               j = i + l - 1; 
               m[i][j] = MAX_INT;
               //cout << "m[i][j] = "<< m[i][j] << endl;
            
               for(int k = i; k <= j - 1; k++ ){
                    //cout << "made it loop 3" << endl;
                      
                    q = m[i][k] + m[k + 1][j] + p[i - 1]*p[k]*p[j];
                    //cout << "made it loop 3.1" << endl;
                    
                    if(q < m[i][j]){
                         //cout << "made it loop 3.2" << endl;
                         
                         m[i][j] = q;
                         
                         //cout << "k = "<< k << endl;
                         //cout << "i = "<< i << endl;
                         //cout << "j = "<< j << endl;
                         //cout << "s[i][j]= "<< s[i][j] << endl;
                         s[i][j] = k;
                         //cout << "made it loop 3.3" << endl;
                         
                     }
            }
        }
    }
    
    // display matrix
     //cout << "matrix m : " << endl;
     //for( int x= 0; x < n ; x++){
     //    
     //     for(int y=0;y<n;y++){
     //        
     //          cout<<m[x][y] << ", "; 
     //     }
     //     cout<<endl;  
     //}
     
     
     //output 
     cout <<  m[1][n-1] << endl;
     PrintOptimalParents( 1 , n - 1);
     cout << endl;
     //cout << endl;
}

int main (int argc, char **argv) {
  
    int *Dimensions;
    int N = -1;
  
// Get the size of the sequence

    cin >> N;
    Dimensions = new int[N + 1];
    

// Read the Prices
    int x;
    for (int i = 0 ; i < N + 1 ; i++){
        cin >> x;
        Dimensions[i] = x ;
        //cout << Dimensions[i] << " ";
    }   
     //cout << endl;
 // Call MatrixChainOrder()
 
     MatrixChainOrder(N + 1 , Dimensions );
     
    
     
 
   
   
    
  
    
   
    
// Free allocated space
    
    delete[]Dimensions;
    
  
return 0;

}


