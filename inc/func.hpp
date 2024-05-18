#ifndef FUNC_HPP
#define FUNC_HPP

namespace Func {
    int getLastRunNumber(std::string);
    std::string getDebugLine(int num);
    void appendStringToFile(std::string fileName, std::string line, int runNum);
}

#endif