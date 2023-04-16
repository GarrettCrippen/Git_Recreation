#ifndef __COMMIT_HPP
#define __COMMIT_HPP
#include <string>
#include <vector>
#include "File.hpp"
#include "Folder.hpp"



class Commit {
    private:
        std::vector<Item* > items;
        std::string commitMessage;

    public:
        

        Commit() : commitMessage("") { }
        Commit(std::string message) : commitMessage(message) { }

	~Commit(){
	for(auto i : items){
	delete i;
	}
	}
        void setMessage(std::string message) {
            commitMessage = message; 
        }
        std::string getMessage() {
            return commitMessage;
        }

        void addItem(Item* itemName) {
            items.push_back(itemName);
        }

        const std::vector<Item*>* getItems() const {
            return &items;
        }

        void removeItem(int index) {
            items.erase(items.begin() + index);
        }
        
        void printFormatted(std::ostream &out) {
            out << "Commit {\n";
            out << "message: " << commitMessage << '\n';
            for (Item * item : items) {
                item->printFormatted(out);
            }
            out << "}\n";
        }

        #define NEXT_ getline(in, recieved)

        void readFormatted(std::istream &in, LineStringFactory * factory) {
            std::string recieved;
            while (true) {
                NEXT_;
                if (recieved == "Folder {") {
                    NEXT_;
                    addItem(new Folder(recieved.substr(6, std::string::npos)));
                    items.back()->readFormatted(in, factory);
                }
                if (recieved == "File {") {
                    NEXT_;
                    addItem(new File(recieved.substr(6)));
                    items.back()->readFormatted(in, factory);
                }
                else if (recieved == "}") break;
            }
        }

        bool itemExists(std::string itemName) {
            for(int i = 0 ; i < items.size(); i++) {
                if(items.at(i)->getName() == itemName) {
                    return true;
                }
            }
            return false;
        }

        Item* getItem(std::string itemName) {
            for(int i = 0 ; i < items.size(); i++) {
                if(items.at(i)->getName() == itemName) {
                    return items.at(i);
                }
            }
            return nullptr;
        }
        
};

#endif
