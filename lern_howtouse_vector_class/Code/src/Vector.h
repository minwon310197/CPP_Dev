#include <iostream>
#include <string>
#include <cmath>

template <class TVectorType>
class Vector {
public: 
   Vector();
   ~Vector();
   Vector(unsigned int size);
   Vector(unsigned int size, const TVectorType& initial);
   Vector(const Vector<TVectorType>& tempVector);
   Vector(Vector<TVectorType>&& tempVector);
   Vector<TVectorType>& operator = (const Vector<TVectorType>& tempVector);
   Vector<TVectorType>& operator = (Vector<TVectorType>&& tempVector);
   TVectorType& front();
   TVectorType& back();
   TVectorType& operator[](unsigned int index);
   unsigned long maxSize() const;
   unsigned int capacity() const;
   unsigned int size() const;
   bool empty() const;
   void clear();
   void pushBack( TVectorType value);
   void popBack();
   void popFront();
   void pushFront(const TVectorType value);
   void allocateNew(unsigned int maxSize);
   void resize(unsigned int size);
   void insert(const TVectorType value,int index);
   void erase(int index);

private:
   unsigned int _vectorSize;
   unsigned int _vectorCapacity;
   TVectorType* buffer;
};

template<class TVectorType>
void Vector<TVectorType>::insert(const TVectorType value,int index) {   

   while (_vectorSize >= _vectorCapacity) {
      allocateNew(_vectorCapacity + 10);
   }

   for( int i = _vectorSize; i > index; i--)
   {
      buffer[i] = buffer[i-1];
   }

   buffer[index] = value;
   _vectorSize++;
}

template<class TVectorType>
void Vector<TVectorType>::erase(int index) {

   for ( unsigned int i = index ; i < _vectorSize ; i++) {
      buffer[i] = buffer[i + 1];
   }

   _vectorSize--;
}

template<class TVectorType>
Vector<TVectorType>::Vector() {
    _vectorCapacity = 10;
    _vectorSize = 0;
    buffer = new TVectorType[10];
}

template<class TVectorType>
Vector<TVectorType>::Vector(const Vector<TVectorType>& tempVector) {
   std::cout<<"copy constructor: used"<<std::endl;

   _vectorSize = tempVector._vectorSize;
   _vectorCapacity = tempVector._vectorCapacity;
   buffer = new TVectorType[_vectorCapacity];

   for (unsigned int i = 0 ; i < _vectorSize ; i++) {
      buffer[i] = tempVector.buffer[i];
   }

}

template<class TVectorType>
Vector<TVectorType>::Vector(Vector<TVectorType>&& tempVector) {

   std::cout<<"move constructor: used"<<std::endl;
   clear();

   _vectorSize = tempVector._vectorSize;
   _vectorCapacity = tempVector._vectorCapacity;
  
   buffer = tempVector.buffer;

   tempVector._vectorCapacity = 0;
   tempVector._vectorSize = 0;
   tempVector.buffer = NULL;
}

template<class TVectorType>
Vector<TVectorType>::Vector(unsigned int size)
{
   _vectorCapacity = size;
   _vectorSize = 0;
   buffer = new TVectorType[size];
}

template<class TVectorType>
Vector<TVectorType>::Vector(unsigned int size, const TVectorType& initial) {
   _vectorSize = size;
   _vectorCapacity = 10;   

   while (_vectorSize >= _vectorCapacity) {
      _vectorCapacity += 10;
   }

   buffer = new TVectorType [_vectorCapacity];

   for (unsigned int i = 0; i < size ; i++) {
      buffer[i] = initial ;
   }

}

template<class TVectorType>
Vector<TVectorType>& Vector<TVectorType>::operator = (const Vector<TVectorType>& tempVector) {

   if (this != &tempVector) {
      std::cout<<"copy assignment: used"<<std::endl;
      delete[] buffer;

      _vectorSize = tempVector._vectorSize;
      _vectorCapacity = tempVector._vectorCapacity;
      buffer = new TVectorType [_vectorCapacity];

      for (unsigned int i = 0 ; i < _vectorSize ; i++) {
         buffer[i] = tempVector.buffer[i];
      }

   }

   return* this;
}

template<class TVectorType>
Vector<TVectorType>& Vector<TVectorType>::operator = (Vector<TVectorType>&& tempVector) {

   if (this != &tempVector) {
      std::cout<<"move assignment: used"<<std::endl;
      delete[] buffer;

      _vectorSize = tempVector._vectorSize;
      _vectorCapacity = tempVector._vectorCapacity;
      buffer = tempVector.buffer;  

      tempVector._vectorCapacity = 0;
      tempVector._vectorSize = 0;
      tempVector.buffer = NULL;
   }

   return *this;

}

template<class TVectorType>
TVectorType& Vector<TVectorType>::front() {

   if (empty() == true) {
      throw " front()-Error: Vector is empty ! ";
   }
   return buffer[0];
}

template<class TVectorType>
TVectorType& Vector<TVectorType>::back() {

   if (empty() == true) {
      throw " back()-Error: Vector is empty ! ";
   }
   return buffer[_vectorSize-1];

}

template<class TVectorType>
TVectorType& Vector<TVectorType>::operator[](unsigned int index) {

   if (index < 0 || index >= _vectorSize) {
      throw "operator[] erro: _vectorSize = 0 ! ";
   }

   return buffer[index]; 
}

template<class TVectorType>
void Vector<TVectorType>::pushBack(const TVectorType tempVector) {

   if (_vectorSize >= _vectorCapacity) {
      allocateNew(_vectorCapacity + 10);
   }

   buffer [_vectorSize++] = tempVector;
}

template<class TVectorType>
void Vector<TVectorType>::pushFront(const TVectorType tempVector) {
   _vectorSize++;

   if (_vectorSize >= _vectorCapacity) {
      allocateNew(_vectorCapacity + 10);
   }

   for ( unsigned int i = 0 ; i < _vectorSize ; i++) {
     buffer[_vectorSize - i] = buffer[(_vectorSize - i) - 1];
   }

   buffer[0]= tempVector;
}

template<class TVectorType>
void Vector<TVectorType>::popBack() {
   _vectorSize--;
}

template<class TVectorType>
void Vector<TVectorType>::popFront() {

   for ( unsigned int r = 0 ; r < _vectorSize ; r++ ) {
      buffer[r]=buffer[r + 1];
   }

   _vectorSize--;
}

template<class TVectorType>
void Vector<TVectorType>::allocateNew(unsigned int maxSize) {

   if(buffer == 0) {
      _vectorSize = 0;
      _vectorCapacity = 0;
   }

   TVectorType *Newbuffer = new TVectorType [maxSize];

   for (unsigned int i = 0; i < maxSize ; i++) {
      Newbuffer[i] = buffer[i];
   }

   _vectorCapacity = maxSize;
   delete[] buffer;
   buffer = Newbuffer;
}

template<class TVectorType>
unsigned int Vector<TVectorType>::size()const {
   return _vectorSize;
}

template<class TVectorType>
void Vector<TVectorType>::resize(unsigned int size) {
   allocateNew(size);
   _vectorSize = size;
}

template<class TVectorType>
unsigned long Vector<TVectorType>::maxSize()const {
   return (std::pow(2,64))/(sizeof(TVectorType)) -1;
}

template<class TVectorType>
unsigned int Vector<TVectorType>::capacity()const {
   return _vectorCapacity;
}

template<class TVectorType>
Vector<TVectorType>::~Vector() {
   delete[] buffer;
}

template <class TVectorType>
void Vector<TVectorType>::clear() {
   _vectorCapacity = 0;
   _vectorSize = 0;
   delete[] buffer;
}

template <class TVectorType>
bool Vector<TVectorType>::empty()const {

   if (_vectorSize == 0) {
      return true;
   }
   else {
      return false;
   }

}

