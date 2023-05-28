#include <iostream>
#include <iterator>
#include <ostream>
#include "Point.hpp"

int main( void ) {
    Point    a(2, 2);
    Point    b(0, 0);
    Point    c(0, 1);
    Point    in(0.2, 0.1);
    Point    out(1.12, 1.94);
    Point    edge(5.09, 0);

    std::cout << "param : " << std::endl;
    std::cout << "  a(" << a.getPointX().toInt() << ";" << a.getPointY().toInt() << ")" << std::endl;
    std::cout << "  b(" << b.getPointX().toInt() << ";" << b.getPointY().toInt() << ")" << std::endl;
    std::cout << "  c(" << c.getPointX().toInt() << ";" << c.getPointY().toInt() << ")\n" << std::endl;
    std::cout << "  in(" << in.getPointX().toInt() << ";" << in.getPointY().toInt() << ")" << std::endl;
    std::cout << "  out(" << out.getPointX().toInt() << ";" << out.getPointY().toInt() << ")" << std::endl;
    std::cout << "  edge(" << edge.getPointX().toInt() << ";" << edge.getPointY().toInt() << ")" << std::endl;
    if (bsp(a, b, c, in))
        std::cout << "in is inside the triangle" << std::endl;
    else
        std::cout << "in is outside the triangle" << std::endl;
    if (bsp(a, b, c, out))
        std::cout << "out is inside the triangle" << std::endl;
    else
        std::cout << "out is outside the triangle" << std::endl;
    if (bsp(a, b, c, edge))
        std::cout << "edge is inside the triangle" << std::endl;
    else
        std::cout << "edge is outside the triangle" << std::endl;
    return 0;
}
