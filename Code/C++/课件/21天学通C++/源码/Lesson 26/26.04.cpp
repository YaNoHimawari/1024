// LISTING 26.4 - Using the std::auto_ptr
#include <memory>
void UsePointer (std::auto_ptr <CSomeClass> spObj);

int main ()
{
    using namespace std;
    cout << "main() started" << endl;

    auto_ptr <CSomeClass> spObject (new CSomeClass ());

    cout << "main: Calling UsePointer()" << endl;

    // Call a function, transfer ownership
    UsePointer (spObject);

    cout << "main: UsePointer() returned, back in main()" << endl;

    // spObject->SaySomthing (); // invalid pointer!

    cout << "main() ends" << endl;

    return 0;
}

void UsePointer (auto_ptr <CSomeClass> spObj)
{
    cout << "UsePointer: started, will use input pointer now" << endl;

    // Use the input pointer
    spObj->SaySomething ();

    cout << "UsePointer: will return now" << endl;
}