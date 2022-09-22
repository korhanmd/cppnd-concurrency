#include <iostream>
#include <thread>

void threadFunctionEven() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1)); // simulate work
    std::cout << "Even thread\n";
}

void threadFunctionOdd() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1)); // simulate work
    std::cout << "Odd thread\n";
}

int main() {
    for (int i = 0; i < 6; i++) {
        std::thread t((i % 2) ? threadFunctionOdd : threadFunctionEven);
        t.detach();
    }

    // ensure that main does not return before the threads are finished
    std::this_thread::sleep_for(std::chrono::milliseconds(1)); // simulate work

    std::cout << "End of main is reached" << std::endl;
    return 0;
}