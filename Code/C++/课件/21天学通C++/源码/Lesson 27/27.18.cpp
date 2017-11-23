//Listing 17.18 Writing a Class to a File
#include <fstream>
#include <iostream>
using namespace std;
  
class Animal
{
  public:
     Animal(int weight,long days):itsWeight(weight),DaysAlive(days){}
     ~Animal(){}
  
     int GetWeight()const { return itsWeight; }
     void SetWeight(int weight) { itsWeight = weight; }
  
     long GetDaysAlive()const { return DaysAlive; }
     void SetDaysAlive(long days) { DaysAlive = days; }
 
  private:
     int itsWeight;
     long DaysAlive;
};
  
int main()   // returns 1 on error
{
   char fileName[80];
  
  
   cout << "Please enter the file name: ";
   cin >> fileName;
   ofstream fout(fileName,ios::binary);
   if (!fout)
   {
      cout << "Unable to open " << fileName << " for writing.\n";
      return(1);
   }
  
   Animal Bear(50,100);
   fout.write((char*) &Bear,sizeof Bear);
  
   fout.close();
  
   ifstream fin(fileName,ios::binary);
   if (!fin)
   {
      cout << "Unable to open " << fileName << " for reading.\n";
      return(1);
   }
  
   Animal BearTwo(1,1);
  
   cout << "BearTwo weight: " << BearTwo.GetWeight() << endl;
   cout << "BearTwo days: " << BearTwo.GetDaysAlive() << endl;
  
   fin.read((char*) &BearTwo, sizeof BearTwo);
  
   cout << "BearTwo weight: " << BearTwo.GetWeight() << endl;
   cout << "BearTwo days: " << BearTwo.GetDaysAlive() << endl;
   fin.close();
   return 0;
}
