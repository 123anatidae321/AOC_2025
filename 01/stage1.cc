#include <iostream>
#include <fstream>

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
        pos += step;

        if (pos % 100 == 0) {
            result++;
        }

    }
    std::cout << "Result is " << result << std::endl;
    file.close();
}