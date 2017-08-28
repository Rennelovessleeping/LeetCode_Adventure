/**************************************************************************
 * File Name : 640-SolveTheEquation.cpp
 *
 * Purpose :
 *
 * Creation Date : 28-08-2017
 *
 * Last Modified : Mon Aug 28 15:26:03 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    string solveEquation(string equation) {
        int n = equation.size(), coeff = 0, sum = 0, sign = 1, i = 0;
        for(int j=0; j<n; j++) {
            if (equation[j] == '+' || equation[j] == '-') {
                if(j > i) sum += sign*stoi(equation.substr(i, j));
                i = j;
            }
            else if (equation[j] == 'x') {
                if (i == j || equation[j-1] == '+') coeff += sign;
                // j == i check the case when 'x' alone appears at the beginning of equation of right after '='
                else if (equation[j-1] == '-') coeff -= sign;
                else coeff += sign*stoi(equation.substr(i, j));

                i = j+1;
            }
            else if (equation[j] == '=') {
                if(j > i) sum += sign*stoi(equation.substr(i, j));
                sign = -1;
                i = j+1;
            }
        }

        // check whether there is a remaining number;
        if(i < n) sum += sign*stoi(equation.substr(i));

        if(coeff == 0 && sum == 0) return "Infinite solutions";
        else if(coeff == 0) return "No solution";
        else return "x=" + to_string(-sum / coeff);
    }
};
