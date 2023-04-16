#ifndef __FILE_HPP
#define __FILE_HPP
#include <vector>
#include <string>
#include "Item.hpp"

class File : public Item{
    private:
        std::vector<LineString*> lines;
        std::string name;

    public:
        File(std::string fileName) : name(fileName) { }
        void setName(std::string fileName){
            name = fileName;
        }
        void addLine(LineStringFactory * factory, const std::string &line){
            lines.push_back(factory->getLineString(line));
        }
        
        std::string getName() { return name; }

        void printFormatted(std::ostream &out) {
            out << "File {\n";
            out << "name: " << this->name << '\n';
            for (LineString * lineString : lines) {
                out << "line: " << lineString->getIndex() << '\n';
            }
            out << "}\n";
        }

        #define NEXT_ getline(in, recieved)

        void readFormatted(std::istream &in, LineStringFactory * factory) {
            std::string recieved;
            while (true) {
                NEXT_;
                if (recieved.substr(0, 6) == "line: ") {
                    lines.push_back(factory->LineStringPool.at(stoi(recieved.substr(6))));
                }
                else if (recieved == "}") break;
            }
        }

};

#endif
