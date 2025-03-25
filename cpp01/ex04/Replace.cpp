#include "Replace.hpp"

Replace::Replace() {}

Replace::~Replace() {}

bool Replace::replaceInFile(const std::string& filename, 
                            const std::string& s1, 
                            const std::string& s2) {
    if (filename.empty() || s1.empty()) {
        std::cerr << "Error: Invalid input parameters" << std::endl;
        return false;
    }

    std::ifstream inputFile(filename.c_str());
    if (!inputFile) {
        std::cerr << "Error: Could not open input file " << filename << std::endl;
        return false;
    }

    std::string outputFilename = filename + ".replace";
    std::ofstream outputFile(outputFilename.c_str());
    if (!outputFile) {
        std::cerr << "Error: Could not create output file " << outputFilename << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos) {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
        outputFile << line << std::endl;
    }

    inputFile.close();
    outputFile.close();

    return true;
}