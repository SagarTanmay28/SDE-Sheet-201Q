class maxHeap {
private:
    vector<int> heap;

    void heapifyUp(int idx) {
        while (idx > 0) {
            int parent = (idx - 1) / 2;

            if (heap[parent] >= heap[idx])
                break;

            swap(heap[parent], heap[idx]);
            idx = parent;
        }
    }

    void heapifyDown(int idx) {
        int n = heap.size();

        while (true) {
            int largest = idx;
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;

            if (left < n && heap[left] > heap[largest])
                largest = left;

            if (right < n && heap[right] > heap[largest])
                largest = right;

            if (largest == idx)
                break;

            swap(heap[idx], heap[largest]);
            idx = largest;
        }
    }

public:
    void push(int x) {
        heap.push_back(x);
        heapifyUp(heap.size() - 1);
    }

    void pop() {
        if (heap.empty())
            return;

        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty())
            heapifyDown(0);
    }

    int peek() {
        return heap.empty() ? -1 : heap[0];
    }

    int size() {
        return heap.size();
    }
};


Complexity
push(x) → O(log n)
pop() → O(log n)
peek() → O(1)
size() → O(1)
