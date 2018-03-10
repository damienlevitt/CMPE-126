
#include <string>
#include "calculator.h"
int operator_priority(std::string operator_in);
bool is_number (std::string input_string);
bool is_operator(std::string input_string);

namespace lab4 {
    void calculator::parse_to_infix(std::string &input_expression) {
        std::string temp = "";
        int front_index = 0;
        int back_index = 0;
        int input_size = input_expression.size();
        while (back_index < input_size) {
            if (input_expression[input_size] == '') {
                if (front_index == 0) {
                    back_index++;
                }
                else {
                    infix_expression.enqueue(temp);
                    temp = "";
                    back_index++;
                    front_index = 0;
                }
            }
                else {
                    temp+=input_expression[back_index];
                    back_index++;
                    front_index++;

            }
        }


    }

    void calculator::convert_to_postfix(lab3::fifo infix_expression) {
        lab3::fifo infix_copy(infix_expression);
        lab3::lifo opStack;
        std::string temp;
        while(!infix_copy.is_empty()) {
            temp = infix_copy.top();
            if (is_number(temp)){
                postfix_expression.enqueue(temp);
            }
            if(is_operator(temp)) {
                while (!opStack.is_empty() && (operator_priority(opStack.top()) >= operator_priority(temp)) && (opStack.top() != "(a")){
                    postfix_expression.enqueue(opStack.top());
                    opStack.pop();
                }
                opStack.push(temp);
            }
            if (temp == "(") {
                opStack.push(temp);
            }
            if (temp == ")") {
                while (opStack.top() != "("){
                    postfix_expression.enqueue(opStack.top());
                    opStack.pop();
                }
                opStack.pop();
            }
            infix_copy.dequeue();
        }
        while(!opStack.is_empty()) {
            postfix_expression.enqueue(opStack.top());
            opStack.pop();
        }
    }

    calculator::calculator() {

    }

    calculator::calculator(std::string &input_expression) {
        parse_to_infix(input_expression);
        convert_to_postfix(infix_expression);
    }

    std::istream &operator>>(std::istream &stream, calculator &RHS) {
        std::string input;
        getline(stream, input);
        RHS.parse_to_infix(input);
        RHS.convert_to_postfix(RHS.infix_expression);
        return stream;
    }

    int lab4::calculator::calculate() {
        int answer;
        bool is_number(std::string input_string);
        bool is_operator(std::string input_string);
        lab3::lifo final_stack;
        while(!postfix_expression.is_empty()){
            if (is_number(postfix_expression.top())){
                final_stack.push(postfix_expression.top());
                postfix_expression.dequeue();
            else if (is_operator(postfix_expression.top())){
                    std::string tempOp = postfix_expression.top();
                    postfix_expression.dequeue();
                    int temp = std::stoi(final_stack.top());
                    final_stack.pop();
                    int temp1 = std::stoi(final_stack.top());
                    final_stack.pop();
            if (tempOp == "/"){
                    answer = temp1 / temp;
                    std::string in = std::to_string(answer);
                    final_stack.push(in);
                    }
             else if (tempOp == "*") {
                answer = temp1 * temp;
                std::string in = std::to_string(answer);
                final_stack.push(in);
            }
            else if(tempOp == "+"){
                answer = temp1 +temp;
                std::string in = std::to_string(answer);
                final_stack.push(in);
            }
            else if(tempOp == "-"){
                answer = temp1 - temp;
                std::string in = std::to_string(answer);
                final_stack.push(in);
            }
                }
            }
        }
        return 0;
    }

    std::ostream &operator<<(std::ostream &stream, calculator &RHS) {
        lab3::fifo temp = RHS.infix_expression;
        lab3::fifo temp2 = RHS.postfix_expression;
        while(!temp.is_empty()) {
            stream << temp.top();
            temp.dequeue();
        }
        while(!temp2.is_empty()){
            stream << temp2.top();
            temp2.dequeue();
        }
        return stream;
    }


    // AUXILIARY FUNCTIONS
    bool is_number(std::string input_string){
        if (input_string >= "0" && input_string <= "999"){
            if(input_string == "-" || input_string == "+" || input_string == "/" || input_string == "*" || input_string == "(" || input_string == ")"){
                return false;
            }
            return true;
        }
    }

    bool is_operator(std::string input_string){
        if(input_string == "+" || input_string == "-" || input_string == "*" || input_string == "/") {
            return true;
        }
        return false;
    }

    int get_number(std::string input_string);

    std::string get_operator(std::string input_string);

    int operator_priority(std::string operator_in){
        int n;
        if(operator_in == "+" || "-"){
            n = 1;
        }
        else if (operator_in == "*" || "/"){
            n = 2;
        }
        else if (operator_in == "^"){
            n = 3;
        }
        return n;
    }
}