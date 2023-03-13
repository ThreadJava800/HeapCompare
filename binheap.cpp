#include "binheap.h"


using namespace std::chrono;

int main() {
    std::ofstream binheap;
    binheap.open("binheap.txt");

    for (int i = 100000; i <= 10000000; i += 100000) {
        long long timeSum = 0;
        for (int j = 0; j < 5; j++) {
            int* vals = generateCArr(i);
            Heap_t* heap = heapCtor(i);

            auto start = high_resolution_clock::now();
            for (int m = 0; m < i; m++) {
                heapAdd(heap, vals[m]);
            }

            for (int m = 0; m < i; m++) {
                vals[m] = extractMin(heap);
            }
            auto end = high_resolution_clock::now();

            auto duration = duration_cast<milliseconds>(end - start);
            timeSum += duration.count();

            free(vals);
            heapDtor(heap);
        }

        binheap << i << " " << (double) timeSum / 5 << '\n';
        binheap.flush();
    }

    return 0;
}