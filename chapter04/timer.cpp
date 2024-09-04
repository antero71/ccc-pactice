#include <iostream>
#include <chrono>
#include <ctime>
#include <cstdio>
#include <thread> 
#include <cstring>  // Tarvitaan strlen ja strncpy

struct TimerClass {
    TimerClass(const char *name) {  // Muutetaan char* -> const char*
        timestamp = std::chrono::high_resolution_clock::now();

        const auto name_len = strlen(name);
        if (name_len + length + 1 > max_length)
            throw std::runtime_error{"name length should be less than 20"};

        name_ptr = new char[max_length];
        std::strncpy(name_ptr, name, max_length - length);
        length += name_len;
        name_ptr[length] = 0;
    }

    ~TimerClass() {
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - timestamp);
        std::cout << "Time difference: " << duration.count() << " microseconds" << std::endl;
        std::cout << "Time difference: " << duration.count() / 1000.F << " milliseconds" << std::endl;
        std::cout << "Time difference: " << duration.count() / 1000.F / 1000.0 << " seconds" << std::endl;
        delete[] name_ptr;  // Varmistetaan oikea muistin vapautus
    }

    TimerClass(const TimerClass& other)
        : max_length{other.max_length}, name_ptr{new char[other.max_length]}, length{other.length} {
        std::strncpy(name_ptr, other.name_ptr, max_length);
        timestamp = other.timestamp;
    }

    TimerClass& operator=(const TimerClass& other) {
        if (this == &other) {
            return *this;
        }
        const auto new_name = new char[other.max_length];
        delete[] name_ptr;
        name_ptr = new_name;
        length = other.length;
        max_length = other.max_length;
        timestamp = other.timestamp;
        std::strncpy(name_ptr, other.name_ptr, max_length);
        return *this;
    }

    // Move-constructor
    TimerClass(TimerClass&& other) noexcept
        : timestamp{std::move(other.timestamp)} {
        other.timestamp = std::chrono::time_point<std::chrono::high_resolution_clock>{};
    }

    // Move-assignment
    TimerClass& operator=(TimerClass&& other) noexcept {
        if (this == &other) {
            return *this;
        }
        timestamp = std::move(other.timestamp);
        name_ptr = std::move(other.name_ptr);
        other.timestamp = std::chrono::time_point<std::chrono::high_resolution_clock>{};
        other.length = 0;
        other.max_length = 0;
        return *this;
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> timestamp;
    char *name_ptr;  // Korjattu muuttujan nimi
    size_t length{};
    size_t max_length{20};
};

int main() {
    auto timeClass = TimerClass{"first timer"};
    std::this_thread::sleep_for(std::chrono::seconds(2));
}
