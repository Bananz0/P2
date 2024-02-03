#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


std::vector<int> convertDecToBinary(int g);
int convertBinaryToDec(std::vector<int> binaryArray);

void printBinaryArray(std::vector<int> binaryArray);
//This is an attempt to build a binary adder

int main()
{
    int input1, input2;
    char operatorType;

    //Single Bit Adder
    class BitAdder {
    public:
        int sum, carryOut;

        BitAdder(int a, int b, int carryIn) {
            carryOut = 0;
            sum = a ^ b ^ carryIn;
            //sum = (~a & b) | (~b & a);
            carryOut = (a & b) | (carryIn & a) | (carryIn & b);
        }

        int getSum() {
            return sum;
        }
        int getCarry() {
            return carryOut;
        }

    };

    //N - Bit adder
    class nBitAdder {

    private:
        int sum, carry;
        std::vector<int> totalSum, totalSumReverse;

    public:
        nBitAdder(std::vector<int> num1, std::vector<int> num2)
        {
            int maxSize = std::max(num1.size(), num2.size());
            int carry = false;
            for (int h = 0; h < maxSize; h++) {
                int bit1 = h < num1.size() ? num1[h] : 0;
                int bit2 = h < num2.size() ? num2[h] : 0;
                BitAdder adderUno(bit1, bit2, carry);

                //std::cout << "" << std::endl;
                //std::cout << "---------------- " << std::endl;
                //std::cout << "Sum value is: " << adderUno.getSum() << std::endl;
                //std::cout << "Carry value is " << adderUno.getCarry() << std::endl;
                //std::cout << "---------------- " << std::endl;
                //std::cout << ""  << std::endl;


                totalSum.push_back(adderUno.getSum());
                /*std::cout << totalSum[h];*/
                carry = adderUno.getCarry();
                if (h == maxSize - 1) {
                    totalSum.push_back(adderUno.getCarry());
                }
                totalSumReverse = totalSum;
                std::reverse(totalSumReverse.begin(), totalSumReverse.end());
                //printBinaryArray(totalSum);
                //printBinaryArray(totalSumReverse);

            }

        }

        std::vector<int> getSum() {
            return totalSumReverse;
        }
    };

    //User Input
    std::cout << "Please enter the first binary number (A): ";
    std::cin >> input1;
    std::vector<int> binary1 = convertDecToBinary(input1);

    std::cout << "Please enter the second binary number (B): ";
    std::cin >> input2;
    std::vector<int> binary2 = convertDecToBinary(input2);

    std::cout << "Select Operation (+ or -): ";
    std::cin >> operatorType;
    


    //Operator checking


    nBitAdder fullAdder(binary1, binary2);

    //int decTotal = convertBinaryToDec({1,0,1,1,1,0,1});
    int decTotal = convertBinaryToDec(fullAdder.getSum());

    printBinaryArray(fullAdder.getSum());
    std::cout << "The decimal equivalent is: " << decTotal;




}

//Convert user input to bits
std::vector<int> convertDecToBinary(int g)
{
    std::vector<int> binArray, binArrayOut;
    while (g > 0) {
        binArray.push_back(g % 2);
        g = g / 2;
    }
    binArrayOut = binArray;
    std::reverse(binArrayOut.begin(), binArrayOut.end());
    std::cout << "The corresponding value in binary is: ";
    for (int y = 0; y < binArrayOut.size(); y++) {
        std::cout << binArrayOut[y];
    }
    std::cout << std::endl;
    return binArray;
}

int convertBinaryToDec(std::vector<int> binaryArray) {
    int decNum = 0;
    int n = binaryArray.size();
    //std::cout << "The size of the binary array is: " << n << std::endl;
    for (int j = 0; j < n; j++) {
        decNum = decNum + binaryArray[j] * pow(2, n - j - 1);
    }
    return decNum;
}

void printBinaryArray(std::vector<int> binaryArray) {
    for (int y = 0; y < binaryArray.size(); y++) {
        std::cout << binaryArray[y];
    }
    std::cout << std::endl;
}
