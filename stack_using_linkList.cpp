#include<iostream>
using namespace std;

class node
{
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

class stack
{
    private:
        node *head, *tail;
    public:
        stack(){
            head = tail = nullptr;
        }
        ~stack()
        {
            cout<<"stack destructor";
        }
        void push(int val){
            node *new_node = new node(val);
            if(head==nullptr){
                head = tail = new_node;
            }else{
                tail->next = new_node;
                new_node->prev = tail;
                tail = new_node;
            }

        }
        int pop(){
            if(tail==nullptr){
                cout<<"Underflow"<<endl;
                return -1;
            }

            node *temp = tail;
            tail = tail->prev;
            int tm = temp->data;
            delete temp;
            return tm;
        }
        int peek(){
            if(tail==nullptr){
                cout<<"Underflow"<<endl;
                return -1;
            }

            return tail->data;
        }
        void traverse(){
            if(tail==nullptr){
                cout<<"Underflow";
            }else{

                node *temp = tail;
                while(temp!=nullptr){
                    cout<<temp->data<<" ";
                    temp = temp->prev;
                }
            }
            cout<<endl;
        }
};






int main(int argc, char const *argv[])
{
    int choice, return_val, temp;

    // stack st;
    stack st = stack();


    do{
        cout<<endl;
        cout<<"1. Push in stack."<<endl;
        cout<<"2. Pop from stack."<<endl;
        cout<<"3. Peek in stack."<<endl;
        cout<<"4. Traverse stack."<<endl;
        cout<<"5. Exit."<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter value for push: ";
                cin>>temp;
                st.push(temp);
                break;
            case 2:
                return_val = st.pop();
                cout<<"Pop value: "<<return_val<<endl;
                break;
            case 3:
                return_val = st.peek();
                cout<<"Peek value: "<<return_val<<endl;
                break;
            case 4:
                st.traverse();
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
