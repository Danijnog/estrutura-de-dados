#include "unity/unity.h"
#include "../include/identificaExp.h"

void setUp() {}; // setup do unity

void tearDown() {}; // isso é executado por padrão depois dos testes, por exemplo limpar espaço de memória

void test_identificaExpInfixa() {
    char *exp = "1 + 2 * 3";
    TEST_ASSERT_EQUAL(1, identificaExpInfixa(exp));
}

int main(void) {
    UNITY_BEGIN(); //inicializa o unity
    RUN_TEST(test_identificaExpInfixa); //macro que roda os testes
    return UNITY_END();
}