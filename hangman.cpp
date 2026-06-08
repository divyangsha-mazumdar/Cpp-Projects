#include <iostream>
#include <random>
#include <string>
#include <vector>

std::string generate_word() {
   std::vector<std::string> words = {"Abroad", "Accept", 
   "Access", "Across", "Acting", "Action", "Active",
   "Actual", "Advice", "Advise", "Affect", "Afford",
   "Afraid", "Agency", "Agenda", "Almost", "Always", 
   "Amount", "Animal", "Annual", "Answer", "Anyone", 
   "Anyway", "Appeal", "Appear", "Around", "Arrive", 
   "Artist", "Aspect", "Assess"};
   
   std::random_device rd;
   std::mt19937 gen(rd());
   std::uniform_int_distribution<> dist(0, 29);

   int c = dist(gen);
   return words[c];
}
int main() {
   std::string word = generate_word();
   std::string guess;
   std::vector<std::string> guesses;
   
   while (true) {
      std::cout << "Enter your guess: ";
      std::cin >> guess;

      if (word.find(guess)) {
	 guesses.push_back(guess);
      }
   }
   return 0;
}
