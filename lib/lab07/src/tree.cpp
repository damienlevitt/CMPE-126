#include "../inc/tree.h"
#include <iostream>

namespace lab7 {
    void clear(node *to_clear);
    int recursive_level(node* top, int location);
    void recursive_insert(node* top, int value);
    node* find_node(node* top, int key);

    // Construct an empty tree
    tree::tree() {
        root = nullptr;
        tree_size = 0;
    }

    // Copy constructor
    tree::tree(const tree &copy) {

    }

    // Deconstruct tree
    tree::~tree() {
        clear(root);
    }

    // Insert
    void tree::insert(int value) {
        if(root == nullptr){
            root = new node(value);
        }
        else{
            recursive_insert(root, value);                           //needs a recursive insertion case if the tree is not just one root.
            }
        }


    // Remove key return true if the key is deleted, and false if it isn't in the tree
    bool tree::remove(int key) {
        if(in_tree(key)){
            node *target = find_node(root, key);
            if(target->frequency > 1){
                target->frequency--;
                return true;
            }
        }
       // node* target_parent =
    }

    // What level is key on?
    int tree::level(int key) {
       // node* top;
        if(in_tree(key)){
            return recursive_level(root, key);
        }
        else
            return -1;
    }

    // Print the path to the key, starting with root
    void tree::path_to(int key) {

    }

    // Number of items in the tree
    unsigned tree::size() {

    }

    // Calculate the depth of the tree, longest string of connections
    unsigned tree::depth() {

    }

    // Determine whether the given key is in the tree
    bool tree::in_tree(int key) {

    }

    // Return the number of times that value is in the tree
    int tree::get_frequency(int key) {

    }

    // Return a string of all of the elements in the tree in order
    std::string tree::to_string() {

    }

    //Use the to string function for the following two functions
    // Print the tree least to greatest, Include duplicates
    void tree::print() {

    }

    // Print the tree least to greatest, Include duplicates
    std::ostream &operator<<(std::ostream &stream, tree &RHS) {

    }

    // Operator= Overload. Allowing for copying of trees
    tree &tree::operator=(const tree &rhs) {

    }

    //Auxiliary function implementations//
    int recursive_level(node* top, int key){
        if(top->data == key){
            return 0;
        }
        else if(key < top->data){                                   //if key is less than top node data go left
            return(recursive_level(top->left, key) + 1);
        }
        else if (key > top->data){                                  //if key is greater than top node data goes right
            return(recursive_level(top->right, key) +1);
        }
    }

    void recursive_insert(node* top, int value){
        if(value < top->data){                                         //makes sure the smaller value goes left
            if(top->left == nullptr){                               //if the top left node is null
                top->left = new node(value);                        //inserts a new node at the location
            }
            else
                recursive_insert(top->left, value);                 //otherwise recursively iterates to location and creates a new node
        }
        else if(value > top->data){                                 //larger data goes right
            if(top->right == nullptr){
                top->right = new node(value);
            }
            else
                recursive_insert(top->right, value);
        }
        else if(value == top->data){                                   //edge case if the value equals the data of the top node
            top->frequency++;
        }
    }
        node* find_node(node* top, int key){
            if(top->data == key){
                return top;
            }
            else if(key < top->data){
                return(find_node(top->left, key));
            }
            else if(key > top->data){
                return(find_node(top->right, key));
            }
        }


    /**************************
     * Extra credit functions *
     **************************/

    // Return a vector with all of the nodes that are greater than the input key in the tree
    std::vector<int> tree::values_above(int key) {

    }

    // Merge rhs into this. Demo to a TA for credit
    tree tree::operator+(const tree &rhs) const {

    }

    // Balance the tree using any published algorithm. Demo to a TA for credit
    void tree::balance() {

    }

    /*********************************************************************
     * Recursion Example                                                 *
     * Print the linked list from greatest to least using recursion      *
     *********************************************************************/

    // Auxiliary functions
    void node_print_gtl(node *top) {
        if (top == nullptr) return;
        node_print_gtl(top->right);
        for (int i = 0; i < top->frequency; i++) std::cout << top->data << " ";
        node_print_gtl(top->left);
    }

    void clear(node *to_clear) {
        if (to_clear == nullptr) return;
        if (to_clear->left != nullptr) clear(to_clear->left);
        if (to_clear->right != nullptr) clear(to_clear->right);
        delete to_clear;
    }

    // Class function
    void tree::print_gtl() {
        node_print_gtl(root);
        std::cout << std::endl;
    }
}