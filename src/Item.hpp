#ifndef __ITEM_HPP
#define __ITEM_HPP
#include "LineStringFactory.hpp"
#include <vector>
#include <string>
#include <iostream>

class Item {
    protected:
        std::string name;
    public:
        Item() { };
        virtual std::string getName() = 0;
        virtual void printFormatted(std::ostream &out) = 0;
        virtual void readFormatted(std::istream &in, LineStringFactory * factory) = 0;
};

#endif
