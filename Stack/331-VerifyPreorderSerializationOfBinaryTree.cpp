/**************************************************************************
 * File Name : 331-VerifyPreorderSerializationOfBinaryTree.cpp
 *
 * Purpose :
 *
 * Creation Date : 05-02-2017
 *
 * Last Modified : Sun Feb  5 12:58:31 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// O(n) solution using stack
ass Solution {
public:
    bool isValidSerialization(string preorder) {
    
        if(preorder=="#") return true;
        
        istringstream ss(preorder);
        string node;
        stack<string> s;
        
        getline(ss, node, ',');
        s.push(node);
        
        while(getline(ss, node, ',') ){
            if(node == "#") {
                while (!s.empty() && s.top() == "#"){
                    s.pop();
                    if(s.empty()) return false;
                    s.pop();
                }
                s.push("#");
            }
            else s.push(node);
        }
        
        return s.size() == 1 && s.top() == "#";
        
    }
};

// O(n) solution by calculating possible leaf numbers;
ass Solution {
public:
    bool isValidSerialization(string preorder) {
    
        if(preorder.empty()) return false;
        istringstream ss(preorder);
        string node;
        
        // leafNums is the number of possible leaf with current nodes included
        int leafNum = 1;
        while(getline(ss, node, ',') ){
            leafNum--;
            if(leafNum < 0) return false;
            if(node != "#") leafNum += 2;
        }
        
        return leafNum == 0;
        
    }
};
