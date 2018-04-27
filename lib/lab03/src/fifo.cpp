#include "fifo.h"

namespace lab3{
    fifo::fifo() {
        fifo_storage.reserve(100);
        front_index = 0;
        back_index = 0;
    }

    fifo::fifo(std::string input_string) {
        fifo_storage.reserve(100);
        front_index = 0;
        back_index = 1;
        fifo_storage.append(input_string);
    }

    fifo::fifo(const fifo &original) {
        fifo_storage.reserve(100);
        back_index = original.back_index;
        front_index = original.front_index;
        for(int n = 0; n < back_index; n++){
            fifo_storage[n] = original.fifo_storage[n];
        }
    }

    fifo::~fifo() {
        fifo_storage.setSize(0);
        front_index = 0;
        back_index = 0;
    }

    fifo &fifo::operator=(const fifo &right) {
        if(&right == this){
            return(*this);
        }
        fifo_storage.reserve(right.fifo_storage.capacity());
        back_index = right.back_index;
        front_index = right.front_index;
        for(int n = 0; n , right.fifo_storage.size(); n++){
            fifo_storage[n] = right.fifo_storage[n];
        }
    }

    bool fifo::is_empty() {
        if(front_index == back_index){
            return true;
        }
        else
            return false;
    }

    int fifo::size() {
        if(!is_empty()){
            return back_index - front_index;
        }
    }

    std::string fifo::top()  {
        return fifo_storage[front_index];
    }

    void fifo::enqueue(std::string input_string) {
        fifo_storage.append(input_string);
        ++back_index;
    }

    void fifo::dequeue() {
        ++front_index;
    }
}