#include <iostream>
#include <iomanip>
#include <chrono>

double get_sqrt(unsigned long long int num, int prec) {
   double ans = num / 3.0;

   for (int i = 0; i <= prec; i++) {
      ans = 0.5 * (ans + (num / ans));
   }
   return ans;
}

int main() {
   double result = 0;
   unsigned long long int i = 1;
   std::cout << std::fixed << std::setprecision(10) << std::endl;

   auto start_time = std::chrono::steady_clock::now();
   const std::chrono::seconds duration(1);
   while (true) {
      if (i % 50000 == 0) {
	 if (std::chrono::high_resolution_clock::now() - start_time > duration) {
	    break;
	 }
      }
      result = get_sqrt(i, 30);
      i++;
   }

   std::cout << "No. of sqrts calculated: " << i << std::endl;

   return 0;
}
