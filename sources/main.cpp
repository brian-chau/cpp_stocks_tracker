#include <iostream>
#include "http_gets.h"
#include <regex>

int main(int argc, char** argv)
{
    http_gets* curler = new http_gets();

    std::string url("https://dividata.com/stock/KSS");
    if (argc > 1)
        url = argv[1];

    std::string response("");
    curler->get_website(url, response);
    std::regex r("<tbody>\\s*<tr>\\s*<td class=\"date\">([^<]+)</td>\\s*<td class=\"money\">([^<]+)");
    std::smatch m;
    std::regex_search(response, m, r);
    std::cout << m[1].str() << " " << m[2].str() << std::endl;

    delete curler;
    return 0;
}
