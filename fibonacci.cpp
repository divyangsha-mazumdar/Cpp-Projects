#include <iostream>

int main() {
   int num, a = 0, b = 1;
   std::cout << "Enter a number: ";
   std::cin >> num;
   b = 1;
   while (a < num) {
      int next_val = a + b;
      a = b;
      b = next_val;
      std::cout << a << std::endl;
   }
}
