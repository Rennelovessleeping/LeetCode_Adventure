/**************************************************************************
 * File Name : 355-DesignTwitter.cpp
 *
 * Purpose :
 *
 * Creation Date : 15-04-2017
 *
 * Last Modified : Sat Apr 15 02:09:15 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Twitter {
    
private:
    int time;
    struct Tweet {
        int time;
        int id;
        Tweet(int timeStamp, int tweetId): time(timeStamp), id(tweetId) {}
    };
    
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<Tweet>> tweetsRec;
    
public:
    
    /** Initialize your data structure here. */
    Twitter() {
        time = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweetsRec[userId].push_back(Tweet(time++, tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    typedef vector<Tweet>::reverse_iterator RIT;
    struct cmp{
        bool operator() (pair<RIT, RIT>& l, pair<RIT, RIT>& r) {return l.second->time < r.second->time;};
    };
    
    vector<int> getNewsFeed(int userId) {
        
        priority_queue<pair<RIT, RIT>, vector<pair<RIT, RIT>>, cmp> pq;
        
        
        for(int usr:following[userId]) {
            auto& t = tweetsRec[usr]; // Pay attention here!!! 
            if(t.size() > 0) {
                pq.push({t.rend(), t.rbegin()});
            }
        }
        if(tweetsRec[userId].size() > 0) pq.push({tweetsRec[userId].rend(), tweetsRec[userId].rbegin()});
        
        vector<int> res;
        for(int i=0; i<10 && !pq.empty(); i++) {
            auto tmp = pq.top(); pq.pop();
            res.push_back(tmp.second->id); 
            if(++tmp.second != tmp.first) {
                pq.push({tmp.first, tmp.second});
            }
        }
        
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
    
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
