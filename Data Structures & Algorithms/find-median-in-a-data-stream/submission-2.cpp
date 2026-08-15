class MedianFinder {
    priority_queue<int, vector<int>> smallHeap;
    priority_queue<int, vector<int>, greater<int>> largeHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        smallHeap.push(num);
        if(largeHeap.empty() || smallHeap.top()>largeHeap.top()){
            largeHeap.push(smallHeap.top());
	smallHeap.pop();
        }
        if(smallHeap.size()>largeHeap.size()+1){
	largeHeap.push(smallHeap.top());
	smallHeap.pop();
        }
        if(largeHeap.size()>smallHeap.size()+1){
	smallHeap.push(largeHeap.top());
	largeHeap.pop();
        }
    }
    
    double findMedian() {
        if(largeHeap.size()>smallHeap.size()) return largeHeap.top();
        else if(smallHeap.size()>largeHeap.size()) return smallHeap.top();
        else{
	return (smallHeap.top()+largeHeap.top())/2.0;
        }
    }
};
