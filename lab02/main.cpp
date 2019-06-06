#include <iostream>

#include "My_list.h"

class Testclass
{
private:
    int member;
public:
    explicit Testclass() : member(0) {};
    explicit Testclass(int _member) : member(_member) {};

    int get() { return member; };
    operator int() { return member; };
};

const int dbl(const int &el, size_t i)
{
    return el*2;
}

const int sm(const int &res, const int &el, size_t i)
{
    return res+el;
}

int main() {
    std::cout << "Constructors: " << std::endl;

    auto tclex1 = new Testclass(2);
    auto tclex2 = new Testclass(5);
    My_list<const int> list({1, 2, 3});
    My_list<Testclass> tcllist(tclex1, 1);

    tcllist.push_back(*tclex2);

    for (int el : list)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl;
    for (auto el : tcllist)
    {
        std::cout << el.get() << " ";
    }

    std::cout << std::endl;
    std::cout << "Map: " << std::endl;

    My_list<const int> list2 = list.map(dbl);

    for (int el : list2)
    {
        std::cout << el << " ";
    }

    std::cout << std::endl;
    std::cout << "Reduce: " << std::endl;

    std::cout << list2.reduce(sm, 0);

    std::cout << std::endl;
    std::cout << "Slice: " << std::endl;

    My_list<const int> list3 = list2.slice(0, 2);

    for (int el : list3)
    {
        std::cout << el << " ";
    }

    std::cout << std::endl;
    std::cout << "Join: " << std::endl;

    std::cout << list.join(" ");
    std::cout << std::endl;
    std::string div(" ");
    std::cout << list.join(div);
    std::cout << std::endl;
    std::cout << tcllist.join(div);

    std::cout << std::endl;
    std::cout << "Pop: " << std::endl;

    std::unique_ptr<const int> p = list2.pop(1);

    for (int el : list2)
    {
        std::cout << el << " ";
    }
    std::cout << *p;

    std::cout << std::endl;
    std::cout << "Insert: " << std::endl;

    const int d = 4;
    list2.insert(d, 1);
    list2.insert(d, 0);

    for (int el : list2)
    {
        std::cout << el << " ";
    }

    std::cout << std::endl;
    std::cout << "Operator+: " << std::endl;

    My_list<const int>listpl = list + list2 + list3;

    for (int el : listpl)
    {
        std::cout << el << " ";
    }

    std::cout << std::endl;
    std::cout << "Operator[]: " << std::endl;

    std::cout << list[0] << " " << list[2];

    std::cout << std::endl;
    std::cout << "Exceptions: " << std::endl;

    try
    {
        list[4];
    }
    catch (Bad_index &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        My_list<const int> list31 = list2.slice(0, 0);
    }
    catch (Bad_index &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        My_list<const int> list32 = list2;
        My_list<const int>::iterator iter = list32.begin();
        list32.clear();
        const int k = *iter;
    }
    catch (Bad_iterator &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}