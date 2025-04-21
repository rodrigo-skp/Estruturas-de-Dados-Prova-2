#include "../include/posfixa.hpp"

#include <gtest/gtest.h>

#include "../include/fila.hpp"
#include "../include/pilha.hpp"

// Função auxiliar para construir uma Fila<char> a partir de uma string
Fila<char> construir_fila(const std::string& expressao) {
  Fila<char> fila(expressao.size());
  for (char c : expressao) {
    if (c != ' ') {  // Ignora espaços se quiser expressões mais legíveis
      fila.enfileirar(c);
    }
  }
  return std::move(fila);
}

// ---------- TESTES ----------

// 5 2 - => 5 - 2 = 3
TEST(PosfixaTest, SubtracaoSimples) {
  auto fila = construir_fila("52-");
  EXPECT_EQ(posfixa(fila), 3);
}

// 6 3 * => 6 * 3 = 18
TEST(PosfixaTest, MultiplicacaoSimples) {
  auto fila = construir_fila("63*");
  EXPECT_EQ(posfixa(fila), 18);
}

// 8 2 / => 8 / 2 = 4
TEST(PosfixaTest, DivisaoSimples) {
  auto fila = construir_fila("82/");
  EXPECT_EQ(posfixa(fila), 4);
}

// 7 2 + 3 * => (7 + 2) * 3 = 27
TEST(PosfixaTest, ExpressaoComposta) {
  auto fila = construir_fila("72+3*");
  EXPECT_EQ(posfixa(fila), 27);
}

// 9 5 2 + * => 9 * (5 + 2) = 63
TEST(PosfixaTest, ExpressaoAninhada) {
  auto fila = construir_fila("952+*");
  EXPECT_EQ(posfixa(fila), 63);
}

// Divisão por zero deve lançar exceção
TEST(PosfixaTest, DivisaoPorZero) {
  auto fila = construir_fila("50/0");
  EXPECT_THROW(posfixa(fila), std::runtime_error);
}

// Expressão malformada: operador sem operandos suficientes
TEST(PosfixaTest, OperadorSemOperandos) {
  auto fila = construir_fila("+");
  EXPECT_THROW(posfixa(fila), std::runtime_error);
}

// Expressão malformada: operandos em excesso
TEST(PosfixaTest, OperandosEmExcesso) {
  auto fila = construir_fila("34");
  EXPECT_THROW(posfixa(fila), std::runtime_error);
}

// Operador inválido
TEST(PosfixaTest, OperadorInvalido) {
  auto fila = construir_fila("34&");
  EXPECT_THROW(posfixa(fila), std::runtime_error);
}
