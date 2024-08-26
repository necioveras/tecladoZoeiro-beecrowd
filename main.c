#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  int letras, qtdeFrases;

  scanf("%d%d", &letras, &qtdeFrases);

  getchar();

  char trocas[(2 * letras)];

  char a, b;
  for (int i = 0; i < (2 * letras); i += 2) {
    scanf(" %c %c", &a, &b);
    trocas[i] = a;
    trocas[(i + 1)] = b;
  }

  char frases[qtdeFrases][10010];
  for (int i = 0; i < qtdeFrases; i++) {
    scanf(" %[^\n]s", frases[i]);
    getchar();
  }

  for (int i = 0; i < qtdeFrases; i++) {
    for (int j = 0; j < strlen(frases[i]); j++) {
      for (int z = 0; z < (2 * letras); z++) {
        if (frases[i][j] == trocas[z]) {
          if ((z % 2 == 0) | (z == 0))
            frases[i][j] = trocas[(z + 1)];
          else
            frases[i][j] = trocas[(z - 1)];
          break;
        }
      }
    }
  }

  for (int i = 0; i < qtdeFrases; i++) {
    printf("%s\n", frases[i]);
  }

  // retorna ok
  return 0;
}
