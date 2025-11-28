Desafio Tetris Stack - Controle de Peças com Estruturas de Dados
Bem-vindo ao desafio "Tetris Stack"! Neste jogo inspirado nas mecânicas clássicas de montagem de peças, o jogador deve organizar, reservar e manipular peças em tempo real. Para isso, você, como programador, será responsável por implementar as estruturas de controle que regem a lógica das peças.

A empresa ByteBros, especializada em jogos educacionais de lógica e programação, contratou você para desenvolver o sistema de gerenciamento de peças, utilizando estruturas como fila circular e pilha.

O desafio está dividido em três níveis: Novato, Aventureiro e Mestre, com cada nível adicionando mais complexidade ao anterior.
Você deve escolher qual desafio deseja realizar.


# 🕹️ Desafio Tetris Stack - Controle de Peças (Nível Novato)

## 🎯 Objetivo do Projeto

Este projeto implementa o sistema inicial de gerenciamento de peças futuras para o jogo "Tetris Stack". O foco principal é a utilização e manipulação correta da estrutura de dados **Fila Circular** em C.

O projeto foi concluído no **Nível Novato** do desafio, demonstrando a correta implementação das operações FIFO (First-In, First-Out) em um array de tamanho fixo.

---

## ✅ Requisitos Funcionais Atendidos

O código (`tetris_stack.c`) atende a todos os requisitos do Nível Novato:

1.  **Fila Circular de Tamanho Fixo:** Implementada com `MAX_FILA = 5`.
2.  **Estrutura de Dados:** Utiliza a `struct Peca` para representar as peças com um `id` (sequencial) e `tipo` (caractere, e.g., 'I', 'O', 'T', 'L').
3.  **Inicialização:** A fila é preenchida automaticamente com 5 peças ao iniciar o programa.
4.  **Ação Principal (1 - Jogar peça):**
    * **Remoção (`dequeue`):** Remove a peça da **frente** da fila.
    * **Reposição Automática:** Imediatamente após a remoção, uma nova peça é gerada (`gerarPeca`) e inserida no **final** da fila (`enqueue`), garantindo que a fila permaneça sempre com 5 elementos.
5.  **Visualização:** A função `mostrar_fila` exibe o estado atual da fila, respeitando a ordem circular, após cada ação.

---

## ⚙️ Estrutura do Código em C

O projeto é modularizado em funções, com base em conceitos de structs e arrays:

### **Structs de Controle**

* `Peca`: Define a peça com `id` e `tipo`.
* `Fila`: Contém o array `itens[MAX_FILA]` e os indicadores `inicio`, `fim` e `total` para controle circular.

### **Funções Principais da Fila (Fila Circular)**

| Função | Comentário/Lógica |
| :--- | :--- |
| `inicializar_fila` | Zera os indicadores da fila (`inicio`, `fim`, `total`). |
| `fila_cheia / fila_vazia` | Funções de validação baseadas no `total` de elementos. |
| `enqueue(Fila *f, Peca p)` | Insere no `f->fim`, aplicando a lógica modular `(f->fim + 1) % MAX_FILA`. |
| `dequeue(Fila *f)` | Remove do `f->inicio`, aplicando a lógica modular e retornando a peça removida. |
| `mostrar_fila(Fila *f)` | Percorre os elementos do `inicio` até o `total`, exibindo a ordem atual da fila. |

### **Funções Auxiliares**

* `gerarPeca()`: Cria uma nova `Peca` com um tipo aleatório (entre 'I', 'O', 'T', 'L') e um `id` incremental global.
* `limparBuffer()`: Trata o buffer de entrada (`stdin`) após o `scanf` para evitar erros no loop do menu.

---

## 🖥️ Como Executar

1.  **Compilação:** Certifique-se de ter um compilador C (como GCC) instalado e execute:
    ```bash
    gcc nome_do_seu_arquivo.c -o tetris_stack
    ```
2.  **Execução:**
    ```bash
    ./tetris_stack
    ```
3.  **Interação:** Digite **1** para "Jogar peça" (dequeue e repor) e **0** para sair do programa.



--------------------------------------------------------------------------------------------------------------------

🚨 Atenção: O nível Novato foca apenas na fila de peças, usando conceitos básicos de structs, arrays e modularização.

🎮 Nível Novato: Fila de Peças Futuras
No nível Novato, você criará o sistema inicial de controle das peças futuras do jogo Tetris Stack. As peças possuem um nome (representando o tipo, como 'I', 'O', 'T', 'L') e um id exclusivo (identificador numérico).

🚩 Objetivo: Criar um programa em C que simula uma fila circular de 5 peças com as seguintes funcionalidades:

Visualizar a fila atual
Jogar (remover) a peça da frente
Inserir automaticamente uma nova peça no final da fila
⚙️ Funcionalidades do Sistema:

Inicializar a fila com 5 peças geradas automaticamente.
Permitir que o usuário:
Jogue uma peça (dequeue)
Insira uma nova peça (enqueue)
Visualize o estado atual da fila
Manter a fila circular, reaproveitando o espaço.
📥 Entrada e 📤 Saída de Dados:

O programa utiliza menus via terminal.
A cada ação, o estado atualizado da fila é exibido com printf.
Simplificações para o Nível Novato:

Trabalhe apenas com a fila.
A fila deve conter exatamente 5 elementos.
Use uma função gerarPeca() para criar automaticamente novas peças.
Utilize structs e arrays. Não implemente pilha.

Boa sorte e divirta-se programando!

Equipe de Ensino - ByteBros
