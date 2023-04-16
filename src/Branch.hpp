#ifndef __BRANCH_HPP
#define __BRANCH_HPP
#include <vector>
#include <string>
#include "Item.hpp"
#include "File.hpp"
#include "Folder.hpp"
#include "Commit.hpp"

class Branch {
    private:
        std::string name;
        std::vector<Commit*> commits;
    public:
        Branch() : name("") { }
        Branch(std::string branchName) : name(branchName) { }

        void addCommit(Commit* newCommit) {
            commits.push_back(newCommit);
        }

        const std::vector<Commit*> * getCommits() const {
            return &commits;
        }

        const Commit * getHead() const {
            return commits.back();
        }

        const std::string getName(){
            return name;
        }

        void printFormatted(std::ostream &out) {
            out << "Branch {\n";
            out << "name: " << this->name << '\n';
            for (Commit * commit : commits) {
               commit->printFormatted(out);
            }
            out << "}\n";
        }

        #define NEXT_ getline(in, recieved)

        void readFormatted(std::istream &in, LineStringFactory * factory) {
            std::string recieved;
            while (true) {
            NEXT_;
                if (recieved == "Commit {") {
                    NEXT_;
                    addCommit(new Commit(recieved.substr(9, std::string::npos)));
                    commits.back()->readFormatted(in, factory);
                }
                else if (recieved == "}") break;
            }
        }

};

#endif
