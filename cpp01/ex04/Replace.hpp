#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <string>
# include <fstream>
# include <iostream>

class Replace {
public:
    Replace();
    ~Replace();

    bool replaceInFile(const std::string& filename, 
                       const std::string& s1, 
                       const std::string& s2);

private:
    Replace(const Replace& other);
    Replace& operator=(const Replace& other);
};

#endif // REPLACE_HPP