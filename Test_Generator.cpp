#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

class Question
{
private:
    vector<string> q;
    vector<int> ans;

public:
    Question()
    {
        updateQuestion();
    }

    void updateQuestion()
    {
        string que;

        que = "Which of the following is not a feature of Object-Oriented Programming?\n1. Encapsulation\n2. Inheritance\n3. Polymorphism\n4. Compilation";
        q.push_back(que);
        ans.push_back(4);

        que = "In OOP, what does encapsulation refer to?\n1. Hiding the implementation details of a class\n2. Deriving new classes from existing ones\n3. Using the same operation to denote different operations\n4. Describing the behavior of objects";
        q.push_back(que);
        ans.push_back(1);

        que = "What is a class in OOP?\n1. A blueprint for creating objects\n2. An instance of an object\n3. A type of function\n4. Hierarchical inheritance";
        q.push_back(que);
        ans.push_back(1);

        que = "What does polymorphism mean in OOP?\n1. Creating multiple functions with the same name but different parameters\n2. Encapsulation of data and functions into a single unit\n3. Deriving new classes from existing ones\n4. Restricting access to the internal state of an object";
        q.push_back(que);
        ans.push_back(1);

        que = "What is the main purpose of a constructor in a class?\n1. To create a new instance of the class\n2. To initialize the object\n3. To delete an object\n4. To allocate memory for the object";
        q.push_back(que);
        ans.push_back(2);

        que = "In which type of inheritance does a derived class inherit from multiple base classes?\n1. Single inheritance\n2. Multilevel inheritance\n3. Multiple inheritance\n4. Hierarchical inheritance";
        q.push_back(que);
        ans.push_back(3);

        que = "Which keyword is used to inherit a class in C++?\n1. extends\n2. implements\n3. inherits\n4. : (colon)";
        q.push_back(que);
        ans.push_back(4);

        que = "What does the 'this' keyword refer to in a class?\n1. The current object\n2. The parent class\n3. The base class\n4. The static methods";
        q.push_back(que);
        ans.push_back(1);

        que = "Which of the following statements is true about destructors?\n1. Destructors can be overloaded\n2. Destructors cannot be virtual\n3. Destructors have the same name as the class with a tilde (~)\n4. Destructors take parameters";
        q.push_back(que);
        ans.push_back(3);

        que = "Which OOP concept is demonstrated by the relationship 'A bird is an animal'?\n1. Encapsulation\n2. Inheritance\n3. Polymorphism\n4. Abstraction";
        q.push_back(que);
        ans.push_back(2);
    }

    int askQuestion()
    {
        int b = 0;
        int score = 0;
        while (b < 5)
        {
            int answerOpt = -1;
            int Rand = rand() % q.size();
            cout << q[Rand] << endl;
            cin >> answerOpt;
            if (answerOpt == ans[Rand])
            {
                cout << "Correct Answer!!" << endl;
                score += 10;
            }
            else
            {
                cout << "You got it wrong!!" << endl;
            }
            b++;
        }
        cout << "Your Total Score: " << score << endl;
        return score;
    }
};

class User : public Question
{
private:
    string name;
    int age;
    int score;

public:
    User() : score(0) {}

    void startQuiz()
    {
        int s = Question::askQuestion();
        score = max(s, score);
    }

    void storeDATA()
    {
        cout << "Enter name: " << endl;
        cin >> name;
        cout << "Enter age: " << endl;
        cin >> age;
    }

    void scoreTable() const
    {
        cout << name << " " << score << endl;
    }
};

int main()
{
    srand(time(0));
    int n;
    User *u[100];
    for (int i = 0; i < 100; i++)
    {
        u[i] = new User;
    }
    int ui = 0;

    do
    {
        cout << "1. To start the game." << endl;
        cout << "2. To view score table." << endl;
        cout << "3. To exit." << endl;
        cin >> n;

        if (n == 1)
        {
            u[ui]->storeDATA();
            u[ui]->startQuiz();
            ui++;
        }
        if (n == 2)
        {
            for (int i = 0; i < ui; i++)
            {
                u[i]->scoreTable();
            }
        }
    } while (n != 3);

    return 0;
}
