#include <iostream>
#include <string>
#include "src/Vector.h"
using namespace std;

template<class TVectorType>
void testPushBackPushFront(Vector<TVectorType>& vector) {
   TVectorType arr[]={1,2,3,4,5};
   cout<<"{1,2,3,4,5}"<<endl;
   cout<<endl<<"pushFront/back process: "<<endl;

   for (int i = 0; i < 5 ; i++) {
      vector.pushFront(arr[i]);
      vector.pushBack(arr[i]);
   }

   output(vector);
   cout<<"front(): "<<vector.front()<<endl ;
   cout<<"back(): "<<vector.back()<<endl ;
   cout<<"capacity(): "<<vector.capacity()<<endl ;
   cout<<"vectorSize: "<<vector.size()<<endl ;
}

template<class TVectorType>
void testInsertErase(Vector<TVectorType> &vector) {
   cout<<endl<<"insert/erase process: "<< endl;

   cout<<" insert value : 4 into position : 5 "<<endl;
   vector.insert(4,5);
   output(vector);

   cout << " erase value from position : 5 " << endl;
   vector.erase(5);

   output(vector);
   cout<<"front(): "<<vector.front()<<endl;
   cout<<"back(): "<<vector.back()<<endl;
   cout<<"capacity(): "<<vector.capacity()<<endl;
   cout<<"vectorSize(): "<<vector.size()<<endl;
}

template<class TVectorType>
void testPopBackPopFront(Vector<TVectorType>& vector) {
   cout<<endl<<"popBack/popFront process: "<<endl;

   cout<<"popBack() , popFront() called: "<<endl;
   vector.popBack();
   vector.popFront();

   output(vector);
   cout<<"front(): "<<vector.front()<<endl ;
   cout<<"back(): "<<vector.back()<<endl ;
   cout<<"capacity() "<<vector.capacity()<<endl ;
   cout<<"vectorSize: "<< vector.size()<<endl ;
}

template<class TVectorType>
void testEmptyClear(Vector<TVectorType> &vector) {
   cout<<endl<<"empty() function process: "<<endl;

   cout<<vector.empty()<<endl;
   cout<<"clear() function called ! "<<endl;
   vector.clear();
   cout<<vector.empty()<<endl;
}

template<class TVectorType>
void output(Vector<TVectorType> &vector) {

   for(unsigned int j = 0; j < vector.size() ; j++) {
      cout <<vector[j] << "   ";
   }

   cout<<endl;
}

template<class TVectorType>
void testFrontBackIndexCondition(Vector<TVectorType> &vector) {
   
   try {
      cout<<"1. test index-[] condition "<<"vector[5]: "<<endl;
      output(vector);
      cout<<"value[5] : "<<vector[5]<<endl;
   }
   catch (const char* message) {
      cerr<<message<<endl;
   }

   try {
      cout<<"1.1 test index-[] condition "<<"vector[5]: "<<endl;
      output(vector);
      cout<<"clear() function called !"<<endl;
      vector.clear();
      cout<<vector[5]<<endl;
   }
   catch (const char* message) {
      cerr<<message<<endl;
   }

   try {
      cout<<endl<<"2. test front(),back() condition "<<endl;
      testPushBackPushFront(vector);
      cout<<"clear() function called ! "<<endl;
      vector.clear();
      output(vector);
      cout<<"vector.front(): "<<vector.front()<<endl;
   }
   catch (const char* message) {
      cerr<<message<<endl;
   }

   try {
      cout<<"vector.back(): "<<vector.back()<<endl;
   }
   catch (const char* message) {
      cerr<<message<<endl;
   }

}

int main() {
   Vector<int> vector(23,6);
   Vector<int> vector1,vector2,vector3;
   Vector<int> vector4(vector3);
   Vector<int> vector5=move(vector3);
   vector4 = vector3;
   cout<<"vector maxsize(): "<<vector.maxSize()<<endl;   
   cout<<endl<<"vector1={}"<<endl;
   testPushBackPushFront(vector1);
   cout<<endl<<"vector1 empty() checking: ";
   cout<<vector1.empty()<<" -----------"<<endl;
   cout<<"move assignment: vector1 -> vector2"<<endl;
   vector2 = move(vector1);
   cout<< "vector1 empty() checking: ";
   cout<<vector1.empty()<<" -----------"<<endl;

   cout<<endl<<"vector2: ";
   testPopBackPopFront(vector2);
   testInsertErase(vector2);
   testEmptyClear(vector2);

   cout<<endl<<"Test: Front(),Back(),Index() condition"<<endl;
   testFrontBackIndexCondition(vector);

   return 0 ;
 }

