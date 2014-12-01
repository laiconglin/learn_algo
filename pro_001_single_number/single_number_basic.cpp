# include <iostream>
# include <vector>
using namespace std;
int main() {
    //single number is 12071.
    int foo[] = { 16, 2, 77, 40, 12071, 78, 77, 16, 2, 78,40};
    int result;
    int length = sizeof(foo)/sizeof(int);
    for(int i = 0; i < length; i++) {
        result = result ^ foo[i];
    }
    cout<<result<<endl;
    return 0;
}
