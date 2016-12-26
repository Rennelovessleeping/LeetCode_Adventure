/**************************************************************************
 * File Name : 415-AddTwoStrings.cpp
 *
 * Purpose :
 *
 * Creation Date : 25-12-2016
 *
 * Last Modified : Sun Dec 25 18:12:46 2016
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    string addStrings(string num1, string num2) {
        
        //num1 = "999";
        //num2 = "1";
        
        string::reverse_iterator itr1=num1.rbegin(); //
        string::reverse_iterator itr2=num2.rbegin();
        int len_itr = min(num1.size(), num2.size());
        int d1, d2, d;
        int carry=0;
        string sum;
        
        for(int i=0;i<len_itr;i++){
            d1 = *itr1 - '0';
            d2 = *itr2 - '0';
            sum.insert(sum.begin(), (d1+d2+carry)%10 + '0');
            if((d1 + d2 + carry)/10) carry = 1;
            else carry = 0;
            itr1++;
            itr2++;
        }
        
        if(itr1!=num1.rend() || itr2!=num2.rend()){
            string::reverse_iterator  itr = itr1!=num1.rend() ? itr1 : itr2;
            len_itr = num1.size() > num2.size() ? num1.size()-num2.size() : num2.size()-num1.size();
            
            for(int i=0;i<len_itr;i++){
                d = *itr -'0';
                //cout << d << endl;
                sum.insert(sum.begin(), (d+carry)%10 + '0');
                if((d + carry)/10) carry = 1;
                else carry = 0;
                itr++;
            }
            
            
        }
        
        if(carry) sum.insert(sum.begin(), '1');
        return sum;
    }
};

// Refine
class Solution {
public:
    string addStrings(string num1, string num2) {
        
        string::reverse_iterator itr1=num1.rbegin(); 
        string::reverse_iterator itr2=num2.rbegin();
        int d1, d2, d;
        int carry=0;
        string sum;
        
        for(int i=num1.size()-1,j=num2.size()-1;i>=0||j>=0||carry;i--,j--){
            d = carry;
            if(i>=0) { d1 = num1[i] - '0'; d += d1;}
            if(j>=0) { d2 = num2[j] - '0'; d += d2;}
            sum.insert(sum.begin(), d%10 + '0');
            carry = d/10;
        }
        
        return sum;
    }
};
