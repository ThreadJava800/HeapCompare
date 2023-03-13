#include "kheap.h"

int main() {
    std::vector<int> values = generateArr(10);
    KHeap heap = KHeap(10);

    for (int i = 0; i < 10; i++) {
        fprintf(stderr, "%d ", values[i]);
        heap.add(values[i]);
    }
    fprintf(stderr, "\n");
    for (int i = 0; i < 10; i++) {
        fprintf(stderr, "%d ", heap.extractMin());
    }

    return 0;
}