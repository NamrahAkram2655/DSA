#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int Count(string filename, string word)
{
    ifstream imf(filename);
    if (!imf)
    {
        exit(0);
    }
    else
    {
        string wordToText;

        string line;
        int lineNumber = 1;

        while (getline(imf, line))
        {
            // lineNumber++;
            int pos = 0;
            int wcount = 0;
            while ((pos = line.find(word, pos)) != -1)
            {
                pos++;
                wcount++;
            }
            cout << lineNumber << " " << wcount << " " << endl;
            lineNumber++;
        }
    }
    imf.close();
}

int main()
{
    Count("input1.txt", "few");
    return 0;
}