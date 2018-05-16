
class MyVector{
public:
   // todo: using vType = int;
   MyVector(int size, int init);
   MyVector(MyVector& init);
   ~MyVector();
   MyVector& operator=(const MyVector& v);
   void print();
   
   int& operator[](int x); // todo: size_t
   
   friend bool operator==(const MyVector& v1, const MyVector& v2);
   
private:
   int size;
   int p [];
};


