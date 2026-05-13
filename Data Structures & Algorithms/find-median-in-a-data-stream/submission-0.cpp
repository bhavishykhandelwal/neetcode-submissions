class MedianFinder {
public:
    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int>> mini;

    MedianFinder() {
        
    }

    void addNum(int num) {
        maxi.push(num);

        mini.push(maxi.top());
        maxi.pop();

        // balance heaps
        if(mini.size() > maxi.size() + 1){
            maxi.push(mini.top());
            mini.pop();
        }
    }

    double findMedian() {
        if(maxi.size() == mini.size()){
            return (maxi.top() + mini.top()) / 2.0;
        }
        else{
            return mini.top();
        }
    }
};
