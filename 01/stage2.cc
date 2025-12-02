#include <iostream>
#include <fstream>
#include <math.h>

// 6131 too low
// 6185 too low

// 6216 not correct

// 6328 too high
int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "No file name specified" << std::endl;
        return 1;
    }
    std::ifstream file;
    file.open(argv[1]);
    if (file.fail())
    {
        std::cerr << "Failed to open file" << std::endl;
        return 1;
    }
    std::string input;
    size_t result = 0;
    int pos = 50;
    while (std::getline(file, input))
    {
        int step = input[0] == 'L' ? -1 * atoi(input.substr(1).c_str()) : atoi(input.substr(1).c_str());
        result += floor(abs(step)/100.0);
        if (pos != 0) {
            int distance_to_zero = step >= 0 ? 100 - pos : pos;
            if((abs(step) % 100) >= distance_to_zero) {
                result++;
            }
        }
        pos = (pos + step) % 100;
        if (pos < 0) pos += 100;
    }
    std::cout << "Result is " << result << std::endl;
    file.close();
}