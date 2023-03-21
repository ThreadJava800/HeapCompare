# Heap performance comparison
I tested basic heap insert() and extractMin() functions. \
Specifically I tested it on [k-heaps](https://github.com/ThreadJava800/HeapCompare/blob/main/kheap.h) (k = 2, 5, 10, 25, 50, 100, 200, 300, 400, 500, 1000).

Here's the comparison: \
![K-Heap comparison](https://github.com/ThreadJava800/HeapCompare/blob/main/graph.png)

Eventually, I figured out that the most efficient heap is with k=e. You can see the results on graph. 