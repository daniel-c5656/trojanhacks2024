#pragma once

#include <string>
#include <vector>
#include <fstream> // If we can't get OCR to work
#include "question.h"



class Paper {
    public:
        Paper();
        Paper(std::vector<Question> qs);
        Paper(int count);


        void addQuestion(int qId);

        void printPaper() const;
        int mark();

    
    private:
        strVec topics_;
        std::vector<int> questionIDs_;
};

class Image {
    
};