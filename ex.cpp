#include <iostream>
#include <vector>

using namespace std;

int main()
{
    const unsigned n = 2;
    std::vector<std::vector<int> > output(n, std::vector<int>(1 << n));

    unsigned num_to_fill = 1U << (n - 1);
    for(unsigned col = 0; col < n; ++col, num_to_fill >>= 1U)
    {
        for(unsigned row = num_to_fill; row < (1U << n); row += (num_to_fill * 2))
        {
            std::fill_n(&output[col][row], num_to_fill, 1);
        }
    }

    // These loops just print out the results, nothing more.
    for(unsigned x = 0; x < (1 << n); ++x)
    {
        for(unsigned y = 0; y < n; ++y)
        {
            std::cout << output[y][x] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}