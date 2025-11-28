Desafio Tetris Stack - Controle de Peças com Estruturas de Dados
Bem-vindo ao desafio "Tetris Stack"! Neste jogo inspirado nas mecânicas clássicas de montagem de peças, o jogador deve organizar, reservar e manipular peças em tempo real. Para isso, você, como programador, será responsável por implementar as estruturas de controle que regem a lógica das peças.

A empresa ByteBros, especializada em jogos educacionais de lógica e programação, contratou você para desenvolver o sistema de gerenciamento de peças, utilizando estruturas como fila circular e pilha.

O desafio está dividido em três níveis: Novato, Aventureiro e Mestre, com cada nível adicionando mais complexidade ao anterior.
Você deve escolher qual desafio deseja realizar.


🕹️ Desafio Tetris Stack - Controle de Peças (Nível Novato)🎯 Objetivo do ProjetoEste projeto implementa o sistema de gerenciamento de peças futuras para o jogo "Tetris Stack", focando na utilização da estrutura de dados Fila Circular para controlar a ordem de aparecimento das peças.Este projeto foi concluído no Nível Novato, conforme os requisitos do desafio da ByteBros.🛠️ Requisitos Funcionais Atendidos (Nível Novato)O programa tetris_stack.c implementa as seguintes funcionalidades:Estrutura da Peça: Utilização da struct Peca contendo um id (inteiro sequencial) e um tipo (caractere, e.g., 'I', 'O', 'T', 'L').Fila Circular: Implementação de uma Fila Circular com capacidade fixa de 5 peças (MAX_FILA = 5).Inicialização: A fila é preenchida com 5 peças geradas automaticamente no início da execução.Ação 'Jogar Peça' (1): Implementa a operação dequeue (remover da frente da fila).Mecanismo de Reposição: Após a remoção, uma nova peça é gerada e inserida automaticamente ao final da fila (enqueue) para manter a capacidade fixa de 5 peças.Visualização: A função mostrar_fila exibe o estado atual da fila após cada ação, garantindo a Usabilidade e Clareza da saída.⚙️ Estrutura do Código (tetris_stack.c)O código é modularizado em funções claras para cada operação da Fila:FunçãoFinalidadestruct PecaDefine a estrutura básica das peças (ID e Tipo).struct FilaDefine a Fila Circular com controle via inicio, fim e total.inicializar_filaZera os contadores da fila (inicio = 0, total = 0).fila_cheia / fila_vaziaValida as condições de inserção e remoção.enqueueInsere uma peça ao final, aplicando a aritmética modular (% MAX_FILA).dequeueRemove a peça do início, avançando o índice inicio circularmente.mostrar_filaPercorre e exibe os elementos da fila do inicio ao fim.gerarPecaCria uma nova peça com tipo aleatório e ID sequencial (proximoId).limparBufferFunção auxiliar para garantir que o scanf não gere erros no loop de menu.🚀 Como Compilar e RodarCompilação: Use um compilador C (como GCC) no terminal:Bashgcc tetris_stack.c -o tetris_stack
Execução:Bash./tetris_stack
Interação: Siga as opções do menu no terminal: 1 para Jogar Peça (dequeue) ou 0 para Sair.Lembre-se de verificar o seu arquivo .c e garantir que ele contém todos os comentários explicando o propósito de cada função e seção, conforme solicitado no tutorial. Feito isso, é só fazer o commit, push e enviar o link do repositório! Boa sorte!


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
