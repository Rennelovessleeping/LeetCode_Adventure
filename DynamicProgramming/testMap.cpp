/**************************************************************************
 * File Name : testMap.cpp
 *
 * Purpose :
 *
 * Creation Date : 01-01-2017
 *
 * Last Modified : Sun Jan  1 15:36:30 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
#include <iostream>
#include <map>
#include <unordered_map>
#include <utility>
#include <vector>
 
using namespace std;
 
int main()
{	
	int maxChoosableInteger = 20;
	int key = (1 << maxChoosableInteger)-1; 
	cout << key << endl;
	cout << bitset<8*sizeof(key)>(key) << endl;

	return 0;
	
}
