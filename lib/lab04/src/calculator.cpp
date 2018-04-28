#include <iostream>
#include "calculator.h"
namespace lab4 {
    int operator_priority(std::string operator_in);
    bool is_number (std::string input_string);
    bool is_operator(std::string input_string);


    void calculator::parse_to_infix(std::string &input_expression) {
        int size = 0;
        int op = 0;
        int infix_size = 0;
        std::string temp[input_expression.size()];
        for (std::string::iterator count = input_expression.begin(); count != input_expression.end(); ++count) {
            temp[size] = *count;
            size++;
        }
        for (int i = 0; i < size; i++) {
            std::string n = temp[i].data();
            if (temp[i] == " ") {
                i++;
            } else if (i == size - 1) {
                infix_expression.enqueue(temp[i]);
                infix_size++;
            }
            if (i != size - 1 && !is_number(temp[i])) {
                infix_expression.enqueue(temp[i]);
                infix_size++;
            }
            if (i != size - 1 && is_number(temp[i]) && !is_number(temp[i + 1])) {
                infix_expression.enqueue(temp[i]);
                infix_size++;
            }
            if (i != size - 1 && is_number(temp[i]) && is_number(temp[i + 1])) {
                op = i;
                if (op == size - 2) {
                    op = op + 2;
                }
                if (op == size - 3) {
                    op = op + 3;
                }
                if (op != size) {
                    while (op != size - 1 && is_number(temp[op])) {
                        op++;
                    }
                }
                std::string int_temp;
                for (int z = i; z < op; z++) {
                    int_temp += temp[i++];
                }
                i = op - 1;
                infix_expression.enqueue(int_temp);
                infix_size++;
            }
        }
    }

    void calculator::convert_to_postfix(lab3::fifo infix_expression) {
        lab3::fifo infix_copy(infix_expression);
        lab3::lifo OperatorStack;
        std::string temporary;
        while(!infix_copy.is_empty()) {
            temporary = infix_copy.top();
            if (is_number(temporary)){
                postfix_expression.enqueue(temporary);
            }
            if(is_operator(temporary)) {
                while (!OperatorStack.is_empty() && (operator_priority(OperatorStack.top()) >= operator_priority(temporary)) && (OperatorStack.top() != "(")){
                    postfix_expression.enqueue(OperatorStack.top());
                    OperatorStack.pop();
                }
                OperatorStack.push(temporary);
            }
            if (temporary == "(") {
                OperatorStack.push(temporary);
            }
            if (temporary == ")") {
                while (OperatorStack.top() != "("){
                    postfix_expression.enqueue(OperatorStack.top());
                    OperatorStack.pop();
                }
                OperatorStack.pop();
            }
            infix_copy.dequeue();
        }
        while(!OperatorStack.is_empty()) {
            postfix_expression.enqueue(OperatorStack.top());
            OperatorStack.pop();
        }
    }

    calculator::calculator() {

    }

    calculator::calculator(std::string &input_expression) {
        parse_to_infix(input_expression);
        convert_to_postfix(infix_expression);
    }

    std::istream &operator>>(std::istream &stream, calculator &RHS) {
        std::string temporary = " ";
        lab3::fifo infix_expression;
        while(stream.peek() != EOF){
            temporary = stream.get();
            RHS.parse_to_infix(temporary);
            RHS.convert_to_postfix(infix_expression);
            return stream;
        }
    }

    int lab4::calculator::calculate() {
        int answer = 0;
        bool is_number(std::string input_string);
        bool is_operator(std::string input_string);
        lab3::lifo tempStack;
        while (!postfix_expression.is_empty()) {
            std::string temp = postfix_expression.top();
            if (is_number(postfix_expression.top())) {
                tempStack.push(postfix_expression.top());
                postfix_expression.dequeue();
            } else if (is_operator(postfix_expression.top())) {
                std::string tempOp = postfix_expression.top();
                postfix_expression.dequeue();
                int temp = std::stoi(tempStack.top());
                tempStack.pop();
                int temp1 = std::stoi(tempStack.top());
                tempStack.pop();
                if (tempOp == "/") {
                    answer = temp1 / temp;
                    std::string in = std::to_string(answer);
                    tempStack.push(in);
                } else if (tempOp == "*") {
                    answer = temp1 * temp;
                    std::string in = std::to_string(answer);
                    tempStack.push(in);
                } else if (tempOp == "+") {
                    answer = temp1 + temp;
                    std::string in = std::to_string(answer);
                    tempStack.push(in);
                } else if (tempOp == "-") {
                    answer = temp1 - temp;
                    std::string in = std::to_string(answer);
                    tempStack.push(in);
                }
            }
        }

        return answer;
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
    bool is_number(std::string const input_string){
        if (input_string >= "0" && input_string <= "999"){
            if(input_string == "-" || input_string == "+" || input_string == "/" || input_string == "*" || input_string == "(" || input_string == ")"){
                return false;
            }                                               //Determines if there are numbers in input_string by
            return true;
        }
    }

    bool is_operator(std::string const input_string){
        if(input_string == "+" || input_string == "-" || input_string == "*" || input_string == "/") {
            return true;
        }
        return false;                                       // Just determines if there is an operator in input_string.
    }

    int get_number(std::string input_string);

    std::string get_operator(std::string input_string);

    int operator_priority(std::string const operator_in){
        int n;
        if(operator_in == "+" || operator_in == "-"){
            n = 1;
        }
        else if (operator_in == "*" || operator_in == "/"){
            n = 2;                                  //Will give precedence to the operators.
        }
        else if (operator_in == "^"){
            n = 3;
        }
        return n;
    }
}