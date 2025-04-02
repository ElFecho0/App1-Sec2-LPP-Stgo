#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define maxLn 100

//gcc -o APP1-SEC2-LPP-STGO testo.c (en la terminal, para poder llamar funciones desde la terminal)
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

int main(int argc, char *argv[]) {
    //importar los datos csv a struct
    FILE *lolo = fopen("data.csv", "r");
    char lala[1024];
    int len;
    while (fgets(lala, sizeof(lala), lolo)) {
        len++;  // Increment the row count for each line read
    }
    fclose(lolo);


   FILE *data = fopen("data.csv", "r");

   Compra compras[maxLn];
    int row = 0;
    char linea[1000];

   fgets(linea, sizeof(linea), data);

   while (fgets(linea, sizeof(linea), data) && row < len) {

      char a[100];
      char b[100];
      char c[100];
      char d[100];
      char e[100];
      char f[300];
      char g[100];
      double h, i, j, k, l;

      if (sscanf(linea, "%lf,%lf,%100[^,],%lf,%100[^,],%100[^,],%lf,%lf,%100[^,],%100[^,],\"%300[^\"]\",%100[^,],", &h, &i, a, &j, b, c, &k, &l, d, e, f, g) == 12) {
        compras[row].PizzaId = h;
        compras[row].OrdenId = i;
        strcpy(compras[row].PizzaNameId, a);
        compras[row].Cantidad = j;
        strcpy(compras[row].Fecha, b);
        strcpy(compras[row].Hora, c);
        compras[row].PrecioUnitario = k;
        compras[row].PrecioTotal = l;
        strcpy(compras[row].Tamanio, d);
        strcpy(compras[row].Categoria, e);
        strcpy(compras[row].Ingredientes, f);
        strcpy(compras[row].Nombre, g);
        row++;
      }
   }
   fclose(data); 
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