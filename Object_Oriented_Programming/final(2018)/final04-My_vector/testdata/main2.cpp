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

      cout << ss.size() << endl;

      for (int i = 0; i < ss.size(); i++)
      {
            cout << ss[i] << " ";
      }
      cout << endl;

      for (int i = 1; i < 1234; i+=3) {
            ss.push_back(i);
      }

      cout << ss.size() << endl;

      for (int i = 0; i < ss.size(); i++)
      {
            cout << ss[i] << " ";
      }
      cout << endl;

      for (int i = 0; i < 400; ++i) {
            ss.pop_back();
      }

      cout << ss.size() << endl;

      for (int i = 0; i < 5; ++i) {
            ss.push_back(i);
      }

      cout << ss.size() << endl;

      for (int i = 0; i < ss.size(); i++)
      {
            cout << ss[i] << " ";
      }
      cout << endl;

      ss.clear();

      for (int i = 0; i < ss.size(); i++)
      {
            cout << ss[i] << " ";
      }
      cout << endl;

      int choice;
      cin >> choice;
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