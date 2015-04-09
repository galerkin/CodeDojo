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