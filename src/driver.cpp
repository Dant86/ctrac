#include "sets/sets.h"
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;


int main(int argc, char *argv[])
{
    int mid = 0;
    sets network;

    time_t now = time(NULL);
    std::vector<std::string> nms = {"name1", "name2"};

    event_register(network, now, nms, &mid);
    
    time_t now2 = time(NULL);
    std::vector<std::string> nooverlap = {"name3"};
    event_register(network, now2, nooverlap, &mid);

    std::vector<std::string> n = {"name2", "name4"};
    event_register(network, now, n, &mid);
    
    std::vector<std::string> n2 = {"name1", "name3"};
    event_register(network, now, n2, &mid);
    
    unlink_group(network, 2);

    display_groups(network);
    return 0;
}
