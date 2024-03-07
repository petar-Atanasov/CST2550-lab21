#include <iostream>
#include <vector>

class MaxPriorityQueue
{
private:
    std::vector<int> heap;

    // Helper function to maintain the max heap property
    void heapifyUp(int index)
    {
        while (index > 0)
        {
            int parent = (index - 1) / 2;
            if (heap[index] > heap[parent])
            {
                std::swap(heap[index], heap[parent]);
                index = parent;
            }
            else
            {
                break;
            }
        }
    }

    // Helper function to maintain the max heap property
    void heapifyDown(int index)
    {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < heap.size() && heap[leftChild] > heap[largest])
        {
            largest = leftChild;
        }

        if (rightChild < heap.size() && heap[rightChild] > heap[largest])
        {
            largest = rightChild;
        }

        if (largest != index)
        {
            std::swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    // Function to insert an element into the priority queue
    void insert(int value)
    {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    // Function to extract the maximum element from the priority queue
    int extractMax()
    {
        if (heap.empty())
        {
            std::cerr << "Priority queue is empty.\n";
            return -1; // You can choose a different way to handle an empty queue
        }

        int maxElement = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return maxElement;
    }

    // Function to get the maximum element without removing it
    int getMax() const
    {
        if (heap.empty())
        {
            std::cerr << "Priority queue is empty.\n";
            return -1; // You can choose a different way to handle an empty queue
        }

        return heap[0];
    }

    // Function to check if the priority queue is empty
    bool isEmpty() const
    {
        return heap.empty();
    }
};

// This is how to use this code in your program

int main()
{
    MaxPriorityQueue priorityQueue;

    priorityQueue.insert(5);
    priorityQueue.insert(2);
    priorityQueue.insert(7);
    priorityQueue.extractMax();
    priorityQueue.insert(1);
    priorityQueue.insert(9);
    priorityQueue.insert(4);
    priorityQueue.extractMax();
    priorityQueue.insert(6);
    priorityQueue.extractMax();
    priorityQueue.insert(21);
    priorityQueue.extractMax();
    priorityQueue.extractMax();
    priorityQueue.insert(3);

    std::cout << "Max Element: " << priorityQueue.getMax() << std::endl;

    while (!priorityQueue.isEmpty())
    {
        std::cout << "Extracted Max Element: " << priorityQueue.extractMax() << std::endl;
    }

    return 0;
}
