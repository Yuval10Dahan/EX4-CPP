#include "Character.hpp"
#include "Team.hpp"
#include "Point.hpp"
#include <string>
#include <vector>

using namespace std;


// test
int main()
{
    cout << "#############################################################" << endl;

    // vector<int> vec(10);

    cout << "#############################################################" << endl;
    
    Point a(6,2);
    // a.print();

    cout << "#############################################################" << endl;

    Cowboy *c = new Cowboy("yuval", a);
    cout << c->print() << endl;
}