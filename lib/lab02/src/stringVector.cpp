#include "../inc/stringVector.h"
namespace lab2 {

    stringVector::stringVector() {
        length = 0;
        allocated_length = 0;
        data = nullptr;
    }

    stringVector::~stringVector() {
        delete[] data;                                 //Deallocates memory used by data object
    }

    unsigned stringVector::size() const {              //Returns the length of the array
        return length;

        //return ;
    }

    unsigned stringVector::capacity() const {
        return allocated_length;                        //Returns the amount of space allocated for the array
        //return ;
    }

    void stringVector::reserve(unsigned new_size) {
        auto *tempArray = new std::string[new_size];  //Allows the user to choose the allocation size
            for(int count = 0; count < new_size && count <length; count++){
                tempArray[count] = data[count];
            }
        if(length > new_size){                        //If the length is greater than the new size the arrray will shrink
            length = new_size;
        }
        allocated_length = new_size;                   //Sets the allocated memory to the new size
        delete[] data;                                 //Deletes the values in data and stores in TempArray until
        data = tempArray;                              //Sets the data array to the temporary tempArray
    }

    bool stringVector::empty() const {
        if (length == 0){
            return true;
        }                                                //Returns true if the array is empty
        else
            return false;

        //return ;
    }

    void stringVector::append(std::string new_data) {
        if (allocated_length == 0) {                         //Utilizes the empty function, and will set to 1 if the capacity is zero
            this->reserve(1);
            this->append(new_data);
        }
        else if (allocated_length == length) {          //Doubles the allocation size
            this->reserve(allocated_length * 2);
            this->append(new_data);
        }
        else{
            data[length] = new_data;                    //Appends data to the end of the array by data location by 1
            length++;
            return;
    }
}
void stringVector::swap(unsigned pos1, unsigned pos2) {
        if (pos1 > length || pos2 > length) {
                throw 0;                                //Throws a zero if any of the two positions are out of bounds
        }
        std::string tempstring = data[pos1];
        data[pos1] = data[pos2];                        //Uses the temporary variable to swap the positions of pos1 and pos2
        data[pos2] = tempstring;
    }

    stringVector &stringVector::operator=(stringVector const &rhs) {
        if (&rhs == this) {
            return (*this);
        } else {
            delete[] data;
            length = rhs.length;                        //Will take the data from an array and copy it to another
            allocated_length = rhs.allocated_length;
            this->data = new std::string[allocated_length];
            for (int i = 0; i < length; i++) {
                this->data[i] = rhs.data[i];
            }
        }
        //return ;
    }

    std::string &stringVector::operator[](unsigned position) const {
        if (position >= allocated_length) {             //Will return the reference location back to the string
            throw 0;
        }
        return data[position];
    }

    void stringVector::setSize(unsigned new_size) {
        length = new_size;
        if(allocated_length != new_size) reserve(new_size);
    }

    void stringVector::sort() {
        std::string string1;
        for (int i = (length - 1); i > 0; i--) {
            for (int n = 0; n < i; n++) {              //Uses bubble sorting to switch any greater number with the lesser number in string number
                if (data[n].compare(data[n + 1]) > 0) {//Repeats until the larger numbers are at the end and the lesser numbers are at the beginning of the array.
                    string1 = data[n];
                    data[n] = data[n + 1];
                    data[n + 1] = string1;
                }
            }
        }

    }
}
//All Tests pass now