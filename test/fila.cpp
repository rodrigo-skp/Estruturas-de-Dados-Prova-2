#include "../include/fila.hpp"

#include <gtest/gtest.h>

// Teste de construção da fila
TEST(FilaTest, TesteConstrutorFilaVazia) {
  Fila<int> fila(3);
  EXPECT_TRUE(fila.esta_vazia());
}

// Teste de enfileirar elementos
TEST(FilaTest, TesteEnfileirar) {
  Fila<int> fila(3);
  fila.enfileirar(10);
  fila.enfileirar(20);

  EXPECT_FALSE(fila.esta_vazia());
  EXPECT_EQ(fila.frente(), 10);
}

// Teste de enfileirar até encher
TEST(FilaTest, TesteFilaCheiaExcecao) {
  Fila<int> fila(2);
  fila.enfileirar(1);
  fila.enfileirar(2);

  EXPECT_THROW(fila.enfileirar(3), std::runtime_error);
}

// Teste de desenfileirar elementos na ordem correta
TEST(FilaTest, TesteDesenfileirar) {
  Fila<int> fila(3);
  fila.enfileirar(1);
  fila.enfileirar(2);
  fila.enfileirar(3);

  EXPECT_EQ(fila.desenfileirar(), 1);
  EXPECT_EQ(fila.desenfileirar(), 2);
  EXPECT_EQ(fila.desenfileirar(), 3);
  EXPECT_TRUE(fila.esta_vazia());
}

// Teste de exceção ao desenfileirar fila vazia
TEST(FilaTest, TesteDesenfileirarVazia) {
  Fila<int> fila(2);
  EXPECT_THROW(fila.desenfileirar(), std::runtime_error);
}

// Teste de acesso ao início da fila
TEST(FilaTest, TesteFrente) {
  Fila<int> fila(2);
  fila.enfileirar(42);
  EXPECT_EQ(fila.frente(), 42);
}

// Teste de exceção ao acessar frente de fila vazia
TEST(FilaTest, TesteFrenteVazia) {
  Fila<int> fila(2);
  EXPECT_THROW(fila.frente(), std::runtime_error);
}

// Teste se a fila mantém a ordem correta mesmo com operações mistas
TEST(FilaTest, TesteEnfileirarDesenfileirarAlternado) {
  Fila<int> fila(3);
  fila.enfileirar(1);
  EXPECT_EQ(fila.desenfileirar(), 1);

  fila.enfileirar(2);
  fila.enfileirar(3);
  EXPECT_EQ(fila.frente(), 2);

  fila.enfileirar(
      4);  // Deve funcionar se índice circular estiver bem implementado
  EXPECT_EQ(fila.desenfileirar(), 2);
  EXPECT_EQ(fila.desenfileirar(), 3);
  EXPECT_EQ(fila.desenfileirar(), 4);
  EXPECT_TRUE(fila.esta_vazia());
}

// Teste se a file reporta corretamente quando está cheia
TEST(FilaTest, TesteEstaCheia) {
  Fila<int> fila(2);  // capacidade 2

  EXPECT_FALSE(fila.esta_cheia());  // Deve estar vazia inicialmente

  fila.enfileirar(10);
  EXPECT_FALSE(fila.esta_cheia());  // Ainda não está cheia

  fila.enfileirar(20);
  EXPECT_TRUE(fila.esta_cheia());  // Agora deve estar cheia
}
