/**************************************************************************
 * File Name : 119-PascalsTriangleII.cpp
 *
 * Purpose :
 *
 * Creation Date : 22-12-2016
 *
 * Last Modified : Thu Dec 22 19:28:36 2016
 *
 * Created By :  
**************************************************************************/
// Utilize the symmetry of Pascal's triangle
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        if (rowIndex==0) return vector<int> {1};
        
        int i,j;
        vector<int> kthRow;
        vector<int> previousRow={1};
        for(i=1;i<=rowIndex;i++){
            kthRow.clear();
            for(j=i/2;j>=1;j--){
                kthRow.insert(kthRow.begin(), previousRow[j]+previousRow[j-1]); 
                kthRow.push_back(previousRow[j]+previousRow[j-1]);
            }
            
            kthRow.insert(kthRow.begin(), 1);
            kthRow.push_back(1);
            previousRow = kthRow;
            
        }
        
        if(rowIndex%2 ==0) kthRow.erase(kthRow.begin()+rowIndex/2);
       
        return kthRow;
        
    }
};

// Using single row to dynamically evolves the triangle;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        int i,j;
        vector<int> kthRow (rowIndex+1);
        kthRow[0] = 1;
        for(i=1;i<=rowIndex;i++){
            for(j=i;j>0;j--) kthRow[j] += kthRow[j-1];
        }
        
        return kthRow;
    }
};

