#include "kheap.h"

#define createOfStream(num) FILE* heap##num = fopen("kheap/heap"#num".txt", "wb");

#define addToVec(num) { heap##num, num },


using namespace std::chrono;


int main() {
    createOfStream(5);
    createOfStream(10);
    createOfStream(25);
    createOfStream(50);
    createOfStream(100);
    createOfStream(200);
    createOfStream(300);
    createOfStream(400);
    createOfStream(500);
    createOfStream(1000);

    std::vector<std::pair<FILE*, int>> supportVec = {
        addToVec(5)
        addToVec(10)
        addToVec(25)
        addToVec(50)
        addToVec(100)
        addToVec(200)
        addToVec(300)
        addToVec(400)
        addToVec(500)
        addToVec(1000)
    };

    for (int i = 100000; i <= 10000000; i += 100000) {
        std::vector<int> values = generateArr(i);

        for (int j = 0; j < supportVec.size(); j++) {
            KHeap kheap = KHeap(supportVec[j].second);

            auto start = high_resolution_clock::now(); 
            for (int m = 0; m < i; m++) {
                kheap.add(values[m]);
            }
            for (int m = 0; m < i; m++) {
                kheap.extractMin();
            }
            auto end = high_resolution_clock::now();

            auto duration = duration_cast<milliseconds>(end - start);

            fprintf(supportVec[j].first, "%d %lld\n", i, duration.count());
            fflush(supportVec[j].first);
        }
    } 

    for (int i = 0; i < supportVec.size(); i++) {
        fclose(supportVec[i].first);
    }

    return 0;
}