#include <iostream>

int main(){
    //variables that store the intergers.
    int number_one;
    int number_two;
    int number_three;
    
//user prompt for number each number
std::cout << "Number one: ";
std::cin >> number_one;

std::cout << "Number two: ";
std::cin >> number_two;

std::cout << "Number three: ";
std::cin >> number_three;

//pointer w/ new operator.
int* pointer_one = new int(number_one);
int* pointer_two = new int(number_two);
int* pointer_three = new int(number_three);

//displays dynamically pointer numbers
std::cout << "Here are the numbers you entered: \n";
std::cout << *pointer_one << "\n";
std::cout << *pointer_two << "\n";
std::cout << *pointer_three << "\n";

//free up the dyanmic memory
delete pointer_one;
delete pointer_two;
delete pointer_three; 
}
