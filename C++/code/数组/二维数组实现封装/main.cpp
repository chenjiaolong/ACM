#include <iostream>
#include "myArray.h"

using namespace std;

int main()
{
   myArray my{{1, 2, 3, 4, 5}, {6, 7, 8}, {1, 2, 3, 4}};
   my.show();
   return 0;
}
