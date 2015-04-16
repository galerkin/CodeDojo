/*!
 * \file ch1-1unique_char.cpp
 *
 * \author eomj
 * \date April 2015
 * \brief 1.1 Implement an algorithm to determine if a string has all
 *        unique characters. What if you cannot use additional data 
 *        structure
 * \details 질문할것: ASCII냐 유니코드냐? 다른 라이브러리 맘대로 써도되냐? 
 *  이 질문에 따라, ASCII면 스트링의 길이가 256(2^8)이상면 자동 false, 
 *  멀티 바이트 코드의 경우에는 해당하는 문자열의 크기만큼 잡아줘
 *  솔루션1: bool 어레이를 ASCII나 유니코드의 유일한 자소 숫자 만큼 잡고
 *  해당 문자의 존재를 체크해. 변종으로는 bool array대신에 bit operator를
 *  써서 잡는 거지 true check = bitmask & (1<<ith), make i-th true =
 *  bitmask |= (1<<ith)
 *  time O(n), space O(1)
 *           
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isUniqueCharset(string &str)
{
    const int NASCII = 256;
    if (str.size() > NASCII) return false;
    
    bool char_set[NASCII];
    for (auto x = 0; x<NASCII; ++x )
    {
        char_set[x] = false;
    }

    for (auto x: str)
    {
        int val = static_cast<int>(x)%256;
        if(char_set[val]) return false;
        char_set[val] = true;
    }
    return true;
}

bool isUniqueCharset2(string &str)
{
    return true;
}
int main_1_1()
{
    cout << isUniqueCharset(string("qwertyuiop[]asdfghjk")) << "\n";
    cout << isUniqueCharset(string("aabb")) << "\n";
    
    //getchar();
    return 0;
}