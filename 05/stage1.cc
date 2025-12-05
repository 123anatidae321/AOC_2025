#include <iostream>
#include <fstream>
#include <vector>

using product_id = unsigned long long;
class range {
public:
    range(const std::string& r) {
        auto delim = r.find("-");
        min = atoll(r.substr(0, delim).c_str());
        max = atoll(r.substr(delim+1).c_str());
    }

    bool matches(product_id n) const { return n >= min && n <= max; }
private:
    product_id min;
    product_id max;
};

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
    std::vector<range> ranges;
    while (std::getline(file, input))
    {
        if (input == "") {
            break;
        }
        ranges.emplace_back(input);
    }

    size_t result = 0;
    while (std::getline(file, input)) {
        product_id p = atoll(input.c_str());
        for (const auto &r : ranges) {
            if (r.matches(p)) {
                result++;
                break;
            }
        }
    }
    file.close();
    std::cout << "Result: " << result << std::endl;
}