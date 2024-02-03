#include <iostream>
#include <vector>
#include <cmath>


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
        std::vector<bool> totalSum;

    public:
        nBitAdder (std::vector<bool> num1, std::vector<bool> num2)
        {

            bool carry = false;
            for (int h = 0; h < num1.size(); h++) {
                BitAdder adderUno(num1[h], num2[h], carry);
                

                std::cout << "---------------: " << std::endl;
                std::cout << "Sum value is: " << adderUno.getSum() << std::endl;
                std::cout << "Carry value is " << adderUno.getCarry() << std::endl;
                std::cout << "---------------: " << std::endl;
                std::cout << ""  << std::endl;


                totalSum.push_back(adderUno.getSum());
                carry = adderUno.getCarry();

                
            }
        }

        std::vector<bool> getSum() {
            return totalSum;
        }
    };
   



    //User Input
    std::cout << "Please enter the first binary number (either 0 or 1): ";
    std::cin >> input1;
    std::vector<bool> binary1 = convertDecToBinary(input1); 

    std::cout << "Please enter the second binary number (either 0 or 1): ";
    std::cin >> input2;
    std::vector<bool> binary2 = convertDecToBinary(input2);
    

    nBitAdder fullAdder(binary1, binary2);



 

}

//Convert user input to bits
std::vector<bool> convertDecToBinary(int g)
{
    std::vector<bool> binArray;
    while (g > 0) {
        binArray.push_back(g % 2);
        g = g / 2;
    }
    std::reverse(binArray.begin(), binArray.end());
    return binArray;
}