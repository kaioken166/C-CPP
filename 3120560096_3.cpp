#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};

class linkedList
{
private:
    node *head;
    node *tail;
    int length = 0;

    void swap(node *a, node *b)
    {
        int temp = a->data;
        a->data = b->data;
        b->data = temp;
    }

public:
    linkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    // tạo node mới có giá trị x
    node *createNode(int x)
    {
        node *temp = new node;
        temp->data = x;
        temp->next = nullptr;
        return temp;
    }

    // thêm phần tử cuối
    void insertTail(int x)
    {
        if (head == nullptr) // nếu danh sách rỗng thì thêm vào head, cập nhật tail
        {
            head = createNode(x);
            tail = head;
        }
        else // ngược lại tại tail->next và cập nhật tail
        {
            tail->next = createNode(x);
            tail = tail->next;
        }
        length++;
    }

    // thêm phần tử đầu
    void insertHead(int x)
    {
        node *temp = createNode(x); // tạo node mới có giá trị x
        temp->next = head;
        head = temp; // cập nhật lại head
        length++;
    }

    // thêm phần tử tại vị trí k (0 <= k < length)
    void insertAt(int x)
    {
        node *temp = head;
        int k;
        cout << "Nhap vi tri can chen: " << endl;
        cin >> k;
        // duyệt tới phần tử k - 1
        for (int i = 0; i < k - 1; i++)
            temp = temp->next;
        node *newNode = createNode(x); // tạo node mới có giá trị x
        newNode->next = temp->next;    // cập nhật next của node mới
        temp->next = newNode;          // cho next của phần tử k - 1 trỏ tới node mới
        length++;
    }

    // xóa phần tử đầu
    void delHead()
    {
        node *temp = head; // tạo biếm tạm = head
        head = head->next; // cập nhật head
        delete (temp);     // giải phóng biến tạm
        length--;
    }

    // xóa phần tử cuối
    void delTail()
    {
        node *temp = head;
        while (temp->next->next != nullptr) // duyệt tới phần tử kế cuối
            temp = temp->next;
        tail = temp;          // cập nhật tail
        temp = temp->next;    // cho biến tạm trỏ tới phần tử cuối
        tail->next = nullptr; // cập nhật next của tail
        delete (temp);        // giải phóng biến tạm
        length--;
    }

    // xóa phần tử tại vị trí k (0 <= k < length)
    void delAt()
    {
        node *temp = head;
        int k;
        cout << "Nhap vi tri can xoa: " << endl;
        cin >> k;
        // duyệt tới phần tử k - 1
        for (int i = 0; i < k - 1; i++)
            temp = temp->next;
        tail = temp;             // cập nhật tail
        temp = temp->next;       // cho biến tạm trỏ tới phần tử tiếp theo
        tail->next = temp->next; // cập nhật next của tail
        delete (temp);           // giải phóng biến tạm
        length--;
    }

    // tìm kiếm theo data, trả về boolean
    // x: data cần tìm
    bool search(int x)
    {
        node *temp = head;
        // duyệt cho tới khi gặp phần tử có giá trị x
        while (temp->next != nullptr)
        {
            // nếu có thì trả về true
            if (temp->data == x)
                return 1;
            temp = temp->next;
        }
        // nếu không có thì trả về false
        return 0;
    }

    void enterList()
    {
        int n;
        cout << "Nhap so luong phan tu: ";
        cin >> n;
        cout << "Nhap phan tu: " << endl;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            insertTail(x);
        }
        length = n;
    }

    void printList()
    {
        node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    int size()
    {
        return length;
    }

    int getHead()
    {
        return head->data;
    }

    int getTail()
    {
        return tail->data;
    }

    // Descending sort
    void sort()
    {
        // sắp xếp cơ bản theo 2 vòng for
        for (node *i = head; i != nullptr; i = i->next)
            for (node *j = head; j != nullptr; j = j->next)
                if (i->data > j->data)
                    swap(i, j);
    }

    // tìm kiếm k phần tử lớn nhất trong danh sách
    void searchKMax(int k)
    {
        node *temp = head;
        // sắp xếp để đưa các giá trị lớn nhất lên đầu
        sort();
        // xuất các phần tử cho đến khi đủ k phần tử hoặc hết danh sách
        while (temp->next != nullptr && k--)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};
class Queue
{
private:
    linkedList q;

public:
    // hàm trả về số lượng của hàng đợi
    int size()
    {
        return q.size(); // sử dụng hàm size của linkedList để lấy số lượng
    }

    // hàm kiểm tra hàng đợi có trống hay không
    bool empty()
    {
        // nếu size == 0 thì hàng đợi trống, trả về true
        if (!q.size())
            return 1;
        return 0; // ngược lại trả false
    }

    // hàm lấy phần tử đầu
    int front()
    {
        // nếu hàng đợi trống thì thông báo cho user
        if (empty())
        {
            cout << "Can't get front from empty queue" << endl;
            return -1;
        }
        // ngược lại sử dụng hàm getHead đề lấy phần tử đầu của hàng đợi
        return q.getHead();
    }

    // hàm lấy phần tử cuối
    int back()
    {
        // nếu hàng đợi trống thì thông báo cho user
        if (empty())
        {
            cout << "Can't get back from empty queue" << endl;
            return -1;
        }
        // ngược lại sử dụng hàm getTail đề lấy phần tử cuối của hàng đợi
        return q.getTail();
    }

    // hàm thêm phần tử vào cuối hàng đợi
    // x: giá trị của phần tử
    void push(int x)
    {
        // sử dụng hàm insertTail để thêm vào cuối hàng đợi
        q.insertTail(x);
    }

    // hàm loại bỏ phần tử đầu của hàng đợi
    void pop()
    {
        // sử dụng hàm delHead để xóa phần tử đầu của hàng đợi
        q.delHead();
    }
};
int main()
{
    // test:

    // Queue myQueue;
    // myQueue.push(3);
    // myQueue.push(6);
    // myQueue.push(7);
    // cout << "The first element of the queue = " << myQueue.front() << endl;
    // cout << "The last element of the queue = " << myQueue.back() << endl;
    // cout << "The queue size is = " << myQueue.size() << endl;
    // cout << "Queue empty: " << boolalpha << myQueue.empty() << endl;
    // while (!myQueue.empty())
    // {
    //     cout << myQueue.front() << endl;
    //     myQueue.pop();
    // }
    // cout << "The queue size is = " << myQueue.size() << endl;
    // cout << "Queue empty: " << boolalpha << myQueue.empty() << endl;
    return 0;
}