#include <iostream>

bool isPrime(int n) {
   for (int i = 2; i <= int(n/2); i++) {
      if (n % i == 0) {
	 return false;
      }
   }
   return true;
}

int main() {
   int num;
   std::cout << "Enter a number: ";
   std::cin >> num;
   std::cout << "Iterating primes upto: " << num << std::endl; 
   for (int i = 1; i <= num; i++) {
      if (isPrime(i)) {
	 std::cout << i << " is a prime" << std::endl;
      }
   }
}
