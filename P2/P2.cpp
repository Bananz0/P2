#include <iostream>


//This is an attempt to build a binary adder

int main()
{
    int input1, input2;
    



    //Single Bit Adder
    class BitAdder {
    public:
        bool sum,carryOut;

        BitAdder(bool a, bool b, int carryIn) {
            sum = a ^ b ^ carryIn; 
            //sum = (~a & b) | (~b & a);
            carryOut = (a & b) | (carryIn & (a ^ b));
        }

        bool getSum() {
            return sum;
        }
        bool getCarry() {
            return carryOut;
        }
        
    };


    //N - Bit adder
    class nBitAdder {

    private: 
        bool sum, carry;
        int totalSum[8];

    public:
        nBitAdder ()
        {
            int num1[8] = { 0,0,0,0,0,0 };

            int num2[8] = { 0,0,0,0,0,0 };
            bool carry = false;
            for (int h = 0; h < 8; h++) {                
                BitAdder adderUno(num1[h], num2[h], carry);
                carry = adderUno.getCarry();

                std::cout << "---------------: " << std::endl;
                std::cout << "Sum value is: " << adderUno.getSum() << std::endl;
                std::cout << "Carry value is " << adderUno.getCarry() << std::endl;
                std::cout << "---------------: " << std::endl;
                std::cout << ""  << std::endl;


                totalSum[h] = adderUno.getSum();

                
            }
        }

        int getSum() {
            return totalSum;
        }
    };
   



    //User Input
    std::cout << "Please enter the first binary number (either 0 or 1): ";
    std::cin >> input1;
    std::cout << "Please enter the second binary number (either 0 or 1): ";
    std::cin >> input2;
    


    //Actual adding
    BitAdder adderUno(1,1,0);
    std::cout << "Sum value is: " << adderUno.getSum() << std::endl;
    std::cout << "Carry value is " << adderUno.getCarry() << std::endl;

    //nBit adding
    nBitAdder fullAdder;
    std::cout << "Total sum value is: " << fullAdder.getSum() << std::endl;
 

}

//Convert user input to bits
int convertDecToBinary(int g)
{
    int binArrayMirror[16], bitSize = 0;

    for (int i = 0; g > 0; i++) {
        binArrayMirror[i] = g % 2;
        g = g / 2;
        bitSize += 1;
    }
    return 0;
}