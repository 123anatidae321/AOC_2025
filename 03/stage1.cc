#include <iostream>
#include <fstream>
#include <vector>

const std::pair<int, int> find_max(const std::vector<int>& v, int start, int end) {
    std::pair<int, int> result(start, 0);
    for (int i = start; i < end; i++) {
        if (v[i] > result.second) {
            result.first = i;
            result.second = v[i];
        }
    }
    return result;
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
        auto m1 = find_max(v, 0, v.size() - 1);
        auto m2 = find_max(v, m1.first + 1, v.size());
        std::cout << m1.second << m2.second << std::endl;
        result += m1.second * 10 + m2.second;
    }
    file.close();
    std::cout << "Result is " << result << std::endl;
}