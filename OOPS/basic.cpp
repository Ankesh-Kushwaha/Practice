#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//class creation
class Employee{
   private:
     string name;
     int salary;

   public:
   Employee(string name,int salary){
     this->name = name;
     this->salary = salary;
   }

   //getter function
   string getName() {return this->name;}
   int getSalary(){ return this->salary;}

   //setter function
   void setName(string &name){
     this->name = name;
   }

   void setSalary(int salary){
     this->salary = salary;
   }
   
   void displayDetail(){
     cout << "Name: " << name << endl;
     cout << "Salary: " << salary << endl;
   }

};

int main(){
  // Employee *emp = new Employee("Ankesh", 50000);
  // cout<<emp->getName()<<endl;
  // cout << emp->getSalary() << endl;
  Employee emp("Ankesh", 500000);
  cout << emp.getName() << endl;
  cout << emp.getSalary() << endl;
  return 0;
}