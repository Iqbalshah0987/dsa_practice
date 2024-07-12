#include<iostream>
using namespace std;

template <typename gen> 
class stack
{
    private:
    public:
        int top, size;
        gen *st;
        stack(){
            top = -1; 
            size = 1;
            st= new gen[size];
        }
        void increase_array_size(){
            size *= 2;
            gen *new_st = new gen[size];

            for(int i=0; i<=top; i++){
                new_st[i] = st[i];
            }

            delete st;
            st = new_st;
        }
        void decrease_array_size(){
            size /= 2;
            gen *new_st = new gen[size];

            for(int i=0; i<=top; i++){
                new_st[i] = st[i];
            }

            delete st;
            st = new_st;
        }
        void push(gen val){

            if(top==size-1){
                increase_array_size();
                cout<<"Now size="<<size<<endl;
            }

            this->top++;
            st[top] = val;

        }

        gen pop(){
            if(top==-1){
                cout<<"Stack is Empty/Underflow."<<endl;
                return gen();
            }

            gen temp = st[top];
            top--;
            if(top == (size - 1)/2){
                decrease_array_size();
                cout<<"Now size="<<size<<endl;
            }
            return temp;

        }

        gen peek(){
            if(top==-1){
                cout<<"Stack is Empty/Underflow."<<endl;
                return gen();
            }

            return st[top];
        }

        int traverse(){
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
};


class infix_to_postfix
{
private:
    stack<char> st;
    string expression = "";
    int len;
    char item;
public:
    infix_to_postfix(/* args */){
    }

    ~infix_to_postfix(){
    }

    int get_precedence(char symbol){
        switch (symbol){
            case '^':
                return 3;
                break;
            case '*':
            case '/':
                return 2;
            case '+':
            case '-':
                return 1;
                break;
            
            default:
                return 0;
                break;
        }
    }

    char associativity(char c) {
        if (c == '^')
            return 'R';
        return 'L'; // Default to left-associative
    }

    string convert(string str){
        len = str.length();
        for(int i=0; i<len; i++){
            item = str[i];
            if(item == '('){
                // insert in stack
                st.push(item);
            }else if(item == ')'){
                // pop from stack until '('

                while(st.top>-1 && st.peek()!='('){
                    expression += st.pop();
                }
                st.pop();

            }else if( (item=='^') || (item=='*') || (item=='/') || (item=='+') || (item=='-') ){

                // 1. check precedence is lower then top of the stack then pop from stack and check again new top
                //2.  check precedence is equal to top of the stack then use associativity rule
                    // associativity rule: 
                    // L to R then pop from stack and push new item
                    // R to L then push new item
                // 3. check precedence is higher then top of the stack then push it on the stack
                while(
                    st.top>-1 && 
                    (
                        (
                            get_precedence(item)<get_precedence(st.peek()) || 
                            get_precedence(item)==get_precedence(st.peek())
                        ) && associativity(item) == 'L'
                    )
                ){

                    expression += st.pop();
                }
                st.push(item);

            }else{
                // pop all from stack
                expression += item;
            }
        }

        return expression;
    }
};



int main(int argc, char const *argv[])
{
    string infix;
    cout<<"Enter Your Infix Expression: ";
    cin>>infix;

    infix_to_postfix infixToPost;
    string expression = infixToPost.convert(infix);
    cout<<expression;


    

    return 0;
}
