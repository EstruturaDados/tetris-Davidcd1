#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Desafio Tetris Stack
// Tema 3 - Integração de Fila e Pilha
// Este código inicial serve como base para o desenvolvimento do sistema de controle de peças.
// Use as instruções de cada nível para desenvolver o desafio.

#define MAX_FILA 5
#define MAX_PILHA 3

typedef struct{
    int id;
    char tipo;
} Peca;

typedef struct{
    Peca itens[MAX_FILA];
    int inicio;
    int fim;
    int total;
} Fila;

typedef struct{
    Peca dados[MAX_PILHA];
    int topo;
} Pilha;

// Fila
void inicializar_fila(Fila *f);
int fila_cheia(Fila *f);
int fila_vazia(Fila *f);
void mostrar_fila(Fila *f);
void enqueue(Fila *f, Peca p);
Peca dequeue(Fila *f);

// Auxiliar
void limparBuffer();

Peca gerarPeca();

// Menu
void exibir_menu();

int proximoId = 0;  // id global incremental

int main() {

    // 🧩 Nível Novato: Fila de Peças Futuras
    //
    // - Crie uma struct Peca com os campos: tipo (char) e id (int).
    // - Implemente uma fila circular com capacidade para 5 peças.
    // - Crie funções como inicializarFila(), enqueue(), dequeue(), filaCheia(), filaVazia().
    // - Cada peça deve ser gerada automaticamente com um tipo aleatório e id sequencial.
    // - Exiba a fila após cada ação com uma função mostrarFila().
    // - Use um menu com opções como:
    //      1 - Jogar peça (remover da frente)
    //      0 - Sair
    // - A cada remoção, insira uma nova peça ao final da fila.



    // 🧠 Nível Aventureiro: Adição da Pilha de Reserva
    //
    // - Implemente uma pilha linear com capacidade para 3 peças.
    // - Crie funções como inicializarPilha(), push(), pop(), pilhaCheia(), pilhaVazia().
    // - Permita enviar uma peça da fila para a pilha (reserva).
    // - Crie um menu com opção:
    //      2 - Enviar peça da fila para a reserva (pilha)
    //      3 - Usar peça da reserva (remover do topo da pilha)
    // - Exiba a pilha junto com a fila após cada ação com mostrarPilha().
    // - Mantenha a fila sempre com 5 peças (repondo com gerarPeca()).


    // 🔄 Nível Mestre: Integração Estratégica entre Fila e Pilha
    //
    // - Implemente interações avançadas entre as estruturas:
    //      4 - Trocar a peça da frente da fila com o topo da pilha
    //      5 - Trocar os 3 primeiros da fila com as 3 peças da pilha
    // - Para a opção 4:
    //      Verifique se a fila não está vazia e a pilha tem ao menos 1 peça.
    //      Troque os elementos diretamente nos arrays.
    // - Para a opção 5:
    //      Verifique se a pilha tem exatamente 3 peças e a fila ao menos 3.
    //      Use a lógica de índice circular para acessar os primeiros da fila.
    // - Sempre valide as condições antes da troca e informe mensagens claras ao usuário.
    // - Use funções auxiliares, se quiser, para modularizar a lógica de troca.
    // - O menu deve ficar assim:
    //      4 - Trocar peça da frente com topo da pilha
    //      5 - Trocar 3 primeiros da fila com os 3 da pilha

    srand((unsigned)time(NULL));

    Fila fila;
    inicializar_fila(&fila);

    // preenche a fila com 5 peças iniciais
    for (int i = 0; i < MAX_FILA; i++) {
        enqueue(&fila, gerarPeca());
    }

    int loop = 1;
    do{
        int opcao;
        exibir_menu();
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao){
            case 1:
                // remover da fila (jogar peça) + gerar nova pra manter fila cheia
                if (fila_vazia(&fila)) {
                    printf("Fila vazia — nada pra jogar.\n");
                } else {
                    Peca usada = dequeue(&fila);
                    printf("Você jogou a peça [%c %d]\n", usada.tipo, usada.id);
                    enqueue(&fila, gerarPeca());
                }
                break;
            case 0:
                loop = 0;
                break;
            default:
                break;
        }
        mostrar_fila(&fila);
    }while(loop);

    return 0;
}

// Zera as variaveis de contagem da Fila
void inicializar_fila(Fila *f){
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
}

// Verifica se a fila esta cheia
int fila_cheia(Fila *f){
    return f->total == MAX_FILA;
}

// Verifica se a fila esta vazia
int fila_vazia(Fila *f){
    return f->total == 0;
}

// Retorna os itens na fila
void mostrar_fila(Fila *f){
    printf("🧩 Fila de Peças [%d | %d]: ", f->total, MAX_FILA);
    
    if(fila_vazia(f)) {
        printf("[VAZIA]\n");
        return;
    }
    
    // 1. Inicializa o índice de leitura com o 'inicio'
    int i = f->inicio;
    // 2. Inicializa um contador para saber quantos itens já foram lidos
    int count = 0; 
    
    // 3. Percorre a fila imprimindo cada item
    while(count < f->total) {
        // Acessa a peça no índice atual
        printf("[%c | %d]", f->itens[i].tipo, f->itens[i].id);
        
        // Avança para o próximo índice de forma CIRCULAR
        i = (i + 1) % MAX_FILA;
        count++;
        
        if (count < f->total) {
            printf(" | ");
        }
    }
    printf("\n");
}

// Insere uma nova peça no final da fila circular
void enqueue(Fila *f, Peca p){
    // Verifica se a fila está cheia
    if(fila_cheia(f))
        return;

    // Insere a peça corretamente na fila
    f->itens[f->fim] = p;
    f->fim = (f->fim + 1) % MAX_FILA;
    f->total++;
}

// Remove a peça da fila
Peca dequeue(Fila *f){
    // Verifica se a fila não está vazia
    Peca vazio = {-1, '\0'};
    if(fila_vazia(f)){
        printf("Fila vazia. Não é possivel remover.\n");
        return vazio;
    }
    
    // Armazena a peça a ser removida
    Peca p = f->itens[f->inicio];

    // Atualiza o indice e o total
    f->inicio = (f->inicio + 1) % MAX_FILA;
    f->total--;

    return p;
}

// Gera peça nova com tipo aleatório e id incremental
Peca gerarPeca() {
    Peca p;
    int r = rand() % 4;
    switch (r) {
        case 0: p.tipo = 'I'; break;
        case 1: p.tipo = 'O'; break;
        case 2: p.tipo = 'T'; break;
        case 3: p.tipo = 'L'; break;
        default: p.tipo = 'I'; break;
    }
    p.id = proximoId++;
    return p;
}

// Exibe as opções do menu
void exibir_menu(){
    printf("---------------------------------------------------------------\n");
    printf("----------------- Desafio Tetris Nível Novato -----------------\n");
    printf("---------------------------------------------------------------\n");
    printf("\n1. Jogar peça (remover da frente)");
    printf("\n0. Sair\n");
    printf("---------------------------------------------------------------\n");
    printf("Escolha uma opção: ");
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
