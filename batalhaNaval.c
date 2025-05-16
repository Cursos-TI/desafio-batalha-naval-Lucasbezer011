#include <stdio.h>

    // Desafio Batalha Naval - MateCheck
    // Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
    // Siga os comentários para implementar cada parte do desafio.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    #define TAM 10        // Tamanho do tabuleiro
    #define TAM_HAB 5     // Tamanho da matriz da habilidade (5x5)
    #define NAVIO 3       // Valor para navio
    #define AGUA 0        // Valor para água
    #define HABILIDADE 5  // Valor para área afetada por habilidade

    // Inicializa o tabuleiro com água (0)
    void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
        for (int i = 0; i < TAM; i++) {
            for (int j = 0; j < TAM; j++) {
                tabuleiro[i][j] = AGUA;
            }
        }
    }

    // Posiciona manualmente alguns navios (fixo para facilitar)
    void posicionarNavios(int tabuleiro[TAM][TAM]) {
        // Exemplo: 1 navio horizontal
        tabuleiro[2][2] = NAVIO;
        tabuleiro[2][3] = NAVIO;
        tabuleiro[2][4] = NAVIO;

        // 1 navio vertical
        tabuleiro[5][5] = NAVIO;
        tabuleiro[6][5] = NAVIO;
        tabuleiro[7][5] = NAVIO;
    }

    // Cria matriz da habilidade Cone (5x5)
    void criarCone(int habilidade[TAM_HAB][TAM_HAB]) {
        for (int i = 0; i < TAM_HAB; i++) {
            for (int j = 0; j < TAM_HAB; j++) {
                if (j >= 2 - i && j <= 2 + i) // Forma triangular
                    habilidade[i][j] = 1;
                else
                    habilidade[i][j] = 0;
            }
        }
    }

    // Cria matriz da habilidade Cruz (5x5)
    void criarCruz(int habilidade[TAM_HAB][TAM_HAB]) {
        for (int i = 0; i < TAM_HAB; i++) {
            for (int j = 0; j < TAM_HAB; j++) {
                if (i == 2 || j == 2) // Linha e coluna do meio
                    habilidade[i][j] = 1;
                else
                    habilidade[i][j] = 0;
            }
        }
    }

    // Cria matriz da habilidade Octaedro (losango 5x5)
    void criarOctaedro(int habilidade[TAM_HAB][TAM_HAB]) {
        for (int i = 0; i < TAM_HAB; i++) {
            for (int j = 0; j < TAM_HAB; j++) {
                if (abs(i - 2) + abs(j - 2) <= 2) // Distância de Manhattan
                    habilidade[i][j] = 1;
                else
                    habilidade[i][j] = 0;
            }
        }
    }

    // Aplica uma habilidade no tabuleiro (marca com 5)
    void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HAB][TAM_HAB], int linha, int coluna) {
        for (int i = 0; i < TAM_HAB; i++) {
            for (int j = 0; j < TAM_HAB; j++) {
                if (habilidade[i][j] == 1) {
                    int l = linha - TAM_HAB / 2 + i;
                    int c = coluna - TAM_HAB / 2 + j;

                    // Verifica se está dentro do tabuleiro
                    if (l >= 0 && l < TAM && c >= 0 && c < TAM && tabuleiro[l][c] == AGUA) {
                        tabuleiro[l][c] = HABILIDADE;
                    }
                }
            }
        }
    }

    // Mostra o tabuleiro no console com símbolos
    void mostrarTabuleiro(int tabuleiro[TAM][TAM]) {
        printf("\n=== TABULEIRO ===\n");
        for (int i = 0; i < TAM; i++) {
            for (int j = 0; j < TAM; j++) {
                if (tabuleiro[i][j] == AGUA)
                    printf("0 ");        // Água
                else if (tabuleiro[i][j] == NAVIO)
                    printf("1 ");        // Navio
                else if (tabuleiro[i][j] == HABILIDADE)
                    printf("2 ");        // Área da habilidade
            }
            printf("\n");
        }
    }

    int main() {
        int tabuleiro[TAM][TAM];
        int cone[TAM_HAB][TAM_HAB];
        int cruz[TAM_HAB][TAM_HAB];
        int octaedro[TAM_HAB][TAM_HAB];

        inicializarTabuleiro(tabuleiro);
        posicionarNavios(tabuleiro);

        criarCone(cone);
        criarCruz(cruz);
        criarOctaedro(octaedro);

        aplicarHabilidade(tabuleiro, cone, 1, 2);       // Ponto de origem do cone
        aplicarHabilidade(tabuleiro, cruz, 5, 5);       // Cruz no meio
        aplicarHabilidade(tabuleiro, octaedro, 8, 8);   // Octaedro no canto

        mostrarTabuleiro(tabuleiro);

        return 0;
}

