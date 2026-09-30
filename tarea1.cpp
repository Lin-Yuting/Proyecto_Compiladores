#include <iostream>
using namespace std;

class Stack{
    private:
        int size;
        int top;
        int *stack_arr;

    public:
        Stack (){
            this->size = sizeof(stack_arr);
            this->top = -1;
            this->stack_arr = new int[size];
        }

        ~Stack(){
            delete[] stack_arr;
        }

        void isEmpty(){
            if (top < 0){
                cout << "Stack vacio" << endl;
            } else{
                cout << "Stack tiene elementos" << endl;
            }
        }

        void topElement(){
            if (top < 0){
                cout << "Stack vacio" << endl;
                return;
            } else{
                cout << "El elemento al top del stack es: " << stack_arr[top] << endl;
            }
        }

        void push(int newvalue){
            top = top + 1;
            stack_arr[top] = newvalue;
        }
            
        void pop(){
            if (top < 0){
                cout << "Stack vacio" << endl;
                return;
            } else{
                top = top - 1;
            }   
        }

        void display(){
            if (top < 0){
                cout << "Stack vacio" << endl;
                return;
            } else{
                cout << "Los elementos del stack son: ";
                for (int i = 0; i <= top; i++){
                    cout << stack_arr[i] << ", ";
                }
                cout << endl;
            }
        }
    
};

class Queue{
    private:
        int actual_size;
        int max_size;
        int front;
        int rear;
        int *queue_arr;

    public:
        Queue(int max_size = 10){
            this->max_size = max_size;
            this->front = -1;
            this->rear = -1;
            this->queue_arr = new int[max_size];
        }
    
        ~Queue(){
            delete[] queue_arr;
        }

        void isEmpty(){
            if (front < 0){
                cout << "Queue vacio" << endl;
            }
            else{
                cout << "Queue tiene elementos" << endl;
            }
        }

        void isFull(){
            if (rear >= max_size - 1){
                cout << "Queue esta lleno, no se puede agregar mas" << endl;
            }
            else{
                cout << "Queue tiene espacio" << endl;
            }
        }

        void frontElement(){
            if (front < 0 || front > rear){
                cout << "Queue vacio" << endl;
                return;
            }
            else{
                cout << "El elemento al frente del queue es: " << queue_arr[front] << endl;
            }
        }

        void rearElement(){
            if (rear < 0 || rear < front){
                cout << "Queue vacio" << endl;
                return;
            }
            else{
                cout << "El elemento al final del queue es: " << queue_arr[rear] << endl;
            }
        }

        void enqueue(int newvalue){
            if (rear >= max_size - 1){
                cout << "Queue esta lleno, no se puede agregar mas" << endl;
                return;
            }
            else{
                rear = rear + 1;
                queue_arr[rear] = newvalue;
                if (front == -1){
                    front = 0;
                }
            }
        }

        void dequeue(){
            if (front < 0 || front > rear){
                cout << "Queue vacio" << endl;
                return;
            }
            else{
                front = front + 1;
            }
        }

        void display(){
            if (front < 0 || front > rear){
                cout << "Queue vacio" << endl;
                return;
            }
            else{
                cout << "Los elementos del queue son: ";
                for (int i = front; i <= rear; i++){
                    cout << queue_arr[i] << ", ";
                }
                cout << endl;
            }
        }
};

class Diccionario {
private:
    int actual_size;
    int max_size;
    int* valores;
    bool* ocupado;      // ocupado[k] == true si la clave k tiene un valor

public:
    explicit Diccionario(int capacidad = 5)
        : actual_size(0), max_size(capacidad),
          valores(new int[capacidad]()), ocupado(new bool[capacidad]()) {}

    ~Diccionario() {
        delete[] valores;
        delete[] ocupado;
    }

    // Prohibir copias (punto 6)
    Diccionario(const Diccionario&) = delete;
    Diccionario& operator=(const Diccionario&) = delete;

    void add(int key, int value) {
        if (key < 0 || key >= max_size) {
            std::cout << "Error: la clave " << key << " esta fuera de rango (Max: " << max_size - 1 << ")." << std::endl;
            return;
        }
        if (!ocupado[key]) {        // solo cuenta si la clave es nueva
            ocupado[key] = true;
            actual_size++;
        }
        valores[key] = value;       // si ya existia, solo se actualiza
    }

    void remove(int key) {
        if (key < 0 || key >= max_size || !ocupado[key]) {
            std::cout << "Error: la clave " << key << " no existe." << std::endl;
            return;
        }
        ocupado[key] = false;
        actual_size--;
    }

    void display() const {
        std::cout << "Los elementos del diccionario son: ";
        if (actual_size == 0) {
            std::cout << "(vacio)";
        }
        for (int i = 0; i < max_size; i++) {    // recorre TODO el arreglo
            if (ocupado[i]) {
                std::cout << "{" << i << ": " << valores[i] << "} ";
            }
        }
        std::cout << std::endl;
    }
};


int main(){
    // Casos de pruebas para stack
    Stack stack;

    // Hacer el display del stack vacio: Stack vacio
    stack.display();

    // Hacer el pop del stack vacio: : Stack vacio
    stack.pop();

    // Hacer el push de 5 elementos al stack, 
    // combinados de numeros enteros, decimales y letras
    stack.push(1);          // Elemento 1
    stack.display();
    stack.push(2);    // Elemento 2
    stack.display();
    stack.push(3);       // Elemento 3
    stack.display();
    stack.push(41);       // Elemento 4
    stack.display();
    stack.push(5);          // Elemento 5
    stack.display();
    stack.topElement();

    // Hacer el pop del stack (5 -> 4 elementos)
    stack.pop();
    stack.display();

    cout << "----------------------------------" << endl;

    // Casos de pruebas para fila
    Queue queue(5);

    queue.isEmpty();
    queue.isFull();

    queue.enqueue(1);
    queue.display();
    queue.enqueue(2);
    queue.display();
    queue.enqueue(3);
    queue.display();
    queue.enqueue(4);
    queue.display();
    queue.enqueue(5);
    queue.display();
    queue.enqueue(6);
    queue.frontElement();
    queue.rearElement();

    queue.isEmpty();
    queue.isFull();

    queue.dequeue();
    queue.display();

    cout << "----------------------------------" << endl;

    // Casos de pruebas para diccionario
    Diccionario diccionario;

    diccionario.add(1, 10);
    diccionario.display();
    diccionario.add(2, 20);
    diccionario.display();
    diccionario.add(3, 30);
    diccionario.display();
    diccionario.add(4, 40);
    diccionario.display();
    diccionario.add(5, 50);
    diccionario.display();
    diccionario.add(6, 60);
    diccionario.display();

    diccionario.remove(2);
    diccionario.display();

    // Indicar que el programa termino 
    return 0;
}