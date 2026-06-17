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
   char guess;
   std::vector<char> guesses;

   while (true) {
      std::cout << "Enter your guess: ";
      std::cin >> guess;

      if (word.find(guess)) {
	 guesses.push_back(guess);
	 std::cout << "Success! letter is in word!" << std::endl;
	 for (int i = 0; i <= word.length(); i++) {
	    std::cout << '_';
	    if (word.at(i) == guess) {
	       std::cout << guess;
	    }
	 }
      }
      else {
	 std::cout << "Letter not in word." << std::endl;
      }
   }
   return 0;
}
