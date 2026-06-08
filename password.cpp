#include <iostream>
#include <string>
#include <random>

std::string generate_password(int len) {
   std::string pass = "";
   int val;

   std::random_device rd;
   std::mt19937 gen(rd());
   std::uniform_int_distribution<> dist(0, 35);

   std::string chars = "abcdefghijklmnopqrstuvwxyz1234567890";
   for (int i = 0; i <= len; i++) {
      val = dist(gen);
      pass += chars[val];
   }
   return pass;
}

int main() {
   int length;
   std::cout << "Enter the length of your password: ";
   std::cin >> length; 
   std::cout << "Your password is: " << std::endl;
   std::cout << generate_password(length - 1) << std::endl;
   return 0;
}
