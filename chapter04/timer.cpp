#include <iostream>
#include <chrono>
#include <ctime>
#include <cstdio>
#include <thread> 

struct TimerClass{


TimerClass(){
  timestamp = std::chrono::high_resolution_clock::now();
}

~TimerClass(){
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - timestamp);
  std::cout << "Time difference: " << duration.count() << " microseconds" << std::endl;
  std::cout << "Time difference: " << duration.count()/1000.F << " milliseconds" << std::endl;
  std::cout << "Time difference: " << duration.count()/1000.F/1000.0 << " seconds" << std::endl;
}

TimerClass(const TimerClass& other)
: timestamp{ other.timestamp}{

}

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> timestamp;
};

int main(){
  auto timeClass = new TimerClass{};
  auto copy_timeClass { timeClass };
  std::this_thread::sleep_for(std::chrono::seconds(2));
  delete timeClass;
  delete copy_timeClass;
}