/**************************************************************************
 * File Name : 353-DesignSnakeGame.cpp
 *
 * Purpose :
 *
 * Creation Date : 23-04-2017
 *
 * Last Modified : Sun Apr 23 14:23:56 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class SnakeGame {
private:
    int w, h, pos;
    vector<pair<int, int>> food;
    deque<pair<int, int>> q;
    set<pair<int, int>> hist;
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        w = width;
        h = height;
        pos = 0; // idx of food
        this->food = food;
        q.push_back({0,0});
        
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        int row = q.back().first, col = q.back().second;
        auto tail = q.front(); q.pop_front();
        hist.erase(tail);
        
        if(direction == "U") row--;
        else if(direction == "D") row++;
        else if(direction == "L") col--;
        else col++;
        
        if(row < 0 || row >= h || col < 0 || col >= w || hist.count({row, col})) return -1;
        
        // Add new head to the back of deque
        hist.insert({row, col}); 
        q.push_back({row, col});
        
        if(pos >= food.size()) return q.size() - 1;
        if(make_pair(row, col) == food[pos]) {
            pos++;
            q.push_front(tail);
            hist.insert(tail);
        }
        
        return q.size() - 1;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */
