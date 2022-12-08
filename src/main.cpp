#include "Zi.h"
#include "Vector.h"
#include <iostream>

int main()
{
    /*
    auto v1 = Zi(4, 5);

    v1 = v1 * -2;

    std::cout << v1;
    */

    auto z1 = Zi(4, 5);
    auto v1 = Vector(4, z1);

    auto v3 = v1*-3;

    std::cout << v1 << "v3: " << v3;
    
}
