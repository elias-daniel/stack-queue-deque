#include <iostream>

using namespace std;

// Node to store an item in a linked-list-based stack
class StackNode {
public:
int value;
StackNode* next;
StackNode(int dataValue, StackNode* nextNode) {
value = dataValue;
next = nextNode;
}
};
// Top to bottom or front to end is read from left to right in the test output
class Stack {
    private:
    StackNode* top;
    public:
    Stack() {
        top = nullptr;
    }

   void Push(int newData){
   
    top = new StackNode(newData, top);
    cout << "Push: " << newData << "\n";

    }

    bool Pop() {
        if(top == nullptr){
            cout << "Pop failed.\n";
            return false;
        }
        else{
            StackNode* poppedNode = top;
            top = top->next;
            cout << "Pop: " << poppedNode->value << "\n";
            delete poppedNode;
            return true;
        }
    }
    void print(){
        if(top == nullptr){
            cout << "The Stack linked list final output: no values " << "\n\n";
        }
        else{
            StackNode* current = top;
            cout << "Stack linked list final output: ";
            while(current != nullptr){
                cout << current->value << " ";
                current = current->next;
            }
            cout << "\n\n";
        }
    }
};



class ArrayStack {
    private:
    //for an unbounded array we don't need a maxlength since the allocation size equals it
    int allocationSize;
    int* array;
    //The length in terms of the stack (amount of numbers)
    int length;
    //index equals length - 1 since an index starts at 0 that is decremented by one from the stack length
    
    

    public:
    ArrayStack(){
      allocationSize = 1;
      length = 0;
      array = new int[allocationSize];

    }
    void Resize(){
        allocationSize *= 2;
        int *newArray = new int[allocationSize];
        for(int i = 0; i < length; ++i) {
            newArray[i] = array[i];
        }
        delete[] array;  
        array = newArray; 
        

    }
    
    void push(int item){
        if(length == allocationSize){
            Resize();
        }
        array[length] = item;
        cout << "Push: " << item << "\n";
        length++;
    }
    bool pop(){
        if(length <= 0){
            cout << "Pop failed.\n";
            return false;
        }
        else{
            //The items gets ignored in terms of the stack and can be changed with the push function
            cout << "Pop: " << array[length - 1] << "\n";
            --length;
            return true;
        }

    }

    void print(){
        //The array and the test output for the stack will be inversed
        if(length == 0){
            cout << "The Stack Array final output: no values\n\n";
        }
        else{
            cout << "Stack Array final output: ";
        for (int i = length - 1; i >= 0; --i) {
                    cout << array[i] << " ";
                }
            cout << "\n\n";
        }
    }

};

class QueueNode {
public:
    int value;
    QueueNode* next;
    QueueNode(int dataValue, QueueNode* nextNode) {
        value = dataValue;
        next = nextNode;
    }
};

class Queue {
private:
    QueueNode* front; 
    QueueNode* end;
    QueueNode* newNode;

public:
    Queue() {
        front = nullptr;
        end = nullptr;
    }
    //Similar to the append function in the monopoly linked list
    void Push(int newData) {

        cout << "Push: " << newData << "\n";

        if(front == nullptr){
            front = new QueueNode(newData, front);
            end = front;
        }
    
        else{
            newNode = new QueueNode(newData, nullptr);
            end->next = newNode;
            end = end->next;            
        }
        
    }
    // I am using the remove function in my stack since the front and the order of the array is similar
    bool Pop() {
        if (front == nullptr) {
        cout << "Pop failed.\n";          
        return false;
        }

        QueueNode* poppedNode = front;
        front = front->next;
    //AI Disclosure: Used Chatgpt to fix the pop function with the logic below for the nullptr
        if (front == nullptr) {
            end = nullptr;
        }
        cout << "Pop: " << poppedNode->value << "\n";
        delete poppedNode;
        return true;
    }

    void print(){
        if(front == nullptr){
            cout << "The Queue Linked list final output: no values" << "\n\n";
        }
        else{
            QueueNode* current = front;
            cout << "Queue Linked list final output: ";
            while(current != nullptr){
                cout << current->value << " ";
                current = current->next;
            }
            cout << "\n\n";
        }
    }

};

class ArrayQueue {
    private:
    //for an unbounded array we don't need a maxlength since the allocation size equals it
    int allocationSize;
    int* array;
    //The length in terms of the stack (amount of numbers)
    int length;
    //index equals length - 1 since an index starts at 0 that is decremented by one from the stack length
    
    

    public:
    ArrayQueue(){
      allocationSize = 1;
      length = 0;
      array = new int[allocationSize];

    }
    void Resize(){
        allocationSize *= 2;
        int *newArray = new int[allocationSize];
        for(int i = 0; i < length; ++i) {
            newArray[i] = array[i];
        }
        delete[] array;  
        array = newArray; 
        

    }
    void push(int item){
        if(length == allocationSize){
            Resize();
        }
        array[length] = item;
        cout << "Push: " << item << "\n";
        length++;
    }
    //Remove the first element and then shift all the other elements to the left
    bool pop(){
        if(length <= 0){
            cout << "Pop failed.\n";
            return false;
        }
        else{
            cout << "Pop: " << array[0] << "\n";
            int index = length - 1;
            for(int i = 0; i < index; ++i){
                array[i] = array[i + 1];
            }
            length--;
            return true;

        }
 
    }

    void print(){

        if(length == 0){
            cout << "The Queue Array final output: no values\n\n";
        }
        else{
            cout << "Queue Array Final output: ";
            for(int i = 0; i <= length - 1; ++i){
                cout << array[i] << " ";
            }
            cout << "\n\n";
        }
    }

}; 

class DequeNode {
public:
    int value;
    DequeNode* next;
    DequeNode* prev;
    DequeNode(int dataValue, DequeNode* nextNode, DequeNode* prevNode) {
        value = dataValue;
        next = nextNode;
        prev = prevNode;
    }
};


class Deque {
private:
    DequeNode* front; 
    DequeNode* end;
    DequeNode* newNode;

public:
    Deque() {
        front = nullptr;
        end = nullptr;
    }
    //A queue pushes back and removes from the front, we can reuse the methods

    //Similar to the append function in the monopoly linked list
    void Push_back(int newData) {

        cout << "Push back: " << newData << "\n";

        if(front == nullptr){
            front = new DequeNode(newData, nullptr, nullptr);
            end = front;
        }
    
        else{
            newNode = new DequeNode(newData, nullptr, nullptr);
            end->next = newNode;
            newNode->prev = end;
            end = newNode;
            
        }
        
        
    }
    //push front we can reuse the logic from the stack as we are working with the same linked list implementation
    void Push_front(int newData){

        cout << "Push front: " << newData << "\n";

        if(front == nullptr){
            front = new DequeNode(newData, nullptr, nullptr);
            end = front;
        }

        else{
            newNode = new DequeNode(newData, nullptr, nullptr);
            newNode->next = front;
            front->prev = newNode;
            front = newNode;

        }
    }
   
    bool Pop_front() {
        if (front == nullptr) {
            cout << "Pop failed.\n";
            return false;
        }

        DequeNode* poppedNode = front;
        front = front->next;
        if (front == nullptr) {
            end = nullptr;
        }
        else {
            front->prev = nullptr;
        }
        cout << "Pop Front: " << poppedNode->value << "\n";
        delete poppedNode;
        return true;
    }


    bool Pop_back() {
        //Zero nodes 
        if (front == nullptr) {
            cout << "Pop failed.\n";
            return false;
        }
        DequeNode* poppedNode = end; 
        //If there is one node than the prev node will be null
        if(end->prev == nullptr){
            front = nullptr;
            end = nullptr;
        }
        //when they're 2 or more nodes
        else{
             end->prev->next = nullptr;
             end = end->prev;
        }  
        cout << "Pop Back: " << poppedNode->value << "\n";
        delete poppedNode;
        return true;
    }

    void print(){
        if(front == nullptr){
            cout << "The Deque Linked list final output: no values" << "\n\n";
        }
        else{
            DequeNode* current = front;
            cout << "Deque Linked list final output: ";
            while(current != nullptr){
                cout << current->value << " ";
                current = current->next;
            }
            cout << "\n\n";
        }
    }
};

class ArrayDeque {
    private:
    //for an unbounded array we don't need a max length since the allocation size equals it
    int allocationSize;
    int* array;
    //The length in terms of the stack (amount of numbers)
    int length;
    //index equals length - 1 since an index starts at 0 that is decremented by one from the stack length
    
    

    public:
    ArrayDeque(){
      allocationSize = 1;
      length = 0;
      array = new int[allocationSize];

    }
    void Resize(){
        allocationSize *= 2;
        int *newArray = new int[allocationSize];
        for(int i = 0; i < length; ++i) {
            newArray[i] = array[i];
        }
        delete[] array;  
        array = newArray; 
        

    }
    void push_front(int item){
        int index = length - 1;
        if(length == allocationSize){
            Resize();
        }
        for(int i = index; i >= 0; --i){
            array[i + 1] = array[i];
        }
        array[0] = item;
        cout << "Push Front: " << item << "\n";
        length++;
    }
    void push_back(int item){
        if(length == allocationSize){
            Resize();
        }
        array[length] = item;
        cout << "Push Back: " << item << "\n";
        length++;
    }
    //Remove the first element and then shift all the other elements to the left
    bool pop_front(){
        
        if(length <= 0){
            cout << "Pop Front failed.\n";
            return false;
        }
        else{
            cout << "Pop Front: " << array[0] << "\n";
            int index = length - 1;
            for(int i = 0; i < index; ++i){
                array[i] = array[i + 1];
            }
            length--;
            return true;
        }
    }

    bool pop_back(){
        if(length <= 0){
            cout << "Pop Back failed.\n";
            return false;
        }
        else{
            
            cout << "Pop Back: " << array[length - 1] << "\n";
            length--;
            return true;
        }
    }

    void print(){

        if(length == 0){
            cout << "The Deque Array final output: no values\n\n";
        }
        else{
            cout << "Deque Array final output: ";
            for(int i = 0; i <= length - 1; ++i){
                cout << array[i] << " ";
            }
            cout << "\n\n";
        }
    }



}; 



int main(){
    
    cout << "Stack Linked List operations\n";
    Stack stackClass;
    stackClass.Push(5);
    stackClass.Push(4);
    stackClass.Pop();
    stackClass.Pop();
    stackClass.Push(3);
    stackClass.Push(2);
    stackClass.Push(1);
    stackClass.Push(0);
    stackClass.Pop();
    stackClass.Pop();
    stackClass.print();

    cout << "Stack Array operations\n";
    ArrayStack arrayStack;
    arrayStack.push(5);
    arrayStack.push(4);
    arrayStack.pop();
    arrayStack.pop();
    arrayStack.push(3);
    arrayStack.push(2);
    arrayStack.push(1);
    arrayStack.push(0);
    arrayStack.pop();
    arrayStack.pop();
    arrayStack.print();

    cout << "Queue Linked List operations\n";
    Queue queueClass;
    queueClass.Push(10);
    queueClass.Pop();
    queueClass.Push(20);
    queueClass.Pop();
    queueClass.Push(30);
    queueClass.Pop();
    queueClass.Push(40);
    queueClass.Pop();
    queueClass.Push(50);
    queueClass.Pop();
    queueClass.print();

    cout << "Queue Array operations\n";
    ArrayQueue arrayQueue;
    arrayQueue.push(10);
    arrayQueue.pop();
    arrayQueue.push(20);
    arrayQueue.pop();
    arrayQueue.push(30);
    arrayQueue.pop();
    arrayQueue.push(40);
    arrayQueue.pop();
    arrayQueue.push(50);
    arrayQueue.pop();
    arrayQueue.print();

    cout << "Deque Linked List operations\n";
    // AI Disclosure: Used Chatgpt to create the sequence for Deque
    Deque dequeClass;
    dequeClass.Push_back(-15);   
    dequeClass.Push_front(-25);  
    dequeClass.Push_back(-35);   
    dequeClass.Pop_front();      
    dequeClass.Push_front(-45);  
    dequeClass.Pop_back();       
    dequeClass.Push_back(-55);  
    dequeClass.Pop_front();      
    dequeClass.Push_front(-65);  
    dequeClass.Pop_back();       
    dequeClass.print();

    cout << "Deque Array operations\n";
    ArrayDeque arrayDeque;
    arrayDeque.push_back(-15);   
    arrayDeque.push_front(-25);  
    arrayDeque.push_back(-35);   
    arrayDeque.pop_front();      
    arrayDeque.push_front(-45);  
    arrayDeque.pop_back();       
    arrayDeque.push_back(-55);   
    arrayDeque.pop_front();      
    arrayDeque.push_front(-65);  
    arrayDeque.pop_back();       
    arrayDeque.pop_front();      
    arrayDeque.pop_back();       
    arrayDeque.pop_front();      
    arrayDeque.pop_back();      
    arrayDeque.print();          

    return 0;
    
}