class MedianFinder {
    priority_queue<int, vector<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(minHeap.size() == maxHeap.size()){
            if(minHeap.empty() || num>=minHeap.top()) minHeap.push(num);
	else maxHeap.push(num);
        } else if(minHeap.size() > maxHeap.size()){
            if((maxHeap.empty() && num<=minHeap.top()) || (!maxHeap.empty() && num<=maxHeap.top())) maxHeap.push(num);
	else{
	    maxHeap.push(minHeap.top());
	    minHeap.pop();
	    minHeap.push(num);
}
        } else {
            if((minHeap.empty() && num>=maxHeap.top()) || (!minHeap.empty() && num>=minHeap.top())) minHeap.push(num);
	else{
	    minHeap.push(maxHeap.top());
	    maxHeap.pop();
	    maxHeap.push(num);
}
        }
    }
    
    double findMedian() {
        if(minHeap.size()>maxHeap.size()) return static_cast<double>(minHeap.top());
        else if(maxHeap.size()>minHeap.size()) return static_cast<double>(maxHeap.top());
        else return static_cast<double>(minHeap.top() + maxHeap.top())/2;
    }
};
