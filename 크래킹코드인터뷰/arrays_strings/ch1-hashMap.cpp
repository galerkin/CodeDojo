/*!
 * \file ch1-hashMap.cpp
 *
 * \author eomj
 * \date April 2015
 * \brief 1 기본 hash table을 쓸줄 알아 물어보는것
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
#include <map>
#include <vector>
#include <string>
#include <iostream>

struct Student
{
    int id;
    std::string name;

    int getID() {return id;}
    Student(): id(0), name("Name"){}
    Student(int id_, std::string name_): id(id_), name(name_){}
};

std::map<int, Student> buildMap(std::vector<Student> &students)
{
    std::map<int, Student> hashMap;
    for (auto s:students)
    {
        hashMap[s.getID()] = s;
    }
    return hashMap;
}

int main1()
{

    std::vector<Student> students;

    for (auto i = 0; i<3; i++)
    {
        Student a(i, std::string("test")+std::to_string(i));
        students.push_back(a);
    }

    std::map<int, Student> mmap = buildMap(students); 

    for(auto s:mmap)
    {
        std::cout << s.first << " " << s.second.name << std::endl;
    }

    return 0;
}