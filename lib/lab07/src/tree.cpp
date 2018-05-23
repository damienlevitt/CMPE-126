#include "../inc/tree.h"

namespace lab7 {
    void clear(node *to_clear);
    int recursive_level(node* top, int location);
    void recursive_insert(node* top, int value);
    node* find_node(node* top, int key);
    node* find_parent(node* top, node* target);
    bool has_children(node* target);
    node* calc_swap(node* top);
    void recursive_path_to(node* top, int key);
    unsigned recursive_size(node* top);
    unsigned recursive_depth(node* top);
    bool recursive_in_tree(node* top, int key);


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
        if(!(in_tree(key))){
            node* target = find_node(root, key);
            if(target->frequency > 1){
                target->frequency--;
                return true;
            }
            node* target_parent = find_parent(root, target);
            if (has_children(target)) {
                node *target_swap = calc_swap(target);
                node *parent_swap = find_parent(root, target_swap);

                if (has_children(target_swap)) parent_swap->right = target_swap->left;
                else parent_swap->right = nullptr;

                target_swap->left = target->left;
                target_swap->right = target->right;
                if(target_parent != nullptr) {
                    if (target_parent->left == target) target_parent->left = target_swap;
                    else target_parent->right = target_swap;
                }
                else root = target_swap;
            }
            else {
                if(target_parent != nullptr) {
                    if (target_parent->left == target) target_parent->left = nullptr;
                    else target_parent->right = nullptr;
                }
                else root = nullptr;
            }
            delete target;
            return true;
        }
        else return false;
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
        recursive_path_to(root, key);
    }

    // Number of items in the tree
    unsigned tree::size() {
        recursive_size(root);
    }

    // Calculate the depth of the tree, longest string of connections
    unsigned tree::depth() {
        recursive_depth(root);
    }

    // Determine whether the given key is in the tree
    bool tree::in_tree(int key) {
        recursive_in_tree(root, key);
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
    int recursive_level(node* top, int location){
        if(top->data == location){
            return 0;
        }
        else if(location < top->data){                                   //if location is less than top node data go left
            return(recursive_level(top->left, location) + 1);
        }
        else if (location > top->data){                                  //if location is greater than top node data goes right
            return(recursive_level(top->right, location) +1);
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
        node* find_parent(node* top, node* target){
            if(top != target){
                if(top->left == target || top->right == target){
                    return top;
                }
                else if (target->data < top->data){
                        return find_parent(top->left, target);
                    }
                else if (target->data > top->data){
                    return find_parent(top->right,  target);
                }

                }
             else
                return top;
        }

    bool has_children(node* target){
        if (!(target->left != nullptr || target->right != nullptr)){
            return false;
        }
        else return true;
    }

    node* calc_swap(node* top){
        if(!(top->left)){
            top = top->right;
            return top;
        }
        else
            top = top->left;
            while(top->right){
                top = top->right;
                return top;
            }
    }
    void recursive_path_to(node* top, int key){
        std::cout << top->data;
        if(!(top->data == key)){
            std::cout << " -> ";
            if(key < top->data){
                recursive_path_to(top->left, key);
            }
            else recursive_path_to(top->right, key);
        }
        else{
            if(top->data == key){
                std::cout << std::endl;
                return;
            }
        }
    }

    unsigned recursive_size(node* top){
        if(top != nullptr){
            return top->frequency + recursive_size(top->left) + recursive_size(top->right);
        }
        else
            return 0;
    }

    unsigned recursive_depth(node* top){
        if(top == nullptr){
            return 0;
        }
        unsigned left = 0;
        unsigned right = 0;
        left = 1 + recursive_depth(top->left);
        right = 1 + recursive_depth(top->right);
        if(right < left){
            return left;
        }
        else return right;
    }
    bool recursive_in_tree(node* top, int key){
        if(top->data == key){
            return true;
        }
        else if(key < top->data){
            return recursive_in_tree(top->left, key);
        }
        else if(key > top->data){
            return recursive_in_tree(top->right, key);
        }
        else
            return false;
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