// vim: set expandtab tabstop=4 shiftwidth=4:

#include "fast/basic_template.h"
#include "fast/get_file_content.h"
#include <iostream>
#include <exception>
#include <string>
#include <map>

int main(int argc, char* argv[]) {
    std::set_terminate(__gnu_cxx::__verbose_terminate_handler);
    if (argc < 3) {
        std::cerr << "Argument missing." << std::endl;
        return 1;
    } else if (!(argc % 2)) { // is even
        std::cerr << "Malformed arguments." << std::endl;
        return 2;
    }
    fast::basic_template< fast::get_file_content, std::string, std::map > tpl(argv[1]);
    std::string block = argv[2];
    fast::map_type vars;
    for (int i = 3; i < argc; ++i) {
        vars[argv[i]] = argv[++i];
    }
    std::cout << tpl.parse(block, vars);
    return 0;
}

