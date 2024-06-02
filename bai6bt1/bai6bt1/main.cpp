#include "SapXep.h"

int main()
{
    SapXep sapXep;
    sapXep.readFromFile("input.txt");
    sapXep.selectionSort();
    sapXep.printData();
    return 0;
}
