#include "support.h"

class KHeap {
    private:
        std::vector<int> values = std::vector<int>();

        int k = 0;

    public:
        KHeap(int _k) {
            values = std::vector<int>();
            this->k    = _k;
        };

        int extractMin() {
            return _del(0);
        }

        void add(int value) {
            _add(value);
        }

        ~KHeap() {
            this->values.clear();
            this->k    = 0;
        }
        

    private:
        void _add(int value) {
            this->values.push_back(value);
            siftUp(this->values.size() - 1);
        }

        int _del(size_t pos) {
            int retVal = this->values[pos];


            this->values[pos] = this->values.back();
            this->values.pop_back();
            siftDown(pos);

            return retVal;
        }

        int findMinChild(size_t parent, size_t* childIndex) {
            ON_ERROR((parent > this->values.size()) || !childIndex, "NULLPTR", -1);

            int mini = INT32_MAX;
            for (size_t i = (size_t) k * parent + 1; i <= (size_t) k * parent + (size_t) k; i++) {
                if (i <= this->values.size()) {
                    if (this->values[i] < mini) {
                        mini = this->values[i];
                        *childIndex = i;
                    }
                }
            }

            return mini;
        }

        void siftDown(size_t index) {
            ON_ERROR((index > this->values.size()), "NULLPTR",);
            // loop between all children and swap if max(children) > node

            while (index * 2 <= this->values.size())
            {
                size_t maxChildInd = 0;
                int minChild = findMinChild(index, &maxChildInd);
                if (minChild < this->values[index]) {
                    std::swap(this->values[index], this->values[maxChildInd]);
                    index = maxChildInd;
                } else {
                    break;
                }
            }
            
        }

        void siftUp(size_t index) {
            ON_ERROR((index > this->values.size()), "NULLPTR",);

            size_t parent = (index - 1) / (size_t) k;
            while (index != 0)
            {
                if (this->values[index] < this->values[parent]) {
                    std::swap(this->values[index], this->values[parent]);
                    index = parent;
                    parent = (index - 1) / (size_t) k;
                } else {
                    break;
                }
            }
        }
};