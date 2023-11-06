#include <iostream>
using namespace std;

class Stack {
    int top;
    int maxSize;
    int *stack;

public:
    Stack(int s = 20); 
    ~Stack(); 

    void push(int); // fonction pour ajouter les ele
    int pop(); // pour supprimer les ele 

    int size(); //  pour obtenir le taille 
    bool isEmpty(); //  pour verifier  pile  vide
    bool isFull(); //  pour verifier pile pleine

    Stack& operator <<(int); 
    Stack& operator >>(int&); 

    // Operateurs ++ et -- sont implementes en utilisant isEmpty et isFull
};

Stack::Stack(int s) {
    maxSize = s;
    stack = new int[maxSize];
    top = -1;
}

Stack::~Stack() {
    delete[] stack;
}

void Stack::push(int num) {
    if (isFull()) {
        throw "La pile est pleine";
    }
    stack[++top] = num;
}

int Stack::pop() {
    if (isEmpty()) {
        throw "La pile est vide";
    }
    return stack[top--];
}

int Stack::size() {
    return top + 1;
}

bool Stack::isEmpty() {
    return top == -1;
}

bool Stack::isFull() {
    return top == maxSize - 1;
}

Stack& Stack::operator <<(int num) {
    push(num);
    return *this;
}

Stack& Stack::operator >>(int& num) {
    if (!isEmpty()) {
        num = stack[top];
        stack[top--] = 0;
    }
    return *this;
}

int main() {
   
  
    Stack p(4);

    int n1 = 10, n2 = 20, n3 = 30 , n4 = 40  ;

    p << n1 << n2 << n3 << n4  ;
    cout << "taille de la pile : " << p.size() << endl;

    p >> n1 >> n2;
    cout << "Valeur  n1 : " << n1 << endl;
    cout << "Valeur  n2 : " << n2 << endl;

    try {
        p >> n3 >> n4 ;
        cout << "Valeur  n3 : " << n3 << endl;
        cout << "Valeur  n4 : " << n4 << endl;
     

    } catch (const char* msg) {
        cout << msg << endl;
    }

    return 0;
}
