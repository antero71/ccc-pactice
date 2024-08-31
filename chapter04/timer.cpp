#include <iostream>
#include <chrono>
#include <ctime>
#include <cstdio>

struct TimerClass{


TimerClass(){
  timestamp = std::chrono::high_resolution_clock::now();
}

~TimerClass(){
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - timestamp);
  std::cout << "Time difference: " << duration.count() << " microseconds" << std::endl;
  std::cout << "Time difference: " << duration.count()/1000 << " milliseconds" << std::endl;
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
  for(long i; i < 9000000000;i++);
  delete timeClass;
}