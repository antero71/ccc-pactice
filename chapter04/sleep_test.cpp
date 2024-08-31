#include <thread>
#include <iostream>
#include <chrono>

int main(){
  auto start = std::chrono::high_resolution_clock::now();
  std::this_thread::sleep_for(std::chrono::seconds(2));
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  std::cout << "Time difference: " << duration.count() << " microseconds" << std::endl;
  std::cout << "Time difference: " << duration.count()/1000.F << " milliseconds" << std::endl;
  std::cout << "Time difference: " << duration.count()/1000.F/1000.0 << " seconds" << std::endl;
}