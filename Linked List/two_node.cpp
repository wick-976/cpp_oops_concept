#include <bits/stdc++.h>
using namespace std;

class Listnode
{
public:
    int data;
    Listnode* next;

    Listnode(int data)
    {
        this->data = data;
        this->next = nullptr;
    }

    Listnode* hp(int n)
    {
        Listnode* head = nullptr;
        Listnode* tail = nullptr;

        for (int i = 0; i < n; i++)
        {
            int value;
            cin >> value;

            Listnode* nn = new Listnode(value);

            if (head == nullptr)
            {
                head = tail = nn;
            }
            else
            {
                tail->next = nn;
                tail = nn;
            }
        }

        return head;
    }

    void display(Listnode* h)
    {
        while (h != nullptr)
        {
            cout << h->data << " ";
            h = h->next;
        }

        cout << endl;
    }

    void two_sum(Listnode* l1, Listnode* l2)
    {
        int carr = 0;

        // Create result list only ONCE
        Listnode Dummy(0);
        Listnode* tail = &Dummy;

        while (l1 != nullptr || l2 != nullptr || carr != 0)
        {
            int sum = carr;

            // Take one node from l1
            if (l1 != nullptr)
            {
                sum += l1->data;
                l1 = l1->next;
            }

            // Take one node from l2
            if (l2 != nullptr)
            {
                sum += l2->data;
                l2 = l2->next;
            }

            carr = sum / 10;

            Listnode* new_one = new Listnode(sum % 10);

            tail->next = new_one;
            tail = tail->next;
        }

        display(Dummy.next);
    }
};

int main()
{
    int n1, n2;

    cin >> n1;
    Listnode obj(0);

    Listnode* head_point1 = obj.hp(n1);

    cin >> n2;
    Listnode* head_point2 = obj.hp(n2);

    obj.display(head_point1);
    obj.display(head_point2);

    obj.two_sum(head_point1, head_point2);

    return 0;
}