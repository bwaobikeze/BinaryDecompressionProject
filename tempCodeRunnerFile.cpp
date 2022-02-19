void findingGreatestCode()
// {
//     ///////TEST INPUT/////////////////
//     int bigNum;
//     // Alphabet symb1;
//     // symb1.symbolLabel = 'a';
//     // symb1.codeAsigned = 2;
//     // symb1.Frequency = 0;

//     // Alphabet symb2;
//     // symb2.symbolLabel = 'b';
//     // symb2.codeAsigned = 4;
//     // symb2.Frequency = 0;

//     // Alphabet symb3;
//     // symb3.symbolLabel = 'c';
//     // symb3.codeAsigned = 5;
//     // symb3.Frequency = 0;

//     // allSymbols.push_back(symb1);
//     // allSymbols.push_back(symb2);
//     // allSymbols.push_back(symb3);
//     ///////TEST INPUT//////////////////////

//     /*This fuction iterates through the vector of structs and retrives
//  their integer code and compares them to each other to determine the Greatest Number and
//  then passes it to the findBinaryLength function
//  */
//     vector<Alphabet>::iterator iter2 = allSymbols.begin() + 1;
//     for (auto it = allSymbols.begin(); it != allSymbols.end(); it++)
//     {
//         // cout << "FIRST ITER: " << it->symbolLabel << endl;
//         if (it->codeAsigned > iter2->codeAsigned)
//         {
//             bigNum += it->codeAsigned;
//             // cout << "The Greatest one: " << bigNum << endl;
//             findBinaryLength(bigNum);
//             break;
//         }
//         else if (iter2->codeAsigned > it->codeAsigned)
//         {
//             bigNum += iter2->codeAsigned;
//             // cout << "The Greatest one: " << bigNum << endl;
//             findBinaryLength(bigNum);
//             break;
//         }
//     }
// }