#include <stdio.h>

//Função stand by
void imprimeTabuleiro(char ptabuleiro[3][3]){
  for(int l = 0; l < 3; l++)
  {
    for(int c = 0; c < 3; c++)
      {
        printf(" %c ", ptabuleiro[l][c]);
        if (c < 2)
          printf("|");
        else
          printf("\n");
      }
    if(l<3)
    printf("---+---+---\n");
  }
}

//Função para verificar um vencedor (coluna, linha e diagonal)
char verificaVencedor(char ptabuleiro[3][3]){
  for(int c = 0; c < 3; c++){
    if(ptabuleiro[0][c] == ptabuleiro[1][c] && ptabuleiro[1][c] == ptabuleiro[2][c])
    {
      return ptabuleiro[0][c];
    }
    if(ptabuleiro[c][0] == ptabuleiro[c][1] && ptabuleiro[c][2] == ptabuleiro[c][1])
    {
      return ptabuleiro[c][0];
    }
    
   }
  if(ptabuleiro[0][0] == ptabuleiro[1][1] && ptabuleiro[2][2] == ptabuleiro[1][1])
  {
    return ptabuleiro[0][0];
  }
  if(ptabuleiro[0][2] == ptabuleiro[1][1] && ptabuleiro[2][0] == ptabuleiro[1][1])
  {
    return ptabuleiro[0][2];
  }
  return ' ';
 }

//Função principal 
int main(void) {
  char tabuleiro[3][3] = {{' ', ' ', ' '},               
                          {' ', ' ', ' '},               
                          {' ', ' ', ' '}};
  int linha, coluna, jogadas = 0;
  char jogadorAtual = 'X';
  char vencedor = ' ';

  printf("Bem-vindo ao jogo da velha!\n");
  while (vencedor == ' ' && jogadas < 9){
    printf("Jogador %c, digite a linha de (1-3):", jogadorAtual);
    scanf("%d", &linha);
    printf("Jogador %c, digite a coluna de (1-3):", jogadorAtual);
    scanf("%d", &coluna);
    //Validação da jogada
    if ((linha > 3) || (coluna > 3) || (linha < 1) || (coluna < 1) || tabuleiro[linha-1][coluna-1] != ' '){
      printf("Jogada inválida, tente novamente.\n");
      continue;
    }
    //Tabuleiro recebendo o jogador atual
    tabuleiro[linha-1][coluna-1] = jogadorAtual;
    jogadas++;
    imprimeTabuleiro(tabuleiro);
    if (jogadas > 4 )
    vencedor = verificaVencedor(tabuleiro);

    if(jogadorAtual == 'X')
      jogadorAtual = 'O';
    else
      jogadorAtual = 'X';
    printf("Jogada %d concluída!\n", jogadas);
  }
  
  switch (vencedor){
    case 'X': printf("Jogador X venceu!\n"); break;
    case 'O': printf("Jogador O venceu!\n"); break;
    default: printf("Empate!\n"); break;
  }
  return 0;
}