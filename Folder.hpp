#ifndef __FOLDER_HPP
#define __FOLDER_HPP
#include <vector>
#include <string>
#include "Item.hpp"

class Folder : public Item {
    private:
        std::vector<Item*> items;
        std::string name;
    public:
        Folder(std::string folderName) : name(folderName) { }

	
	~Folder(){
		for(auto i : items){
			delete i;
		}
	}

        std::string getName() {
            return name;
        }
        
        void printFormatted(std::ostream &out) {
            out << "Folder {\n";
            out << "name: " << this->name << '\n';
            for (Item * item : items) {
                item->printFormatted(out);
            }
            out << "}\n";
        }

        #define NEXT_ getline(in, recieved)

        void readFormatted(std::istream &in, LineStringFactory * factory) {
            std::string recieved;
            NEXT_;
            while (true) {
                if (recieved == "Folder {") {
                    NEXT_;
                    addItem(new Folder(recieved.substr(6, std::string::npos)));
                    items.back()->readFormatted(in, factory);
                }
                if (recieved == "File {") {
                    NEXT_;
                    addItem(new File(recieved.substr(6, std::string::npos)));
                    items.back()->readFormatted(in, factory);
                }
                else if (recieved == "}") break;
            }
        }

        void addItem(Item * itemName) {
            items.push_back(itemName);
        }

        void newItem(std::string fileName) {
            items.push_back(new File(fileName));
        }

};

#endif
