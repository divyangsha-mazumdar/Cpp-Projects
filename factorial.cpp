#include <iostream>

int main() {
   int num;
   int fact=1;
   std::cout << "Enter a number: ";
   std::cin >> num;
   for (int i = 1; i <= num; i++) {
      fact = fact*i;
   }
   std::cout << "The factorial of " << num << " is " << fact<< std::endl;
   return 0;
}
