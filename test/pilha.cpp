#include "../include/pilha.hpp"

#include <gtest/gtest.h>

// Teste de inicialização
TEST(PilhaTest, TesteConstrutorVazio) {
  Pilha<int> pilha(5);  // Pilha com capacidade 5
  EXPECT_TRUE(
      pilha.esta_vazia());  // A pilha deve estar vazia após a construção
}

// Teste de empilhamento
TEST(PilhaTest, TesteEmpilhar) {
  Pilha<int> pilha(3);  // Pilha com capacidade 3
  pilha.empilhar(10);
  pilha.empilhar(20);
  pilha.empilhar(30);

  EXPECT_FALSE(pilha.esta_vazia());  // A pilha não deve estar vazia
  EXPECT_EQ(pilha.topo(), 30);       // O topo da pilha deve ser 30
}

// Teste de empilhamento quando a pilha está cheia
TEST(PilhaTest, TesteEmpilharCheia) {
  Pilha<int> pilha(2);  // Pilha com capacidade 2
  pilha.empilhar(10);
  pilha.empilhar(20);

  EXPECT_THROW(pilha.empilhar(30),
               std::runtime_error);  // Tentativa de empilhar na pilha cheia
                                     // deve lançar exceção
}

// Teste de desempilhamento
TEST(PilhaTest, TesteDesempilhar) {
  Pilha<int> pilha(3);  // Pilha com capacidade 3
  pilha.empilhar(10);
  pilha.empilhar(20);
  pilha.empilhar(30);

  EXPECT_EQ(pilha.desempilhar(), 30);  // O valor desempilhado deve ser 30
  EXPECT_EQ(pilha.desempilhar(), 20);  // O valor desempilhado deve ser 20
  EXPECT_EQ(pilha.desempilhar(), 10);  // O valor desempilhado deve ser 10
}

// Teste de desempilhamento em pilha vazia
TEST(PilhaTest, TesteDesempilharVazio) {
  Pilha<int> pilha(2);  // Pilha com capacidade 2

  EXPECT_THROW(
      pilha.desempilhar(),
      std::runtime_error);  // Desempilhar em pilha vazia deve lançar exceção
}

// Teste de topo
TEST(PilhaTest, TesteTopo) {
  Pilha<int> pilha(3);  // Pilha com capacidade 3
  pilha.empilhar(10);
  pilha.empilhar(20);

  EXPECT_EQ(pilha.topo(), 20);  // O topo da pilha deve ser 20
}

// Teste de topo em pilha vazia
TEST(PilhaTest, TesteTopoVazio) {
  Pilha<int> pilha(2);  // Pilha com capacidade 2

  EXPECT_THROW(
      pilha.topo(),
      std::runtime_error);  // Acesso ao topo em pilha vazia deve lançar exceção
}

// Teste de pilha cheia
TEST(PilhaTest, TestePilhaCheia) {
  Pilha<int> pilha(3);  // Pilha com capacidade 3
  pilha.empilhar(10);
  pilha.empilhar(20);
  pilha.empilhar(30);

  EXPECT_TRUE(pilha.esta_vazia() ==
              false);  // A pilha deve estar cheia após o empilhamento
}

// Teste se a pilha reporta corretamente quando está cheia
TEST(PilhaTest, TesteEstaCheia) {
  Pilha<int> pilha(2);  // capacidade 2

  EXPECT_FALSE(pilha.esta_cheia());  // Inicialmente, não deve estar cheia

  pilha.empilhar(1);
  EXPECT_FALSE(pilha.esta_cheia());  // Ainda não está cheia

  pilha.empilhar(2);
  EXPECT_TRUE(pilha.esta_cheia());  // Agora está cheia
}
