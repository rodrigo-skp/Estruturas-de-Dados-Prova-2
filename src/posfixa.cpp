#include "../include/posfixa.hpp"

int posfixa(Fila<char> &entrada) {
    
    Pilha<int> pilha(entrada.capacidade);

    while (!entrada.esta_vazia()) {
        char token = entrada.desenfileirar();

        if (std::isdigit(token)) {
            pilha.empilhar(token - '0');
        } else if (token == '+' || token == '-' || token == '*' || token == '/') {
            if (pilha.esta_vazia()) throw std::runtime_error("Faltam operandos");
            int b = pilha.desempilhar();
            if (pilha.esta_vazia()) throw std::runtime_error("Faltam operandos");
            int a = pilha.desempilhar();

            int resultado;
            switch (token) {
                case '+': resultado = a + b; break;
                case '-': resultado = a - b; break;
                case '*': resultado = a * b; break;
                case '/':
                    if (b == 0) throw std::runtime_error("Divisão por zero");
                    resultado = a / b;
                    break;
                default:
                    throw std::runtime_error("Operador invalido");
            }

            pilha.empilhar(resultado);
        } else if (token != ' ') {
            throw std::runtime_error("Caractere inválido na expressao");
        }
    }

    if (pilha.esta_vazia()) throw std::runtime_error("Expressão malformada");
    int resultado_final = pilha.desempilhar();
    if (!pilha.esta_vazia()) throw std::runtime_error("Operandos em excesso");

    return resultado_final;
}





