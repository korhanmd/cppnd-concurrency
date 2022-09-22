#include <iostream>
#include <thread>

void threadFunctionEven() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1)); // simulate work
    std::cout << "Even thread\n";
}

int main() {
    // ensure that main does not return before the threads are finished
    std::this_thread::sleep_for(std::chrono::milliseconds(1)); // simulate work

    std::cout << "End of main is reached" << std::endl;
    return 0;
}