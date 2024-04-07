#pragma once

#include "question.h"
#include <vector>
#include <map>
#include <unordered_map>

class Quiz {

    public:
        Quiz();
        Quiz(std::map<int, MCQuestion>& mcQuestions, std::map<int, SAQuestion>& saQuestions);
        Quiz(int questionCount);
        ~Quiz();
        
        /**
         * @brief Runs through the testing interface.
        */
        void test();

        /**
         * @brief Goes through each question and its corresponding answer and checks for correctness.
        */

        void printInsights();

    private:

        void mark();
        std::map<int, SAQuestion> saQuestions_;
        std::map<int, MCQuestion> mcQuestions_;
        std::vector<std::string> saAnswers_;
        std::vector<std::string> mcAnswers_;
        std::map<std::string, int> wrongAnswerTags_;
        int correct_;
        double percentCorrect_;

};