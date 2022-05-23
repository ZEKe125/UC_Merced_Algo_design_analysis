#include <iostream>
#include <map>
 
using namespace std;

 
int main(void) {

  // hash and hash iterator
  map<pair<int, int>, int> h;
   map<pair<int, int>, int> set;
  map<pair<int, int>, int>::iterator it;
  map<pair<int, int>, int>::iterator it2;

  //declare variables
  int num, num1 , num2;
  int maxCoorSum = -1;
  
  // read in number of pairs
  cin >> num;
  
  //read in all the pairs
  // add them to a hash
  for ( int i = 0; i < num; i++){
     cin >> num1;
     cin >> num2;
     pair<int,int> pt1 = make_pair(num1, num2);
     pair<pair<int,int>, int> new_e = make_pair(pt1, num1 + num2);
     h.insert(new_e);
  }
// use for loop to iterate throught the pairs in the hash map
 for (it = h.begin(); it != h.end(); ++it) {
      // search for first case of diagonal 
     it2 = h.find(make_pair<int, int>(it->first.first - 1 , it->first.second - 1 ));	
     if (it2 != h.end()){
          // insert new pair into set bc it has a diagonal
          pair<int,int> pt1 = make_pair(it->first.first,it->first.second);
          pair<pair<int,int>, int> new_e = make_pair(pt1, it->first.first + it->first.second);
          set.insert(new_e);
          // check if max needs to be updated
          if (it->first.first + it->first.second > maxCoorSum){
               maxCoorSum = it->first.first + it->first.second;
               //cout << maxCoorSum;
          }
     }
     //search for second case of diagonal 
     it2 = h.find(make_pair<int, int>(it->first.first + 1 , it->first.second + 1 ));	
     if (it2 != h.end()){
          // insert new pair into set bc it has a diagonal
          pair<int,int> pt1 = make_pair(it->first.first,it->first.second);
          pair<pair<int,int>, int> new_e = make_pair(pt1, it->first.first + it->first.second);
          set.insert(new_e);
          // check if max need to be updated
          if (it->first.first + it->first.second > maxCoorSum){
               maxCoorSum = it->first.first + it->first.second;
          }
     }     

     
  }

  cout << maxCoorSum; 
  
  //it2 = h.find(make_pair<int, int>(3, 2));	
  //if (it != h.end())
  //  cout << "(" << it->first.first << "," << it->first.second << ") exists and its coordinate sum is " << it->second << endl;
  //else
  //  cout <<  "(" << it->first.first << "," << it->first.second << ") doesn't exist)"<<endl;


  return 0;

}

