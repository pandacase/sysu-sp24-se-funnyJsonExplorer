#include <iostream>
#include <string>

#include "../include/buffer.hh"

using namespace std;


int main() {
    StringBuffer sb;
    sb.addOneLine();

    sb.write(0, 0, 'a');
    sb.write(1, 3, "abc");

    sb.print();
}