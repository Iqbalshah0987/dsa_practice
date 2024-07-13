#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

template <typename gen> class stack {
private:
public:
  int top, size;
  gen *st;
  stack() {
    top = -1;
    size = 1;
    st = new gen[size];
  }
  void increase_array_size() {
    size *= 2;
    gen *new_st = new gen[size];

    for (int i = 0; i <= top; i++) {
      new_st[i] = st[i];
    }

    delete st;
    st = new_st;
  }
  void decrease_array_size() {
    size /= 2;
    gen *new_st = new gen[size];

    for (int i = 0; i <= top; i++) {
      new_st[i] = st[i];
    }

    delete st;
    st = new_st;
  }
  void push(gen val) {

    if (top == size - 1) {
      increase_array_size();
      // cout << "Now size=" << size << endl;
    }

    this->top++;
    st[top] = val;
  }

  gen pop() {
    if (isEmpty()) {
      cout << "Stack is Empty/Underflow." << endl;
      return gen();
    }

    gen temp = st[top];
    top--;
    if (top == (size - 1) / 2) {
      decrease_array_size();
      // cout << "Now size=" << size << endl;
    }
    return temp;
  }

  gen peek() {
    if (isEmpty()) {
      cout << "Stack is Empty/Underflow." << endl;
      return gen();
    }

    return st[top];
  }

  bool isEmpty() { return top == -1; }

  gen traverse() {
    if (isEmpty()) {
      cout << "Stack is Empty/Underflow." << endl;
      return gen();
    }
    cout << "All Elements are: ";
    for (int i = top; i >= 0; i--) {
      cout << st[i] << " ";
    }
    cout << endl;
    return gen();
  }
};

class infix_to_prefix {
private:
  stack<char> st;
  string expression = "";
  int len;
  char item;

public:
  infix_to_prefix(/* args */) {}

  ~infix_to_prefix() {}

  int get_precedence(char symbol) {
    switch (symbol) {
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

  bool is_operator(char c) {
    return (c == '^' || c == '*' || c == '/' || c == '+' || c == '-');
  }

  bool has_lower_precedence(char top, char current) {
    int top_precedence = get_precedence(top);
    int current_precedence = get_precedence(current);
    if (top_precedence > current_precedence) {
      return true;
    }
    if (top_precedence == current_precedence) {
      return associativity(current) == 'L';
    }
    return false;
  }

  string convert(string str) {
    len = str.length();
    for (int i = 0; i < len; i++) {
      item = str[i];
      if (item == '(') {
        // insert in stack
        st.push(item);
      } else if (item == ')') {
        // pop from stack until '('

        while (!st.isEmpty() && st.peek() != '(') {
          expression += st.pop();
        }
        st.pop();

      } else if (is_operator(item)) {

        // 1. check precedence if current element is lower then top of the stack
        // then pop from stack and check again new top
        // 2.  check precedence if current element is equal to top of the stack
        // then use associativity rule associativity rule: L to R then pop from
        // stack and push new item R to L then push new item
        // 3. check precedence is higher then top of the stack then push it on
        // the stack
        while (!st.isEmpty() && has_lower_precedence(st.peek(), item)) {

          expression += st.pop();
        }
        st.push(item);
      } else {
        expression += item;
      }
    }
    // pop all from stack
    while (!st.isEmpty() && st.peek() != '(') {
      expression += st.pop();
    }

    return expression;
  }

  void replace_parentheses(string &str) {
    for (char &c : str) {
      if (c == '(') {
        c = ')';
      } else if (c == ')') {
        c = '(';
      }
    }
  }

  string convert_pre(string str) {
    reverse(str.begin(), str.end());
    // cout << "before replace: " << str << endl;
    replace_parentheses(str);
    cout << "before: " << str << endl;
    str = convert(str);
    cout << "after: " << str << endl;
    reverse(str.begin(), str.end());
    return str;
  }
};

int main(int argc, char const *argv[]) {
  string infix;
  cout << "Enter Your Infix Expression: ";
  cin >> infix;

  infix_to_prefix infixToPre;
  string expression = infixToPre.convert_pre(infix);
  cout << "Prefix Expression is: " << expression << endl;

  return 0;
}
