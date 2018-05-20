#include "../inc/doubly_linked_list.h"

namespace lab6 {
    doubly_linked_list::doubly_linked_list() {
        head = nullptr;
        tail = nullptr;
    }

    doubly_linked_list::doubly_linked_list(int input) {
        head = new node(input);
        tail = head;
    }

    doubly_linked_list::doubly_linked_list(std::vector<int> vector_input) {
        head = new node(vector_input.front());
        tail = head;
        for (int i = 1; i < vector_input.size(); i++) {
            append(vector_input.at(i));
        }
    }

    doubly_linked_list::doubly_linked_list(const doubly_linked_list &original) {
        node *temp = original.head;
        node *copy = new node(temp->get_data());
        this->head = copy;
        while (temp->next != nullptr) {
            temp = temp->next;
            node *new_copy = new node(temp->get_data());
            copy->next = new_copy;
            new_copy->prev = copy;
            copy = new_copy;
        }
        copy->next = nullptr;
        tail = copy;
    }

    doubly_linked_list::~doubly_linked_list() {
        node *temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    int doubly_linked_list::get_data(unsigned position) {
        node *temp = head;
        int answer;
        for (int i = 0; i < position; i++) {
            temp = temp->next;
        }
        answer = temp->get_data();
        return answer;
    }


    std::vector<int> doubly_linked_list::get_set(unsigned position_from, unsigned position_to) {
        node *current = head;
        std::vector<int> answer;
        int i = 0;                  //location in the answer vector
        unsigned counter = 0;
        if (position_from >= size() || position_to >= size() || position_from > position_to || position_from < 0 ||
            position_to < 0) {
            throw "invalid position";
        }
        while (counter != position_from) {
            current = current->next;
            counter++;
        }
        while (counter != position_to) {
            answer.at(i) = current->get_data();
            current = current->next;
            counter++;
            i++;
        }
        return answer;
    }


    unsigned doubly_linked_list::size()const {
        node* temp = head;
        unsigned counter = 0;
        while(temp != nullptr) {
            temp = temp->next;
            counter++;
        }
        return counter;
    }

    bool doubly_linked_list::is_empty() {
    if(size() == 0){
        return true;
    }
        return false;
    }

    void doubly_linked_list::append(int input) {
    node *temp = new node(input);
        node* current = head;
        if(!is_empty()) {
            while(current->next != nullptr){
                current = current->next;
            }
            current->next = temp;
            temp->next = nullptr;
            temp->prev = current;
            tail = temp;
    }
        else
            head = temp;
            tail = temp;
    }

    void doubly_linked_list::insert(int input, unsigned int location) {
        node* current = head;
        node* previous = nullptr;
       // node* next = current->next;
        node* new_node = new node(input);
        unsigned counter = 0;
        if (head == nullptr) {
            head = new_node;
            tail = new_node;
            return;
        }
        while(counter != location){
            previous = current;                 //finds the current node at position "location"
            current = current->next;
            counter++;
        }
        if(previous){
            previous->next = new_node;
            new_node->prev = previous;
            new_node->next = current;
            current->prev = new_node;
        }
        else
            head = new_node;
            head->next = current;
            current->prev = head;
            head->prev = nullptr;

        }


    void doubly_linked_list::remove(unsigned location) {
        node* current = head;
        node* previous = current->prev;
        node* next_node = current->next;
        unsigned counter = 0;
        if (location) {
            while (counter != location) {
                current = current->next;
                counter++;
            }
            next_node->prev = previous;
            previous->next = next_node;
            current->next = nullptr;
            current->prev = nullptr;
        }
        throw "location does not exist.";
    }

    doubly_linked_list doubly_linked_list::split(unsigned position) {
    doubly_linked_list split(get_set(position, size() - 1));
            for(int i = size() - 1; i >= position && i >=0; i--){
                remove(i);
            }
        return split;
    }

    doubly_linked_list doubly_linked_list::split_set(unsigned position_1, unsigned position_2) {
    doubly_linked_list split_set;
        node* temp = head;
        int counter = 0;
        while(counter != position_1){
            temp = temp->next;
            counter++;
        }
        node* temp2 = temp;
        for (int i = position_1; i < position_2; i++){
            split_set.append(temp2->get_data());
            temp2 = temp2->next;
        }
        split_set.append(temp2->get_data());
        for(int i = position_2; i >= position_1; i--){
            remove(i);
        }
        return split_set;
    }

    void doubly_linked_list::swap(unsigned position_1, unsigned position_2) {
        node* temp = head;
        node* tempPrev = temp->prev;
        node* tempNext = temp->next;
        int counter = 0;
        if (position_1 > position_2){
            int temp = position_1;      //this will ensure that position_2 is always after position_1
            position_1 = position_2;
            position_2 = temp;
        }
        if (position_1 == position_2){
            throw "position_1 and position_2 are equal.";
        }
        while(counter != position_1){
            temp = temp->next;
            counter++;
        }
        node* temp2 = head;
        node* tempPrev2 = temp2->prev;
        node* tempNext2 = temp2->next;
        for (int i = position_1; i<position_2; i++){
            temp2 = temp2->next;
        }
        if(tempPrev == nullptr && tempNext != nullptr){             //edge case when swapping head and an element that is not tail
            if(tempNext == temp2){              //head and element are next to each other
                temp2->next = temp;
                temp->prev = temp2;
                temp->next = tempNext2;
                temp2->prev = nullptr;
                head = temp2;
            }
            else{
                tempNext->prev = temp2;
                tempPrev2->next = temp;
                tempNext2->prev = temp;
                temp->prev = tempPrev;
                temp2->prev = nullptr;
                temp->next = tempNext2;
                temp2->next = tempNext;
                head = temp2;
            }
        }
        else if (tempPrev != nullptr && tempNext2 == nullptr) {           //swap for tail and an element that is not head.
            if(tempNext == temp2){
                tempPrev->next = temp2;
                temp2->prev = tempPrev;
                temp2->next = temp;
                temp->prev = temp2;
                temp->next = nullptr;
                tail = temp;
            }
            else{
                tempPrev->next = temp2;
                temp2->prev = tempPrev;
                temp2->next = tempNext;
                tempNext->prev = temp2;
                tempPrev2->next = temp;
                temp->prev = tempPrev2;
                temp->next = nullptr;
                tail = temp;
            }
        }

    }

    void doubly_linked_list::swap_set(unsigned location_1_start, unsigned location_1_end, unsigned location_2_start,
                                      unsigned location_2_end) {

    }

    void doubly_linked_list::sort() {
        // Implement Insertion Sort
    }

    doubly_linked_list doubly_linked_list::operator+(const doubly_linked_list &rhs) const {
    doubly_linked_list final;
    node *temp = this->head;
    node *rhs_temp = rhs.head;
        while(temp != nullptr){
            final.append(temp->get_data());
            temp = temp->next;
        }
        while(rhs_temp != nullptr){
            final.append(rhs_temp->get_data());
            rhs_temp = rhs_temp->next;
        }
        return final;
    }

    doubly_linked_list& doubly_linked_list::operator=(const doubly_linked_list &rhs) {
    doubly_linked_list new_list(rhs);
        return *this;
    }

    doubly_linked_list& doubly_linked_list::operator+=(const doubly_linked_list &rhs) {
        doubly_linked_list left;
        node *rhs_temp = rhs.head;
        while(rhs_temp != nullptr){
            left.append(rhs_temp->get_data());
            rhs_temp = rhs_temp->next;
        }
        return *this;
    }

    bool doubly_linked_list::operator==(const doubly_linked_list &rhs) {
    node* current = head;
    node* right = rhs.head;
        if (this->size() != rhs.size()){                 //objects are different sizes therefore not equal
            return false;
        }
        else{
            while(current){
                if(current->get_data() != right->get_data()){       //objects have the same data at the same locations
                    return false;
                }
                current = current->next;
                right = right->next;
            }
            return true;
        }
    }

    std::ostream &operator<<(std::ostream &stream, doubly_linked_list &RHS) {
        node* current = RHS.head;
        stream << std::string("nullptr <- ");
        while(current->next){
            stream << current->get_data();
            stream << " <-> ";
            current = current->next;
        }
        stream << current->get_data();
        stream << " -> nullptr";
        return stream;
    }

    std::istream &operator>>(std::istream &stream, doubly_linked_list &RHS) {
        int input;
        stream >> input;
        RHS.append(input);
        return stream;
    }
}

