class NumArray {
    vector<int>tree;
    int arrayLen;
public:
    void initSegmentTree(vector<int>& nums, int node, int begIndex, int endIndex) {
        if (begIndex == endIndex) {
            tree[node] = nums[begIndex];
            return;
        }
        int left = 2*node+1, right = 2*node+2, mid = (begIndex+endIndex)/2;
        initSegmentTree(nums, left, begIndex, mid);
        initSegmentTree(nums, right, mid+1, endIndex);
        tree[node] = tree[left] + tree[right];
        return;
    }
    
    int queryInSegmentTree(int node, int begIndex, int endIndex, int from, int to) {
        if (begIndex > to || endIndex < from) {
            return 0;
        }
        if (begIndex >= from && endIndex <= to) {
            return tree[node];
        }
        int left = 2*node+1, right = 2*node+2, mid = (begIndex+endIndex)/2;
        return queryInSegmentTree(left, begIndex, mid, from, to) + queryInSegmentTree(right, mid+1, endIndex, from, to);
    }
    
    void updateSegmentTree(int node, int begIndex, int endIndex, int from, int to, int newValue) {
        if (begIndex > to || endIndex < from) {
            return;
        }
        if (begIndex>=from && endIndex <= to) {
            tree[node] = newValue;
            return;
        }
        int left = 2*node+1, right = 2*node+2, mid = (begIndex+endIndex)/2;
        updateSegmentTree(left, begIndex, mid, from, to, newValue);
        updateSegmentTree(right, mid+1, endIndex, from, to, newValue);
        tree[node] = tree[left] + tree[right];
        return;
    }
    NumArray(vector<int>& nums) {
        arrayLen = nums.size();
        tree.assign(4*arrayLen, 0);
        initSegmentTree(nums, 0, 0, arrayLen-1);
    }
    
    void update(int index, int val) {
        updateSegmentTree(0, 0, arrayLen-1, index, index, val);
        return;
    }
    
    int sumRange(int left, int right) {
        return queryInSegmentTree(0, 0, arrayLen-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */