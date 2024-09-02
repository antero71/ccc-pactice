#include <iostream>
#include <chrono>
#include <ctime>
#include <cstdio>
#include <thread> 

struct TimerClass{


TimerClass(char name[]){
  timestamp = std::chrono::high_resolution_clock::now();
  if(strlen(name)>19){
    throw std::runtime_error{"name lenght should be less than 20"};
  }
  this.name=name;
}

~TimerClass(){
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - timestamp);
  std::cout << "Time difference: " << duration.count() << " microseconds" << std::endl;
  std::cout << "Time difference: " << duration.count()/1000.F << " milliseconds" << std::endl;
  std::cout << "Time difference: " << duration.count()/1000.F/1000.0 << " seconds" << std::endl;
}

TimerClass(const TimerClass& other){
 timestamp = other.timestamp;
}

TimerClass& operator=(const TimerClass& other){
  if ( this == &other){
    return *this;
  }

  timestamp = other.timestamp;
  return *this;
}

  // Move-constructor
    TimerClass(TimerClass&& other) noexcept
    : timestamp{std::move(other.timestamp)} {
    
        other.timestamp = std::chrono::time_point<std::chrono::high_resolution_clock>{}; // Nollataan toisen objektin timestamp
    }

    // Move-assignment
    TimerClass& operator=(TimerClass&& other) noexcept {
        if (this == &other) {
            return *this;
        }
        timestamp = std::move(other.timestamp);
        other.timestamp = std::chrono::time_point<std::chrono::high_resolution_clock>{}; // Nollataan toisen objektin timestamp
        return *this;
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> timestamp;
    char name[20];
};

int main(){
  auto timeClass = new TimerClass{};
  auto moved_timeClass = std::move(*timeClass);  // Siirretään timeClass -> moved_timeClass
    
  std::this_thread::sleep_for(std::chrono::seconds(2));
  delete timeClass;
}