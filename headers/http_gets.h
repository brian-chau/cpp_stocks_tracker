#ifndef HTTP_GETS_H
#define HTTP_GETS_H
#include <string>

class http_gets{
public:
                   http_gets();
                  ~http_gets();
    int            get_website(std::string hostname, std::string & result);
};
#endif
