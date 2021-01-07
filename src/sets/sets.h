#include <ctime>
#include <list>
#include <vector>
#include <map>
#include <string>
#ifndef SETS_H
#define SETS_H

struct event_t
{
    int id;
    time_t date;
};

typedef std::vector<std::map<std::string, event_t> > sets;

void event_register(sets &s, time_t date, std::vector<std::string> names, int *mid);

void display_groups(sets &s);

void unlink_group(sets &s, int id);

#endif
