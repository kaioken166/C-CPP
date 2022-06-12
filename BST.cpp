// Binary Search Tree operations in C++
#include <iostream>
using namespace std;

// khởi tạo cấu trúc node
struct Node
{
    int data;
    struct Node *left, *right;
};

// tạo node mới
struct Node *newNode(int item)
{
    struct Node *temp;
    temp = new Node;
    temp->data = item;
    temp->left = temp->right = nullptr;
    return temp;
}

// duyệt trung tự Inorder Traversal
void inOrderTraversal(struct Node *root)
{
    if (root != nullptr)
    {
        // duyệt nhánh bên trái
        inOrderTraversal(root->left);

        // duyệt node hiện tại
        cout << root->data << " -> ";

        // duyệt nhánh bên phải
        inOrderTraversal(root->right);
    }
}

// hàm tìm kiếm node
bool searchNode(struct Node *root, int searchItem)
{
    // tạo node dể chạy
    struct Node *current;
    // tạo cờ xác định kết quả tìm kiếm
    bool found = false;
    // cây rỗng
    if (root == nullptr)
        cout << "Cannot search an empty tree." << endl;
    else // cây không rỗng
    {
        current = root;
        // đặt điều kiện kép cho quá trình tìm kiếm
        while (current != nullptr && !found)
        {
            // so sánh với nút hiện tại
            if (current->data == searchItem)
                found = true;
            else if (current->data > searchItem) // tiếp tục với nhánh trái
                current = current->left;
            else // tiếp tục với nhánh phải
                current = current->right;
        } // end while
    }     // end else

    // trả về kết quả tìm kiếm
    return found;
} // end search

// hàm chèn node
struct Node *insertNode(struct Node *node, int key)
{
    // trả về node mới nếu cây đang rỗng
    if (node == nullptr)
        return newNode(key);

    // duyệt nhánh trái để chèn node
    if (key < node->data)
        node->left = insertNode(node->left, key);
    else // duyệt nhánh phải để chèn node
        node->right = insertNode(node->right, key);

    return node;
}

// tìm node mới để sắp xếp cây tìm kiếm nhị phân
// sau khi một nút bị xóa
struct Node *minValueNode(struct Node *node)
{
    struct Node *current = node;

    // tìm nhánh ngoài cùng bên trái
    while (current && current->left != nullptr)
        current = current->left;

    return current;
}

// hàm xóa node
struct Node *deleteNode(struct Node *root, int key)
{
    // nếu cây rỗng
    if (root == nullptr)
        return root;

    // tìm node để xóa
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        // If the node is with only one child or no child
        if (root->left == nullptr)
        {
            struct Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            struct Node *temp = root->left;
            delete root;
            return temp;
        }

        // nếu node có hai nhánh con
        struct Node *temp = minValueNode(root->right);

        // cập nhật cấu trúc của cây sau khi xóa nút có hai nhánh con
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// hàm đến nút
int nodeCount(struct Node *p)
{
    if (p == nullptr)
        return 0;
    else
        return 1 + nodeCount(p->left) + nodeCount(p->right);
}

// hàm dếm lá
int leavesCount(struct Node *p)
{
    if (p == nullptr)
        return 0;
    else if (p->left == nullptr && p->right == nullptr)
        return 1;
    else
        return leavesCount(p->left) + leavesCount(p->right);
}

int singleParent(struct Node *p)
{
    if (p == nullptr)
        return 0;
    else if (p->left == nullptr && p->right != nullptr)
        return 1 + singleParent(p->right);
    else if (p->left != nullptr && p->right == nullptr)
        return 1 + singleParent(p->left);
    else
        return singleParent(p->left) + singleParent(p->right);
}

int main()
{
    // khởi tạo cây
    struct Node *root = nullptr;
    root = insertNode(root, 10);
    root = insertNode(root, 2);
    root = insertNode(root, 4);
    root = insertNode(root, 70);
    root = insertNode(root, 15);
    root = insertNode(root, 23);
    root = insertNode(root, 6);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    cout << "Duyệt trung tự: ";
    inOrderTraversal(root);
    cout << endl
         << searchNode(root, 10) << endl;
    cout << nodeCount(root) << endl;
    cout << leavesCount(root) << endl;
    cout << singleParent(root) << endl;

    cout << "\nSau khi xóa node 10\n";
    root = deleteNode(root, 10);
    cout << "Duyệt trung tự: ";
    inOrderTraversal(root);
    cout << endl
         << searchNode(root, 10) << endl;
    cout << nodeCount(root) << endl;
    cout << leavesCount(root) << endl;
    cout << singleParent(root) << endl;
}