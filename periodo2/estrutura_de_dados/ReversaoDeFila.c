
/*
    As filas não têm um método direto de reversão, mas as pilhas podem funcionar bem como métodos auxiliares;

    Passos da lógica:
        * Transferir da fila original para uma pilha
            - ordem automaticamente invertida na pilha
        * Transferir da pilha para uma nova fila
            - o resultado é uma fila com ordem reversa da original
*/

 // ---------------------------------- Implementação ---------------------------------------

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 #define MAX 50

 typedef struct {
    char nome[30];
    int idade;
 } Pessoa;

 typedef struct {
    Pessoa dados[MAX];
    int inicio, fim;
 } Fila;

 typedef struct {
    Pessoa dados[MAX];
    int topo;
 } Pilha;


 // ----------------------------- operações básicas Fila ------------------------------

 void inserir(Fila *f, Pessoa p){
   if(f->fim < MAX){
      f->dados[f->fim++] = p;
   }
 }

 Pessoa remover(Fila *f){
   return f->dados[f->inicio++];
 }

 void exibirFila(Fila f){
   for (int i = f.inicio; i < f.fim; i++)
   {
      printf("Nome: %s | Idade: %d \n", f.dados[i].nome, f.dados[i].idade);
   } 
 }

  // ----------------------------- operações básicas Pilha ------------------------------

 void push(Pilha *p, Pessoa pes){
   if(p->topo < MAX - 1){
      p->dados[++p->topo] = pes;
   }
 }

 Pessoa pop(Pilha *p){
   return p->dados[p->topo--];
 }

void peek(Pilha *p) {    
    Pessoa topo = p->dados[p->topo];
    printf("Elemento do topo: %s, %d anos\n", topo.nome, topo.idade);
}


 // ----------------------------- métodos auxiliares ------------------------------

 void inicializarFila(Fila *f){
   f->inicio = 0;
   f->fim = 0;
 }

 void inicializarPilha(Pilha *p){
   p->topo = -1;
 }

 // ------------------------------- Execução --------------------------------------

 int main(){

   Fila filaOriginal, filaInvertida;
   Pilha pilhaAuxiliar;

   inicializarFila(&filaOriginal);
   inicializarFila(&filaInvertida);
   inicializarPilha(&pilhaAuxiliar);

   Pessoa pessoas[] = {{"Joao", 20}, {"Jose", 52}, {"Pedro", 1}};

   // inserindo os dados na fila original
   for (int i = 0; i < (sizeof(pessoas) / sizeof(pessoas[0])); i++){
      inserir(&filaOriginal, pessoas[i]);
   }
   
   exibirFila(filaOriginal);

   while (filaOriginal.inicio < filaOriginal.fim)
   {
      Pessoa p = remover(&filaOriginal);
      push(&pilhaAuxiliar, p);
   }

   peek(&pilhaAuxiliar);

   while (pilhaAuxiliar.topo >=0)
   {
      Pessoa p = pop(&pilhaAuxiliar);
      inserir(&filaInvertida, p);
   }
   
   exibirFila(filaInvertida);
   










 }