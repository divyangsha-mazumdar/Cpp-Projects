#include <iostream>
#include <string>

bool checkWin(std::string c1, std::string c2, std::string c3,
              std::string c4, std::string c5, std::string c6, 
	      std::string c7, std::string c8, std::string c9) {
   // Rows
   if (c1 != " " && c1 == c2 && c2 == c3) {
      return true;
   }
   else if (c4 != " " && c4 == c5 && c5 == c6) {
      return true;
   }
   else if (c7 != " " && c7 == c8 && c8 == c9) {
      return true;
   }
   // Columns
   else if (c1 != " " && c1 == c4 && c4 == c7) {
      return true;
   }
   else if (c2 != " " && c2 == c5 && c5 == c8) {
      return true;
   }
   else if (c3 != " " && c3 == c6 && c6 == c9) {
      return true;
   }
   // Diagonals
   else if (c1 != " " && c1 == c5 && c5 == c9) {
      return 0;
   }
   else if (c3 != " " && c3 == c5 && c5 == c7) {
      return true;
   }
   return false;
}
void displayBoard(std::string a, std::string b, std::string c,
		  std::string d, std::string e, std::string f,
		  std::string g, std::string h, std::string i) {
   std::cout << " " << a << " " << "|";
   std::cout << " " << b << " " << "|";
   std::cout << " " << c << " " << std::endl;
   std::cout << " " << d << " " << "|";
   std::cout << " " << e << " " << "|";
   std::cout << " " << f << " " << std::endl;
   std::cout << " " << g << " " << "|" ;
   std::cout << " " << h << " " << "|";
   std::cout << " " << i << " " << std::endl;
}

int main() {
   std::string board[9];
   bool won;
   for (int i = 0; i < 9; i++) {
      board[i] = " ";
   }
   int square = -1;
   int turn = 0;
   std::string player;

   while (turn <= 9) {
      if (turn % 2 == 0) player = "O";
      else player = "X";
      turn++;
      displayBoard(board[0], board[1], board[2],
	           board[3], board[4], board[5],
	           board[6], board[7], board[8]);

      if (turn > 9) {
	 std::cout << "It was a draw!" << std::endl;
	 break;
      }

      won = checkWin(board[0], board[1], board[2], 
	             board[3], board[4], board[5],
	             board[6], board[7], board[8]);

      if (won != false) {
	 if (player == "X") {
	    player = "O";
	 }
	 else {
	    player = "X";
	 }
	 std::cout << player << " won!" << std::endl;
	 break;
      }

      std::cout << player << ": Enter a square: ";
      // Check square validation
      if (!(std::cin >> square)) {
	 std::cout << "Invalid move!" << std::endl;
	 square = -1;
	 continue;
      }
      if (square < 0 || square > 9) {
	 std::cout << "Invalid square" << std::endl;
	 continue;
      }

      // Check board square availability
      if (board[square - 1] == " ") {
	 board[square - 1] = player;
      }
      else {
	 std::cout << "Invalid move! " << std::endl;
	 turn--;
	 continue;
      }
   }

   return 0;
}
