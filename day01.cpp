#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void part1(void)
{
    string line;
    ifstream input("input01.txt");
    if(input.is_open())
    {
        int lastValue;
        int numGreater = 0;

        if(getline(input, line))
        {
            lastValue = stoi(line);
        }

        while(getline(input, line))
        {
            int currentValue = stoi(line);
            if(currentValue > lastValue)
            {
                numGreater++;
            }
            lastValue = currentValue;
        }
        input.close();

        cout << "PART1: " << numGreater << " is the answer\n";
    }
}

int sumWindow(int *values)
{
    int sum = 0;
    for(int i = 0; i < 3; ++i)
    {
        sum += values[i];
    }

    return sum;
}

void part2(void)
{
    string line;
    ifstream input("input01.txt");
    if(input.is_open())
    {
        int window[3];
        int windowIndex = 0;
        int numGreater = 0;
        int lastValue;

        for(int i = 0; i < 3; ++i)
        {
            if(getline(input, line))
            {
                window[i] = stoi(line);
            }
        }

        lastValue = sumWindow(window);

        while(getline(input, line))
        {
            window[windowIndex] = stoi(line);
            windowIndex = (windowIndex + 1) % 3;

            int currentValue = sumWindow(window);
            if(currentValue > lastValue)
            {
                numGreater++;
            }
            lastValue = currentValue;
        }
        input.close();

        cout << "PART2: " << numGreater << " is the answer\n";
    }
}

int main(void)
{
    part1();
    part2();

    return 0;
}