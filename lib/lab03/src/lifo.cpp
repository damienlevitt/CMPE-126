#include "lifo.h"


namespace lab3{
    lifo::lifo() {
        lifo_storage.reserve(100);            //Allocated 100 spaced in array lifo_storage.
        index = 0;                                  //Sets the index to the beginning of the array.
    }

    lifo::lifo(std::string input_string) {
        lab2::stringVector lifo_storage;            //Does the same as the default constructor
        lifo_storage.reserve(100);
        lifo_storage.append(input_string);
    }

    lifo::lifo(const lifo &original) {
        lifo_storage.reserve(100);
        index=original.index;
        for(int n = 0; n < index; n++){
            lifo_storage[n] = original.lifo_storage[n];
        }
    }

    lifo::~lifo() {
        index = 0;
    }

    lifo &lifo::operator=(const lifo &right) {
        lifo_storage.reserve(100);
        lifo_storage.reserve(right.lifo_storage.capacity());
        index = right.index;

        for (int i = 0; i < index; i++) {
            this->lifo_storage[i] = right.lifo_storage[i];
        }
    }

    bool lifo::is_empty() {
        if (index >= 1) {
            return false;
        }
        else
            return true;
    }

    int lifo::size()  {
        if(!is_empty()) {
            return index;
        }
        else
            return 0;
    }

    std::string lifo::top() {
       return lifo_storage[index];
    }

    void lifo::push(std::string input) {
        ++index;
        lifo_storage.append(input);
    }

    void lifo::pop() {
        --index;
    }
}
