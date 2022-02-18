#include <iostream>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <pthread.h>
#include <iomanip>

using namespace std;
#define NOPER 3

class FixedDecrompressor
{
public:
    struct Alphabet
    {
        char symbolLabel;
        int codeAsigned;
        int Frequency;
        string binaryStr;
    };

    vector<Alphabet> allSymbols;
    int binaryLength;
    string Message = "010010010100101101101";
    string finalDecodedmessage;
    // void startProgram()
    // {
    //     string textFile;
    //     string readFile;
    //     string label;
    //     string value;

    //     while (getline(cin, textFile, ' '))
    //     {
    //         cout << "key read: " << textFile << endl;
    //         istringstream ss_key(textFile);
    //         ss_key >> textFile;

    //         getline(cin, value);
    //         cout << "value read: " << value << endl;
    //     }

    // }

    void settingUPTable()
    {
        Alphabet symb1;
        symb1.symbolLabel = 'a';
        symb1.codeAsigned = 2;
        symb1.Frequency = 0;

        Alphabet symb2;
        symb2.symbolLabel = 'b';
        symb2.codeAsigned = 4;
        symb2.Frequency = 0;

        Alphabet symb3;
        symb3.symbolLabel = 'c';
        symb3.codeAsigned = 5;
        symb3.Frequency = 0;

        allSymbols.push_back(symb1);
        allSymbols.push_back(symb2);
        allSymbols.push_back(symb3);
    }

    // void creatingThreads()
    // {
    //     pthread_t threads[NOPER];
    //     for (int i = 0; i < NOPER; i++)
    //     {

    //         pthread_create(&threads[i], NULL, binaryConversion, NULL);
    //         cout << "creating Thread"
    //              << " " << i << endl;
    //     }
    //     for (int j = 0; j < NOPER; j++)
    //     {
    //         pthread_join(threads[j], NULL);
    //     }
    // }

    // static void *calculator(void *arg)
    // {
    //     cout << " Is saying HI" << endl;
    // }

    void findingGreatestCode()
    {
        ///////TEST INPUT/////////////////
        int bigNum;
        // Alphabet symb1;
        // symb1.symbolLabel = 'a';
        // symb1.codeAsigned = 2;
        // symb1.Frequency = 0;

        // Alphabet symb2;
        // symb2.symbolLabel = 'b';
        // symb2.codeAsigned = 4;
        // symb2.Frequency = 0;

        // Alphabet symb3;
        // symb3.symbolLabel = 'c';
        // symb3.codeAsigned = 5;
        // symb3.Frequency = 0;

        // allSymbols.push_back(symb1);
        // allSymbols.push_back(symb2);
        // allSymbols.push_back(symb3);
        ///////TEST INPUT//////////////////////

        /*This fuction iterates through the vector of structs and retrives
     their integer code and compares them to each other to determine the Greatest Number and
     then passes it to the findBinaryLength function
     */
        vector<Alphabet>::iterator iter2 = allSymbols.begin() + 1;
        for (auto it = allSymbols.begin(); it != allSymbols.end(); it++)
        {
            // cout << "FIRST ITER: " << it->symbolLabel << endl;
            if (it->codeAsigned > iter2->codeAsigned)
            {
                bigNum += it->codeAsigned;
                // cout << "The Greatest one: " << bigNum << endl;
                findBinaryLength(bigNum);
                break;
            }
            else if (iter2->codeAsigned > it->codeAsigned)
            {
                bigNum += iter2->codeAsigned;
                // cout << "The Greatest one: " << bigNum << endl;
                findBinaryLength(bigNum);
                break;
            }
        }
    }
    // /*This fuction performs the calculation
    //  to determine the Digit Length
    //  */
    void findBinaryLength(int Number)
    {
        binaryLength = ceil(log2(Number + 1));
        // cout << "LENGTH OF BINARY: " << binaryLength << endl;
    }

    /*This fuction iterates through the vector of structs and retrives
     their integer code as well as their symbolLabel and performs the claculation
     to convert to binary
     */
    void *binaryConversion(void *arg)
    {
        struct Alphabet *pos_ptr = (struct Alphabet *)arg;
        string result;
        for (auto it3 = allSymbols.begin(); it3 != allSymbols.end(); it3++)
        {
            int codeNumber = it3->codeAsigned;
            string stri = bitset<128>(codeNumber).to_string();
            for (int i = stri.length() - 1; it3->binaryStr.length() != binaryLength; i--)
            {
                it3->binaryStr += stri[i];
            }
            reverse(it3->binaryStr.begin(), it3->binaryStr.end());
        }
    }
    void MessageDecompressor()
    {

        string tempBinStorage;
        for (auto it4 = allSymbols.begin(); it4 != allSymbols.end(); it4++)
        {
            for (int i = 0; i < Message.length(); i++)
            {
                tempBinStorage += Message[i];
                if (tempBinStorage.size() == binaryLength)
                {
                    if (tempBinStorage == it4->binaryStr)
                    {
                        tempBinStorage.clear();

                        finalDecodedmessage += it4->symbolLabel;
                        it4->Frequency++;
                    }
                    else
                    {
                        tempBinStorage.clear();
                    }
                }
            }
        }
    }
    void printInfo()
    {
        for (auto it5 = allSymbols.begin(); it5 != allSymbols.end(); it5++)
        {
            cout << "Character: " << it5->symbolLabel << " Code: " << it5->binaryStr << " Frequency: " << it5->Frequency << endl;
        }
        cout << "Decoded Message: " << finalDecodedmessage << endl;
    }
};