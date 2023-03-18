class BrowserHistory {
public:
    vector <string> history;
    int currPageIndex = -1, max = -1;
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        currPageIndex++;
        max = currPageIndex;
    }
    
    void visit(string url) {
        if(currPageIndex == history.size() - 1) {
            history.push_back(url);
            ++currPageIndex;
        } 
        else {
            history[++currPageIndex] = url;
        }
        max = currPageIndex;
    }
    
    string back(int steps) {
        if (currPageIndex >= steps)   currPageIndex -= steps;
        else currPageIndex = 0;
        return history[currPageIndex];
    }
    
    string forward(int steps) {
        if (currPageIndex + steps > max)  currPageIndex = max;
        else currPageIndex += steps;
        return history[currPageIndex];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */