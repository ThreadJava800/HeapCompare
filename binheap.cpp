#include "binheap.h"

#define createOfStream(num) FILE* heap##num = fopen("kheap/heap"#num".txt", "wb");

#define addToVec(num) { heap##num, num },


using namespace std::chrono;


int main() {
    std::ofstream heap2;
    heap2.open("binheap.txt");

    for (int i = 100000; i <= 10000000; i += 100000) {
        long dur = 0;
        std::vector<int> values = generateArr(i);

        for (int j = 0; j < 5; j++) {
            Heap_t* heap = heapCtor(i);

            auto start = high_resolution_clock::now(); 
            for (int m = 0; m < i; m++) {
                heapAdd(heap, values[m]);
            }
            for (int m = 0; m < i; m++) {
                extractMin(heap);
            }
            auto end = high_resolution_clock::now();

            dur += duration_cast<milliseconds>(end - start).count();

            heapDtor(heap);
        }

        heap2 << i << ' ' << (double) dur / 5 << '\n';
        heap2.flush();
    } 

    heap2.close();

    return 0;
}