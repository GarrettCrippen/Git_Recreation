#pragma once

#include <ostream>
#include <string>

class LineString {
    private:
    int index;
    int hash;
    std::string data;

    public:
    LineString(int index, int hash, std::string data) : index(index), hash(hash), data(data) { }

    const int getIndex() {
        return index;
    }

    const int getHash() const {
        return hash;
    }

    const std::string &getData() const {
        return data;
    }

    // friend std::ostream &operator<<(std::ostream & out, const LineString & line);
    std::ostream & print(std::ostream & out) { out << index << ": " << hash << ": " << data; return out; }
};
