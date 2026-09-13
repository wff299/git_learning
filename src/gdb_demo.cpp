#include <iostream>
#include <string>
#include <exception>

int calculateTotal(int price, int count)
{
    int total = price * count;
    return total;
}

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cerr << "用法: " << argv[0]
                  << " <price> <max_count>"
                  << std::endl;
        return 1;
    }
    int price=0;
    int maxCount=0;
    try
    {
        price = std::stoi(argv[1]);
        maxCount = std::stoi(argv[2]);
    }
    catch(const std::exception& error)
    {
        std::cerr<<"参数错误:"<<error.what()<<std::endl;
        return 1;
    }
    for (int count = 1; count <= maxCount; ++count)
    {
        int total = calculateTotal(price, count);

        std::cout << "count = " << count
                  << ", total = " << total
                  << std::endl;
    }

    return 0;
}
