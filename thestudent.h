//
// Created by 29349 on 2024/11/29.
//

/*
 *实现学生成绩表的结构体：
 *有关操作（1）：插入学生信息，修改学生信息，删除学生信息
 *有关操作（2）：学生信息的IO（输入和输出）
 *有关操作（3）：学生列表的排序，分析平均值，分析最大最小值
 *有关操作（4）：按照特定的姓名，ID，成绩进行查询
*/
#ifndef THESTUDENT_H
#define THESTUDENT_H
#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>
#include <string>
using namespace std;

//定义student结构体
struct student
{
    long long studentnum=0;
    string name;
    int grade1=100;
    int grade2=100;
    int grade3=100;
};




inline void printthestudent(const student& student);
inline student getstudent(bool flag,student& current);


void modify(vector<student>&students, const student &current);
void append(vector<student>&students, const student &current);
void erase(vector<student>&students,long long target);

void sortbyID(vector<student>& students);
void sortbyname(vector<student>& students);
void sortbytime(vector<student>& students);
void sortbygrade(vector<student>& students);
void analysethegrade(vector<student>& students);

bool comparebyid(const student& a,const student& b);
bool comparebygrades(const student& a,const student& b);
bool comparebyname(const student& a,const student& b);

void searchbyname(vector<student>& students,string name);
void searchbygrade1(vector<student>& students,int grade1);
void searchbygrade2(vector<student>& students,int grade2);
void searchbygrade3(vector<student>& students,int grade3);
void searchbytotalgrade(vector<student>& students,int grade4);
void searchbyID(vector<student>& students,long long ID);


void printthemenu() {
    cout<<"This is a student grade inquiry and analysis table. "
          "In the table, each student has a name, ID, and their scores for three subjects. "
          "You can perform the following operations:"<<endl;
    cout<<"____________________________________________________________________________________"<<endl;

    cout<<"To add student information, press 1."<<endl;
    cout<<"To modify student information, press 2."<<endl;
    cout<<"To delete student information, press 3."<<endl;
    cout<<"To output the list by time, press 4."<<endl;
    cout<<"To output the list in ascending order by ID, press 5."<<endl;
    cout<<"To output the list by scores, press 6."<<endl;
    cout<<"To analyze grades, press 7."<<endl;
    cout<<"To search by specific name, ID, or scores, press 8,9,10,11,12,13."<<endl;
    cout<<"To exit, press 0."<<endl;
    cout<<"Thank you!"<<endl;
    cout<<"____________________________________________________________________________________"<<endl;
    cout<<endl<<endl<<endl;
    cout<<"Please enter the operations:"<<endl;
}



//操作（1）的函数定义
//插入学生信息，默认按照插入的时间顺序排列
void append(vector<student>&students, const student &current){
    if(!students.empty()){
        for (const auto & student : students) {
            if (student.studentnum==current.studentnum) {
                cout<<"That student has been appended previously.Do you want to modify it?(y/n)"<<endl;
                printthestudent(student);
                char ch;cin>>ch;
                assert(ch!='y'&&ch!='n');
                if(ch=='y') {
                    modify(students, current);
                }
                break;
            }
        }
    }
    students.push_back(current);
    cout<<"successfully appended"<<endl;
}

//修改学生信息
void modify(vector<student>&students, const student &current){
    bool successful=false;
    if(!students.empty()){
        for (auto & student : students) {
            if (student.studentnum==current.studentnum) {
                cout<<"successful modified!"<<endl;
                cout<<"Before modified:"<<endl;
                printthestudent(student);
                cout<<"After modified:"<<endl;
                printthestudent(current);
                student=current;
                successful=true;
                break;
            }
        }
    }
    if(!successful) {
        cout<<"No such student"<<endl;
    }
}

//删除学生信息
void erase(vector<student>&students,long long target){
    bool successful=false;
    if(!students.empty()){
        for (int i=0;i<students.size();i++) {
            if (students[i].studentnum==target) {
                students.erase(students.begin()+i);
                cout<<"Successfully erased:"<<endl;
                printthestudent(students[i]);
                successful=true;
                break;
            }
        }
    }
    if(!successful) {
        cout<<"No such student"<<endl;
    }
}


//操作（2）的函数定义
//学生信息的输入
inline student getstudent(bool flag,student& current) {

    if (flag) {
        cout<<"studentnum:";
        cin>>current.studentnum;
    }
    cout<<"grades:";
    cin>>current.grade1;
    cin>>current.grade2;
    cin>>current.grade3;
    cin.ignore();
    cout<<"name:";
    getline(cin,current.name);
    return current;
}

//学生信息的输出
inline void printthestudent(const student& student) {
    cout<<"____________________________________________________________________________________"<<endl;
    cout<<"The ID number: "<<student.studentnum<<endl;
    cout<<"The name of student: "<<student.name<<endl;
    cout<<"The grade: "<<student.grade1<<" "<<student.grade2<<" "<<student.grade3<<endl;
    cout<<"The sum of the grades: "<<student.grade1+student.grade2+student.grade3<<endl;
    cout<<"____________________________________________________________________________________"<<endl;
}

//操作（3）的函数定义

inline bool comparebyid(const student& a,const student& b){
    //按学号升序排序
    return a.studentnum<b.studentnum;
}

inline bool comparebygrades(const student& a,const student& b){
    //按总分降序排序
    int totala=a.grade1+a.grade2+a.grade3;
    int totalb=b.grade1+b.grade2+b.grade3;
    if(totala!=totalb){
        return totala>totalb;
    }
    return a.studentnum<b.studentnum;
}

inline bool comparebyname(const student& a,const student& b) {
    //按照名字的字典序进行排列
    return a.name<b.name;
}


void sortbyID(vector<student>& students) {
    //按照学号升序排序
    if(!students.empty()){
        cout<<"The students are sorted by ID:"<<endl;
        vector<student> theoutcopy(students);
        sort(theoutcopy.begin(),theoutcopy.end(),comparebyid);
        for (const auto & student : theoutcopy) {
            printthestudent(student);
        }
    }else {
        cout<<"Please append some students"<<endl;
    }
    cout<<"Student numbers: "<<students.size()<<endl;
}

void sortbytime(vector<student>& students) {
    //按照插入时间进行排序
    if(!students.empty()){
        cout<<"The students are sorted by appended time:"<<endl;
        vector<student> theoutcopy(students);
        for (const auto & student : theoutcopy) {
            printthestudent(student);
        }
    }else {
        cout<<"Please append some students"<<endl;
    }
    cout<<"Student numbers: "<<students.size()<<endl;
}

void sortbyname(vector<student>& students) {
    //按照插入名字的字典序进行排列
    if(!students.empty()){
        cout<<"The students are sorted by name:"<<endl;
        vector<student> theoutcopy(students);
        sort(theoutcopy.begin(),theoutcopy.end(),comparebyname);
        for (const auto & student : theoutcopy) {
            printthestudent(student);
        }
    }else {
        cout<<"Please append some students"<<endl;
    }
    cout<<"Student numbers: "<<students.size()<<endl;
}

void sortbygrade(vector<student>& students) {
    if(!students.empty()){
        cout<<"The students are sorted by total grades:"<<endl;
        vector<student> theoutcopy(students);
        sort(theoutcopy.begin(),theoutcopy.end(),comparebygrades);
        for (const auto & student : theoutcopy) {
            printthestudent(student);
        }
    }else {
        cout<<"Please append some students"<<endl;
    }
    cout<<"Student numbers: "<<students.size()<<endl;
}

void analysethegrade(vector<student>& students) {
    vector<vector<int>> thegradescount(students.size(),vector<int>(4));
    vector<int> maxgrade={0,0,0,0};
    vector<int> mingrade={100,100,100,300};
    vector<int> sumgrade={0,0,0,0};
    vector<double> averagegrade(4);

    for (int i=0;i<students.size();i++) {
        thegradescount[i][0]=students[i].grade1;
        thegradescount[i][1]=students[i].grade2;
        thegradescount[i][2]=students[i].grade3;
        thegradescount[i][3]=students[i].grade1+students[i].grade2+students[i].grade3;
        for (int j=0;j<4;j++) {
            if (maxgrade[j]<thegradescount[i][j]) {
                maxgrade[j]=thegradescount[i][j];
            }
            if (mingrade[j]>thegradescount[i][j]) {
                mingrade[j]=thegradescount[i][j];
            }
            sumgrade[j]+=thegradescount[i][j];
        }
    }
    cout<<"average max min"<<endl;
    for (int j=0;j<4;j++) {
        averagegrade[j]=double(sumgrade[j])/3;
        cout<<averagegrade[j]<<" "<<maxgrade[j]<<" "<<mingrade[j]<<endl;
    }

}

void searchbyname(vector<student>& students,string name) {
    bool found=false;
    if(!students.empty()){
        for (auto & student : students) {
            if (student.name==name) {
                printthestudent(student);
                found=true;
            }
        }
    }
    if (!found) {
        cout<<"404 Not found"<<endl;
    }
}

void searchbygrade1(vector<student>& students,int grade1) {
    bool found=false;
    if(!students.empty()){
        for (auto & student : students) {
            if (student.grade1==grade1) {
                printthestudent(student);
                found=true;
            }
        }
    }
    if (!found) {
        cout<<"404 Not found"<<endl;
    }
}

void searchbygrade2(vector<student>& students,int grade2) {
    bool found=false;
    if(!students.empty()) {
        for (auto & student : students) {
            if (student.grade2==grade2) {
                printthestudent(student);
                found=true;
            }
        }
    }
    if (!found) {
        cout<<"404 Not found"<<endl;
    }
}


void searchbygrade3(vector<student>& students,int grade3) {
    bool found=false;
    if(!students.empty()) {
        for (auto & student : students) {
            if (student.grade3==grade3) {
                printthestudent(student);
                found=true;
            }
        }
    }
    if (!found) {
        cout<<"404 Not found"<<endl;
    }
}

void searchbytotalgrade(vector<student>& students,int grade4) {
    bool found=false;
    if(!students.empty()) {
        for (auto & student : students) {
            if (student.grade1+student.grade2+student.grade3==grade4) {
                printthestudent(student);
                found=true;
            }
        }
    }
    if (!found) {
        cout<<"404 Not found"<<endl;
    }
}

void searchbyID(vector<student>& students,long long ID) {
    bool found=false;
    if(!students.empty()) {
        for (auto & student : students) {
            if (student.studentnum==ID) {
                printthestudent(student);
                found=true;
            }
        }
    }
    if (!found) {
        cout<<"404 Not found"<<endl;
    }
}


#endif //THESTUDENT_H
