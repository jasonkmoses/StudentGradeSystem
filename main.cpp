#include <iostream>
#include <vector>
#include <fstream>
std::ofstream f("/Users/jasonmoses/Desktop/C++/StudentGradeSystem/allGrades.txt", std::fstream::app);
std::ifstream fout("/Users/jasonmoses/Desktop/C++/StudentGradeSystem/allGrades.txt");
std::vector<std::string> AllInfo;
int input;
void CreateEntries()
{
int inp;
std::string fileInputStudentName;
std::string fileInputStudentNumber;
std::string fileInputStudentGrade;
std::string fileInputStudentComment;
std::cout<<"1) Create Student"<<std::endl;
std::cout<<"2) Delete Student"<<std::endl;
std::cout<<"3) Edit Student"<<std::endl;
std::cout<<"3) Menu"<<std::endl;
std::cin>>inp;
switch (inp)
 {
case 1:
    std::cout<<"Enter Student Details: Student Number, Student Name, Grade and Comment \n";
    printf("Student Number: ");
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
    if (fileInputStudentGrade.length() <= 2)
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
       f << fileInputStudentComment + "           ";
    }
    else
    {
      std::cout<<"Please try again student comment must be less than or equal to 13!"<<std::endl;
      std::cin >> fileInputStudentComment;
      f << fileInputStudentComment + "           ";
    }
    f << "\n";
    break;
case 2:
    break;
case 3:
    break;
case 4:
    exit(0);
    break;
 }
}
void FindByStudentNumber() {
    int countwords=0;
    std::string line;
    std::string word;
    if(fout.is_open())
    {
        while(getline(fout,line))
        {
            std::cout<<line<<std::endl;
        }
        std::cin>>word;
        while(!fout.eof())
        {
            if(word.compare(line)==0) {
                countwords++;
            }
        }
        std::cout<<"The word has been found "<<countwords<<" times."<<std::endl;
        if (countwords != 0)
        {
        std::string word;
    	int i = 0;
    	while(fout >> word)
    	{
           ++i;
           fout >> AllInfo.at(i);
           std::cout<<AllInfo.at(i)<<std::endl;
        }
        if (std::find(AllInfo.begin(), AllInfo.end(), word) != AllInfo.end()) {
            for (int y = 0; y < 3; ++y)
            {
            std::cout<<AllInfo.at(y)<<std::endl;
            }
            fout.close();
        }
    }
}
}
void ViewEntries()
 {
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
        FindByStudentNumber();
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
