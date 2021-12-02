#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void part1(void)
{
    ifstream input("input02.txt");
    if(input.is_open())
    {
        string line;
        string delimiter = " ";
        int horizontal = 0;
        int depth = 0;

        while(getline(input, line))
        {
            size_t pos = line.find(delimiter);
            string instruction = line.substr(0, pos);
            string distanceText = line.substr(pos + 1);
            int distance = stoi(distanceText);

            if(instruction == "forward")
            {
                horizontal += distance;
            }
            else if(instruction == "down")
            {
                depth += distance;
            }
            else if(instruction == "up")
            {
                depth -= distance;
            }
        }
        input.close();

        int result = horizontal * depth;
        cout << "PART1: " << result << " is the answer\n";
    }
}

void part2(void)
{
    ifstream input("input02.txt");
    if(input.is_open())
    {
        string line;
        string delimiter = " ";
        int horizontal = 0;
        int depth = 0;
        int aim = 0;

        while(getline(input, line))
        {
            size_t pos = line.find(delimiter);
            string instruction = line.substr(0, pos);
            string distanceText = line.substr(pos + 1);
            int distance = stoi(distanceText);

            if(instruction == "forward")
            {
                horizontal += distance;
                depth += aim * distance;
            }
            else if(instruction == "down")
            {
                aim += distance;
            }
            else if(instruction == "up")
            {
                aim -= distance;
            }
        }
        input.close();

        int result = horizontal * depth;
        cout << "PART2: " << result << " is the answer\n";
    }
}

int main(void)
{
    part1();
    part2();

    return 0;
}