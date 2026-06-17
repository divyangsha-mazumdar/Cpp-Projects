#include <iostream>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <string>
#include <thread>
#include <cstdlib>

int current_time_int() {
   std::time_t ct = std::time(nullptr);

   std::tm* local_time = std::localtime(&ct);
   int current_time = (local_time->tm_hour * 3600) +
		      (local_time->tm_min * 60) +
		      (local_time->tm_sec);
   return current_time;
}

int time_to_s(int h, int m, int s) {
   return (h * 3600) + (m * 60) + s;
}
int main() {
   int hr,min,sec;
   int uhr,umin,usec;

   std::cout << "Enter hour: ";
   std::cin >> hr;
   std::cout << "Enter minute: ";
   std::cin >> min;
   std::cout << "Enter seconds: ";
   std::cin >> sec;

   int u_time = time_to_s(hr,min,sec);
   std::cout << "Timer set for: " << std::setfill('0')
	     << std::setw(2) << hr << ":"
	     << std::setw(2) << min << ":"
	     << std::setw(2) << sec << std::endl;
   int current_time_now = current_time_int();

   while (current_time_now < u_time) {
      current_time_now = current_time_int();
      uhr = current_time_now / 3600;
      umin = (current_time_now % 3600) / 60;
      usec = current_time_now % 60;

      std::cout << "\rCurrent time:  " << std::setfill('0')
	        << std::setw(2) << uhr << ":"
		<< std::setw(2) << umin << ":"
		<< std::setw(2) << usec << std::flush;

      std::this_thread::sleep_for(std::chrono::seconds(1));
   }
   std::cout << std::endl;
   std::cout << "Time finished!" << std::endl;

   std::string command = "nohup mpv --loop-file=inf test.wav > /dev/null 2>&1 &";

   int result = std::system(command.c_str());

   return 0;
}
