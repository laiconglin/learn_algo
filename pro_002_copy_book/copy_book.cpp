#include <stdio.h> 
#include <iostream>
using namespace std;
#define MAX 10001  
int startIndex[MAX], endIndex[MAX];
int check(int *p, int bookNum, int k, int middle) {
    int sum = 0;
    int needAssignBookNum = bookNum;
    for(int i = k - 1; i >= 0; i--) {
        sum = 0;
        while((sum + p[needAssignBookNum - 1]) <= middle && needAssignBookNum > 0) {
            sum += p[needAssignBookNum - 1];
            needAssignBookNum--;
        }
        if(needAssignBookNum == 0) {
            return 1;
        }
    }
    return false;
}
int solution(int *p, int bookNum, int k) {
    int total = 0;
    for(int i = 0; i < bookNum; i++) {
        total += p[i];
    }
    int left = 0, right = total;
    int middle  = 0;
    while(left < right) {
        middle = (left + right) / 2;
        //cout<<"left:"<<left<<", middle:"<<middle<<",right:"<<right<<endl;
        if(check(p, bookNum, k, middle)) {
            right = middle;
        } else {
            left = middle + 1;
        }
    }
    return left;
}
int main() {
    //freopen("input.txt","r",stdin); 
    int m, k;
    cin>>m>>k;
    int *p = new int[m];
    int tmp;
    for(int i = 0; i < m; i++) {
        cin>>tmp;
        p[i] = tmp;
    }
    if(k > 0 && m > 0) {
        int minCopyTime = solution(p, m, k);
        //cout<<minCopyTime<<endl;
        int needAssignBookIndex = m;
        int sum = 0;
        for(int i = k - 1; i >= 0; i--) {
            endIndex[i] = needAssignBookIndex;
            sum = 0;
            while(sum + p[needAssignBookIndex - 1] <= minCopyTime && needAssignBookIndex > 0) {
                sum += p[needAssignBookIndex - 1];
                needAssignBookIndex--;
            }
            startIndex[i] = needAssignBookIndex + 1;
        }
        for(int i = 0; i < k; i++) {
            cout<<startIndex[i]<<" "<<endIndex[i]<<endl;
        }
    } else {
        cout<<endl;
    }
    return 0;
}
