#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <functional>
int input;
std::string file_contents = "";
void deletef() {
    std::string str;
    std::ifstream fout("/Users/jasonmoses/Desktop/C++/StudentGradeSystem/allGrades.txt");
    while (str != "q") {
        int t;
        std::string s;
        std::string line;
        std::vector<std::string> vectorOfStrings2;
        int it;
        std::cout<<"Delete Student type Student Number or type q to exit"<<std::endl;
        std::cin>>str;
    if (fout.is_open())
        {
        if (str.length() == 9)
        {
        while (std::getline(fout, line))
        {
            file_contents += line;
            vectorOfStrings2.push_back(line + "\n");
        }
            std::ofstream fout2("/Users/jasonmoses/Desktop/C++/StudentGradeSystem/allGrades.txt");
                    for (int e = 0; e < vectorOfStrings2.size(); e++)
                    {
                    it = vectorOfStrings2.at(e).find(str);
                    if (it != std::string::npos)
                        {
                        std::cout<<vectorOfStrings2.at(e)<<std::endl;
                        vectorOfStrings2.erase(vectorOfStrings2.begin() + e);
                        }
                    }
                    for (int j =0; j < vectorOfStrings2.size(); j++)
                    {
                    fout2 << vectorOfStrings2.at(j);
                    }
                }
                else {
                 std::cout<<"Not in Database Try Again!"<<std::endl;
                }
            vectorOfStrings2.clear();
            }
        else
        {
        std::cout<<"Please Try Again student numbers begin with u and is 9 charcthers long!"<<std::endl;
        }
        fout.close();
}
if (str != "q") {  fout.close(); }
}
void editf() {
    std::string fileInputStudentName;
    std::string fileInputStudentNumber;
    std::string fileInputStudentGrade;
    std::string fileInputStudentComment;
    std::string str;
    std::ifstream fout("/Users/jasonmoses/Desktop/C++/StudentGradeSystem/allGrades.txt");
    std::ofstream f("/Users/jasonmoses/Desktop/C++/StudentGradeSystem/allGrades.txt", std::fstream::app);
    while (str != "q") {
        int t;
        std::string s;
        std::string line;
        std::vector<std::string> vectorOfStrings2;
        int it;
        std::cout<<"Edit Student type Student Number or type q to exit"<<std::endl;
        std::cin>>str;
    if (fout.is_open())
        {
        if (str.length() == 9)
        {
        while (std::getline(fout, line))
        {
            file_contents += line;
            vectorOfStrings2.push_back(line + "\n");
        }
            std::ofstream fout2("/Users/jasonmoses/Desktop/C++/StudentGradeSystem/allGrades.txt");
                    for (int e = 0; e < vectorOfStrings2.size(); e++)
                    {
                    it = vectorOfStrings2.at(e).find(str);
                    if (it != std::string::npos)
                        {
                        std::cout<<vectorOfStrings2.at(e)<<std::endl;
                        vectorOfStrings2.erase(vectorOfStrings2.begin() + e);
                        }
                        else {
                         std::cout<<"Not in Database Try Again!"<<std::endl;
                        }
                    }
                    for (int j =0; j < vectorOfStrings2.size(); j++)
                    {
                    fout2 << vectorOfStrings2.at(j);
                    }
                    fout2.close();
                    std::cout<<"Enter New Student Details: Student Number, Student Name, Grade and Comment \n";
                    printf("Student Number: ");
                    std::cin >> fileInputStudentNumber;
                    if (fileInputStudentNumber == "q")
                    {
                        f.close();
                        exit(1);
                    }
                    if (fileInputStudentNumber.length() == 9)
                    {
                       f << fileInputStudentNumber +  "           ";
                    }
                    else
                    {
                      std::cout<<"Please try again student number must be of length 9 characters!"<<std::endl;
                      std::cin >> fileInputStudentNumber;
                      f << fileInputStudentNumber + "           ";
                    }
                    printf("Student Name: ");
                    std::cin >> fileInputStudentName;
                    if (fileInputStudentName.length() <= 14)
                    {
                       f << fileInputStudentName + "   ";
                    }
                    else
                    {
                      std::cout<<"Please try again student name must be less than or equal to 14 characters!"<<std::endl;
                      std::cin >> fileInputStudentName;
                      f << fileInputStudentName + "   ";
                    }
                    printf("Student Grade: ");
                    std::cin >> fileInputStudentGrade;
                    if (fileInputStudentGrade.length() <= 3)
                    {
                       f << fileInputStudentGrade + "           ";
                    }
                    else
                    {
                     std::cout<<"Please try again Student Grade must be less than or equal to 2!"<<std::endl;
                     std::cin >> fileInputStudentGrade;
                     f << fileInputStudentGrade  + "           ";
                    }
                    printf("Student Comment: ");
                    std::cin >> fileInputStudentComment;
                    if (fileInputStudentComment.length() <= 13)
                    {
                       f << fileInputStudentComment + "\n";
                    }
                    else
                    {
                      std::cout<<"Please try again student comment must be less than or equal to 13!"<<std::endl;
                      std::cin >> fileInputStudentComment;
                      f << fileInputStudentComment + "\n";
                    }
            }
            else
            {
            std::cout<<"Please Try Again student numbers begin with u and is 9 charcthers long!"<<std::endl;
            }
            }
            vectorOfStrings2.clear();
            }
if (str == "q" ) { fout.close(); }
}
void searchf() {
    std::ifstream fout("/Users/jasonmoses/Desktop/C++/StudentGradeSystem/allGrades.txt");
    int t;
    std::string str;
    std::string line;
    std::vector<std::string> vectorOfStrings;
    while (str != "q") {
        std::cout<<"Search Student Number type q to exit"<<std::endl;
        std::cin>>str;
    if (fout.is_open())
        {
        if (str.length() == 9)
        {
        while (std::getline(fout, line))
        {
            file_contents += line;
            vectorOfStrings.push_back(line);
        }
            size_t found = file_contents.find(str);
            if (found != std::string::npos)
            {
                for (int e = 0; e < vectorOfStrings.size(); e++)
                {
                    if ((vectorOfStrings.at(e)).find(str) != std::string::npos)
                    {
                        std::cout<<vectorOfStrings.at(e)<<std::endl;
                    }
                }
            }
            else {
                std::cout<<"Not in Database Try Again!"<<std::endl;
            }
        }
        else
        {
        std::cout<<"Please Try Again student numbers begin with u and is 9 charcthers long!"<<std::endl;
        }
    vectorOfStrings.clear();
}
}
}
void createStudent() {
    std::ofstream f("/Users/jasonmoses/Desktop/C++/StudentGradeSystem/allGrades.txt", std::fstream::app);
    std::string fileInputStudentName;
    std::string fileInputStudentNumber;
    std::string fileInputStudentGrade;
    std::string fileInputStudentComment;
    while (fileInputStudentNumber != "q") {
    std::cout<<"Enter Student Details: Student Number, Student Name, Grade and Comment \n";
    printf("Student Number: (Type q to exit now) ");
    std::cin >> fileInputStudentNumber;
    if (fileInputStudentNumber.length() == 9)
    {
       f << fileInputStudentNumber +  "           ";
    }
    else
    {
      std::cout<<"Please try again student number must be of length 9 characters!"<<std::endl;
      std::cin >> fileInputStudentNumber;
      f << fileInputStudentNumber + "           ";
  }
    printf("Student Name: ");
    std::cin >> fileInputStudentName;
    if (fileInputStudentName.length() <= 14)
    {
       f << fileInputStudentName + "   ";
    }
    else
    {
      std::cout<<"Please try again student name must be less than or equal to 14 characters!"<<std::endl;
      std::cin >> fileInputStudentName;
      f << fileInputStudentName + "   ";
    }
    printf("Student Grade: ");
    std::cin >> fileInputStudentGrade;
    if (fileInputStudentGrade.length() <= 3)
    {
       f << fileInputStudentGrade + "           ";
    }
    else
    {
     std::cout<<"Please try again Student Grade must be less than or equal to 2!"<<std::endl;
     std::cin >> fileInputStudentGrade;
     f << fileInputStudentGrade  + "           ";
    }
    printf("Student Comment: ");
    std::cin >> fileInputStudentComment;
    if (fileInputStudentComment.length() <= 13)
    {
       f << fileInputStudentComment + "\n";
    }
    else
    {
      std::cout<<"Please try again student comment must be less than or equal to 13!"<<std::endl;
      std::cin >> fileInputStudentComment;
      f << fileInputStudentComment + "\n";
    }
}
    if (fileInputStudentNumber == "q") { f.close(); }
}
void CreateEntries()
{
int inp;
std::cout<<"1) Create Student"<<std::endl;
std::cout<<"2) Delete Student"<<std::endl;
std::cout<<"3) Edit Student"<<std::endl;
std::cout<<"3) Menu"<<std::endl;
std::cin>>inp;
switch (inp)
 {
case 1:
    createStudent();
    break;
case 2:
    deletef();
    break;
case 3:
    editf();
    break;
case 4:
    exit(0);
    break;
 }
}
void ViewEntries()
 {
    std::ifstream fout("/Users/jasonmoses/Desktop/C++/StudentGradeSystem/allGrades.txt");
    std::cout<<"1) View All Entries"<<std::endl;
    std::cout<<"2) Find Student by using Student Number"<<std::endl;
    std::cout<<"3) Exit"<<std::endl;
    std::cin>>input;
    switch (input) {
    case 1:
        if (fout.is_open())
        {
          std::cout << fout.rdbuf() <<std::endl;
        }
        break;
    case 2:
        searchf();
        break;
    case 3:
        exit(0);
        break;
     }
 }
void Menu()
{
std::cout<<"1) Create Entries And Modify"<<std::endl;
std::cout<<"2) View Entries"<<std::endl;
std::cout<<"3) Exit"<<std::endl;
std::cin>>input;
switch (input)
{
case 1:
    CreateEntries();
    break;
case 2:
    ViewEntries();
    break;
case 3:
    exit(0);
    break;
 }
}
int main() {
Menu();
}
