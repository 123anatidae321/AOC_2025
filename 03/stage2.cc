#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

/*
# 1701089651593824 too high
# 3121910778619
# 31103799668619
*/
const size_t find_max(const std::vector<int>& v, int start, int numbers_left) {
    std::pair<int, int> local_max(start, 0);
    for (int i = start; i < v.size() - numbers_left; i++) {
        if (v[i] > local_max.second) {
            local_max.first = i;
            local_max.second = v[i];
        }
    }
    if (numbers_left == 0) {
        return local_max.second;
    }
    else {
        return pow(10, numbers_left)*local_max.second + find_max(v, local_max.first + 1, numbers_left - 1);
    }
}

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
    size_t result = 0;
    std::string input;
    while (std::getline(file, input))
    {
        std::vector<int> v;
        for(auto i : input) {
            v.emplace_back(i-0x30);
        }
        result += find_max(v, 0, 11);
    }
    file.close();
    std::cout << "Result is " << result << std::endl;
}