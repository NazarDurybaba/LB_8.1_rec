#include <iostream>
#include <cstring>
using namespace std;

// Функція для підрахунку входжень "abc"
int Count(char* str, int i = 0)
{
    if (strlen(str) - i < 3)
        return 0;
    if (str[i] == 'a' && str[i + 1] == 'b' && str[i + 2] == 'c')
        return 1 + Count(str, i + 1);
    else
        return Count(str, i + 1);
}

// Функція для заміни "abc" на "**"
char* Change(char* dest, const char* str, char* t, int i = 0)
{
    if (str[i] != 0)
    {
        if (str[i] == 'a' && str[i + 1] == 'b' && str[i + 2] == 'c')
        {
            strcat_s(t, strlen(t) + 3, "**");
            return Change(dest, str, t + 2, i + 3);
        }
        else
        {
            *t++ = str[i];
            *t = '\0';
            return Change(dest, str, t, i + 1);
        }
    }
    else
    {
        return dest;
    }
}

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    cout << "String contained " << Count(str) << " groups of 'abc'" << endl;
    char* dest1 = new char[151];
    dest1[0] = '\0';
    char* dest2;
    dest2 = Change(dest1, str, dest1);
    cout << "Modified string (param) : " << dest1 << endl;
    cout << "Modified string (result): " << dest2 << endl;
    delete[] dest1;
    return 0;
}
