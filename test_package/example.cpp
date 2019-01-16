#include <cstdlib>
#include <iostream>

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <bsoncxx/json.hpp>

using namespace bsoncxx;
using namespace mongocxx;

int main()
{
    const mongocxx::instance instance_; // This should be done only once.
    auto c = mongocxx::client{mongocxx::uri{}};

    std::cout << "Hello!\n";
    return EXIT_SUCCESS;
}
