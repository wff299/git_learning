#include <chrono>
#include <iostream>
#include <thread>
#include <mutex>

std::mutex outputMutex;

void worker(int workerId)
{
    for (int step = 1; step <= 3; ++step)
    {
        int value = workerId * 100 + step;
        {
            std::lock_guard<std::mutex> lock(outputMutex);
	    std::cout << "worker " << workerId<< ", value = " << value << std::endl;
        }
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

int main()
{
    std::thread first(worker, 1);
    std::thread second(worker, 2);

    first.join();
    second.join();

    return 0;
}
