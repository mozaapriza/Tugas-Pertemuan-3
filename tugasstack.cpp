#include <iostream>
#include <string>
using namespace std;

#define MAX 20

struct Stack {
    int top;
    char data[MAX];
};

void initStack(Stack &s) {
    s.top = -1;
}

bool isEmpty(Stack &s) {
    return s.top == -1;
}

bool isFull(Stack &s) {
    return s.top == MAX - 1;
}

void push(Stack &s, char c) {
    if (isFull(s)) {
        cout << "stack sudah penuh" << endl;
    } else {
        s.top++;
        s.data[s.top] = c;
    }
}

char pop(Stack &s) {
    if (isEmpty(s)) {
        cout << "stack kosong!" << endl;
        return '\0';
    } else {
        char c = s.data[s.top];
        s.top--;
        return c;
    }
}

int main() {
    Stack s;
    initStack(s);
    
    string kata;
    cout << "masukkan kata: ";
    cin >> kata;

    for (int i = 0; i < kata.length(); i++) {
        push(s, kata[i]);
    }

    string reverseKata = "";
    while (!isEmpty(s)) {
        reverseKata += pop(s);
    }

    cout << "hasil kata setelah dibalik: " << reverseKata << endl;

    return 0;
}