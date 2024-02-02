#include <iostream>


//This is an attempt to build a binary adder

int main()
{
    int num1, num2;
    class singleBitAdder {
    public:
        int sum;
        int carry;
        int add(int a, int b) {
            sum = a ^ b; 
            carry = a & b;
            return sum;
        }
    };
    std::cout << "Please enter the first binary number (either 0 or 1): ";
    num1 = std::cin.get();
    std::cout << "Please enter the second binary number (either 0 or 1): ";
    num2 = std::cin.get();

    singleBitAdder adderUno;
    std::cout << adderUno.add(num1, num2);


}
