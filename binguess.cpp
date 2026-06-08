#include <iostream>
#include <cmath>

void guess(int n) {
   int head, tail, g;
   int guess_num = 1;
   head = pow(10, ceil(log10(n)) + 1);
   tail = 0;
   g = ceil((head + tail) / 2);
   std::cout << "Computer chose: " << g << std::endl;
   while (g != n) {
      if (g < n) {
	 tail = g;
	 g = ceil((head + tail) / 2);
	 guess_num++;
	 std::cout << "Computer chose: " << g << std::endl;
      }
      else {
	 head = g;
	 g = ceil((head + tail) / 2);
	 guess_num++;
	 std::cout << "Computer chose: " << g << std::endl;
      }
   } 
   std::cout << "Computer guessed " << n << " in " << guess_num << " tries." << std::endl;
}

int main() {
   int num;
   std::cout << "Enter a number: ";
   std::cin >> num;
   guess(num);
   return 0;
}
