#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    char firstname[] = "Alfred";
    char middlename[] = "E";
    char lastname[] = "Numan";
    char fullname[80];
    int offset = 0;
    strcpy(fullname,firstname);
    offset = strlen(firstname);
    strcpy(fullname+offset," ");
    offset += 1;
    strcpy(fullname+offset,middlename);
    offset += strlen(middlename);
    strcpy(fullname+offset,". ");
    offset += 2;
    strcpy(fullname+offset,lastname);
    cout << firstname << "-" << middlename << "-"
        << lastname << endl;
    cout << "Fullname: " << fullname << endl;
    return 0;
}