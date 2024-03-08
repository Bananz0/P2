#include <iostream>
#include <vector>
#include <algorithm>
const int bitCount = 8;
bool overflow;
bool XOR(bool a, bool b);
bool OR(bool a, bool b);
bool AND(bool a, bool b);
std::vector<bool> complementBinaryVector(std::vector<bool> binVector);
std::vector<bool> convertDecToBinary(int dec);
void printBinaryVec(std::vector<bool> binVector);
void convertBinaryToDec(std::vector<bool> binVector);


class halfAdder {
private:
    bool sum = false, cOut = false;
public:
    halfAdder(bool a, bool b, bool c) {
        sum = XOR(XOR(a, b), c);
        cOut = (a & b) | (b & c) | (a & c);
    }
    bool getSum() {
        return sum;
    }
    bool getCarry() {
        return cOut;
    }
};

class nBitAdder {
private:
    std::vector<bool> binVecSum;
    bool cIn = false, sum, cOut, overflow;
public:
    nBitAdder(std::vector<bool> binVec1, std::vector<bool> binVec2, bool cIn) {
        for (int i = bitCount - 1; i >= 0; i--) {
            halfAdder adder(binVec1[i], binVec2[i], cIn);
            binVecSum.push_back(adder.getSum());
            cIn = adder.getCarry();
            if (i == 0 && cIn) {
                overflow = true;
                binVecSum.push_back(adder.getCarry());
            }
        }
        std::reverse(binVecSum.begin(), binVecSum.end());
    }
    std::vector<bool> getSum() {
        return binVecSum;
    }
    bool getOverflow() {
        return overflow;
    }
    bool getCarry() {
        return cIn;
    }
};

int main()
{
    bool binary1 = false, binary2 = false, cIn = false;
    int num1 = 0, num2 = 0;
    std::vector<bool> binVec1, binVec2, binVecSum;
    char operatorType = '+';

    std::cout << "Input your first number (A): ";
    std::cin >> num1;
    binVec1 = convertDecToBinary(num1);

    std::cout << "Input your second number (B): ";
    std::cin >> num2;
    binVec2 = convertDecToBinary(num2);

    std::cout << "Input your intended operation( (+) or (-) ): ";
    std::cin >> operatorType;
    binVec2 = convertDecToBinary(num2);

    printBinaryVec(binVec1);
    printBinaryVec(binVec2);

    std::cout << "cIn value is: ";
    std::cin >> cIn;
    if (operatorType == '-') {
        binVec2 = complementBinaryVector(binVec2);
    }

    nBitAdder BinaryAdder(binVec1, binVec2, cIn);
    binVecSum = BinaryAdder.getSum();

    printBinaryVec(binVecSum);
    convertBinaryToDec(binVecSum);
    std::cout << "Carry: " << BinaryAdder.getCarry() << " Overflow: " << BinaryAdder.getOverflow() << std::endl;
    std::cin.get();

}



bool XOR(bool a, bool b) {
    return a ^ b;
}
bool OR(bool a, bool b) {
    return a | b;
}
bool AND(bool a, bool b) {
    return a & b;
}
std::vector<bool> convertDecToBinary(int dec) {
    std::vector<bool> binVector;
    bool isNeg = false;
    //Handling negative numbers
    if (dec < 0) {
        dec = -dec;
        isNeg = 1;
    }
    while (dec > 0) {
        binVector.push_back(dec % 2);
        dec = dec / 2;
    }
    std::reverse(binVector.begin(), binVector.end());

    //Pad the vector to bitSize
    while (binVector.size() < bitCount) {
        binVector.insert(binVector.begin(), false);
    }
    if (isNeg) binVector = complementBinaryVector(binVector);
    return binVector;
}
std::vector<bool> complementBinaryVector(std::vector<bool> binVector) {
    //Bitwise Not (One's Complement)
    for (int i = 0; i < binVector.size(); i++) {
        binVector[i] = !binVector[i];
    }
    //two's Complement
    for (int i = binVector.size() - 1; i >= 0; i--) {
        if (binVector[i] == 0) {
            binVector[i] = 1;
            break;
        }
        binVector[i] = 0;
    }
    return binVector;
}
void printBinaryVec(std::vector<bool> binVector) {
    if (bitCount != binVector.size()) {
        std::cout << "The binary representation of the number is: ";
        for (int i = 1; i < binVector.size(); i++) {
            std::cout << binVector[i];
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "The binary representation of the number is: ";
        for (int i = 0; i < binVector.size(); i++) {
            std::cout << binVector[i];
        }
        std::cout << std::endl;
    }

}
void convertBinaryToDec(std::vector<bool> binVector) {
    int decNum = 0;
    int n = binVector.size();
    if (binVector.size() == bitCount) {
        std::cout << binVector.size() << bitCount << std::endl;
    }
    //std::cout << "The size of the binary array is: " << n << std::endl;


    for (int j = 1; j < n; j++) {
        decNum = decNum + binVector[j] * pow(2, n - j - 1);
    }

    std::cout << "The decNum of the binary array is: " << decNum << std::endl;

    if (binVector[0] == 1 && decNum != 0) {
        decNum = decNum - pow(2, binVector.size() - 1);
    }

    std::cout << "The decimal equivalent is: " << decNum << std::endl;

}




