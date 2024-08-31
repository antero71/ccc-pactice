#include <iostream>
#include <chrono>
#include <ctime>

int main() {
    // Hanki nykyinen aika järjestelmäkellosta
    auto now = std::chrono::system_clock::now();
    
    // Muunna aika aikaleimaksi (timestamp)
    std::time_t timestamp = std::chrono::system_clock::to_time_t(now);
    
    // Tulosta aikaleima
    std::cout << "Timestamp: " << timestamp << std::endl;
    
    // Esimerkin vuoksi voit myös muuntaa aikaleiman luettavaksi ajaksi
    std::cout << "Current time: " << std::ctime(&timestamp);

    return 0;
}
