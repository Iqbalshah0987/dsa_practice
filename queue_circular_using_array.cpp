#include<iostream>
using namespace std;

class queue
{
private:
    int front, rear, size, *qu;
public:
    queue(){
        front = rear = -1;
        size = 1;
        qu = new int[size];
    }

    ~queue()
    {
    }
    void increase_array_size(){
        // cout<<"################"<<endl;
        size *= 2;
        int *new_qu = new int[size];
        int j = 0, i;
        // cout<<"front => "<<front<<" rear => "<<rear<<" size => "<<size<<endl;
        for(i=front; i!=rear; i=(i+1)%size){
            new_qu[j] = qu[i];
            // cout<<"in => "<<new_qu[j]<<endl;
            j++;
        }
        new_qu[j] = qu[i];
        // cout<<endl<<"j => "<<j<<endl;
        front = 0;
        rear = j;
        delete qu;
        qu = new_qu;
        // cout<<"front => "<<front<<" rear => "<<rear<<" size => "<<size<<endl;
        // cout<<"################"<<endl;
    }
    void decrease_array_size(){
        size /= 2;
        int *new_qu = new int[size];
        int j = 0, i;
        for(i=front; i!=rear; i=(i+1)%size){
            new_qu[j] = qu[i];
            j++;
        }
        new_qu[j] = qu[i];
        front = 0;
        rear = j;
        delete qu;
        qu = new_qu;
    }
    void enqueue(int val){
        if((rear + 1)%size == front){
            increase_array_size();
            cout<<"Now size="<<size<<endl;
        }
        if(front==-1 && rear==-1){
            front = rear = 0;
            qu[rear] = val;
        }else{
            rear = (rear + 1)%size;
            qu[rear] = val;
        }
    }
    int dequeue(){
        int temp = -1, s=0;
        if(front==-1 && rear==-1){
            cout<<"Underflow/Empty."<<endl;
        }else if(front==rear){
            temp = qu[front];
            front = rear = -1;
        }else{
            temp = qu[front];
            front = (front + 1)%size;
        }

        for(int i=front; i!=rear; i=(i+1)%size){
            s++;
        }
        s++;
        if(s == (size - 1)/2){
            decrease_array_size();
            cout<<"Now size="<<size<<endl;
        }

        return temp;
    }
    int peek(){
        int temp = -1;
        if(front==-1 && rear==-1){
            cout<<"Underflow/Empty."<<endl;
        }else{
            temp = qu[front];
        }
        return temp;
    }
    void traverse(){
        if(front==-1 && rear==-1){
            cout<<"Underflow/Empty."<<endl;
        }else{
            // cout<<"front => "<<front<<" rear => "<<rear<<" size => "<<size<<endl;
            cout<<"All queue Elements: ";
            int i;
            for(i=front; i!=rear; i=(i+1)%size){
                cout<<qu[i]<<" ";
            }
            cout<<qu[i]<<" ";
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
