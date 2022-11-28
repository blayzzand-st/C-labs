#include <iostream>

// addl is for push_forward ((1, 2) -> addl 3 -> (3, 1, 2))
// addr is for push_back ((1, 2) -> addr 3 -> (1, 2, 3))
// del is for delete first ((1, 2) -> del -> (2)
// pop is for delete last ((1, 2) -> pop -> (1)

struct Node {
    int data;
    Node *next; // next is right ->
    Node *last; // last is left <-

    explicit Node(int value)  : data(value), next(nullptr), last(nullptr) {}
};

struct List{
    Node* head;
    Node* tail;
    int length = 0;

    explicit List(): head(nullptr), tail(nullptr) {}

    void push_forward(int x) {
        if (length == 0){
            Node *reserve = new Node(x);
            reserve->data = x;
            head = reserve;
            tail = reserve;
            length++;
        } else
        {
            Node *reserve = new Node(x);
            reserve->data = x;
            reserve->next = head;
            head->last = reserve;
            head = reserve;
            length++;
        }
    }
    void push_back(int x) {
        if (length == 0) {
            Node *reserve = new Node(x);
            reserve->data = x;
            head = reserve;
            tail = reserve;
            length++;
        } else {
            Node *reserve = new Node(x);
            reserve->data = x;
            reserve->last = tail;
            tail->next = reserve;
            tail = reserve;
            length++;
        }
    }
    void del_forward() {
        if (length == 0) {
            return;
        } else if (length == 1) {
            head = nullptr;
            tail = nullptr;
            length--;
        }
        else {
            head = head->next;
            head->last = nullptr;
            length--;
        }
    }
    void del_back() {
        if (length == 0) {
            return;
        } else if (length == 1) {
            head = nullptr;
            tail = nullptr;
            length--;
        }
        else {
            Node* reserve = tail;
            tail = tail->last;
            tail->next = nullptr;
            delete reserve;
            length--;
        }
    }

    void print() const {
        if (length == 0) {
            return;
        }
        Node *reserve = head;
        while (reserve) {
            std::cout << reserve->data << ' ';
            reserve = reserve->next;
        }
    }
};

int main() {
    List list;
    int value = 0;
    int n = 0;
    std::cin >> n;
    std::string string;

    for (int i = 0; i < 2 * n; i += 2) {
        std::cin >> string;
        if (string == "addl") {
            std::cin >> value;
            list.push_forward(value);
        }
        else if (string == "addr"){
            std::cin >> value;
            list.push_back(value);
        }
        else if (string == "del") {
            list.del_forward();
        }
        else if (string == "pop") {
            list.del_back();
        }
        else {
            std::cout << "Idi nahuy";
        }
    }

    list.print();
    return 0;
}