# include <iostream>
# include <vector>
# include <deque>
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

class NodePro{
    public:
        Node * node;
        int level;
        NodePro() {
            node = NULL;
            level = -1;
        }
        NodePro(Node * n, int lv) {
            node = n;
            level = lv;
        }
};

/**
 * for example:
 * Node * top = generate_tree(1, 3);
 * top will point to the Top.
 * will generate full tree with high 3:
 *
 *          1
 *        /   \
 *       2     3
 *      / \   / \
 *     4   5 6   7  
 *
 */
Node * generate_tree(int topNodeVal, int high) {
    Node *top = new Node(topNodeVal);
    if(high > 1) {
        top->left = generate_tree(2 * topNodeVal, high - 1);
        top->right = generate_tree(2 * topNodeVal + 1, high - 1);
    }
    return top;
}

int get_tree_node_number(Node * top) {
    if(top == NULL) {
        return 0;
    }
    return 1 + get_tree_node_number(top->left) + get_tree_node_number(top->right);
}

int get_tree_height(Node * top) {
    if(top == NULL) {
        return 0;
    }
    int leftChildrenHeight = get_tree_height(top->left);
    int rightChildrenHeight = get_tree_height(top->right);
    int maxHeight = (leftChildrenHeight > rightChildrenHeight) ? leftChildrenHeight : rightChildrenHeight;
    return (maxHeight + 1);
}

void destroy_tree(Node * top) {
    if(top->left != NULL) {
        destroy_tree(top->left);
    }
    if(top->right != NULL) {
        destroy_tree(top->right);
    }
    if(top != NULL) {
        delete top;
    }
}

void display_tree_hierarchy_simple(Node * top) {
    deque<NodePro> nodeQueue;
    int curLevel = -1;
    NodePro topNodePro = NodePro(top, 1);
    NodePro curNodePro, tmpNodePro;
    nodeQueue.push_back(topNodePro);

    while(nodeQueue.size() > 0) {
        curNodePro = nodeQueue.front();
        if(curLevel == -1) {
            curLevel = curNodePro.level;
        } else if(curNodePro.level != curLevel) {
            cout<<endl;
            curLevel = curNodePro.level;
        } else {
            cout<<" ";
        }
        if(curNodePro.node != NULL) {
            if(curNodePro.node->left != NULL) {
                tmpNodePro = NodePro(curNodePro.node->left, curNodePro.level + 1);
                nodeQueue.push_back(tmpNodePro);
            }
            if(curNodePro.node->right != NULL) {
                tmpNodePro = NodePro(curNodePro.node->right, curNodePro.level + 1);
                nodeQueue.push_back(tmpNodePro);
            }
            cout<<curNodePro.node->val;
        }
        nodeQueue.pop_front();
    }
    cout<<endl;
}

void display_tree_hierarchy_double_loop(Node * top) {
    deque<Node*> queueNode;
    queueNode.push_back(top);
    Node *head;
    Node *tail;
    Node *cur;
    while(queueNode.size() > 0) {
        head = queueNode.front();
        tail = queueNode.back();
        cur = head;
        if(cur != NULL) {
            if(cur->left != NULL) {
                queueNode.push_back(cur->left);
            }
            if(cur->right != NULL) {
                queueNode.push_back(cur->right);
            }
            cout<<cur->val;
            queueNode.pop_front();
            if(head != tail) {
                cur = queueNode.front();
                while(cur != tail) {
                    if(cur != NULL) {
                        if(cur->left != NULL) {
                            queueNode.push_back(cur->left);
                        }
                        if(cur->right != NULL) {
                            queueNode.push_back(cur->right);
                        }
                    }
                    cout<<" "<<cur->val;
                    queueNode.pop_front();
                    cur = queueNode.front();
                }
                if(cur != NULL) {
                    if(cur->left != NULL) {
                        queueNode.push_back(cur->left);
                    }
                    if(cur->right != NULL) {
                        queueNode.push_back(cur->right);
                    }
                }
                cout<<" "<<cur->val;
                queueNode.pop_front();
            }
            cout<<endl;
        }
    }
}
int main() {
    //first level
    Node * top = generate_tree(1, 5);
    //cout<<top->val<<endl;
    //cout<<get_tree_height(top)<<endl;
    //cout<<get_tree_node_number(top)<<endl;
    display_tree_hierarchy_simple(top);
    display_tree_hierarchy_double_loop(top);
    destroy_tree(top);
    return 0;
}
