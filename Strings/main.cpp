#include <iostream>
#include "strings.h"

int main()
{
    std::cout << std::endl << "Enter string:\t";
    String name = String(10);
    name.input();
    //name.reverse();
    name.display("Input: ");
    // std::cout << std::endl << std::boolalpha << name.isPalindrome();
    name.toUpper('a');
    name.display("\nUpper: ");
    name.toLower('a');
    name.display("\nLower: ");
    return 0;
}