/**************************************************************************
 * File Name : 166-FractionToRecurringDecimal.cpp
 *
 * Purpose :
 *
 * Creation Date : 27-01-2017
 *
 * Last Modified : Fri Jan 27 23:23:47 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
ass Solution {
public:
    string fractionToDecimal(long numerator, long denominator) {
        
        if(numerator==0) return "0";
        
        string res = (numerator<0 ^ denominator<0) ? "-" : "";
        if(numerator<0) numerator = -numerator;
        if(denominator<0) denominator = -denominator;
        
        long rem = numerator % denominator, quot = numerator/denominator;
        res += to_string(quot);
        if(rem==0) return res;
        res += ".";
        
        unordered_map<int,int> decimal_map;
        
        for(long r=numerator%denominator; r>0; r%=denominator){
            if (decimal_map.count(r) > 0){
                // repeated patterns started with digit that has already ocurred.
                res.insert(decimal_map[r],1,'(');
                res += ")";
                break;
            }
            decimal_map[r] = res.size(); // remember the possible pos for (;
            r *= 10; // raise up by 1 digit;
            res += to_string(r/denominator);
        }
        
        return res;
    }
};
