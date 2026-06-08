#include <ctime>
#include <iostream>
#include <chrono>
#include <thread>

void get_current_time() {
   auto now = std::chrono::system_clock::now();

   std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
   std::cout << "Current time: " << std::ctime(&currentTime);
}

int main() {
   int time_h, time_m, time_s;
   // Times
   std::cout << "Hours: ";
   std::cin >> time_h;
   std::cout << "Minutes: ";
   std::cin >> time_m;
   std::cout << "Seconds: ";

   if (time_h > 59 || time_m > 59 || time_s > 59) {
      std::cout << "Invalid time parameters!";
      return 0;
   }
   std::cin >> time_s;
   while (true) {
      std::this_thread::sleep_for(std::chrono::seconds(1));
      // Time calculations
      time_s--;
      if (time_s == 0) {
	 time_s = 59;
	 time_m--;
	 if (time_m == -1) {
	    time_m = 59;
	    time_h--;
	 }
      }

      if (time_h == 0 && time_m == 0 && time_s == 0) {
	 break;
	 get_current_time();
      }
      std::cout << "Time remaining: " << time_h << ":" << time_m << ":" << time_s << std::endl;
      get_current_time();
   }
   return 0;
}
