#include <iostream>
#include <string>
#include <regex>
#include <map>
#include <ios>

struct comporator {
    bool operator() (int a, int b) {
        return a > b;
    }
};

std::string derivative(std::string polynomial) {
    std::regex re("([+-]?)(\\d*)\\*?x\\^?(\\d*)");
    std::smatch xResults;
    std::map<int, int, comporator> data;

    while (std::regex_search(polynomial, xResults, re)) {
        std::string s_pow = xResults[3] == "" ? "1" : (std::string)xResults[3];
        std::string s_cnst = xResults[2] == "" ? "1" : (std::string)xResults[2];
        int sign = xResults[1] == "-" ? -1 : 1;
        int pow = std::stoi(s_pow);
        int cnst = std::stoi(s_cnst);

        data[pow-1] += (cnst * pow) * sign;

        polynomial = xResults.suffix().str();
    }

    auto itr = data.begin();
    std::string result = "";
    result += std::to_string(itr->second);
    result += itr->first > 1 ? "*x^" : itr->first == 1 ? "*x" : "";
    result += itr->first > 1 ? std::to_string(itr->first) : "";
    itr++;

    for (; itr != data.end(); itr++) {
        result += itr->second < 0 ? "" : "+";
        result += std::to_string(itr->second);
        result += itr->first > 1 ? "*x^" : itr->first == 1 ? "*x" : "";
        result += itr->first > 1 ? std::to_string(itr->first) : "";
    }

    return result;
}

int main(int, char**) {
    std::ios_base::sync_with_stdio(false);
    std::string polynomial;
    std::cin >> polynomial;

    std::cout << derivative(polynomial);

    std::cout << std::endl;

    return 0;
}
