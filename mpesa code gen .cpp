#include<iostream>
#include<ctime>
#include<cstdlib>
#include<string>
#include<unordered_set>//for storing the transaction codes and checking for uniqueness For large data stores consider creating a database
 using namespace std;

 class MpesaCode{
    private:
    //create a set for uniqueness checking 
    unordered_set<string>sets;
    public:
    //intilise the class by seeding with time on declaration
     MpesaCode(){srand(time(0));};
     string CodeGenerator (){
         //strings in which the code is generated from
         string Kawaii = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
         string TransactionCode = "";
         do{
            for(int x=0; x<10; x++){
              //pick a string at random limited to 10 strings
                TransactionCode += Kawaii[rand()%36];
            }
           //check for uniqueness
         }while(sets.find(TransactionCode) != sets.end());
             //insert only if no similar transaction resembles it 
        sets.insert(TransactionCode);
        return TransactionCode;
    }
 };

 int main(){
    MpesaCode obj;
   cout<< obj.CodeGenerator();
