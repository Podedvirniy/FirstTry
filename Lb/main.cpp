#include <iostream>
using namespace std;



class ForList;

class List
{
public:
    List();
    ~List();



    void NEXT(int position);
    int RETRIEVE(int position);
    int LOCATE(int data);
    void new_head(int data);
    void INSERT(int data, int position);
    void DELETE(int position);
    int END();
    int FIRST();
    void destroy2();
    void destroy();
    void adding(int data);




private:
    class ForList
    {
    public:
        ForList* next;
        int data;



        ForList(int data=0, ForList* next = nullptr)
        {
            this->data = data;
            this->next = next;
        }
    };
    ForList* head;
    int size;
};

List::List()
{
    head = nullptr;
    size = 0;
}

List::~List()
{
    destroy2();
}

void List::NEXT(int position)
{
    if (position == 0)
    {
        cout <<"NEXT "<< head->next << endl << endl;
    }
    else
    {
        ForList* current = this->head;
        for (int i = 0; i < position; i++)
        {
            current = current->next;
        }
        cout <<"NEXT()\t\t"<< current->next << endl<<endl;
    }
}

int List::RETRIEVE(int position)
{
    if(position==0)
    {
        return head->data;
    }
    else
    {
        ForList* current = this->head;
        for (int i = 0; i < position; i++)
        {
            current = current->next;
        }
        return current->data;
    }
}

int List::LOCATE(int data)
{
    int position = 0;
    ForList* current = this->head;
    

    while (current->next != nullptr)
    {
        current = current->next;
        position++;
        if (current->data == data)
        {
            return position;
        }
    }
    return 0;
}

void List::new_head(int data)
{
    head = new ForList(data, head);
    size++;
}

void List::INSERT(int data, int position)
{
    if (position == 0)
    {
        new_head(data);
    }
    else
    {
        ForList* previous = this->head;
        for (int i = 0; i < position - 1; i++)
        {
            previous = previous->next;
        }
        ForList* New = new ForList(data, previous->next);
        previous->next = New;
        size++;
    }
}

void List::DELETE(int position)
{
    if (position == 0)
    {
        destroy();
    }
    else
    {
        ForList* previous = this->head;
        for (int i = 0; i < position - 1; i++)
        {
            previous = previous->next;
        }
        ForList* Delete = previous->next;
        previous->next = Delete->next;
        delete Delete;
        size--;
    }
}

int List::END()
{
    ForList* current = this->head;
    int Last;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    Last = current->data;
    return Last;
}

int List::FIRST()
{
    return head->data;
}



void List::destroy2()
{
    while(size>0)
    {
        destroy();
    }
}

void List::destroy()
{
    ForList *temp = head;
    head = head->next;
    delete temp;

    size--;
}

void List::adding(int data)
{
    if(this->head==nullptr)
    {
        this->head = new ForList(data);
    }
    else
    {
        ForList* current = this->head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = new ForList(data);


    }
    size++;
}

int main()
{
    List list;
    list.adding(35);
    list.adding(111);
    list.adding(984);
    list.adding(333);
    list.adding(92);
    
    cout << "END "<<list.END() << endl;
    cout << "FIRST " << list.FIRST() << endl;
    list.INSERT(999, 2);
    list.DELETE(1);
    cout << "LOCATE " << list.LOCATE(333) << endl;
    cout << "RETRIEVE " << list.RETRIEVE(0) << endl;
    list.NEXT(0);

    list.~List();
}

