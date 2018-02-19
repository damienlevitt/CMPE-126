#include "fifo.h"

namespace lab3{
    fifo::fifo() {
        fifo_storage.lab2::reserve(100);
        front_index = 0;
        back_index = 0;
    }

    fifo::fifo(std::string input_string) {

    }

    fifo::fifo(const fifo &original) {

    }

    fifo::~fifo() {
        delete[] fifo;
    }

    fifo &fifo::operator=(const fifo &right) {

    }

    bool fifo::is_empty() const {
        //return false;
    }

    unsigned fifo::size() const {
        //return 0;
    }

    std::string fifo::top() const {
        //return std::__cxx11::string();
    }

    void fifo::enqueue(std::string input) {

    }

    void fifo::dequeue() {

    }
}