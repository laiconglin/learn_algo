# include <iostream>
# include <math.h>
using namespace std;
int main() {
    /**
     * (1 + 2 + 3 + ..... + N) = y
     *
     * N(N + 1)/2 = y
     *
     * N^2 + N - 2y = 0
     *
     */
    int y;
    cin>>y;
    
    double root = (sqrt(8*y + 1) - 1.0 ) / 2.0;
    int rootCeil = (int) root;
    int nearY = rootCeil * (rootCeil + 1) / 2;
    int diff = y - nearY;
    int resultNumerator = 0;
    int resultDenominator = 1;
    if(rootCeil % 2 == 0) {
        if(diff == 0) {
            resultNumerator = rootCeil;
            resultDenominator = 1;
        } else if(diff >= 1){
            resultNumerator = rootCeil + 1 + 1 - diff;
            resultDenominator = diff;
        }
    } else {
        if(diff == 0) {
            resultNumerator = 1;
            resultDenominator = rootCeil;
        } else if(diff >= 1){
            resultNumerator = diff;
            resultDenominator = rootCeil + 1 + 1 - diff;
        }
    }
    cout<<resultNumerator<<"/"<<resultDenominator<<endl;
    return 0;
}
