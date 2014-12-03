# include <iostream>
using namespace std;
class Node{
public:
    int val;
    Node * left;
    Node * right;
    Node(int v) {
        val = v;
        left = NULL;
        right = NULL;
    }
};
void generate_tree(Node *top, int high) {
    
}
int main() {
    //first level
    Node *first = new Node(1);
    for(int i = 2; i <
    cout<<first->val<<endl;
    return 0;
}
