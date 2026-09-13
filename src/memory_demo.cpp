#include <iostream>
#include <string>
#include <exception>

int readValue(const int* address)
{
    if(address == nullptr)
    {
        throw std::invalid_argument("address 不能为nullptr");
    }
    return *address;
}

int selectValue(bool useNull)
{
    int value = 42;
    const int* address = &value;

    if (useNull)
    {
        address = nullptr;
    }

    return readValue(address);
}

int main(int argc, char* argv[])
{

    bool shouldCrash =
        argc == 2 && std::string(argv[1]) == "crash";

    try
    {
        int result = selectValue(shouldCrash);
        std::cout << "result = " << result << std::endl;
    }
    catch (const std::exception& error)
    {
        std::cerr << "读取失败: " << error.what() << std::endl;
        return 1;
    }
    return 0;
}

