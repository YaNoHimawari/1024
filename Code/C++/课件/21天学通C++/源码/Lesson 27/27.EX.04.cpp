#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char**argv) // returns 1 on error
{
    if (argc != 2)
    {
        cout << "Usage: argv[0] <infile>\n";
        return(1);
    }
    // open the input stream
    ifstream fin (argv[1],ios::binary);
    if (!fin)
    {
        cout << "Unable to open " << argv[1] <<" for reading.\n";
        return(1);
    }
    char ch;
    while ( fin.get(ch))
        if ((ch > 32 && ch < 127) || ch == '\n'|| ch == '\t')
            cout << ch;
    fin.close();
}