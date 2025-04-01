#include <stdio.h>
#include <string.h>

//gcc -o APP1-SEC2-LPP-STGO app1.c (en la terminal, para poder llamar funciones desde la terminal)
//./APP1-SEC2-LPP-STGO pls (en la terminal, para ejecutar)

void pls() {
   printf("Llamaste a pls\n");
}

void pms() {
   printf("Llamaste a pms\n");
}

int main(int argc, char *argv[]) {
   for (int i = 1; i < argc; i++) {
      if (strcmp(argv[i], "pls") == 0) {
         pls();
      } else if (strcmp(argv[i], "pms") == 0) {
         pms();
      } else {
         printf("%s No es un comando\n", argv[i]);
      }
   }
   return 0;
}