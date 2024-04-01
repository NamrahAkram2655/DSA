#include <iostream>
#include <fstream>
#include <string>
#include <stack>
using namespace std;

bool delimiterOk(const string &expression)
{
    stack<char> s;
    for (char val : expression)
    {
        if (val == '(' || val == '[' || val == '{')
        {
            s.push(val);
        }
        else if (val == ')' || val == ']' || val == '{')
        {
            if (s.empty() || (val == ')' && s.top() != '(') || (val == ']' && s.top() != '[') || (val == '}' && s.top() != '{'))
            {
                return false;
            }
            else
            {
                s.pop();
            }
        }
    }

    return s.empty();
}
int main()
{

    ifstream imf("input (1).txt");

    if (!imf)
    {
        cout << "File didn't open \n";
    }
    else
    {
        int count;
        imf >> count;
        cout << count <<endl;

        imf.ignore();
        string str;
        for (int i = 0; i < count; i++)
        {
            getline(imf, str);
            if (delimiterOk(str))
            {
                cout <<str<< " is Valid \n";
            }
            else
            {
                cout <<str<< " is Invalid\n";
            }
        }
    }

    imf.close();
    return 0;
}