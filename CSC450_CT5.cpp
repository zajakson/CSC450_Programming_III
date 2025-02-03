#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

int main() {
    
    //variable for userinput 
    std::string userInput;
    char choice;
    
    //Opted for WHILE-TRUE loop to continuously add inputs until an conditional 'exit' is met
    while (true) {
        std::cout << "Enter text (To quit enter 'exit'): ";
        //get the entire line regardless including whitespace. 
        std::getline(std::cin, userInput);
        
        //CONDITIONAL to quit program
        if (userInput == "exit") {
            break;
        }
        
        //Send the user input to the text file
        std::ofstream outFile("CSC450_CT5_mod5.txt", std::ios::app);
        outFile << userInput << std::endl;
        outFile.close();
        std::cout << "Text Added.\n";
         
        //Needed to read file without introducing overwrites
        std::ifstream inFile("CSC450_CT5_mod5.txt");

        //reads CSC450_CT5_mod5.txt and stores as content to prepare for reverse functionality.
        std::string content;
        char ch;
        while (inFile.get(ch)) {
            content += ch;
        }
        inFile.close();

        
        //reverse method on applied to content
        std::reverse(content.begin(), content.end());
        
        //output file for instance named reverse 
        std::ofstream reverseFile("CSC450-mod5-reverse.txt");
        
        //apply contents to reverseFile
        reverseFile << content;
        reverseFile.close();
    }
    
    return 0;
}
