#include <iostream>
using namespace std;


// Una clase para representar un stack (pila) de enteros
// Donde los elemento se agregan y se eliminan del mismo lado, que es el top de la pila
// Los atributos de la clase son privados: tamao maximo, el top, y el arreglo de stack
// Los metodos son publicos para que permiten interactuar con el stack:
// - isEmpty: indica si el stack esta vacio
// - topElement: indica el elemento al top del stack
// - push: agrega un elemento al top del stack
// - pop: elimina el elemento al top del stack
// - display: muestra los elementos del stack
class Stack{
    private:
        int max_size;
        int top;
        int *stack_arr;

    public:
        Stack (int max_size = 5){
            this->max_size = max_size;
            this->top = -1;
            this->stack_arr = new int[max_size];
        }

        ~Stack(){
            delete[] stack_arr;
        }

        Stack(const Stack&) = delete;
        Stack& operator=(const Stack&) = delete;

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
            if (top >= max_size - 1){
                cout << "Stack esta lleno, no se puede agregar mas" << endl;
                return;
            }
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


// Una clase para representar una queue (fila) de enteros
// Donde los elementos se agregan al final de la fila (rear) y se eliminan del frente de la fila (front)
// Los atributos de la clase son privados: tamao maximo, el tamao actual, el frente, el final, y el arreglo de queue
// Los metodos son publicos para que permiten interactuar con la queue:
// - isEmpty: indica si la queue esta vacia
// - isFull: indica si la queue esta llena
// - frontElement: indica el elemento al frente de la queue
// - rearElement: indica el elemento al final de la queue
// - enqueue: agrega un elemento al final de la queue
// - dequeue: elimina el elemento al frente de la queue
// - display: muestra los elementos de la queue
class Queue{
    private:
        int max_size;
        int actual_size;
        int front;
        int rear;
        int *queue_arr;

    public:
        Queue(int max_size = 5){
            this->max_size = max_size;
            this->actual_size = 0;
            this->front = -1;
            this->rear = -1;
            this->queue_arr = new int[max_size];
        }
    
        ~Queue(){
            delete[] queue_arr;
        }

        Queue(const Queue&) = delete;
        Queue& operator=(const Queue&) = delete;

        void isEmpty(){
            if (actual_size == 0){
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
            if (actual_size == 0){
                cout << "Queue vacio" << endl;
                return;
            }
            else{
                cout << "El elemento al frente del queue es: " << queue_arr[front] << endl;
            }
        }

        void rearElement(){
            if (actual_size == 0){
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
                actual_size = actual_size + 1;
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
                actual_size = actual_size - 1;
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


// Una clase para representar un diccionario (mapa) de enteros
// Donde los elementos se agregan y se eliminan por clave (key) y valor (value)
// Los atributos de la clase son privados: tamao maximo, el tamao actual, el arreglo de valores, y un arreglo de booleanos que indica si una clave esta ocupada
// Los metodos son publicos para que permiten interactuar con el diccionario:
// - add: agrega un elemento al diccionario
// - remove: elimina un elemento del diccionario
// - display: muestra los elementos del diccionario
class Diccionario {
private:
    int actual_size;
    int max_size;
    int* valores;
    bool* ocupado;      // ocupado[k] == true si la clave k tiene un valor

public:
    explicit Diccionario(int capacidad = 6)
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

    // display y pop del stack vacio: Stack vacio
    stack.display();
    stack.pop();

    // push de 6 elementos al stack, 
    stack.push(1);         
    stack.display();
    stack.push(21);         
    stack.display();
    stack.push(32);         
    stack.display();
    stack.push(43);       
    stack.display();
    stack.push(54);         
    stack.display();
    stack.push(65);         // Elemento 6, pero debe de indicar que esta lleno
    stack.display();
    stack.topElement();

    // pop del stack (5 -> 4 elementos)
    stack.pop();
    stack.display();

    cout << "----------------------------------" << endl;

    // Casos de pruebas para fila
    Queue queue(5);

    // display y dequeue del queue vacio: Queue vacio
    queue.display();
    queue.dequeue();

    // verificar si esta vacio o lleno de queue sin elementos
    queue.isEmpty();
    queue.isFull();

    // enqueue de 6 elementos al queue
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
    queue.enqueue(6);       // Elemento 6, pero debe de indicar que esta llena
    queue.frontElement();
    queue.rearElement();

    // verificar si esta vacio o lleno de queue con elementos
    queue.isEmpty();
    queue.isFull();

    // dequeue (5 -> 4 elementos)
    queue.dequeue();
    queue.display();

    cout << "----------------------------------" << endl;

    // Casos de pruebas para diccionario
    Diccionario diccionario;

    // remove de un elemento que no existe
    diccionario.remove(2);
    //display del diccionario vacio
    diccionario.display();

    // add de 6 elementos al diccionario
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
    diccionario.add(6, 60);     // fuera de rango
    diccionario.display();

    // remove de un elemento que si existe
    diccionario.remove(2);
    diccionario.display();

    // Indicar que el programa termino 
    return 0;
}