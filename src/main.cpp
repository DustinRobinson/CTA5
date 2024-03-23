#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

//takes std::string source and destination and reverses file contents
void reversal(string source, string destination)
{
    //filestream for file to be reversed
    std::ifstream toReverse;
    //filestream for reversed destination file
    std::ofstream reversed;
    //string stream to read contents of file
    std::stringstream buffer;

    //open source file stream
    toReverse.open(source);
    //if file is open read to buffer
    if (toReverse.is_open())
    {
        buffer << toReverse.rdbuf();
    }
    //else cout issue
    else
    {
        std::cout << "Unable to open source file";
    }
    //close source file stream
    toReverse.close();

    //open destination file stream
    reversed.open(destination);
    //if file is open set string based on buffer, reverse string, and write to destination file
    if (reversed.is_open())
    {  
        std::string s = buffer.str();
        std::reverse(s.begin(), s.end());
        reversed << s;
    }
    //else cout issue
    else
    {
        std::cout << "Unable to open destination file";
    }
    //close destination file stream
    reversed.close();
}

int main() {

    std::string sourceFile = "CSC450_CT5_mod5.txt";
    std::string destinationFile = "CSC450-mod5-reverse.txt";
    std::string userInput = "";

    //file stream for appending to source file
    std::ofstream file;
    //open file to append user input
    file.open(sourceFile, std::ios::app);
    //if file is open request input and append
    if (file.is_open()) 
    {
        std::cout << "Please, enter data to append to file." << endl;
        std::getline(cin, userInput);
        file << userInput;
    } 
    //else cout issue
    else
    {
        std::cout << "Unable to open file";
    }
    //close file stream for appending to source file
    file.close();
    //copy source file to destination file, but with reversed contents
    reversal(sourceFile, destinationFile);
    return 0;
}