//Listing 17.20 Using Command-line Arguments
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
  
     long GetDaysAlive()const { return  DaysAlive; }
     void SetDaysAlive(long days) { DaysAlive = days; }
  
  private:
     int itsWeight;
     long DaysAlive;
};
  
int main(int argc, char *argv[])   // returns 1 on error
{
   if (argc != 2)
   {
      cout << "Usage: " << argv[0] << " <filename>" << endl;
      return(1);
   }
  
   ofstream fout(argv[1],ios::binary);
   if (!fout)
   {
      cout << "Unable to open " << argv[1] << " for writing.\n";
      return(1);
   }
  
   Animal Bear(50,100);
   fout.write((char*) &Bear,sizeof Bear);
  
   fout.close();
   
   ifstream fin(argv[1],ios::binary);
   if (!fin)
   {
      cout << "Unable to open " << argv[1] << " for reading.\n";
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
