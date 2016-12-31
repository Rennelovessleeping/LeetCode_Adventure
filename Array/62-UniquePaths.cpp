/**************************************************************************
 * File Name : 62-UniquePaths.cpp
 *
 * Purpose :
 *
 * Creation Date : 28-12-2016
 *
 * Last Modified : Fri Dec 30 22:43:00 2016
 *
 * Created By :  Renne Bai
**************************************************************************/
// Math solution
class Solution {
public:
    int uniquePaths(int m, int n) {
        
        if(m<n) swap(m, n);
        int i,j=n-1;
        long int pathNum=1;
        
        for(i=1;i<=n-1;i++){
            pathNum *= (i+m-1);
            while(j>=0 && !pathNum%j) {pathNum /=j; j--;};
        }
        
        if(j) pathNum /= factorial(j);
        
        return pathNum;
        
    }
    
    long int factorial(int x){
        if (x==0) return 1;
        return x*factorial(x-1);
    }
    
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        
        //if(m<n) swap(m, n);
        int i,j;
        
        /*
        vector<vector<int>> pathNum(m, vector<int>(n,1));
        for(i=1;i<m;i++){
            for(j=1;j<n;j++){
                pathNum[i][j] = pathNum[i-1][j]+pathNum[i][j-1];
            }
        }
        return pathNum[m-1][n-1];
        */
        
        // Save space 1st
        vector<int> pathNum(m,1);
        vector<int> pre(m,1);
        for(j=1;j<n;j++){
            for(i=1;i<m;i++){
                pathNum[i] = pathNum[i-1]+ pre[i];
            }
            pre = pathNum;
        }
        return pathNum[m-1];
        
        // Save space 2nd
        /*
        vector<int> pathNum(m,1);
        for(j=1;j<n;j++){
            for(i=1;i<m;i++){
                pathNum[i] += pathNum[i-1]; 
            }
        }
        
        return pathNum[m-1];
        */
    }
    
};
