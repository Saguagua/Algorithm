#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> quiz) {
    vector<string> answer = vector<string>(quiz.size());
    vector<string> split;
    string word;

    for (int i = 0; i < quiz.size(); i++)
    {
        split.clear();
        stringstream ss(quiz[i]);

        while (ss >> word)
        {
            split.push_back(word);
        }
        int num1 = std::stoi(split[0]);
        int num2 = std::stoi(split[2]);
        int result = std::stoi(split[4]);

        if (split[1] == "+")
        {
            if (num1 + num2 == result)
                answer[i] = "O";
            else
                answer[i] = "X";
        }
        else
        {
            if (num1 - num2 == result)
                answer[i] = "O";
            else
                answer[i] = "X";
        }

    }

    return answer;
}
void main()
{
    vector<string> v = { "p", "o", "s" };
    vector<string> v2 = { "3 - 4 = -3", "5 + 6 = 11"};
    vector<int> v3 = {7, 77, 17};
    solution(v2);
}