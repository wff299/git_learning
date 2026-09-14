#include <iostream>

int readValue(const int* address)
{
    return *address;
}

int processTask(int taskId)
{
    int multiplier = 10;
    int storedValue = taskId;
    const int* valueAddress = &storedValue;

    std::cout << "processing task " << taskId << std::endl;

    int value = readValue(valueAddress);

    return value * multiplier;
}

int main()
{
    int result = processTask(7);

    std::cout << "result = " << result << std::endl;

    return 0;
}
