#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>


using product_id = unsigned long long;
class range {
public:
    range(const std::string& r) {
        auto delim = r.find("-");
        _min = atoll(r.substr(0, delim).c_str());
        _max = atoll(r.substr(delim+1).c_str());
    }

    bool matches(product_id n) const { return n >= _min && n <= _max; }

    bool operator<(const range& r) {
        return this->_min < r._min;
    }

    product_id min() { return _min; }
    product_id max() { return _max; }
    product_id max(product_id m) { return _max = m; }
private:
    product_id _min;
    product_id _max;
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

    file.close();

    std::list<range> merged_ranges;
    std::sort(ranges.begin(), ranges.end());
    for (auto r : ranges) {
        if (merged_ranges.size() == 0 ||
            merged_ranges.back().max() < r.min()) {
                merged_ranges.push_back(r);
            }
        else if (r.max() > merged_ranges.back().max()) {
            merged_ranges.back().max(r.max());
        }
    }

    size_t result = 0;
    for (auto r : merged_ranges) {
        result += r.max() - r.min() + 1;
    }
    std::cout << "Result: " << result << std::endl;
}