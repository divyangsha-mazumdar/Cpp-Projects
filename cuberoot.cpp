#include <cmath>
#include <iostream>

double cbrtnum(int x) {
   double ans = x;
   for (int i = 0; i <= 30; i++) {
      ans =  ((x / pow(ans, 2)) + (2 * ans)) / 3.0;
   }
   return ans;
}
int main() {
   std::cout << cbrtnum(729) << std::endl;
   return 0;
}
