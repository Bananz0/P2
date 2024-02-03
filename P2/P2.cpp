#include <iostream>


//This is an attempt to build a binary adder

int main()
{
    int num1, num2;

    class singleBitAdder {
    public:
        int sum,carryOut;
        int add(int a, int b, int carryIn) {
            sum = a ^ b ^ carryIn; 
            carryOut = (a & b) | (carryIn & (a ^ b));
            return sum;
        }
    };

    //User Input
    std::cout << "Please enter the first binary number (either 0 or 1): ";
    std::cin >> num1;
    std::cout << "Please enter the second binary number (either 0 or 1): ";
    std::cin >> num2;
    

    //Actual adding
    singleBitAdder adderUno;
    std::cout << "Sum value is: " << adderUno.add(num1, num2, 0) << std::endl;
    std::cout << "Carry value is " << adderUno.carryOut << std::endl;


}
