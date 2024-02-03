#include <iostream>


//This is an attempt to build a binary adder

int main()
{
    int num1, num2;

    class BitAdder {
    public:
        int sum,carryOut;

        BitAdder(int a, int b, int carryIn) {
            sum = a ^ b ^ carryIn; 
            //sum = (~a & b) | (~b & a);
            carryOut = (a & b) | (carryIn & (a ^ b));
        }

        int getSum() {
            return sum;
        }
        int getCarry() {
            return carryOut;
        }
        
    };

   



    //User Input
    std::cout << "Please enter the first binary number (either 0 or 1): ";
    std::cin >> num1;
    std::cout << "Please enter the second binary number (either 0 or 1): ";
    std::cin >> num2;
    
    //Convert user input to bits


    //Actual adding
    BitAdder adderUno(1,1,0);
    std::cout << "Sum value is: " << adderUno.getSum() << std::endl;
    std::cout << "Carry value is " << adderUno.getCarry() << std::endl;


}
