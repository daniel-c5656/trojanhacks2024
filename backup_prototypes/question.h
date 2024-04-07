#pragma once

#include "paper.h"
#include <vector>

typedef std::vector<std::string> strVec;


class Question {
    public:
        Question(); // constructor, using scanner (Adobe acrobat style)
        Question(std::string text); // ctor instantiated using question text
        ~Question(); // Just in case we need to allocate dynamic memory
        void parseTopics();
        std::string getQuestionText() const;
        std::string getAnswer() const;
        strVec getTopics() const;
        Image getImage() const;
    private:
        const int questionId;
        std::string questionText_;
        std::string answer_;
        std::string imageFileName_;
        static int totalIds;

        strVec topics_; // topics the question involves e.g. 12.7 Spherical Coordinates
        Image image_;
        int type; // 0 = long form, 1 = MCQ
};
