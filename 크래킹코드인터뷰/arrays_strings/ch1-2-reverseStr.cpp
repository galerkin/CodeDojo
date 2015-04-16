/*!
 * \file ch1-2-reverseStr.cpp
 *
 * \author eomj
 * \date April 2015
 * \brief 1.1 Implement an algorithm to determine if a string has all
 *        unique characters. What if you cannot use additional data 
 *        structure
 * \details 전형적인 인터뷰 문제, 주의할점은 null character처리
 *  time O(n), space O(1)
 *           
 */
#include <iostream>

void reverse(char* str)
{
    char *end = str;
    char tmp;

    if (str)
    {
        // find end of str
        while (*end)
        {
            ++end;
        }
        --end; // step back from null terminated

        while (str < end)
        {
            tmp = *str;
            *str++ = *end;
            *end-- = tmp;
        }
    }
}

int main()
{
    using namespace std;

    char str1[] = "test1234567890";
    reverse(str1);

    cout << str1 <<"\n";

    return 0;
}