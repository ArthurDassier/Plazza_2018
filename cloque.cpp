#include <iostream>
#include <ctime>
#include <cmath>

int main()
{
    clock_t camzer = clock();

    for (int x = 0; x < 3000000000; ++x) {
       if (((clock() - (float)camzer) / CLOCKS_PER_SEC) > 2) {
            std::cout << "2s camzer" << std::endl;
            camzer = clock();
       }
    }
}