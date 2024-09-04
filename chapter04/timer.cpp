#include <iostream>
#include <chrono>
#include <ctime>
#include <cstdio>
#include <thread>
#include <cstring>

struct TimerClass {
    TimerClass(const char* name) {
        timestamp = std::chrono::high_resolution_clock::now();

        const auto name_len = strlen(name);
        if (name_len + length + 1 > max_length)
            throw std::runtime_error{"name length should be less than 20"};

        name_ptr = new char[max_length];
        std::strncpy(name_ptr, name, max_length);
        length = name_len;
        name_ptr[length] = 0;
        std::cout << "Construct " << name_ptr << std::endl;
    }

    ~TimerClass() {
        std::cout << "Destruct " << (name_ptr ? name_ptr : "nullptr") << std::endl;
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - timestamp);
        std::cout << "Time difference: " << duration.count() << " microseconds" << std::endl;
        std::cout << "Time difference: " << duration.count() / 1000.F << " milliseconds" << std::endl;
        std::cout << "Time difference: " << duration.count() / 1000.F / 1000.0 << " seconds" << std::endl;
        delete[] name_ptr;  // Ensure proper memory deallocation
    }

    // Copy constructor
    TimerClass(const TimerClass& other)
        : max_length{other.max_length}, name_ptr{new char[other.max_length]}, length{other.length} {
        std::strncpy(name_ptr, other.name_ptr, max_length);
        timestamp = std::chrono::high_resolution_clock::now();  // New timestamp
        std::cout << "Copy construct " << name_ptr << std::endl;
    }

    // Copy assignment operator
    TimerClass& operator=(const TimerClass& other) {
        if (this == &other) {
            return *this;
        }
        delete[] name_ptr;  // Free the current resource
        name_ptr = new char[other.max_length];
        length = other.length;
        max_length = other.max_length;
        std::strncpy(name_ptr, other.name_ptr, max_length);
        timestamp = std::chrono::high_resolution_clock::now();  // New timestamp
        std::cout << "Copy assign " << name_ptr << std::endl;
        return *this;
    }

    // Move constructor
    TimerClass(TimerClass&& other) noexcept
        : timestamp{std::move(other.timestamp)}, name_ptr{other.name_ptr}, length{other.length}, max_length{other.max_length} {
        other.name_ptr = nullptr;   // Clear the moved object
        std::cout << "Move construct" << std::endl;
    }

     // Move assignment operator
    TimerClass& operator=(TimerClass&& other) noexcept {
        if (this == &other) {
            return *this;
        }
        delete[] name_ptr;  // Free the current resource
        name_ptr = other.name_ptr;
        length = other.length;
        max_length = other.max_length;
        timestamp = std::move(other.timestamp);
        other.name_ptr = nullptr;  // Clear the moved object
        std::cout << "Move assign" << std::endl;
        return *this;
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> timestamp;
    char* name_ptr = nullptr;  // Initialize to nullptr
    size_t length{};
    size_t max_length{20};
};

int main() {
    auto timeClass = TimerClass{"first timer"};
    auto timeClass2 = TimerClass("second timer");
    auto timeClass_copy{timeClass};  // Copy the object
    auto timeClass_move{std::move(timeClass)};  // Move the object
    auto timeClass_copy2{ timeClass2};
    std::this_thread::sleep_for(std::chrono::seconds(2));
}
