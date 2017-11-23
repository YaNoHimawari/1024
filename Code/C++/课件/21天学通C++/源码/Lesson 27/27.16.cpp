//Listing 17.16 Opening Files for Read and Write
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
   char fileName[80];
   char buffer[255];    // for user input
   cout << "File name: ";
   cin >> fileName;

   ofstream fout(fileName);  // open for writing
   fout << "This line written directly to the file...\n";
   cout << "Enter text for the file: ";
   cin.ignore(1,'\n');  // eat the newline after the file name
   cin.getline(buffer,255);  // get the user's input
   fout << buffer << "\n";   // and write it to the file
   fout.close();             // close the file, ready for reopen

   ifstream fin(fileName);    // reopen for reading
   cout << "Here's the contents of the file:\n";
   char ch;
   while (fin.get(ch))
      cout << ch;

   cout << "\n***End of file contents.***\n";

   fin.close();            // always pays to be tidy
   return 0;
}
