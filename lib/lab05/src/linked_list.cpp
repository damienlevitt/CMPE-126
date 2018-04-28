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
        return false;
    }

    unsigned linked_list::listSize() const {
        return 0;
    }

    void linked_list::insert(const std::string input, unsigned int location) {

    }

    void linked_list::append(const std::string input) {

    }

    void linked_list::remove(unsigned location) {

    }

    std::ostream& operator<<(std::ostream &stream, linked_list &RHS) {
        return stream;
    }

    std::istream& operator>>(std::istream &stream, linked_list &RHS) {
        return stream;
    }

    void linked_list::sort() {

    }

    std::string linked_list::get_value_at(unsigned location) {

    }
}