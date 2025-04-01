#include <stdio.h>
#include <string.h>

//gcc -o APP1-SEC2-LPP-STGO app1.c (en la terminal, para poder llamar funciones desde la terminal)
//./APP1-SEC2-LPP-STGO pls (en la terminal, para ejecutar)
void pms() {
   printf("Llamaste a pms\n");
}
void pls() {
   printf("Llamaste a pls\n");
}
void dms() {
   printf("Llamaste a dms\n");
}
void dls() {
   printf("Llamaste a dls\n");
}
void dmsp() {
   printf("Llamaste a dmsp\n");
}
void dlsp() {
   printf("Llamaste a dlsp\n");
}
void apo() {
   printf("Llamaste a apo\n");
}
void apd() {
   printf("Llamaste a apd\n");
}
void ims() {
   printf("Llamaste a ims\n");
}
void hp() {
   printf("Llamaste a hp\n");
}
void import() {
   return 0;
}

int main(int argc, char *argv[]) {
   for (int i = 1; i < argc; i++) {
      if (strcmp(argv[i], "pms") == 0) {
         pms();
      } else if (strcmp(argv[i], "pls") == 0) {
         pls();
      } else if (strcmp(argv[i], "dms") == 0) {
         dms();
      } else if (strcmp(argv[i], "dls") == 0) {
         dls();
      } else if (strcmp(argv[i], "dmsp") == 0) {
         dmsp();
      } else if (strcmp(argv[i], "dlsp") == 0) {
         dlsp();
      } else if (strcmp(argv[i], "apo") == 0) {
         apo();
      } else if (strcmp(argv[i], "apd") == 0) {
         apd();
      } else if (strcmp(argv[i], "ims") == 0) {
         ims();
      } else if (strcmp(argv[i], "hp") == 0) {
         hp();
      }  else {
         printf("%s No es un comando\n", argv[i]);
      }
   }
   return 0;
}