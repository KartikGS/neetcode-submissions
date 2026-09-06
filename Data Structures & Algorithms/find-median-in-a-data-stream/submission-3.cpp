class MedianFinder {
	priority_queue<int, vector<int>> smallHeap;
	priority_queue<int, vector<int>, greater<int>> largeHeap;
public:
    MedianFinder() {
        
    }
    
    	void addNum(int num) {
        		smallHeap.push(num);
		if(!largeHeap.empty() && largeHeap.top()<smallHeap.top()){
	int tmp = smallHeap.top();
	smallHeap.pop();
	largeHeap.push(tmp);
}
if(smallHeap.size()>largeHeap.size()+1){
	int tmp = smallHeap.top();
	smallHeap.pop();
	largeHeap.push(tmp);
} else if(largeHeap.size()>smallHeap.size()+1){
	int tmp = largeHeap.top();
	largeHeap.pop();
	smallHeap.push(tmp);
}
    	}
    
    	double findMedian() {
        		if(largeHeap.size()==smallHeap.size()) return static_cast<double>(largeHeap.top()+smallHeap.top())/2;
		else if(largeHeap.size()>smallHeap.size()) return largeHeap.top();
		else return smallHeap.top();
    	}
};

