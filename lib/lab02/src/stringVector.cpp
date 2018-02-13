#include "../inc/stringVector.h"


stringVector::stringVector() {
    length;
    allocated_length;
    data = nullptr;
}

stringVector::~stringVector() {
    delete[] data;
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
        std::string *data = new std::string int[new_size];
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
    if(empty() == false) {
        this->reserve(1);
    }
    else{
        for(int counter = 0; counter < allocated_length; counter++){
         data[length++] = new_data[counter + 1];
        }
        int temp = 2*allocated_length;
        allocated_length = temp;
    }
}

void stringVector::swap(unsigned pos1, unsigned pos2) {
    if(pos1 > allocated_length || pos2 > allocated_length) {

    }
}

stringVector &stringVector::operator=(stringVector const &rhs) {
   if(&rhs == this){
       return (*this);
   }
    else {
       delete[] data;
       length = rhs.length;
       allocated_length = rhs.allocated_length;
       this->data = new std::string int[allocated_length];
       for(int i = 0; i<length; i++) {
           this->data[i] = rhs.data[i];
       }
   }
    //return ;
}

std::string &stringVector::operator[](unsigned position) {
        if (position >= allocated_length) {
            throw 0;
        }
        return data[position];
    }


void stringVector::sort() {
    std::string string1;
    for(int i = (length - 1); i > 0; i--){
        for(int n = 0; n < i; n++){
            if(data[n].compare(data[n + 1]) > 0){
                string1 = data[n];
                data[n] = data[n + 1];
                data[n+1] = string1;
            }
        }
    }

}
