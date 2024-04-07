#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>




/* Object class for exam questions */
class Question {

    public:
        const int QUESTION_SIZE{20};
        // Load the question from a filestream
        Question();
        Question(int id, int type, std::string questionBody, std::string correctAns, std::vector<std::string> tags);
        ~Question();
        std::string getQuestionBody();
        bool isCorrect(std::string ans);

    protected:
        int id_{};
        int type_{}; // 0 = MCQ, 1 = SAQ
        std::string questionBody_{};
        std::string correctAns_{};
        std::vector<std::string> tags_{};
    friend class Quiz;
};

class MCQuestion : public Question {

    public:
        MCQuestion(int id, int type, std::string questionBody, std::string correctAns, 
            std::vector<std::string> tags, std::vector<std::string> possibleAnswers);
        bool isCorrect(std::string ans);
    private:
        std::vector<std::string> possibleAnswers_;
    friend class Quiz;
    
};


class SAQuestion : public Question {

    public:
        SAQuestion(int id, int type, std::string questionBody, std::string correctAns, std::vector<std::string> tags);
        bool isCorrect(std::string ans, int questionID);
        
    // private:
    //     std::string explanation_;
    friend class Quiz;
    
};