#include<iostream>
using namespace std;


class stack
{
    private:
        int top, size, *st;
    public:
        stack();
        void increase_array_size();
        void decrease_array_size();
        int push(int);
        int pop();
        int peek();
        int traverse();
};

stack::stack(){
    top = -1; 
    size = 1;
    st= new int[size];
}
void stack::increase_array_size(){
    size *= 2;
    int *new_st = new int[size];

    for(int i=0; i<=top; i++){
        new_st[i] = st[i];
    }

    delete st;
    st = new_st;
}
void stack::decrease_array_size(){
    size /= 2;
    int *new_st = new int[size];

    for(int i=0; i<=top; i++){
        new_st[i] = st[i];
    }

    delete st;
    st = new_st;
}
int stack::push(int val){

    if(top==size-1){
        increase_array_size();
        cout<<"Now size="<<size<<endl;
    }

    this->top++;
    st[top] = val;

    return top;
}

int stack::pop(){
    if(top==-1){
        cout<<"Stack is Empty/Underflow."<<endl;
        return -1;
    }

    int temp = st[top];
    top--;
    if(top == (size - 1)/2){
        decrease_array_size();
        cout<<"Now size="<<size<<endl;
    }
    return temp;

}

int stack::peek(){
    if(top==-1){
        cout<<"Stack is Empty/Underflow."<<endl;
        return -1;
    }

    return st[top];
}

int stack::traverse(){
    if(top==-1){
        cout<<"Stack is Empty/Underflow."<<endl;
        return -1;
    }
    cout<<"All Elements are: ";
    for(int i=top; i>=0; i--){
        cout<<st[i]<<" ";
    }
    cout<<endl;
    return 1;
}



int main(){
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