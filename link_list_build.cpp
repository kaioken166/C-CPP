#include <iostream>
using namespace std;

/* danh sách liên kết */
struct Node
{
    int info;
    Node *link;
};

struct Node *head = nullptr;

/* tạo Node mới */
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
    cout << "Enter a list of integers ending with -999:" << endl;
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

/* Chèn phần tử x vào vị trí i */
void insertAt(struct Node *node, int x, int i)
{
    Node *newNode = creatNode(x); // tạo node mới

    if (i == 0 || node == nullptr)
    {
        newNode->link = node;
        node = newNode;
    }
    else if (i > getLength(node)) // nếu lớn hơn độ dài thì thêm vào đuôi
    {
        while (node != nullptr)
        {
            node = node->link;
            // tiếp tục trỏ tới nút tiếp theo
        }

        // tạo node mới
        node->link = newNode;
    }
    else
    {
        int index = 1; // đếm vị trí
        // duyệt dslk cùng với vị trí
        while (node != nullptr && index != i)
        {
            index++;
            node = node->link;
        }

        // tạo node mới
        newNode->link = node->link;
        node->link = newNode;
    }
}

int getPosition(struct Node *node, int x)
{
    int position = 0;
    for (Node *p = node; p != nullptr; p = p->link)
    {
        if (p->info == x)
        {
            return position;
        }
        ++position;
    }
    return -1;
}

double trungbinhcong(struct Node *node)
{
    int sum = 0;
    for (Node *p = node; p != nullptr; p = p->link)
    {
        sum += p->info;
    }
    return (double)sum / getLength(node);
}

void swap(Node *a, Node *b)
    {
        int temp = a->info;
        a->info = b->info;
        b->info = temp;
    }

void sortLinkedListA(struct Node *node)
{
    for (Node *p = node; p != nullptr; p = p->link)
        for (Node *q = p->link; q != nullptr; q = q->link)
            if (p->info > q->info)
                swap(p->info, q->info);
}

int main()
{
    // khởi tạo và nhập dslk
    head = buildListForward();
    // cout << "Chieu dai danh sach: " << getLength(head) << endl;

    // int x, position;
    // cout << "Chen gia tri: ";
    // cin >> x;
    // cout << "Vao vi tri: ";
    // cin >> position;
    // insertAt(x, position);

    // sortLinkedListA(head);

    // cout << "Trung binh cong danh sach lien ket: " << trungbinhcong(head);

    // int value;
    // cout << "Tim vi tri cua gia tri: ";
    // cin >> value;
    // cout << "Khong tim thay = -1/ Tim thay: " << getPosition(head, value);
    printLinkedList(head);
    return 0;
}