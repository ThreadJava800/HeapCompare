#include "support.h"


typedef struct {
    int size;
    int capacity;
    int* arr;
} Heap_t;


Heap_t* heapCtor(int n);
void heapAdd(Heap_t* heap, int value);
int heapDel(Heap_t* heap, int index);
int getMaxIndex(Heap_t* heap);
int extractMin(Heap_t* heap);
void heapSiftDown(Heap_t* heap, int index);
void heapSiftUp(Heap_t* heap, int index);
void heapDtor(Heap_t* heap);


Heap_t* heapCtor(int n) {
    int* vals = (int*) calloc((size_t) n + 1, sizeof(int));
    Heap_t* heap = (Heap_t*) calloc(1, sizeof(Heap_t));
    ON_ERROR(!heap || !vals, "Nullptr", NULL);

    heap->arr       = vals;
    heap->size      = 1;
    heap->capacity  = n;

    return heap;
}

void heapAdd(Heap_t* heap, int value) {
    ON_ERROR(!heap, "Null ptr, Noob", );

    if (heap->size > heap->capacity) {
        if (value < heap->arr[1]) {
            heap->arr[1] = value;
            heapSiftDown(heap, 1);
        }

        return;
    }

    heap->arr[(heap->size)++] = value;
    heapSiftUp(heap, heap->size - 1);
}

int heapDel(Heap_t* heap, int index) {
    ON_ERROR(!heap, "Null ptr, Noob", 0);

    int val = heap->arr[index];
    heap->arr[index] = heap->arr[--(heap->size)];
    heapSiftDown(heap, index);

    return val;
}

int getMaxIndex(Heap_t* heap) {
    ON_ERROR(!heap, "Null ptr, Noob", -1);

    int maxi = 0;
    int index = 1;
    for (int i = heap->size / 2; i < heap->size; i++) {
        if (maxi <= heap->arr[i]) {
            maxi = heap->arr[i];
            index = i;
        }
    }

    return index;
}

int extractMin(Heap_t* heap) {
    ON_ERROR(!heap, "Null ptr, Noob", 0);

    return heapDel(heap, 1);
}

void heapSiftDown(Heap_t* heap, int index) {
    ON_ERROR(!heap, "Null ptr, Noob", );

    while (index * 2 + 1 <= heap->size) {
        int leftSon  = index * 2;
        int rightSon = index * 2 + 1;

        if (heap->arr[leftSon]  > heap->arr[index] &&
            heap->arr[rightSon] > heap->arr[index]) {
                break;
        }

        if (heap->arr[leftSon] < heap->arr[rightSon]) {
            int temp = heap->arr[leftSon];
            heap->arr[leftSon] = heap->arr[index];
            heap->arr[index] = temp;

            index = leftSon;
        } else {
            int temp = heap->arr[rightSon];
            heap->arr[rightSon] = heap->arr[index];
            heap->arr[index] = temp;

            index = rightSon;
        }
    }
}

void heapSiftUp(Heap_t* heap, int index) {
    ON_ERROR(!heap, "Null ptr, Noob", );

    int* vals = heap->arr;
    while (vals[index] < vals[index / 2] && index != 1) {
        int temp = vals[index];
        vals[index] = vals[index / 2];
        vals[index / 2] = temp;

        index /= 2;
    }
}

void heapDtor(Heap_t* heap) {
    ON_ERROR(!heap, "Null ptr, Noob", );

    free(heap->arr);
    free(heap);
}