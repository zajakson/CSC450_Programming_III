//A simple application 

#include <iostream>
using namespace std;

int main() {
    // personal identification information (PII)
    string firstName = "Hod";
    string lastName = "Toffman";
    string streetAddress = "1 Goldmine Lane";
    string city = "Klondike";
    //improved code by adding state
    string state = "AK";
    string zipCode = "00112";

    // Display the PII
    cout << "First Name: " << firstName << endl;
    cout << "Last Name: " << lastName << endl;
    cout << "Street Address: " << streetAddress << endl;
    cout << "City: " << city << endl;
    cout << "State: " << state << endl; 
    cout << "Zip Code: " << zipCode << endl;

    return 0;
}