/**************************************************************************
 * File Name : testSet.cpp
 *
 * Purpose :
 *
 * Creation Date : 21-12-2016
 *
 * Last Modified : Wed Dec 21 20:56:42 2016
 *
 * Created By :  
**************************************************************************/

// set_intersection example
#include <iostream>     // std::cout
#include <algorithm>    // std::set_intersection, std::sort
#include <vector>       // std::vector

int main () {
  int first[] = {5,10,15,20,25,20,20,10};
  int second[] = {50,40,30,20,10,10,10};
  std::vector<int> v(10);                      // 0  0  0  0  0  0  0  0  0  0
  std::vector<int>::iterator it;

  std::sort (first,first+8);     //  5 10 15 20 25
  std::sort (second,second+7);   // 10 20 30 40 50

  it=std::set_intersection (first, first+8, second, second+7, v.begin());
                                               // 10 20 0  0  0  0  0  0  0  0
  v.resize(it-v.begin());                      // 10 20

  std::cout << "The intersection has " << (v.size()) << " elements:\n";
  for (it=v.begin(); it!=v.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
