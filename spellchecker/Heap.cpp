#include "Heap.h"
#include <stdexcept>



Heap::Heap(size_t capacity) : mCapacity(capacity), mCount(0){
    mData = new Entry[capacity];    
}






Heap::Heap(const Heap& other):mCapacity(other.mCapacity), mCount(other.mCount){
    mData = new Entry[mCapacity];
    for(size_t i = 0; i<mCount; i++){
        mData[i] = other.mData[i];
    }

}
Heap::Heap(Heap&& other): mData(other.mData), mCapacity(other.mCapacity), mCount(other.mCount){
    other.mData = nullptr;
    other.mCapacity = 0;
    other.mCount = 0;
}

Heap::~Heap(){
    delete[] mData;
}




size_t Heap::capacity() const{
    return mCapacity;
}


size_t Heap::count() const{
    return mCount;
}

const Heap::Entry& Heap::lookup(size_t index) const{
    if(index>= mCount){
        throw std::out_of_range("Index out of range");
    }
    return mData[index];
}



Heap::Entry Heap::pop(){
    if (mCount == 0){
        throw std::underflow_error("Heap is empty");
    }
    Entry result = mData[0];
    mData[0] = mData[mCount - 1];
    --mCount;

    size_t index = 0;
    while (true) {
        size_t left = 2 * index + 1;
        size_t right = 2 * index + 2;
        size_t smallest = index;

        if (left < mCount && mData[left].score < mData[smallest].score) {
            smallest = left;
        }
        if (right < mCount && mData[right].score < mData[smallest].score) {
            smallest = right;
        }
        if (smallest == index) break;

        Entry temp = mData[index];
        mData[index] = mData[smallest];
        mData[smallest] = temp;

        index = smallest;
    }

    return result;
}




Heap::Entry Heap::pushpop(const std::string& value, float score){
    if (mCount == 0)
        throw std::underflow_error("Heap is empty");
    Entry result = mData[0];
    mData[0] = {value, score};
    size_t index = 0;
    while (true) {
        size_t left = 2 * index + 1;
        size_t right = 2 * index + 2;
        size_t smallest = index;

        if (left < mCount && mData[left].score < mData[smallest].score) {
            smallest = left;
        }
        if (right < mCount && mData[right].score < mData[smallest].score) {
            smallest = right;
        }
        if (smallest == index) break;

        Entry temp = mData[index];
        mData[index] = mData[smallest];
        mData[smallest] = temp;

        index = smallest;
    }

    return result;
}

void Heap::push(const std::string& value, float score){
    if (mCount >= mCapacity)
        throw std::overflow_error("Heap is full");
    size_t index = mCount++;
    mData[index] = {value, score};

    while (index > 0) {
        size_t parent = (index - 1) / 2;
        if (mData[parent].score <= mData[index].score) break;

        Entry temp = mData[parent];
        mData[parent] = mData[index];
        mData[index] = temp;

        index = parent;
    }
}


const Heap::Entry& Heap::top() const{
    if (mCount == 0)
        throw std::underflow_error("Heap is empty");
    return mData[0];
}


