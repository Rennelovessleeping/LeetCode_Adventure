/**************************************************************************
 * File Name : GitCommit.cpp
 *
 * Purpose :
 *
 * Creation Date : 17-10-2017
 *
 * Last Modified : Tue Oct 17 22:55:34 2017
 *
 * Created By :  Renee Bai
**************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

struct GitNode{
    int id;
    vector<GitNode*> parent;
    GitNode(int id): id(id) {}
};

class GitCommit {
    vector<GitNode*> findAllCommits(GitNode* node) {
        vector<GitNode*> res;
        queue<GitNode*> q;
        unordred_set<GitNode*> visited;

        q.push(node);
        visited.insert(node);

        while(!q.empty()) {
            auto tmp = q.front(); q.pop();
            res.push_back(tmp);
            for(auto nebr:tmp->parent) {
                if(!visited.count(nebr)) {
                    q.push(nebr);
                    visited.insert(nebr);
                }
            }
        }

        return res;
    }


    GitNode* findLCA(GitNode* node1, GitNode* node2) {
        // Bidirectinal BFS to detect the collision node
        if(!node1 || !node2) return nullptr;

        queue<GitNode*> q1, q2;
        q1.push(node1);
        q2.push(node2);

        unorderd_set<GitNode*> s1, s2;
        s1.insert(node1);
        s2.insert(node2);
        
        while(!q1.empty() && !q2.empty()) {
            int len1 = q1.size();
            for(int i=0; i<len1; i++) {
                auto tmp = q1.front();
                for(auto nebr: tmp->parent) {
                    if(s2.count(nebr)) return nebr;
                    else if(!s1.count(nebr)) {
                        q1.push(nebr);
                        s1.insert(nebr);
                    }
                }
            }

            int len2 = q2.size();
            for(int i=0; i<len2; i++) {
                auto tmp = q2.front();
                for(auto nebr: tmp->parent) {
                    if(s1.count(nebr)) return nebr;
                    else if(!s2.count(nebr)) {
                        q2.push(nebr);
                        s2.insert(nebr);
                    }
                }
            }
        }


        return nullptr;
    }
};

int main(){
}
