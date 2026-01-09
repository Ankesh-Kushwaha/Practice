#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Encapsulation says 2 things:
1. An Object's Characteristics and its behaviour are encapsulated together
within that Object.
2. All the characteristics or behaviours are not for everyone to access.
Object should provide data security.

We follow above 2 pointers about Object of real world in programming by:
1. Creating a class that act as a blueprint for Object creation. Class contain
all the characteristics (class variable) and behaviour (class methods) in one block,
encapsulating it together.
2. We introduce access modifiers (public, private, protected) etc to provide data
security to the class members.
*/

class SportsCar{
   private:
     string brand;
     string model;
     int currSpeed;
     int currGear;
     int price;
     string tyreCompany;
     bool isEngineOn;

   public:
     SportsCar(const string &brand, const string &model, const int &price)
     {
       this->model = model;
       this->brand = brand;
       currSpeed = 0;
       currGear = 0;
       this->price = price;
       isEngineOn = false;
       tyreCompany = "";
     }
     
    //setter function 
    void SetTyreCompany(const string &tyreCompany){
      this->tyreCompany = tyreCompany;
    }

    void SetPrice(int newPrice){
      this->price = newPrice;
    }

    //getter function
    string getTyreCompany(){
      return tyreCompany;
    }
    
    int getPrice(){
      return price;
    }

    void startCar(){
        if(isEngineOn){
          cout << "engine is already started";
          return;
        }
        isEngineOn = true;
        cout << "Engine started successfullly........." << endl;
    }

    void accerelate(){
         if(!isEngineOn){
           cout << "Engine is Off" << endl;
           return;
         }
         currSpeed+=20;
         cout << "car is accerelated with 20km/hr" << endl;
    }

   void shiftGear(int gear){
       if(!isEngineOn){
         cout << "Engine is Off." << endl;
         return;
       }

       currGear += gear;
       cout << "gear is shifted successfully";
   }

   void applyBreak(){
     currSpeed = max(0, currSpeed -= 20);
     cout << "Car is slowing down by -20km/hr" << endl;
   }

   void StopCar(){
       if(!isEngineOn){
         cout << "Car is already stopped" << endl;
       }
       else{
         isEngineOn = false;
         currSpeed = 0;
         cout << "Car stopped successfully" << endl;
       }
   }

   //destructor
   ~SportsCar() {};
};
int main(){
  SportsCar *car1 = new SportsCar("Ford", "Mustang", 1000000);
  car1->startCar();
  car1->shiftGear(1);
  car1->accerelate();
  car1->accerelate();
  car1->shiftGear(2);
  car1->shiftGear(3);
  car1->applyBreak();
  car1->StopCar();

  car1->SetTyreCompany("Nylon");
  cout << car1->getTyreCompany() << endl;
  cout << car1->getPrice() << endl;
  car1->~SportsCar();
  return 0;
}