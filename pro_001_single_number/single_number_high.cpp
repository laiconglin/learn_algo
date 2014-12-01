# include <iostream>
# include <vector>
using namespace std;
int getLowestPositiveBit(int result) {
    int count = 1;
    while((result & 1) == 0) {
        //shift to right 1 bit
        result >>= 1;
        count++;
    }
    return count;
}
int isNumHasPositiveBitAtK(int num, int k) {
    num = num >> (k - 1);
    return (num & 1);
}
int getAllXorResult(int *foo, int length) {
    int result = 0;
    for(int i = 0; i < length; i++) {
        result = result ^ foo[i];
    }
    return result;
}
int main() {
    //single number is 12071.
    int foo[] = {16, -2, -77, 40, 12071, 78, -77, 16, 889, 40, -2, 78, -9};
    int result = 0;
    int length = sizeof(foo)/sizeof(int);
    result = getAllXorResult(foo, length);
    cout<<"all xor rersult:"<<result<<endl;
    int k = getLowestPositiveBit(result);
    cout<<"lowest positive bit:"<<k<<endl;
    int number_first = 0;
    for(int i = 0; i < length; i++) {
        if(isNumHasPositiveBitAtK(foo[i], k)) {
            number_first = number_first ^ foo[i];
        }
    }
    int number_second = 0;
    for(int i = 0; i < length; i++) {
        if(isNumHasPositiveBitAtK(foo[i], k) == 0) {
            number_second= number_second ^ foo[i];
        }
    }
    cout<<"first number:"<<number_first<<endl;
    cout<<"second number:"<<number_second<<endl;
    return 0;
}
