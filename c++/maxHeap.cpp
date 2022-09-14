#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
    int *heap;
    int capacity;
    int size;
    MaxHeap(int cap): capacity(cap){
        heap = new int[cap];
    }
    int left(int i){
        return 2*i+1;
    }
    int right(int i){
        return 2*i+2;
    }
    int parent(int i){
        return (i-1)/2;
    }
    void insert(int K){
        if(capacity == size){
            return;
        }else{
            size++;
            heap[size-1] = K;
            int current = size-1;
            while (current!=0 && heap[current]>heap[parent(current)])
            {
                swap(&heap[current], &heap[parent(current)])
                current = parent(current);
            }
        }
    }
    void increaseKey(int i, int val){
        heap[i] = val;
        while (i!=0 && heap[i]>heap[parent(i)])
        {
            swap(&heap[i], &heap[parent(i)]);
            i = parent(i);
        }
    }
    void heapify(int i){
        int largest = i;
        int l = left(i);
        int r = right(i);
        if(l<size && heap[largest]<heap[l]){
            largest = l;
        }
        if(r<size && heap[largest]<heap[r]){
            largest = r;
        }
        if(largest!=i){
            swap(&heap[i], &heap[largest]);
            heapify(largest);
        }
    }
}
int main(){

}