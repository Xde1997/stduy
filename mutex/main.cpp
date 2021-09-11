#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void print_block(int n, char c)
{
    mtx.lock();
    for (int i = 0; i < n; i++)
    {
        std::cout << c << '\t';
    }
    std::cout << std::endl;
    mtx.unlock();
}
int main()
{
    std::thread th1(print_block, 50, '*');
    std::thread th2(print_block, 50, '$');
    th1.join();
    th2.join();
    system("pause");
    return 0;
}