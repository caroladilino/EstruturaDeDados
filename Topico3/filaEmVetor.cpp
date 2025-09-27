// Copyright [2025] Carolina Monteiro Quintanilha Adilino
#ifndef STRUCTURES_ARRAY_QUEUE_H
#define STRUCTURES_ARRAY_QUEUE_H

#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ Exceptions

namespace structures {

template<typename T>
//! classe ArrayQueue
class ArrayQueue {
 public:
    //! construtor padrao
    ArrayQueue();
    //! construtor com parametro
    explicit ArrayQueue(std::size_t max);
    //! destrutor padrao
    ~ArrayQueue();
    //! metodo enfileirar
    void enqueue(const T& data);
    //! metodo desenfileirar
    T dequeue();
    //! metodo retorna o ultimo
    T& back();
    //! metodo limpa a fila
    void clear();
    //! metodo retorna tamanho atual
    std::size_t size();
    //! metodo retorna tamanho maximo
    std::size_t max_size();
    //! metodo verifica se vazio
    bool empty();
    //! metodo verifica se esta cheio
    bool full();

 private:
    T* contents;
    std::size_t size_;
    std::size_t max_size_;
    int begin_;  // indice do inicio (para fila circular)
    int end_;  // indice do fim (para fila circular)
    static const auto DEFAULT_SIZE = 10u;
};

}  // namespace structures

#endif

//! construtor padrao
template<typename T>
structures::ArrayQueue<T>::ArrayQueue() {
    max_size_ = DEFAULT_SIZE;
    contents = new T[max_size_];
    begin_ = 0;
    end_ = -1;
    size_ = 0;
}

//! construtor com parametro
template<typename T>
structures::ArrayQueue<T>::ArrayQueue(std::size_t max) {
    max_size_ = max;
    contents = new T[max_size_];
    begin_ = 0;
    end_ = -1;
    size_ = 0;
}

//! destrutor padrao
template<typename T>
structures::ArrayQueue<T>::~ArrayQueue() {
    delete [] contents;
}

//! metodo enfileirar
template<typename T>
void structures::ArrayQueue<T>::enqueue(const T& data) {
    if (!full()) {
        end_ = (end_ + 1) % max_size();
        contents[end_] = data;
        size_++;
    } else {
        throw std::out_of_range("fora");
    }
}
//! metodo desenfileirar
template<typename T>
T structures::ArrayQueue<T>::dequeue() {
    T valor = contents[begin_];
    if (empty()) {
        throw std::out_of_range("fora");
    } else {
        for (int i=0; i < end_ ; i++) {
            contents[i] = contents[i+1];
        }
    end_--;
    size_--;}
    return valor;
}
//! metodo retorna o ultimo
template<typename T>
T& structures::ArrayQueue<T>::back() {
    if (empty()) {
        throw std::out_of_range("fora");
    } else {
    return contents[end_];
    }
}
//! metodo limpa a fila
template<typename T>
void structures::ArrayQueue<T>::clear() {
    size_ = 0;
    begin_ = 0;
    end_ = -1;
}
//! metodo retorna tamanho atual
template<typename T>
std::size_t structures::ArrayQueue<T>::size() {
    int valor = size_;
    return valor;
}
//! metodo retorna tamanho maximo
template<typename T>
std::size_t structures::ArrayQueue<T>::max_size() {
    return max_size_;
}
//! metodo verifica se vazio
template<typename T>
bool structures::ArrayQueue<T>::empty() {
     bool vazio;
    if (size_ == 0) {
        vazio = true;
    } else {
        vazio = false;
    }
    return vazio;
}
//! metodo verifica se esta cheio
template<typename T>
bool structures::ArrayQueue<T>::full() {
    bool valor;
    if (size_ == max_size_) {
        valor = true;
    } else {
        valor = false;
    }
    return valor;
}
