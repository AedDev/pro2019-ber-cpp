#pragma once

#include <iostream>
#include <string>
#include <limits>

using namespace std;

class Util {
public:
    static int readInt(const string& msg, int min = INT_MIN, int max = INT_MAX)
    {
        int val = 0;
        do
        {
            cout << msg;
            cin >> val;

            if (cin.fail() || val < min || val > max)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else
            {
                break;
            }
        } while (true);

        return val;
    }
	
	template <typename T>
    static T readEnum(const string& msg, T min, T max, int offset = 0)
    {
        int intVal = Util::readInt(msg, static_cast<int>(min) + -offset, static_cast<int>(max) + -offset);
        T enumVal = static_cast<T>(intVal + offset);

        return enumVal;
    }
};
