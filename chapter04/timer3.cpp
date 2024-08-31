#include <iostream>
#include <chrono>

int main() {
    // Tallenna alkuaika
    auto start = std::chrono::high_resolution_clock::now();

    // Suorita jotain aikaa vievää tehtävää
    for (int i = 0; i < 10000000; ++i) {
        // Esimerkkilaskentaa
        int x = i * i;
    }

    // Tallenna loppuaika
    auto end = std::chrono::high_resolution_clock::now();

    // Laske aikaero
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    // Tulosta aikaero mikrosekunteina
    std::cout << "Aikaero: " << duration.count() << " mikrosekuntia" << std::endl;

    return 0;
}
