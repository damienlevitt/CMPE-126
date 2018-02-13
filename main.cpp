#include <iostream>
#include <stringVector.h>
int main() {
    lab2::stringVector sample;
    sample.append(std::string("Example String"));
    std::cout << sample[0] << std::endl;
    sample.append(std::string("another Example"));
    std::cout << sample[1] << std::endl;
    sample.append(std::string("yet another"));
    std::cout << sample[2] << std::endl;
    return 0;
}