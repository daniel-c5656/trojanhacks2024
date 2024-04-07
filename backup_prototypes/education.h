#include <cstdlib>
#include "user.h"
#include "paper.h"
#include <unordered_map>

class Education {
    public:

    private:
        std::unordered_map<int, User> users_;
        std::unordered_map<int, Question> questions_;
};