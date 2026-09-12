#include <iostream>
#include <thread>

void worker()
{
    std::cout << "hello from worker thread!" << std::endl;
}

int main()
{
    std::thread thread(worker);
    thread.join();
    return 0;
}
