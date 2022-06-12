#include <iostream>
using namespace std;

/* danh sách liên kết */
struct Node
{
    int info;
    struct Node *link;
};

struct Node *head = nullptr;

Node *creatNode(int value)
{
    Node *newNode = new Node;
    newNode->info = value;
    newNode->link = nullptr;
    return newNode;
}

/* tạo và nhập danh sách liên kết */
Node *buildListForward()
{
    // khởi tạo giá trị của các con trỏ là nullptr
    Node *first, *newNode, *last;
    int num;
    // nhập giá trị cho danh sách liên kết
    // kết thúc việc nhập bằng việc nhập -999
    cout << "Enter a list of integers ending with -999." << endl;
    cin >> num;
    first = nullptr;
    while (num != -999)
    {
        // cấp phát bộ nhớ cho nodeType và lưu trữ
        // địa chỉ của bộ nhớ được cấp phát trong newNode
        newNode = new Node;

        // sao chép giá trị của biến num
        // vào biến info trong newNode
        newNode->info = num;

        // khởi tạo con trỏ link của newNode
        newNode->link = nullptr;

        // nếu biến first có giá trị là nullptr,
        // danh sách rỗng, trỏ đến newNode
        if (first == nullptr)
        {
            first = newNode;
            last = newNode;
        }
        else // nếu danh sách không rỗng
        {
            // chèn newNode tại vị trí cuối cùng của danh sách
            last->link = newNode;
            // biến last trỏ đến vị trí cuối cùng của danh sách
            last = newNode;
        }
        // đọc vào giá trị tiếp theo
        cin >> num;
    } // kết thúc vòng while
    return first;
} // kết thúc hàm buildListForward

void printLinkedList(struct Node *node)
{
    // thao tác duyệt
    while (node != nullptr)
    {
        cout << node->info << " ";
        // in ra giá trị của nút
        node = node->link;
        // tiếp tục trỏ tới nút tiếp theo
    }
    cout << endl;
}

/* Chèn phần tử x vào vị trí i */
void insertAt(int x, int i)
{
    struct Node *node = head;

    if (i == 0)
    {
        Node *newNode = new Node;

        // chèn dữ liệu
        newNode->info = x;
        newNode->link = head;
        head = newNode;
    }
    else
    {

        int index = 1;
        while (node != nullptr && index != i)
        {
            index++;           // tăng vị trí
            node = node->link; // tiếp tục trỏ tới phần tử tiếp theo
        }
        if (index != i)
        {
            cout << "Vuot qua do dai cua Danh sach!\nSe chen vao cuoi danh sach\n";
            if (head == nullptr)
            {
                Node *newNode = new Node;

                // chèn dữ liệu
                newNode->info = x;
                head = newNode;
            }
        }
        else
        {
            Node *newNode = new Node;

            // chèn dữ liệu
            newNode->info = x;
            newNode->link = node->link;
            node->link = newNode;
        }
    }
}

int getLength(struct Node *node)
{
    int length = 0; // tương tự index
    // duyệt qua từng phần tử của DSLK
    while (node != nullptr)
    {
        length++;          // đếm số phần tử
        node = node->link; // tiếp tục trỏ tới phần tử tiếp theo
    }
    return length;
}

int main()
{
    // khởi tạo và nhập dslk
    // head = buildListForward();

    int x, position;
    cout << "Chen gia tri: ";
    cin >> x;
    cout << "Vao vi tri: ";
    cin >> position;
    insertAt(x, position);
    printLinkedList(head);
    return 0;
}