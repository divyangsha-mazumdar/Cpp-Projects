#include <iostream>
#include <cmath>
#include <ostream>

bool IsPrime(int i) {
   if (i <= 0) {
      return false;
   }
   if (i % 2 == 0) {
      return false;
   }
   for (int j = 0; j <= std::sqrt(i); j += 2) {
      if (i % j == 0) {
	 return false;
      }
   }
   return true;
}

int main() {
   int start;
   std::cout << "Enter a number: ";
   std::cin >> start;

   for (int i = 0; i <= start; i++) {
      if (IsPrime(i)) {
	 std::cout << i << ": is a prime" << std::endl;
      }
   }
   return 0;
}
