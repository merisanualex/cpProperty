# include <iostream>
# include <string>

# include "Property.hpp"

class Test
{
    int _var                = 1;
    double _anothervar      = 10;
    std::string _stringvar  = "what";
    std::string _stringvar2 = "test";

public:
    
    rwProperty<int> var                = _var; 
    roProperty<double> anothervar      = _anothervar;
    roProperty<std::string> stringvar  = _stringvar;
    rwProperty<std::string> stringvar2 = _stringvar2;
};

int main()
{
    using std::cout;

    Test test;
    cout<< "Initial values:\n";
    cout<< "var        = "<< test.var       <<"\n";
    cout<< "anothervar = "<< test.anothervar<<"\n";
    cout<< "strinvar   = "<< test.stringvar <<"\n";
    cout<< "stringvar2 = "<< test.stringvar2<<"\n";

    test.var += 5;

    // Compile errors (read only properties)
    // test.anothervar = 42;
    // test.strinvar = "value";

    test.stringvar2 = "value";

    cout<< "\nNew values:\n";
    cout<< "var        = "<< test.var       <<"\n";
    cout<< "anothervar = "<< test.anothervar<<"\n";
    cout<< "strinvar   = "<< test.stringvar <<"\n";
    cout<< "stringvar2 = "<< test.stringvar2<<"\n";
}
