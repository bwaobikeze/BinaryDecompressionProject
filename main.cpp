#include <iostream>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <pthread.h>
#include <iomanip>
using namespace std;
int Numthreads;
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
// functions
void startProgram();
void findingGreatestCode();
void findBinaryLength(int Number);
int creatingThread();
void *binaryConversion(void *arg);
void *MessageDecompressor(void *arj);
void printInfo();

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

    // allSymbols.push_back(symb1);
    // allSymbols.push_back(symb2);
    // allSymbols.push_back(symb3);
}

/*This fuction iterates through the vector of structs and retrives
 their integer code as well as their symbolLabel and performs the claculation
 to convert to binary
 */

int main()
{
    startProgram();

    return 0;
}

void startProgram()
{
    string textFile;
    string label;
    char label2;
    string value;

    if (textFile.empty())
    {
        getline(cin, textFile);
        // cout << "Number of thread: " << textFile << endl;
        stringstream threadconvert(textFile);
        threadconvert >> Numthreads;
    }
    while (getline(cin, textFile))
    {
        Alphabet Symbols;
        stringstream ss(textFile);

        while (getline(ss, label, ' '))
        {
            stringstream charconvert(label);

            charconvert >> Symbols.symbolLabel;
            // cout << "key: " << label << endl;

            getline(ss, value);
            stringstream IntegerConvert(value);
            IntegerConvert >> Symbols.codeAsigned;
            Symbols.Frequency = 0;
        }
        allSymbols.push_back(Symbols);
    }
    // printInfo();
    findingGreatestCode();
}

/*This fuction iterates through the vector of structs and retrives
their integer code and compares them to each other to determine the Greatest Number and
then passes it to the findBinaryLength function
*/
void findingGreatestCode()
{
    int bigNum;
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
    creatingThread();
}

int creatingThread()
{
    pthread_t threads[Numthreads];
    for (int i = 0; i < Numthreads; i++)
    {

        int err = pthread_create(&threads[i], NULL, binaryConversion, &allSymbols[i]);
        if (err)
        {
            cout << "Thread creation faild: " << strerror(err);
            return err;
        }
        else
            cout << "Thread Created with ID: " << i << endl;

        cout << "Wait for Threads to end" << endl;
    }
    for (int i = 0; i < Numthreads; i++)
    {
        int er = pthread_join(threads[i], NULL);

        if (er)
        {
            cout << "Failed to join Thread : " << strerror(er) << endl;
            return er;
        }
        printInfo();
        cout << "Exiting Main" << endl;
    }
}

void *binaryConversion(void *arg)
{
    struct Alphabet *pos_ptr = (struct Alphabet *)arg;
    string result;

    int codeNumber = pos_ptr->codeAsigned;
    string stri = bitset<128>(codeNumber).to_string();
    for (int i = stri.length() - 1; pos_ptr->binaryStr.length() != binaryLength; i--)
    {
        pos_ptr->binaryStr += stri[i];
    }
    reverse(pos_ptr->binaryStr.begin(), pos_ptr->binaryStr.end());
    MessageDecompressor(pos_ptr);
    // cout << "Character: " << pos_ptr->symbolLabel << " Code: " << pos_ptr->binaryStr << " Frequency: " << pos_ptr->Frequency << endl;
    //  break;
}

void *MessageDecompressor(void *arj)
{
    struct Alphabet *pos_ptr2 = (struct Alphabet *)arj;

    string tempBinStorage;

    for (int i = 0; i < Message.length(); i++)
    {
        tempBinStorage += Message[i];
        if (tempBinStorage.size() == binaryLength)
        {
            if (tempBinStorage == pos_ptr2->binaryStr)
            {
                tempBinStorage.clear();

                finalDecodedmessage += pos_ptr2->symbolLabel;
                pos_ptr2->Frequency++;
            }
            else
            {
                tempBinStorage.clear();
            }
        }
    }
}

void printInfo()
{
    for (auto it5 = allSymbols.begin(); it5 != allSymbols.end(); it5++)
    {
        cout << "Character: " << it5->symbolLabel << ","
             << " Code: " << it5->binaryStr << ","
             << " Frequency: " << it5->Frequency
             << endl;
    }
    // cout << "Decoded Message: " << finalDecodedmessage << endl;
}
