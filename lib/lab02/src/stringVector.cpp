#include "../inc/stringVector.h"
using namespace lab2;
stringVector::stringVector() {
    length;
    allocated_length;
    data = nullptr;
}

stringVector::~stringVector() {
    delete []data;
}

unsigned stringVector::size() const{
    return length;

    //return ;
}

unsigned stringVector::capacity() const{
    return allocated_length;
    //return ;
}

void stringVector::reserve(unsigned new_size) {
        data = new int[new_size];
        delete data;

}

bool stringVector::empty() const{
    if(length != 0)
        return true;
    else
        return false;

    //return ;
}

void stringVector::append(std::string new_data) {
    if(allocated_length)
}

void stringVector::swap(unsigned pos1, unsigned pos2) {

}

stringVector &stringVector::operator=(stringVector const &rhs) {
    //return ;
}

std::string &stringVector::operator[](unsigned position) {
    //return ;
}

void stringVector::sort() {

}
