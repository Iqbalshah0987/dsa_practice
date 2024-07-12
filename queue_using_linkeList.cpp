#include<iostream>
using namespace std;

class node
{
private:
public:
    int data;
    node *next, *prev;
    node(int data){
        this->data = data;
        next = prev = nullptr;
    }

    ~node()
    {
        cout<<"node destructor";
    }
};



class queue
{
private:
    node *head, *tail;
public:
    queue(){
        head = tail = nullptr;
    }

    ~queue()
    {
    }
    void enqueue(int val){
        node *temp = new node(val);
        if(head == nullptr){
            head = tail = temp;
        }else{
            tail->next = temp;
            temp->prev = tail;
            tail = temp;

        }
    }
    int dequeue(){
        node *temp = head;
        if(head == nullptr){
            cout<<"Underflow/Empty."<<endl;
            return -1;
        }else if(head==tail){
            head = tail = nullptr;
        }else{
            head = head->next;
        }

        int tm = temp->data;
        delete temp;
        return tm;
    }
    int peek(){
        if(head == nullptr){
            cout<<"Underflow/Empty."<<endl;
            return -1;
        }
        return head->data;
    }
    void traverse(){
        if(head==nullptr){
            cout<<"Underflow/Empty."<<endl;
        }else{
            node *temp = head;
            cout<<"All queue Elements: ";
            while(temp!=nullptr){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }

    }
};



int main(int argc, char const *argv[])
{
    int choice, temp, return_val;

    queue que = queue();
    
    do{
        cout<<endl;
        cout<<"1. Push in queue."<<endl;
        cout<<"2. Pop from queue."<<endl;
        cout<<"3. Peek in queue."<<endl;
        cout<<"4. Traverse queue."<<endl;
        cout<<"5. Exit."<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter value for push: ";
                cin>>temp;
                que.enqueue(temp);
                break;
            case 2:
                return_val = que.dequeue();
                cout<<"Pop value: "<<return_val<<endl;
                break;
            case 3:
                return_val = que.peek();
                cout<<"Peek value: "<<return_val<<endl;
                break;
            case 4:
                que.traverse();
                break;
            case 5:
                break;
            default:
                cout<<"Invalid Choice!"<<endl;
        }

        if(choice==5){
            break;
        }

    }while(true);
    

    return 0;
}
