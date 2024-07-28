#include<iostream>
using namespace std;


class node
{
private:
    /* data */
public:
    int data;
    node *left, *right;
    node(int data){
        this->data = data;
        left = right = nullptr;
    }

    ~node()
    {
    }
};



class BST
{
private:
    node *root = nullptr;

    
    node *insert_node(node *temp, int item){
        node * temp_node = new node(item);

        if(temp==nullptr){
            temp = temp_node;
        }else if(item<temp->data){
            // traverse left child
            temp->left = insert_node(temp->left, item);
        }else{
            // traverse right child
            temp->right = insert_node(temp->right, item);
        }

        return temp;
    }

    node *delete_node(node *temp, int item){
        if(temp==nullptr){
            cout<<item<<" is not in tree"<<endl;
        }else if(item<temp->data){
            // traverse left child
            temp->left = delete_node(temp->left, item);
        }else if(item>temp->data){
            // traverse right child
            temp->right = delete_node(temp->right, item);
        }else{

            node *t;

            // item matches
            if(temp->left==nullptr && temp->right==nullptr){
                // for delete leaf node
                cout<<"Deleted Value: "<<temp->data<<endl;
                delete temp;
                temp=nullptr;
            }else if(temp->left==nullptr){
                // when only right child
                t=temp;
                temp = temp->right;
                cout<<"Deleted Value: "<<t->data<<endl;
                delete t;
            }else if(temp->right==nullptr){
                // when only left child
                t=temp;
                temp = temp->left;
                cout<<"Deleted Value: "<<t->data<<endl;
                delete t;
            }else{
                // when both children exist

                // find largest element in left subtree called in order predecessor
                t = find_max(temp->left);
                temp->data = t->data;
                temp->left = delete_node(temp->left, temp->data);

                // // find smallest element in right subtree called in order successor
                // t = find_min(temp->right);
                // temp->data = t->data;
                // delete t;
                // temp->right = delete_node(temp->right, temp->data);

            }
        }

        return temp;
    }

    void in_order(node *temp){
        if(temp!=nullptr){
            in_order(temp->left);
            cout<<temp->data<<" ";
            in_order(temp->right);
        }
    }

    void pre_order(node *temp){
        if(temp!=nullptr){
            cout<<temp->data<<" ";
            pre_order(temp->left);
            pre_order(temp->right);
        }
    }

    void post_order(node *temp){
        if(temp!=nullptr){
            post_order(temp->left);
            post_order(temp->right);
            cout<<temp->data<<" ";
        }
    }

    void level_order(node *temp){
        int h = height(temp);
        for(int i=1; i<=h; i++){
            level_data(temp, i);
        }
    }

    void level_data(node *temp, int level){
        if(temp==nullptr || level<1) 
            return;
        else if(level==1){
            cout<<temp->data<<" ";
        }else{
            level_data(temp->left, level-1);
            level_data(temp->right, level-1);
        }
    }

    // find smallest value in left sub tree
    node *find_min(node *temp){
        if(temp==nullptr){
            // cout<<"Tree is Empty.";
            return temp;
        }else if(temp->left==nullptr){
            return temp;
        }else{
            return find_min(temp->left);
        }

    }

    // find greatest value in right sub tree
    node *find_max(node *temp){
        if(temp==nullptr){
            return temp;
        }else if(temp->right==nullptr){
            return temp;
        } else{
            return find_max(temp->right);
        }
    }

    // find height or level=height-1
    int height(node *temp){
        int left_height, right_height;
        if(temp==nullptr){
            return 0;
        }else{
            left_height = height(temp->left);
            right_height = height(temp->right);
        }

        return max(left_height, right_height) + 1;
    }

    node* search_value(node *temp, int item){
        if(temp==nullptr){
            return temp;
        }else if(item<temp->data){
            return search_value(temp->left, item);
        }else if(item>temp->data){
            return search_value(temp->right, item);
        }else{
            return temp;
        }
    }

public:
    BST(/* args */)
    {
    }

    ~BST()
    {
    }

    void insert_node(int item){
        root = insert_node(root, item);
    }

    void delete_node(int item){
        root = delete_node(root, item);
    }

    void in_order(){
        in_order(root);
    }

    void pre_order(){
        pre_order(root);
    }

    void post_order(){
        post_order(root);
    }

    void level_order(){
        level_order(root);
    }

    int find_max(){
        node *temp = find_max(root);
        if(temp==nullptr)
            return -1;
        else
            return temp->data;
    }

    int find_min(){
        node *temp = find_min(root);
        if(temp==nullptr)
            return -1;
        else
            return temp->data;
    }

    int height(){
        return height(root);
    }

    bool search_value(int item){
        node *temp = search_value(root, item);
        if(temp==nullptr)
            return false;
        else
            return true;
    }


};



int main(int argc, char const *argv[])
{
    BST bst;
    int value;
    int choice;
    do{
        cout<<endl;
        cout<<"Binary Search Tree Operations:\n";
        cout<<"1. Insert\n";
        cout<<"2. Delete\n";
        cout<<"3. In-order traversal\n";
        cout<<"4. Pre-order traversal\n";
        cout<<"5. Post-order traversal\n";
        cout<<"6. Level-order traversal\n";
        cout<<"7. Find Max\n";
        cout<<"8. Find Min\n";
        cout<<"9. Height\n";
        cout<<"10. Search Value\n";
        cout<<"11. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;


        switch(choice){
            case 1:
                cout<<"Enter the value to insert: ";
                cin>>value;
                bst.insert_node(value);
                break;
            case 2:
                cout<<"Enter the value to delete: ";
                cin>>value;
                bst.delete_node(value);
                break;
            case 3:
                cout<<"In-order traversal: ";
                bst.in_order();
                cout<<endl;
                break;
            case 4:
                cout<<"Pre-order traversal: ";
                bst.pre_order();
                cout<<endl;
                break;
            case 5:
                cout<<"Post-order traversal: ";
                bst.post_order();
                cout<<endl;
                break;
            case 6:
                cout<<"Level-order traversal: ";
                bst.level_order();
                cout<<endl;
                break;
            case 7:
                cout<<"Max Value is: "<<bst.find_max()<<endl;
                break;
            case 8:
                cout<<"Min Value is: "<<bst.find_min()<<endl;
                break;
            case 9:
                cout<<"Height is: "<<bst.height()<<endl;
                break;
            case 10:
                cout<<"Enter value for search in tree: ";
                cin>>value;
                if(bst.search_value(value)){
                    cout<<value<<" found in tree."<<endl;
                }else{
                    cout<<value<<" not found in tree."<<endl;
                }
                break;
            default:
                cout<<"Choice is Invalid"<<endl;
        }
    }while(choice!=11);
    return 0;
}

