#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

std::mutex firstMutex;
std::mutex secondMutex;

void taskA()
{
    std::lock_guard<std::mutex> firstLock(firstMutex);

    std::cout << "taskA locked firstMutex" << std::endl;

    std::this_thread::sleep_for(
        std::chrono::milliseconds(200)
    );

    std::cout << "taskA waiting for secondMutex" << std::endl;

    std::lock_guard<std::mutex> secondLock(secondMutex);

    std::cout << "taskA finished" << std::endl;
}

void taskB()
{
    std::lock_guard<std::mutex> firstLock(firstMutex);

    std::cout << "taskB locked firstMutex" << std::endl;

    std::this_thread::sleep_for(
        std::chrono::milliseconds(200)
    );

    std::cout << "taskB waiting for secondMutex" << std::endl;

    std::lock_guard<std::mutex> secondLock(secondMutex);

    std::cout << "taskB finished" << std::endl;
}

int main()
{
    std::thread first(taskA);
    std::thread second(taskB);

    first.join();
    second.join();

    return 0;
}
