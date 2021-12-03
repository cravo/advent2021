#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void part1(void)
{
    ifstream input("input03.txt");
    if(input.is_open())
    {
        string line;
        int const digits = 12;
        int countOne[digits];
        int countZero[digits];

        for(int i = 0; i < digits; ++i)
        {
            countOne[i] = 0;
            countZero[i] = 0;
        }

        while(getline(input, line))
        {
            for(int i = 0; i < digits; ++i)
            {
                if(line.at(i) == '1')
                {
                    countOne[i]++;
                }
                else
                {
                    countZero[i]++;
                }
            }
        }
        input.close();

        string gammaRateText = "";
        string epsilonRateText = "";
        for(int i = 0; i < digits; ++i)
        {
            if(countOne[i] > countZero[i])
            {
                gammaRateText += "1";
                epsilonRateText += "0";
            }
            else
            {
                gammaRateText += "0";
                epsilonRateText += "1";
            }
        }

        int gammaRate = stoi(gammaRateText, nullptr, 2);
        int epsilonRate = stoi(epsilonRateText, nullptr, 2);

        int result = gammaRate * epsilonRate;
        cout << "PART1: " << result << " is the answer\n";
    }
}

void part2(void)
{
    ifstream input("input03.txt");
    if(input.is_open())
    {
        vector<string> lines[2];

        string line;
        while(getline(input, line))
        {
            lines[0].push_back(line);
            lines[1].push_back(line);
        }
        input.close();

        for(int result = 0; result < 2; ++result)
        {
            int const digits = 12;
            for(int digit = 0; digit<digits && lines[result].size() > 1; ++digit)
            {
                int count[2] = { 0, 0 };
                int numLines = lines[result].size();

                for(int i = 0; i < numLines; ++i)
                {
                    int bit = lines[result][i].at(digit) - '0';
                    count[bit]++;
                }

                char keep = '0' + result;
                if(count[1] >= count[0])
                {
                    keep = '0' + (1 - result);
                }

                vector<string> remainingLines;
                for(int i = 0; i < numLines; ++i)
                {
                    if(lines[result][i].at(digit) == keep)
                    {
                        remainingLines.push_back(lines[result][i]);
                    }
                }

                lines[result] = remainingLines;
            }
        }

        int oxygenRating = stoi(lines[0][0], nullptr, 2);
        int co2Rating = stoi(lines[1][0], nullptr, 2);
        int result = oxygenRating * co2Rating;

        cout << "PART2: " << result << "\n";
    }
}

int main(void)
{
    part1();
    part2();

    return 0;
}