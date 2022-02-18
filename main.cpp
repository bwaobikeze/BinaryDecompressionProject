#include <iostream>
#include "codeDecompressor.h"
#include <pthread.h>
#include <iomanip>
using namespace std;

int main()
{

    FixedDecrompressor symbol;
    // symbol.creatingThreads();
    symbol.findingGreatestCode();
    // symbol.binaryConversion();
    symbol.MessageDecompressor();
    symbol.printInfo();
    return 0;
}