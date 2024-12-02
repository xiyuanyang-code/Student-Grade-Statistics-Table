/*
 * @Author: Xiyuan Yang   xiyuan_yang@outlook.com
 * @Date: 2024-11-28 20:35:19
 * @LastEditors: Xiyuan Yang   xiyuan_yang@outlook.com
 * @LastEditTime: 2024-11-28 23:22:07
 * @FilePath: \CODE_for_Vscode\C++_project\thegradelist.cpp
 * @Description:
 * Do you code and make progress today?
 * Copyright (c) 2024 by Xiyuan Yang, All Rights Reserved.
 */
#include <iostream>

#include "thestudent.h"
using namespace std;

/*
*void printthemenu() {
    cout<<"This is a student grade inquiry and analysis table. "
        "In the table, each student has a name, ID, and their scores for three subjects. "
        "You can perform the following operations:"<<endl;
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
    cout<<"Please enter the operations:"<<endl;
}
 */

int main(){
    vector<student> students;
    cout<<"Hello!"<<endl;
    int operate;
    while (true) {
        printthemenu();
        cin>>operate;
        assert(operate>=0&&operate<=13);


        long long target=0;
        string name;
        int grade;
        student current;


        if (!operate) {
            cout<<"Exit Successfully!"<<endl;
            break;
        }


        switch (operate) {
            case 1:
                append(students,getstudent(true,current));
                break;
            case 2:
                modify(students,getstudent(true,current));
            break;
            case 3:
                cin>>target;
                erase(students,target);
            break;
            case 4:
                sortbytime(students);break;
            case 5:
                sortbyID(students);break;
            case 6:
                sortbygrade(students);break;
            case 7:
                analysethegrade(students);break;
            case 8:
                getline(cin,name);
                searchbyname(students,name);break;
            case 9:
                cin>>target;
                searchbyID(students,target);break;
            case 10:
                cin>>grade;
                searchbygrade1(students,grade);break;
            case 11:
                cin>>grade;
                searchbygrade2(students,grade);break;
            case 12:
                cin>>grade;
                searchbygrade3(students,grade);break;
            case 13:
                cin>>grade;
                searchbytotalgrade(students,grade);break;
            default:
                cout<<"Wrong Choice!"<<endl;
        }
    }
    return 0;
}
