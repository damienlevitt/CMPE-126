#include "lifo.h"

namespace lab3{
    lifo::lifo() {
        lifo_storage.lab2::reserve(100);            //Allocated 100 spaced in array lifo_stroage.
        index = 0;                                  //Sets the index to the beginning of the array.
    }

    lifo::lifo(std::string input_string) {
        lab2::stringVector lifo_storage;
        lifo_storage.lab2::reserve(100);
        lifo_storage.lab2::append(input_string);
    }

    lifo::lifo(const lifo &original) {
        index=original.index;
    }

    lifo::~lifo() {
        delete[] lifo;
    }

    lifo &lifo::operator=(const lifo &right) {
        for (int i = 0; i < index; i++) {
            this->lifo_storage[i] = right.lifo_storage[i];
        }
    }

    bool lifo::is_empty() const {
        if (index >= 1) {
            return false;
        }
        else
            return true;
    }

    unsigned lifo::size() const {
        return index;
    }

    std::string lifo::top() const {
       return lifo_storage[index];
    }

    void lifo::push(std::string input) {
        ++index;
        lifo_storage[index];
        lab2::stringVector append.lifo_storage;
    }

    void lifo::pop() {
        lifo_storage[index];
        --index;
    }
}
