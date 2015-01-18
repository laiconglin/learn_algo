# include <iostream>
class A {
};
class A1 {
    public:
        A1();
        ~A1();
};
class A2 {
    public:
        A2();
        virtual ~A2();
        virtual void test() {
        }
};

class B {
    private:
        int val;
};
class B1 {
    private:
        long val;
};
using namespace std;
int main() {
    cout<<"A size:"<<sizeof(A)<<endl;
    cout<<"A1 size:"<<sizeof(A1)<<endl;
    cout<<"A2 size:"<<sizeof(A2)<<endl;
    cout<<"B size:"<<sizeof(B)<<endl;
    cout<<"B1 size:"<<sizeof(B1)<<endl;
    return 0;
}
