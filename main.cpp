#include<iostream>
#include<windows.h>
#include<fstream>
#include<stdlib.h>
class Student{
    private:
        std::string admissionNumber,studentName,studentClass,searched,studentAge,course_semester;
        std::string searched_course_semester;
        std::string unit1,unit2,unit3,unit4,unit5,unit6,unit7,unit8;
        std::string unitMarks1,unitMarks2,unitMarks3,unitMarks4,unitMarks5,unitMarks6,unitMarks7,unitMarks8,averageMarks;
        std::fstream file, file2;
    public:
        void askUnits();
        void askDetails();
        void displayStudentResults();
};
int main()
{
    int choice;
    lb:
    std::cout<<"########################################-lastKING-School-########################################\n";
    std::cout<<"\t 1. Add units done during exams\n";
    std::cout<<"\t 2. Input student's details and marks\n";
    std::cout<<"\t 3. View student results\n";
    std::cout<<"\t 4. Exit\n";
    std::cout<<"-------------------------------------------------------------------------------------------------\n";
    std::cout<<"Enter your choice: ";
    std::cin>>choice;
    system("cls");
    Student student;
    if(choice == 1){
        std::cin.ignore();
        student.askUnits();
        goto lb;
    }
    else if(choice == 2){
        std::cin.ignore();
        student.askDetails();
        goto lb;
    }
    else if(choice == 3){
        std::cin.ignore();
        student.displayStudentResults();
        goto lb;
    }
    else if(choice == 4){
        return 0;
    }
    else{
        std::cout<<"\n\tInvalid input(choose between 1-4)";
    }
    return 0;
}
void Student :: askUnits(){
    std::cout<<"\n------------------------Enter course units done in final examination------------------------";
    std::cout<<"\n\nEnter the course and semester details(COURSENAME_SEMESTER):: ";
    getline(std::cin,course_semester);
    std::cout<<"\n\n\tUnit1: ";
    getline(std::cin,unit1);
    std::cout<<"\n\tUnit2: ";
    getline(std::cin,unit2);
    std::cout<<"\n\tUnit3: ";
    getline(std::cin,unit3);
    std::cout<<"\n\tUnit4: ";
    getline(std::cin,unit4);
    std::cout<<"\n\tUnit5: ";
    getline(std::cin,unit5);
    std::cout<<"\n\tUnit6: ";
    getline(std::cin,unit6);
    std::cout<<"\n\tUnit7: ";
    getline(std::cin,unit7);
    std::cout<<"\n\tUnit8: ";
    getline(std::cin,unit8);
    file.open("UnitsDone.txt",std::ios :: out | std::ios :: app);
    file<<course_semester<<"*"<<unit1<<"*"<<unit2<<"*"<<unit3<<"*"<<unit4<<"*"<<unit5<<"*"<<unit6<<"*"<<unit7<<"*"<<unit8<<std::endl;
    file.close();
    system("cls");
    std::cout<<"\n\n\t\tPlease wait,Updating Details...";
    Sleep(3500);
    system("cls");
    std::cout<<"\n\n\t\tUnits' details updated successfully";
    Sleep(3000);
    system("cls");

}

void Student :: askDetails(){
    std::cout<<" \nEnter student's name: ";
    getline(std::cin,studentName);
    std::cout<<" \nEnter student's Admission number: ";
    getline(std::cin,admissionNumber);
    std::cout<<" \nEnter student's class: ";
    getline(std::cin,studentClass);
    std::cout<<" \nEnter student's age: ";
    std::cin>>studentAge;
    system("cls");
    std::cout<<"\n\n\t\tPlease wait,Updating Details...";
    Sleep(3500);
    system("cls");
    std::cout<<"\n\n\t\tStudent's details updated successfully";
    Sleep(3000);
    system("cls");
    std::cout<<"\n\n\t\tRedirecting to the next page...";
    Sleep(2000);
    system("cls");

    std::cout<<"\nEnter the course and semester(COURSENAME_SEMESTER): ";
    std::cin.ignore();
    getline(std::cin,searched_course_semester);

    file.open("unitsDone.txt",std::ios :: in);
    getline(file,course_semester,'*');
    getline(file,unit1,'*');
    getline(file,unit2,'*');
    getline(file,unit3,'*');
    getline(file,unit4,'*');
    getline(file,unit5,'*');
    getline(file,unit6,'*');
    getline(file,unit7,'*');
    getline(file,unit8,'\n');

    bool courseFound = false;
    while(!file.eof()){
        if(searched_course_semester == course_semester){
            std::cout<<unit1<<" : ";
            std::cin>>unitMarks1;
            std::cout<<unit2<<" : ";
            std::cin>>unitMarks2;
            std::cout<<unit3<<" : ";
            std::cin>>unitMarks3;
            std::cout<<unit4<<" : ";
            std::cin>>unitMarks4;
            std::cout<<unit5<<" : ";
            std::cin>>unitMarks5;
            std::cout<<unit6<<" : ";
            std::cin>>unitMarks6;
            std::cout<<unit7<<" : ";
            std::cin>>unitMarks7;
            std::cout<<unit8<<" : ";
            std::cin>>unitMarks8;

            courseFound = true;
        }
        getline(file,course_semester,'*');
        getline(file,unit1,'*');
        getline(file,unit2,'*');
        getline(file,unit3,'*');
        getline(file,unit4,'*');
        getline(file,unit5,'*');
        getline(file,unit6,'*');
        getline(file,unit7,'*');
        getline(file,unit8,'\n');
    }
    if(courseFound == false){
        int choicee;
        std::cout<<"\n\tCourse not Found!\n\n";
        std::cout<<"\t1.Add course,semester and it's units: ";
        std::cout<<"\n\t2.Exit";
        std::cout<<"\n\n\t\tEnter choice: ";
        std::cin>>choicee;
        if(choicee==1){
            std::cin.ignore();
            askUnits();
        }
        else if(choicee==2){

        }
        else{
            std::cout<<"\n\nInvalid choice!";
        }
    }
    file.close();

    file2.open("studentsData.txt",std::ios :: out | std::ios :: app);
    file2<<studentName<<"*"<<admissionNumber<<"*"<<studentClass<<"*"<<studentAge<<"*"<<unitMarks1<<"*"<<unitMarks2<<"*"<<unitMarks3<<"*"<<unitMarks4<<"*"<<unitMarks5<<"*"<<unitMarks6<<"*"<<unitMarks7<<"*"<<unitMarks8<<std::endl;
    file2.close();
    system("cls");
    std::cout<<"\n\n\t\tPlease wait,Updating Marks...";
    Sleep(3500);
    system("cls");
    std::cout<<"\n\n\t\tStudent's marks updated successfully";
    Sleep(3000);
    system("cls");


}

void Student :: displayStudentResults(){
    std::cout<<"\n Enter student name: ";
    getline(std::cin,searched);
    std::cout<<"\nEnter the course and semester(COURSENAME_SEMESTER): ";
    getline(std::cin,searched_course_semester);
    system("cls");

    file.open("unitsDone.txt",std::ios :: in);
    getline(file,course_semester,'*');
    getline(file,unit1,'*');
    getline(file,unit2,'*');
    getline(file,unit3,'*');
    getline(file,unit4,'*');
    getline(file,unit5,'*');
    getline(file,unit6,'*');
    getline(file,unit7,'*');
    getline(file,unit8,'\n');

    bool courseFound = false;
    while(!file.eof()){
        if(searched_course_semester == course_semester){
            bool courseFound = true;

            file2.open("studentsData.txt", std::ios :: in);
            getline(file2,studentName,'*');
            getline(file2,admissionNumber,'*');
            getline(file2,studentClass,'*');
            getline(file2,studentAge,'*');
            getline(file2,unitMarks1,'*');
            getline(file2,unitMarks2,'*');
            getline(file2,unitMarks3,'*');
            getline(file2,unitMarks4,'*');
            getline(file2,unitMarks5,'*');
            getline(file2,unitMarks6,'*');
            getline(file2,unitMarks7,'*');
            getline(file2,unitMarks8,'\n');
            // averageMarks=(int(unitMarks1)+int(unitMarks2)+int(unitMarks3)+int(unitMarks4)+int(unitMarks5)+int(unitMarks6)+int(unitMarks7)+int(unitMarks8))/8;

            bool studentFound = false;
            while(!file2.eof()){
                if(searched == studentName){
                    std::cout<<"\n##################################################################################\n";
                    std::cout<<"Name : "<<studentName;
                    std::cout<<"\nAdmission Number : "<<admissionNumber;
                    std::cout<<"\nStudent class : "<<studentClass;
                    std::cout<<"\nStudent age : "<<studentAge;
                    std::cout<<"\n\n-------------------------Student Marks-------------------------";
                    std::cout<<"\n1."<<unit1<<" : "<<unitMarks1;
                    std::cout<<"\n2."<<unit2<<" : "<<unitMarks2;
                    std::cout<<"\n3."<<unit3<<" : "<<unitMarks3;
                    std::cout<<"\n4."<<unit4<<" : "<<unitMarks4;
                    std::cout<<"\n5."<<unit5<<" : "<<unitMarks5;
                    std::cout<<"\n6."<<unit6<<" : "<<unitMarks6;
                    std::cout<<"\n7."<<unit7<<" : "<<unitMarks7;
                    std::cout<<"\n8."<<unit8<<" : "<<unitMarks8;
                    //std::cout<<"\n\tAverage = "<<" : "<<averageMarks;
                    std::cout<<"\n\n-------------------------THANK YOU FOR USING THE PROGRAM-------------------------\n\n\n";

                    studentFound = true;
                }
                getline(file2,studentName,'*');
                getline(file2,admissionNumber,'*');
                getline(file2,studentClass,'*');
                getline(file2,studentAge,'*');
                getline(file2,unitMarks1,'*');
                getline(file2,unitMarks2,'*');
                getline(file2,unitMarks3,'*');
                getline(file2,unitMarks4,'*');
                getline(file2,unitMarks5,'*');
                getline(file2,unitMarks6,'*');
                getline(file2,unitMarks7,'*');
                getline(file2,unitMarks8,'\n');
            }
            if(studentFound == false){
                std::cout<<"\n\t\tStudent not Found!\n\n\n";
            }
            file2.close();
        }
        getline(file,course_semester,'*');
        getline(file,unit1,'*');
        getline(file,unit2,'*');
        getline(file,unit3,'*');
        getline(file,unit4,'*');
        getline(file,unit5,'*');
        getline(file,unit6,'*');
        getline(file,unit7,'*');
        getline(file,unit8,'\n');
    }
    if(!courseFound == false){
        std::cout<<"\n\n\tCourse not found!";
    }
    file.close();
}
