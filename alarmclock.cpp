#include <chrono>
#include <iostream>
#include <ctime>
#include <ostream>
#include <string>
#include <thread>
#include <cstdlib>

int timeOfday(int a) {
   std::time_t now = std::time(nullptr);
   std::string ph = "", pm = "", ps = "";

   std::tm* tc = std::localtime(&now);

   int hr = tc->tm_hour;

   int min = tc->tm_min;
   int sec = tc->tm_sec;
   if (hr < 10) {
      ph = "0";
   }
   
   if (min < 10) {
      pm = "0";
   }
   
   if (sec < 10) {
      ps = "0";
   }
   
   if (a == 1) {
      std::cout << "\rCurrent time:  " << ph << hr << ":" << pm << min << ":" << ps << sec << std::flush;
      return (hr * 3600) + (min * 60) + sec;;
   }
   else {
      return (hr * 3600) + (min * 60) + sec;
   }
}
int main() {
   int mhr,mmin,msec;
   std::string padm = "", padh = "", pads = "";

   std::cout << "Enter hrs: ";
   std::cin >> mhr;
   std::cout << "Enter mins: ";
   std::cin >> mmin;
   std::cout << "Enter secs: ";
   std::cin >> msec;

   int current_time = timeOfday(0);
   int utime = (mhr * 3600) + (mmin * 60) + msec;
   int duration = utime - current_time;

   if (mhr < 10) {
      padh = '0';
   }
   if (mmin < 10) {
      padm = '0';
   }
   if (msec < 10) {
      pads = '0';
   }

   if (duration < 0) {
      duration += 86400;
   }
   
   std::cout << std::endl;
   std::cout << "Alarm set for: " << padh << mhr << ":" << padm << mmin << ":" << pads << msec 
   << std::endl;

   while (duration != 0) {
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
      timeOfday(1);
      duration--;
   }
   std::cout << std::endl;
   std::cout << "Time finished!" << std::endl;
   std::string command = "nohup sh -c 'while true; do play-audio test.wav; done' > /dev/null 2>&1 &";

   int result = std::system(command.c_str());
   return 0;
}
