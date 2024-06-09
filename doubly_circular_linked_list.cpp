#include<iostream>
#define NULL __null
using namespace std;
struct node
{
    int data = 0;
    // initialize as null
    struct node *next = NULL, *prev=NULL;
} *head=NULL, *temp=NULL, *current=NULL;

struct node * create_node(){
    int data;
    cout<<"Enter the Element: ";
    cin>>data;
    struct node *new_node = new node;
    new_node->data = data;

    return new_node;
}

int list_length(){
    if(head==NULL){
        return 0;
    }

    int i=0;
    temp = head;

    do{
        i++;
        temp = temp->next;
    }while(temp!=head);
    return i;
}

void traverse_list(){
    temp = head;
    if(head==NULL){
        cout<<"List Till not exist!"<<endl;
    }else{
        cout<<"All Elements are Here."<<endl;

        do{
            cout<<temp->data<<" ";
            temp = temp->next;
        }while(temp!=head);

    }
    cout<<endl;
}


int find_position(int ele){
    temp = head;
    int pos= 1;
    bool flag = true;

    if(head==NULL){
        return -1;
    }

    if(temp->data==ele){
        return pos;
    }
    do{
        pos++;
        temp = temp->next;
    }while(temp!=head && temp->data!=ele);

    if(temp==head && temp->data!=ele){
        return -1;
    }else{
        return pos;
    }

}

void insert_at_beginning(struct node *new_node=NULL){
    if(head==NULL){
        head = new_node;
        new_node->next = new_node->prev = head;
    }else{
        temp = head;

        current = head->prev;
        current->next = new_node;

        new_node->prev = temp->prev;
        new_node->next = temp;
        temp->prev = new_node;
        head = new_node;
    }
}

void insert_at_end(struct node *new_node=NULL){

    if(head==NULL){
        head = new_node;
    }else{
       temp = head->prev;
       new_node->next = temp->next;
       new_node->prev = temp;

       temp->next = new_node;
       head->prev = new_node;
    }
}

int insert_at_position(struct node *new_node=NULL, int pos=-1){

    int i=pos;
    int len = list_length();
    if(pos<1 || (len+1)<pos){
        cout<<"Invalid Position of"<<pos<<"Because Length is "<<len<<endl;
        return 0;
    }

    if(pos==1){
        insert_at_beginning(new_node);
    }else if(pos==len+1){
        insert_at_end(new_node);
    }else{
        temp = head;
        while((pos-1)!=1){
            temp = temp->next;
            pos--;
        }
        temp->next->prev = new_node;
        new_node->next = temp->next;
        new_node->prev = temp;
        temp->next = new_node;
    }

    
    return i;
}

int insert_after_data(struct node *new_node=NULL){
    int temp_data;
    cout<<"Enter Element after which to insert: ";
    cin>>temp_data;

    int pos = find_position(temp_data);
    if(pos==-1){
        cout<<"Element is not exist in list."<<endl;
        return -1;
    }
    insert_at_position(new_node, pos+1);
    return pos;
}

void insert_in_list(){
    int choice, pos;
    struct node *new_node;

    do{
        cout<<endl;
        cout<<"Where do you Insert: "<<endl;
        cout<<"1. At Beginning."<<endl;
        cout<<"2. At End."<<endl;
        cout<<"3. At Any Position."<<endl;
        cout<<"4. After Any Data."<<endl;
        cout<<"5. Not Insert the Element."<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch (choice)
        {
            case 1:
                new_node = create_node();
                insert_at_beginning(new_node);
                break;
            case 2:
                new_node = create_node();
                insert_at_end(new_node);
                break;
            case 3:
                new_node = create_node();
                cout<<"Enter the position where you insert the element: ";
                cin>>pos;
                insert_at_position(new_node, pos);
                break;
            case 4:
                new_node = create_node();
                insert_after_data(new_node);
                break;
            case 5:
                break;
            default:
                cout<<"Invalid Choice!";
                break;
        }
        cout<<"Element Inserted Successfully!"<<endl;
        if(choice==5){
            break;
        }
    }while(true);
}

// return deleted value else -1
int delete_from_beginning(){
    if(head==NULL){
        cout<<"List is empty";
        return -1;
    }
    temp = head;
    if(head->next==head){
        delete head;
    }else{
        current = head->prev;

        head = temp->next;
        head->prev=temp->prev;
        current->next = head;
    }
    int del_val = temp->data;
    delete temp;
    return del_val;
}

// return deleted value else -1
int delete_from_end(){
    if(head==NULL){
        cout<<"List is empty";
        return -1;
    }
    temp = head;
    if(head->next==head){
        delete head;
    }else{
        // while(temp->next!=head){
        //     current = temp;
        //     temp = temp->next;
        // }
        temp = head->prev;
        current = temp->prev;
        
        current->next = temp->next;
        head->prev = current;
    }

    int del_val = temp->data;
    delete temp;
    return del_val;
}

// return deleted value else -1
int delete_from_position(int pos=-1){
    if(head==NULL){
        cout<<"List is empty";
        return -1;
    }

    int i=pos;
    int len = list_length();
    if(pos<1 || len<pos){
        cout<<"Invalid Position of"<<pos<<"Because Length is "<<len<<endl;
        return 0;
    }

    if(pos==1){
        delete_from_beginning();
    }else if(pos==len){
        delete_from_end();
    }else{

        temp = head;
        while(pos!=1){
            current = temp;
            temp = temp->next;
            pos--;
        }
        current->next = temp->next;
        current->next->prev = current;
    }

    int del_val = temp->data;
    delete temp;
    return del_val;
}

int delete_specific_data(){
    int temp_data;
    cout<<"Enter data which you want to delete: ";
    cin>>temp_data;

    int pos = find_position(temp_data);
    if(pos==-1){
        cout<<"Element is not exist in list."<<endl;
        return -1;
    }
    delete_from_position(pos);
    return temp_data;
}

void delete_from_list(){
    int choice, del_val;

    do{
        cout<<endl;
        cout<<"List is: "; traverse_list();
        cout<<endl;
        cout<<"1. From Beginning."<<endl;
        cout<<"2. From End."<<endl;
        cout<<"3. From Any Position."<<endl;
        cout<<"4. Specific Data."<<endl;
        cout<<"5. Not Delete the Element."<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch (choice)
        {
            case 1:
                del_val = delete_from_beginning();
                break;
            case 2:
                del_val = delete_from_end();
                break;
            case 3:
                int pos;
                cout<<"Enter position to delete element: ";
                cin>>pos;
                del_val = delete_from_position(pos);
                break;
            case 4:
                del_val = delete_specific_data();
                break;
            case 5:
                break;
            default:
                cout<<"Invalid Choice!";
                break;
        }
        cout<< del_val <<" Element Deleted Successfully!"<<endl;
        if(choice==5){
            break;
        }
    }while(true);
}


void reverse_list(){
    struct node *temp_ptr, *prev_link, *next_link;
    current = head;

    traverse_list();
    do{
        prev_link = current;

        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        
        current = current->prev;
    }while(current!=head);
    // head = prev_link;
    head = temp->prev;
    traverse_list();
}

// 19 90 654 34 23 56 22 32 432 768
int main(){
    
    int choice;
    do{
        cout<<endl;
        cout<<"1. Insert Element."<<endl;
        cout<<"2. Delete Element."<<endl;
        cout<<"3. Traverse the List."<<endl;
        cout<<"4. Length of List."<<endl;
        cout<<"5. Reserve the List."<<endl;
        cout<<"6. Find Element Position."<<endl;
        cout<<"7. Exit."<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch (choice)
        {
            case 1:
                insert_in_list();
                break;
            case 2:
                delete_from_list();
                break;
            case 3:
                traverse_list();
                break;
            case 4:
                cout<<"Length of a List is "<<list_length()<<"."<<endl;
                break;
            case 5:
                reverse_list();
                break;
            case 6:
                int ele;
                cout<<"Enter Element to find position: ";
                cin>>ele;
                cout<<ele<<" position in list is "<<find_position(ele)<<"."<<endl;
                break;
            case 7:
                break;
            default:
                cout<<"Invalid Choice!"<<endl;
                break;
        }

        if(choice==7){
            break;
        }
    }while(true);


    return 0;

}