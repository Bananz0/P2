#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


std::vector<bool> convertDecToBinary(int g);


int convertBinaryToDec(std::vector<bool> binaryArray);
std::vector<bool> complementBinaryArray(std::vector<bool> binaryArray);
void printBinaryArray(std::vector<bool> binaryArray);



int input1, input2;
char operatorType;
int maxSize = 8;



//This is an attempt to build a binary adder

int main()
{
    
    //Single Bit Adder
    class BitAdder {
    public:
        bool sum = 0; 
        bool carryOut = 0;

        BitAdder(bool a, bool b, bool carryIn) {
            carryOut = 0;
            sum = a ^ b ^ carryIn;
            //sum = (~a & b) | (~b & a);
            carryOut = (a & b) | (carryIn & a) | (carryIn & b);
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
        nBitAdder(std::vector<bool> num1, std::vector<bool> num2)
        {
            //int maxSize = std::max(num1.size(), num2.size());
            //int minSize = std::min(num1.size(), num2.size());
            //maxSize = 9;


            bool carry = false;
            for (int h = maxSize - 1; h > 0; h--) {




                //bool bit1 = h < num1.size() ? num1[h] : 0;
                //bool bit2 = h < num2.size() ? num2[h] : 0;
                BitAdder adderUno(num1[h], num2[h], carry);


                //std::cout << "" << std::endl;
                //std::cout << "---------------- " << std::endl;
                //std::cout << "Sum value is: " << adderUno.getSum() << std::endl;
                //std::cout << "Carry value is " << adderUno.getCarry() << std::endl;
                //std::cout << "---------------- " << std::endl;
                //std::cout << ""  << std::endl;
    
                totalSum.push_back(adderUno.getSum());

                /*std::cout << totalSum[h];*/
                carry = adderUno.getCarry();
                //printBinaryArray(totalSum);
            }
        }
        std::vector<bool> getSum() {
            return totalSum;
        }
    };

    //User Input
    std::cout << "Please enter the first binary number (A): ";
    std::cin >> input1;
    std::vector<bool> binary1 = convertDecToBinary(input1);

    std::cout << "Select Operation (+ or -): ";
    std::cin >> operatorType;

    std::cout << "Please enter the second binary number (B): ";
    std::cin >> input2;
    std::vector<bool> binary2 = convertDecToBinary(input2);

    nBitAdder fullAdder(binary1, binary2);

    //int decTotal = convertBinaryToDec({1,1,0});
    int decTotal = convertBinaryToDec(fullAdder.getSum());

    printBinaryArray(fullAdder.getSum());
    std::cout << "The decimal equivalent is: " << decTotal;
}



std::vector<bool> convertDecToBinary(int g)
{
    std::vector<bool> binArray, binArrayOut, binArrayComplement;
    
    if (g < 0) {
        g = -g;
        operatorType = '-';
    }

    while (g != 0) {
        binArray.push_back(g % 2);
        g = g / 2;
    }
    std::reverse(binArray.begin(), binArray.end());
    while (binArray.size() < maxSize) {
        binArray.insert(binArray.begin(), false); // Insert '0' at the beginning
    }


    binArrayOut = binArray;
    if (operatorType == '-') {
    binArrayComplement = complementBinaryArray(binArray);
    binArrayOut = binArrayComplement;
        
    } else if (operatorType == '+'){
        binArrayOut = binArray;
    }
    printBinaryArray(binArrayOut);
    return binArrayOut;

}

int convertBinaryToDec(std::vector<bool> binaryArray) {
    int decNum = 0;
    int n = binaryArray.size();
    //std::cout << "The size of the binary array is: " << n << std::endl;
    for (int j = 0; j < n; j++) {
        decNum = decNum + binaryArray[j] * pow(2, n - j - 1);
    }
    return decNum;
}

void printBinaryArray(std::vector<bool> binArray) {
    std::cout << "The corresponding value in binary is: ";
    for (int y = 0; y < binArray.size(); y++) {
        std::cout << binArray[y];
    }
    std::cout << std::endl;
}

std::vector<bool> complementBinaryArray(std::vector<bool> binaryArray) {
    std::vector<bool> binArrayComplement;
    //One's complement operation
    for (int i = binaryArray.size() - 1; i > 0; i--) {
        binArrayComplement.push_back(1 ^ binaryArray[i]);
    }
    //Two's complement operation
    //Add 1
    for (int j = binArrayComplement.size() - 1; j > 0; j--) {
        if (binArrayComplement[j] == 0) {
            binArrayComplement[j] = 1;
            break;
        }
        else { binArrayComplement[j] = 0; }
        }
    return binArrayComplement;
}