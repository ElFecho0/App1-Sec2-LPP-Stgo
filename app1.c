#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//gcc -o APP1-SEC2-LPP-STGO app1.c (en la terminal, para poder llamar funciones desde la terminal)
//./APP1-SEC2-LPP-STGO pls (en la terminal, para ejecutar)

//10 distintas metricas

//Pizza mas vendida
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

//Un struct por cada linea que tenga el csv
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

int main(int argc, char *argv[]) {
   //declaracion de variables
   int args = argc;
   char *argArr[args];
   char lenLinea[800];
   int len = 0;
   int registro = 0;
   for (int i = 0; i < args; i++){
      argArr[i] = argv[i];
   }

   //proceso para tener una variable que muestre la cantidad de lineas que tiene el csv (len)
   FILE *lala;
   lala = fopen("datos.csv","r");
   fgets(lenLinea, sizeof(lenLinea), lala);
   while (fgets(lenLinea, sizeof(lenLinea), lala)) {
      len++;
   }
   fclose(lala);

   //proceso para leer cada linea del csv, y almacenarlas en structs, donde cada atributo del mismo es una columna del csv
   Compra compras[len-1];
   FILE *data;
   data = fopen("datos.csv","r");
   int skip = 1;
   do
   {
      if(skip == 1){
         skip = 0;
         continue;
      }
      fscanf(data, "%lf, %lf\n", &compras[registro].PizzaId, &compras[registro].OrdenId);
      //printf("%lf\n",compras[registro].PizzaId);
      //printf("%lf\n",compras[registro].OrdenId);
      if(registro == len-1){
         break;
      }
      registro++;
   } while (fgets(lenLinea, sizeof(lenLinea), data));
   fclose(data);

   //procesar el(los) input(s) del usuario, y llamar a la(s) funcion(es)
   for (int i = 1; i < args; i++) {
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