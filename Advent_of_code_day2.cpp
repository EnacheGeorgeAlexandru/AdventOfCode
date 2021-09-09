#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

ifstream is("input.txt");

pair<int, int> getLimits(const std::string& limits) {
    string::const_iterator itr = limits.begin();
    string min, max;
    for (; itr != limits.end(); ++itr) {
        if (*itr == '-') {
            break;
        }
        min.push_back(*itr);
    }

    for (; itr != limits.end(); ++itr) {
        if (*itr == '-') {
            continue;
        }
        max.push_back(*itr);
    }
    return { stoi(min), stoi(max) };
}

int getOccurence(const std::string& text, const char r) {
    return count(text.begin(), text.end(), r);
}

bool partOne(int res, const pair<int, int>& lim) {
    if (res >= lim.first && res <= lim.second) {
        return true;
    }
    return false;
}

bool partTwo(const string& text, const pair<int, int>& lim, const char r) {

    if (lim.first > text.size() || lim.second > text.size()) {
        return false;
    }

    if (text[lim.first - 1] == r ^
        text[lim.second - 1] == r) {
        return true;
    }
    return false;
}

int main()
{
    string limits, restriction, text;
    int resultsPartOne = 0, resultsPartTwo = 0;
    while (!is.eof()) {
        is >> limits >> restriction >> text;

        int res = getOccurence(text, restriction.front());
        pair<int, int> lim = getLimits(limits);

        if (true == partOne(res, lim)) {
            ++resultsPartOne;
        }

        if (true == partTwo(text, lim, restriction.front())) {
            ++resultsPartTwo;
        }
    }
    std::cout << resultsPartOne << std::endl;
    std::cout << resultsPartTwo << " ";
}