#pragma once

#include "education.h"
#include "paper.h"
#include <unordered_map>

class User {
    public:
        User();
        User(std::string name, int id);

    private:
        std::unordered_map<int, Paper> papers_; // Papers assigned to user
        std::string name_;
        int userId_;
        static int totalUserIds_;
};