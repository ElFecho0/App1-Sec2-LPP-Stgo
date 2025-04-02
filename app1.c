#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//gcc -o APP1-SEC2-LPP-STGO app1.c (en la terminal, para poder llamar funciones desde la terminal)
//./APP1-SEC2-LPP-STGO pls (en la terminal, para ejecutar)

//10 distintas metricas
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

typedef struct {
   double PizzaId;
   double OrdenId;
   char PizzaNameId[100];
   double Cantidad;
   char Fecha[100];
   char Hora[100];
   double PrecioUnitario;
   double PrecioTotal;
   char Tamanio;
   char Categoria[100];
   char Ingredientes[300];
   char Nombre[100];
} Compra;

typedef struct {
   double pepe;
} ete;

int main(int argc, char *argv[]) {
   char lenLinea[800];
   int len = 0;
   int leer = 0;
   int registro = 0;

   FILE *lala;
   lala = fopen("datos.csv","r");
   fgets(lenLinea, sizeof(lenLinea), lala);
   while (fgets(lenLinea, sizeof(lenLinea), lala)) {
      len++;  // Increment the row count for each line read
   }
   fclose(lala);

   //printf("%i\n", len);
   ete waza[len-1];
   Compra compras[len-1];
   FILE *data;
   data = fopen("datos.csv","r");
   //fgets(lenLinea, sizeof(lenLinea), data);
   //printf("%s", lenLinea);

   while (fgets(lenLinea, sizeof(lenLinea), data)) {
      //printf("%s", lenLinea);
      int leer = 0;
      leer = fscanf(data, "%lf", &waza[registro].pepe);
      //printf("%lf\n",waza[registro].pepe);
      //printf("leer es %i\n",leer);
      if(registro == len-1){
         break;
      }
      if (leer == 1){
         registro++;
      }
      //printf("%i\n",leer);
      //printf("%s",lenLinea);
   }
   fclose(data);

   
   for(int i = 0; i < len; i++){
      printf("%lf\n", waza[i].pepe);
   }
   //procesar el input del usuario, y llamar a las funciones
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