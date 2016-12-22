/**************************************************************************
 * File Name : testSet.cpp
 *
 * Purpose :
 *
 * Creation Date : 21-12-2016
 *
 * Last Modified : Wed Dec 21 22:47:28 2016
 *
 * Created By :  
**************************************************************************/
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main ()
{
  int myints[]={ 12,82,37,64,15,19,19,19,12 };
  std::set<int> first;
  first = std::set<int>(myints, myints+sizeof(myints)/sizeof(int));                 // and first is empty
  vector<int> second (myints, myints+sizeof(myints)/sizeof(int));
  for(auto const& a:first){
      cout << a << "---";
      cout << count(second.begin(), second.end(), a) << endl;
  }

  int a = '1' - '0';
  cout << a << endl;

  return 0;
}
