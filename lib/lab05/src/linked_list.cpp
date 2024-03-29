#include <linked_list.h>
#include "node.h"
namespace lab5 {
    linked_list::linked_list() {
        head = nullptr;
        tail = nullptr;
    }

    linked_list::linked_list(std::string &data) {
        head = nullptr;
        tail = nullptr;
        append(data);
    }

    linked_list::linked_list(const linked_list &original) {
        node* link = original.head;
        node* linkcopy = head;
        for (int n = 0; n < original.listSize(); n++){
            linkcopy -> data = link -> data;
            linkcopy -> next = link -> next;
        }
    }

    linked_list::~linked_list() {
        node* cnode = head;
        while(cnode != nullptr){
            node* nextnode = cnode -> next;
            delete cnode;
            cnode = nextnode;
        }
        head = nullptr;
    }

    linked_list &lab5::linked_list::operator=(const linked_list &RHS) {
        //return <#initializer#>;
    }


    bool linked_list::isEmpty() const {
        node* cnode = head;
        node* tail;
        if(cnode == nullptr && tail == nullptr){
            return true;
        }
        else
            return false;
    }

    unsigned linked_list::listSize() const {
        node *cnode = head;
        int count = 0;
        if (cnode == nullptr){
            throw "list is empty";
        }
        else
            while(cnode != nullptr){
                cnode = cnode -> next;
                count++;
                return count;
            }
    }

    void linked_list::insert(const std::string input, unsigned int location) {
            node* new_node = new node(input);
            node* previous = nullptr;
            node* cnode;
        if(head == nullptr){
            new_node ->next = head;
            head = new_node;
        }
        else {
            for(int i = 0; i < location; i++){
                new_node ->next = cnode;
                previous -> next = new_node;
            }
        }
    }

    void linked_list::append(const std::string input) {
        node *new_node = new node(input);
        if (head == nullptr) {
            head = new_node;
        } else
            new_node = head;
        if (new_node->next == nullptr) {
            throw "can't add to list";
        }
        else
            new_node = new_node->next;
            new_node ->next = new node(input);
    }

    void linked_list::remove(unsigned location) {
        node *previous = nullptr;
        node *cnode = head;
        if(isEmpty()){
            throw "stack is empty";
        }
        for(int n = 0; n < location; n++){
            previous = cnode;
            cnode = cnode->next;

            if(location > listSize()){
                throw "cannot remove";
            }
            else previous->next = cnode->next;
        }
    }

    std::ostream& operator<<(std::ostream &stream, linked_list &RHS) {
        node* cnode = RHS.head;
        while (cnode != nullptr){
            stream << cnode ->data;
        }
        return stream;
    }

    std::istream& operator>>(std::istream &stream, linked_list &RHS) {
        std::string temp;
        stream >> temp;
        RHS.append(temp);

        return stream;
    }

    void linked_list::sort() {
        node *new_node;
        node *cnode = head;
        for (cnode = head; cnode ->next != nullptr; cnode == cnode->next){
            if (cnode ->data > cnode->next->data){
                new_node ->data = cnode ->data;
                cnode ->data = cnode ->next->data;
                cnode -> next ->data = new_node-> data;
            }

        }

    }

    std::string linked_list::get_value_at(unsigned location) {
        std::string temp;
        node* cnode = head;
        for(int i=0; i<location; i++){
            cnode = cnode->next;
            temp = cnode->data;
        }
        return std::string(temp);
    }
}