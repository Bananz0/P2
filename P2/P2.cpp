#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


std::vector<bool> convertDecToBinary(int g);
int convertBinaryToDec(std::vector<bool> binaryArray);
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
            int maxSize = std::max(num1.size(), num2.size());
            bool carry = false;
            for (int h = 0; h < maxSize; h++) {
                bool bit1 = h < num1.size() ? num1[h] : 0;
                bool bit2 = h < num2.size() ? num2[h] : 0;
                BitAdder adderUno(bit1, bit2, carry);
                
                //std::cout << "" << std::endl;
                //std::cout << "---------------: " << std::endl;
                //std::cout << "Sum value is: " << adderUno.getSum() << std::endl;
                //std::cout << "Carry value is " << adderUno.getCarry() << std::endl;
                //std::cout << "---------------: " << std::endl;
                //std::cout << ""  << std::endl;


                totalSum.push_back(adderUno.getSum());
                std::cout << totalSum[h];
                carry = adderUno.getCarry();
                if (h == maxSize - 1) {
                    totalSum.push_back(adderUno.getCarry());
                }

                
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

    //int decTotal = convertBinaryToDec({1,0,1,1,1,0,1});
    int decTotal = convertBinaryToDec(fullAdder.getSum());


    std::cout << decTotal;


 

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
    for (int y = 0; y < binArray.size(); y++) {
        std::cout << binArray[y];
    }
    std::cout << std::endl;
    return binArray;
}

int convertBinaryToDec(std::vector<bool> binaryArray) {
    int decNum = 0;
    int n = binaryArray.size();
    std::cout << "The size of the binary array is: " << n << std::endl;
    for (int j = 0; j < n; j++) {
        decNum += binaryArray[j] * pow(2, n - j - 1);
    }
    return decNum;
}
