#include "../inc/doubly_linked_list.h"

namespace lab6{
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
    for(int i = 1; i < vector_input.size(); i++){
        append(vector_input.at(i));
        }
    }

    doubly_linked_list::doubly_linked_list(const doubly_linked_list &original) {
    node *temp = original.head;
    node *copy = new node(temp->get_data());
        this->head = copy;
        while(temp->next != nullptr){
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
    node* temp;
        while(head) {
            temp = head;
            head = head -> next;
            delete temp;
        }
    }

    int doubly_linked_list::get_data(unsigned position) {
        node* temp = head;
        int counter = 0;
        while(counter != position) {
            temp = temp->next;
            counter++;
        }
       return temp->get_data();
    }


    std::vector<int> doubly_linked_list::get_set(unsigned position_from, unsigned position_to) {
        node* current = head;
        std::vector answer<int>;
        int i = 0;                  //location in the answer vector
        unsigned counter = 0;
        if(current->next != nullptr) {
            while (counter != position_from) {
                current = current->next;
                counter++;
            }
            while (counter != position_to){
                answer.at(i) = current->get_data();
                counter++;
                i++;
            }
           return answer;
        }
        throw "linked list only has one node";
    }

    unsigned doubly_linked_list::size() {
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
    if(!is_empty()) {
        node *temp = new node(input);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    else
        throw "empty list";

    }

    void doubly_linked_list::insert(int input, unsigned int location) {
        node* current = head;
        node* previous = current->prev;
        node* next_node = current->next;
        node *new_node = new node(input);
        unsigned counter = 0;
        if (location) {
            while (counter != location) {
                current = current->next;
                counter++;
            }


        }

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

    }

    doubly_linked_list doubly_linked_list::split_set(unsigned position_1, unsigned position_2) {

    }

    void doubly_linked_list::swap(unsigned position_1, unsigned position_2) {

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
        return new_list;
    }

    doubly_linked_list& doubly_linked_list::operator+=(const doubly_linked_list &rhs) {
        doubly_linked_list left;
        node *rhs_temp = rhs.head;
        while(rhs_temp != nullptr){
            left.append(rhs_temp->get_data());
            rhs_temp = rhs_temp->next;
        }
        return left;
    }

    bool doubly_linked_list::operator==(const doubly_linked_list &rhs) {

    }

    std::ostream &operator<<(std::ostream &stream, doubly_linked_list &RHS) {

    }

    std::istream &operator>>(std::istream &stream, doubly_linked_list &RHS) {

    }
}

