/*

* C++ Program to Implement MyVector

*/
#include <iostream>
#include <string>
#include <cstdlib>
#include "MyVector.h"

using namespace std;

#ifndef _VECTOR_
#ifndef _ARRAY_
#ifndef _DEQUE_
#ifndef _FORWARD_LIST_
#ifndef _LIST_
#ifndef _STACK_
#ifndef _SET_
#ifndef _MAP_

int main()
{
      MyVector<int> ss;
      int choice, item;

      cout << "\n---------------------" << endl;
      cout << "MyVector Implementation" << endl;
      cout << "\n---------------------" << endl;
      cout << "1.Insert Element into the MyVector" << endl;
      cout << "2.Delete Last Element of the MyVector" << endl;
      cout << "3.Size of the MyVector" << endl;
      cout << "4.Display by Index" << endl;
      cout << "5.Clear the MyVector" << endl;
      cout << "6.Exit" << endl;

      while (1)
      {
            cout << "Enter your Choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                  cout << "Enter value to be inserted: ";
                  cin >> item;
                  ss.push_back(item);
                  break;

            case 2:
                  cout << "Delete Last Element Inserted" << endl;
                  ss.pop_back();
                  break;

            case 3:
                  cout << "Size of Vector: ";
                  cout << ss.size() << endl;
                  break;

            case 4:
                  cout << "Displaying Vector by Index: ";
                  for (int i = 0; i < ss.size(); i++)
                  {
                        cout << ss[i] << " ";
                  }
                  cout << endl;
                  break;

            case 5:
                  ss.clear();
                  cout << "Vector Cleared" << endl;
                  break;

            case 6:
                  exit(1);
                  break;

            default:
                  cout << "Wrong Choice" << endl;
            }
      }
      return 0;
}

#endif // !_MAP_
#endif // !_SET_
#endif // !_STACK_
#endif // !_LIST_
#endif // !_FORWARD_LIST_
#endif // !_DEQUE_
#endif // !_ARRAY_
#endif // !_VECTOR_