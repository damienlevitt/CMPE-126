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
        this->tail = copy;
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
        if (position >= size()){
            throw "the position does not exist.";
        }
        for (int i = 0; i < position; i++) {
            temp = temp->next;
        }
        answer = temp->get_data();
        return answer;
    }


    std::vector<int> doubly_linked_list::get_set(unsigned position_from, unsigned position_to) {
        node *current = head;
        std::vector<int> answer;
        int counter;                   //location in the answer vector
        if (position_from >= size() || position_to >= size() || position_from > position_to || position_from < 0 ||
            position_to < 0) {
            throw "invalid position";
        }
        for(int i = 0; i < position_from; i++) {
            current = current->next;
        }
        for(int i = position_from; i<=position_to; i++) {
            counter = current->get_data();
            current = current->next;
            answer.push_back(counter);
        }
        return answer;
    }


    unsigned doubly_linked_list::size() const {
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
        node *current = head;
        node *previous = nullptr;
        // node* next = current->next;
        node *new_node = new node(input);
        if (head == nullptr) {
            head = new_node;
            tail = new_node;
            return;
        }
        for (int i = 0; i < location; i++) {
            previous = current;                 //finds the current node at position "location"
            current = current->next;
        }
        if (previous) {
            previous->next = new_node;
            new_node->prev = previous;
            new_node->next = current;
            current->prev = new_node;
        } else {
            head = new_node;
            head->next = current;           //no previous node, therefore new_node is at the head.
            current->prev = head;
            head->prev = nullptr;

        }
    }

    void doubly_linked_list::remove(unsigned location) {
        node *previous = nullptr;
        node *current;
        current = head;
        if(location>size()){
            throw "location larger than the list.";
        }
        for(int i = 0; i < location; i++) { // finds the node at location
            previous = current;
            current = current->next;
        }
        if (previous) { // edge case for a previous node
            if(!current->next){
                previous->next = nullptr;
                tail = previous;
                delete(current);
                return;
            }
            previous->next = current->next;
            current->next->prev = current->prev;
        }
        else{
            head = current->next;
        }
        delete(current);
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

        if(position_1 > position_2){    //makes sure that position one always comes before position2
            int temp = position_1;
            position_1 = position_2;
            position_2 = temp;
        }

        if(position_1 == position_2){
            throw "error, positions are the same.";
        }

        node* tempA = head;
        for(int i=0; i<position_1; i++) {
            tempA = tempA->next;
        }

        node* tempB = tempA;
        for(int i=position_1; i<position_2; i++){
            tempB = tempB->next;
        }

        node* tempAprev = tempA->prev;
        node* tempAnext = tempA->next;
        node* tempBprev = tempB->prev;
        node* tempBnext = tempB->next;

        if(tempAnext == tempB && tempAprev != nullptr && tempBnext != nullptr){   //swaps the elements that are next to each other
            tempAprev->next = tempB;
            tempB->prev = tempAprev;
            tempB->next = tempA;
            tempA->prev = tempB;
            tempA->next = tempBnext;
            tempBnext->prev = tempA;
        }

        else if(tempAprev == nullptr && tempBnext == nullptr){ //edge case for swapping head and tail
            if(size()==2){
                tempB->next = tempA;
                tempA->prev = tempB;
                tempA->next = nullptr;
                tempB->prev = nullptr;
                head = tempB;
                tail = tempA;
            }
            else {
                tempA->prev = tempBprev;
                tempA->next = nullptr;
                tempBprev->next = tempA;
                tempB->prev = nullptr;
                tempB->next = tempAnext;
                tempAnext->prev = tempB;
                head = tempB;
                tail = tempA;
            }
        }

        else if(tempAprev == nullptr && tempBnext != nullptr){    // edge case for swapping head and not tail

            if(tempAnext == tempB){
                tempA->prev = tempB;
                tempA->next = tempBnext;
                tempBnext->prev = tempA;
                tempB->prev = nullptr;
                head = tempB;

            }
            else {
                tempAnext->prev = tempB;
                tempBprev->next = tempA;
                tempBnext->prev = tempA;
                tempA->prev = tempBprev;
                tempB->prev = nullptr;
                tempA->next = tempBnext;
                tempB->next = tempAnext;
                head = tempB;
            }
        }

        else if(tempAprev != nullptr && tempBnext == nullptr){    //edge case for swapping tail and not head

            if(tempAnext == tempB) {
                tempAprev->next = tempB;
                tempB->prev = tempAprev;
                tempB->next = tempA;
                tempA->prev = tempB;
                tempA->next = nullptr;
                tail = tempA;
            }
            else{
                tempAprev->next = tempB;
                tempB->prev = tempAprev;
                tempB->next = tempAnext;
                tempAnext->prev = tempB;
                tempBprev->next = tempA;
                tempA->prev = tempBprev;
                tempA->next = nullptr;
                tail = tempA;
            }
        }

        else {                  //if no edge cases apply
            tempAprev->next = tempB;
            tempAnext->prev = tempB;
            tempBprev->next = tempA;
            tempBnext->prev = tempA;
            tempA->prev = tempBprev;
            tempB->prev = tempAprev;
            tempA->next = tempBnext;
            tempB->next = tempAnext;
        }
    }

    void doubly_linked_list::swap_set(unsigned location_1_start, unsigned location_1_end, unsigned location_2_start,
                                      unsigned location_2_end) {
        node* tempA = head;
        if(location_1_start > location_2_start && location_1_start > location_2_end){
            int start = location_1_start;
            int end = location_1_end;
            location_1_start = location_2_start;            //makes sure that the start1 is before start2
            location_2_start = start;                       //makes sure that start1 comes before end2
            location_1_end = location_2_end;
            location_2_end = end;
        }
        if(location_1_start > location_1_end){
            int temp = location_1_start;            //performs a simple temp swap if the start and end locations are flipped for location1
            location_1_start = location_1_end;
            location_1_end = temp;
        }
        if(location_2_start > location_2_end){
            int temp = location_2_start;
            location_2_start = location_2_end;
            location_2_end = temp;
        }
        if(location_1_end >= location_2_start){
            throw "error: invalid location bounds.";
        }
        int count = 0;
        while(count != location_1_start){
            tempA = tempA->next;
            count++;
        }
        node* tempB = tempA;
        while(count != location_1_end){
            tempB = tempB->next;
            count++;
        }
        node* tempC = tempB;
        while(count != location_2_start){
            tempC = tempC->next;
            count++;
        }
        node* tempD = tempC;
        while(count != location_2_end){
            tempD = tempD->next;
            count++;
        }
        node* tempAprev = tempA->prev;
        node* tempAnext = tempB->next;
        node* tempBprev = tempC->prev;
        node* tempCnext = tempD->next;

        if (tempAprev != nullptr && tempCnext != nullptr && tempBprev == tempB){
            tempAprev->next = tempC;
            tempC->prev = tempAprev;
            tempD->next = tempA;
            tempA->prev = tempD;
            tempB->next = tempCnext;
            tempCnext->prev = tempB;
        }
        else if(tempAprev == nullptr && tempCnext != nullptr){                       //edge case for swapping set with head and another set that does not have a tail
            if(tempAnext == tempD || tempBprev == tempD){
               tempC->prev = nullptr;
                tempD->next = tempA;
                tempA->prev = tempD;
                tempB->next = tempCnext;
                tempCnext->prev = tempD;
                head = tempC;
            }
            else{
                tempC->prev = nullptr;
                tempD->next = tempAnext;
                tempAnext->prev = tempD;
                tempBprev->next = tempA;
                tempA->prev = tempBprev;
                tempB->next = tempCnext;
                tempCnext->prev = tempB;
                head = tempC;
            }
        }
        else if(tempAprev != nullptr && tempCnext == nullptr){                       //edge case for swapping a set with tail and a set that does not have a head
            if(tempBprev == tempB){
                tempAprev->next = tempC;
                tempC->prev = tempAprev;
                tempD->next = tempA;
                tempB->prev = tempD;
                tempB->next = nullptr;
                tail = tempB;
            }
            else{
                tempAprev->next = tempC;
                tempC->prev = tempAprev;
                tempD->next = tempAnext;
                tempAnext->prev = tempD;
                tempBprev->next = tempA;
                tempA->prev = tempBprev;
                tempB->next = nullptr;
                tail = tempB;
            }
        }
        else if(tempAprev == nullptr && tempCnext == nullptr){
            if(tempBprev == tempB){
                tempC->prev = nullptr;
                tempD->next = tempA;
                tempA->prev = tempD;
                tempB->next = nullptr;
                head = tempC;
                tail = tempB;
            }
            else{
                tempC->prev = nullptr;
                tempD->next = tempAnext;
                tempAnext->prev = tempD;
                tempBprev->next = tempA;
                tempA->prev = tempBprev;
                tempB->next = nullptr;
                head = tempC;
                tail = tempB;
            }
        }
        else{
            tempAprev->next = tempC;
            tempC->prev = tempAprev;
            tempD->next = tempAnext;
            tempAnext->prev = tempD;
            tempBprev->next = tempA;
            tempA->prev = tempBprev;
            tempB->next = tempCnext;
            tempCnext->prev = tempB;
        }
    }

    void doubly_linked_list::sort() {
       if (!is_empty()){
           node* prev = head;
           node* current = prev->next;
           node* temp = current;
           int prev_location = 0;
           int current_location = 1;
           while (current != nullptr) {      //if so, then out of bounds or empty list.
               current = current->next;
               int temp_location = current_location;
               int temp_location2 = prev_location;
               while(temp->prev != nullptr && temp->get_data() < temp->prev->get_data()){
                   swap(temp_location,temp_location2);
                   temp_location--;
                   temp_location2--;
               }
               current_location++;
               prev_location++;
           }
       }
        throw "list is empty";
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
        while(!this->is_empty()){
            this->remove(0);
        }
        node* copy = rhs.head;
        while(copy != nullptr){
            this->append(copy->get_data());
            copy = copy->next;
        }
        return *this;
    }

    doubly_linked_list& doubly_linked_list::operator+=(const doubly_linked_list &rhs) {
        node *rhs_temp = rhs.head;
        while(rhs_temp != nullptr){
            this->append(rhs_temp->get_data());
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
        stream << std::string("NULL <- ");
        while(current->next){
            stream << current->get_data();
            stream << " <-> ";
            current = current->next;
        }
        stream << current->get_data();
        stream << " -> NULL";
        return stream;
    }

    std::istream &operator>>(std::istream &stream, doubly_linked_list &RHS) {
        int input;
        stream >> input;
        RHS.append(input);
        return stream;
    }
}

