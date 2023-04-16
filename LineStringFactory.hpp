#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "LineString.hpp"

int Hash(const std::string & str) {
    int output = 0;
    int i = 0;
    for (char c : str) {
        output += (c * i);
        i++;
    }
    return output;
}

class LineStringFactory {
    private:
    std::vector<LineString*> LineStringPool;

    public:
    ~LineStringFactory(){
		for(auto i : LineStringPool){
			delete i;
		}
	}
    LineString * getLineString(const std::string & str) {
        int hash = Hash(str);
        for (LineString * lineString : LineStringPool) {
            if (lineString->getHash() == hash) {
                if (lineString->getData() == str) {
                    return lineString;
                }
            }
        }

        LineStringPool.push_back(new LineString(LineStringPool.size(), hash, str));
        return LineStringPool.back();
    }

    friend class File;

    LineString * getLineString(const int index) {
        return LineStringPool.at(index);
    }

    void writeToFile(const char * filename) {
        std::ofstream ofs(filename);
        for (LineString * lineString : LineStringPool) {
            lineString->print(ofs) << '\n';
        }
    }

    void readFromFile(const char * filename) {
        std::ifstream ifs(filename);
        std::string line;
        int hash;
        int index;
        while (!ifs.eof()) {
            ifs >> index;
            ifs.ignore(2);
            ifs >> hash;
            ifs.ignore(2);
            getline(ifs, line);
            LineStringPool.push_back(new LineString(index, hash, line));

            // std::cout << hash << ":" << line << std::endl;
        }
    }
};
