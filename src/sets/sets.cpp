#include "sets.h"
#include <ctime>
#include <list>
#include <vector>
#include <map>
#include <string>
#include <iostream>

void event_register(sets &s, time_t date, std::vector<std::string> names, int *mid)
{
    int trav;
    event_t e = {*mid, date};
    *mid += 1;
    std::vector<uint> overlaps;
    for (std::string str : names)
    {
        trav = 0;
        for (std::map<std::string, event_t> m : s)
        {
            if (m.find(str) != m.end())
            {
                overlaps.push_back(trav);
                break;
            }
            ++trav;
        }
    }
    std::map<std::string, event_t> m;
    for (std::string name : names)
        m.insert(make_pair(name, e));
    std::map<std::string, event_t> m_;
    for (int ix : overlaps)
    {
        m_ = s[ix];
        for (auto p : m_) {
            if (m.find(p.first) == m.end())
                m.insert(p);
        }
    }
    int removed = 0;
    for (int ix : overlaps)
    {
        s.erase(s.begin() + ix - removed++);
    }
    s.push_back(m);
}

void display_groups(sets &s)
{
    std::string str;
    int id;
    for (std::map<std::string, event_t> m : s)
    {
        for (auto p : m)
        {
            str = std::string(ctime(&(p.second.date)));
            str.erase(str.length() - 1);
            id = p.second.id;
            std::cout << p.first << "    " << id << " (" << str << ")" << std::endl;
        }
        std::cout << std::endl;
    }
}

void unlink_group(sets &s, int id)
{
    time_t init = time(NULL);
    int ix = 0;
    for (std::map<std::string, event_t> m : s)
    {
        std::vector<std::string> v;
        for (auto p : m)
        {
            if (p.second.id == id)
                v.push_back(p.first);
        }
        for (std::string str : v) {
            std::map<std::string, event_t> m_;
            event_t e = {-1, init};
            m_.insert(make_pair(str, e));
            s.push_back(m_);
            s[ix].erase(str);
        }
        ix += 1;
    }
}

