#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 300

//gcc -o APP1-SEC2-LPP-STGO app1.c (en la terminal, para poder llamar funciones desde la terminal)
//./APP1-SEC2-LPP-STGO pls (en la terminal, para ejecutar)

//Un struct por cada linea que tenga el csv
typedef struct {
   double PizzaId;
   double OrdenId;
   char PizzaNameId[50];
   double Cantidad;
   char Fecha[50];
   char Hora[50];
   double PrecioUnitario;
   double PrecioTotal;
   char Tamanio[50];
   char Categoria[100];
   char Ingredientes[300];
   char Nombre[100];
} Compra;


//10 distintas metricas
//Pizza mas vendida
void pms(Compra compras[], int registro) {
   typedef struct {
       char nombre[50];
       double total_vendida;
   } PizzaVentas;

   PizzaVentas ventas[100];
   int total_pizzas = 0;

   for (int i = 0; i < registro; i++) {
       int encontrada = 0;
       for (int j = 0; j < total_pizzas; j++) {
           if (strcmp(compras[i].PizzaNameId, ventas[j].nombre) == 0) {
               ventas[j].total_vendida += compras[i].Cantidad;
               encontrada = 1;
               break;
           }
       }
       if (!encontrada) {
           strcpy(ventas[total_pizzas].nombre, compras[i].PizzaNameId);
           ventas[total_pizzas].total_vendida = compras[i].Cantidad;
           total_pizzas++;
       }
   }

   // Buscar la pizza más vendida
   double max_cantidad = 0;
   char pizza_mas_vendida[50];
   for (int i = 0; i < total_pizzas; i++) {
       if (ventas[i].total_vendida > max_cantidad) {
           max_cantidad = ventas[i].total_vendida;
           strcpy(pizza_mas_vendida, ventas[i].nombre);
       }
   }

   printf("La pizza más vendida fue: %s con un total de %.0f unidades vendidas.\n", pizza_mas_vendida, max_cantidad);
}
void pls(Compra compras[], int registro) {
   typedef struct {
       char nombre[50];
       double total_vendida;
   } PizzaVentas;

   PizzaVentas ventas[100];
   int total_pizzas = 0;

   for (int i = 0; i < registro; i++) {
       int encontrada = 0;
       for (int j = 0; j < total_pizzas; j++) {
           if (strcmp(compras[i].PizzaNameId, ventas[j].nombre) == 0) {
               ventas[j].total_vendida += compras[i].Cantidad;
               encontrada = 1;
               break;
           }
       }
       if (!encontrada) {
           strcpy(ventas[total_pizzas].nombre, compras[i].PizzaNameId);
           ventas[total_pizzas].total_vendida = compras[i].Cantidad;
           total_pizzas++;
       }
   }

   // Buscar la pizza menos vendida
   double min_cantidad = ventas[0].total_vendida;
   char pizza_menos_vendida[50];
   strcpy(pizza_menos_vendida, ventas[0].nombre);

   for (int i = 1; i < total_pizzas; i++) {
       if (ventas[i].total_vendida < min_cantidad) {
           min_cantidad = ventas[i].total_vendida;
           strcpy(pizza_menos_vendida, ventas[i].nombre);
       }
   }

   printf("La pizza menos vendida fue: %s con un total de %.0f unidades vendidas.\n", pizza_menos_vendida, min_cantidad);
}

void dms(Compra compras[], int registro) {
   typedef struct {
       char fecha[50];
       double total_dinero;
   } VentasFecha;

   VentasFecha ventas[100];
   int total_fechas = 0;

   for (int i = 0; i < registro; i++) {
       int encontrada = 0;
       for (int j = 0; j < total_fechas; j++) {
           if (strcmp(compras[i].Fecha, ventas[j].fecha) == 0) {
               ventas[j].total_dinero += compras[i].PrecioTotal;
               encontrada = 1;
               break;
           }
       }
       if (!encontrada) {
           strcpy(ventas[total_fechas].fecha, compras[i].Fecha);
           ventas[total_fechas].total_dinero = compras[i].PrecioTotal;
           total_fechas++;
       }
   }

   // Buscar la fecha con más dinero recaudado
   double max_dinero = ventas[0].total_dinero;
   char fecha_top[50];
   strcpy(fecha_top, ventas[0].fecha);

   for (int i = 1; i < total_fechas; i++) {
       if (ventas[i].total_dinero > max_dinero) {
           max_dinero = ventas[i].total_dinero;
           strcpy(fecha_top, ventas[i].fecha);
       }
   }

   printf("La fecha con mayor dinero recaudado fue: %s con un total de $%.2f\n", fecha_top, max_dinero);
}


void dls(Compra compras[], int registro) {
   typedef struct {
       char fecha[50];
       double total_dinero;
   } VentasFecha;

   VentasFecha ventas[100];
   int total_fechas = 0;

   for (int i = 0; i < registro; i++) {
       int encontrada = 0;
       for (int j = 0; j < total_fechas; j++) {
           if (strcmp(compras[i].Fecha, ventas[j].fecha) == 0) {
               ventas[j].total_dinero += compras[i].PrecioTotal;
               encontrada = 1;
               break;
           }
       }
       if (!encontrada) {
           strcpy(ventas[total_fechas].fecha, compras[i].Fecha);
           ventas[total_fechas].total_dinero = compras[i].PrecioTotal;
           total_fechas++;
       }
   }

   // Buscar la fecha con menos dinero recaudado
   double min_dinero = ventas[0].total_dinero;
   char fecha_menos[50];
   strcpy(fecha_menos, ventas[0].fecha);

   for (int i = 1; i < total_fechas; i++) {
       if (ventas[i].total_dinero < min_dinero) {
           min_dinero = ventas[i].total_dinero;
           strcpy(fecha_menos, ventas[i].fecha);
       }
   }

   printf("La fecha con menor dinero recaudado fue: %s con un total de $%.2f\n", fecha_menos, min_dinero);
}


void dmsp(Compra compras[], int registro) {
   typedef struct {
       char fecha[50];
       double total_pizzas;
   } VentasFecha;

   VentasFecha ventas[100];
   int total_fechas = 0;

   for (int i = 0; i < registro; i++) {
       int encontrada = 0;
       for (int j = 0; j < total_fechas; j++) {
           if (strcmp(compras[i].Fecha, ventas[j].fecha) == 0) {
               ventas[j].total_pizzas += compras[i].Cantidad;
               encontrada = 1;
               break;
           }
       }
       if (!encontrada) {
           strcpy(ventas[total_fechas].fecha, compras[i].Fecha);
           ventas[total_fechas].total_pizzas = compras[i].Cantidad;
           total_fechas++;
       }
   }

   // Buscar la fecha con más pizzas vendidas
   double max_pizzas = ventas[0].total_pizzas;
   char fecha_max[50];
   strcpy(fecha_max, ventas[0].fecha);

   for (int i = 1; i < total_fechas; i++) {
       if (ventas[i].total_pizzas > max_pizzas) {
           max_pizzas = ventas[i].total_pizzas;
           strcpy(fecha_max, ventas[i].fecha);
       }
   }

   printf("La fecha con más pizzas vendidas fue: %s con un total de %.0f pizzas.\n", fecha_max, max_pizzas);
}

void dlsp(Compra compras[], int registro) {
   typedef struct {
       char fecha[50];
       double total_pizzas;
   } VentasFecha;

   VentasFecha ventas[100];
   int total_fechas = 0;

   for (int i = 0; i < registro; i++) {
       int encontrada = 0;
       for (int j = 0; j < total_fechas; j++) {
           if (strcmp(compras[i].Fecha, ventas[j].fecha) == 0) {
               ventas[j].total_pizzas += compras[i].Cantidad;
               encontrada = 1;
               break;
           }
       }
       if (!encontrada) {
           strcpy(ventas[total_fechas].fecha, compras[i].Fecha);
           ventas[total_fechas].total_pizzas = compras[i].Cantidad;
           total_fechas++;
       }
   }

   // Buscar la fecha con menos pizzas vendidas
   double min_pizzas = ventas[0].total_pizzas;
   char fecha_min[50];
   strcpy(fecha_min, ventas[0].fecha);

   for (int i = 1; i < total_fechas; i++) {
       if (ventas[i].total_pizzas < min_pizzas) {
           min_pizzas = ventas[i].total_pizzas;
           strcpy(fecha_min, ventas[i].fecha);
       }
   }

   printf("La fecha con menos pizzas vendidas fue: %s con un total de %.0f pizzas.\n", fecha_min, min_pizzas);
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



int main(int argc, char *argv[]) {
   //declaracion de variables
   int args = argc;
   char **argArr = argv;
   char lenLinea[2048];
   int registro = 0;

   //proceso para leer cada linea del csv, y almacenarlas en structs, donde cada atributo del mismo es una columna del csv
   Compra compras[100];
   FILE *data;
   data = fopen("datos.csv","r");

   if (fgets(lenLinea, sizeof(lenLinea), data) == NULL) {
      perror("Failed to read header");
      fclose(data);
      return -1;
   }

   while (fgets(lenLinea, 2048, data)) {
      char *start = lenLinea;
      char *end;

      compras[registro].PizzaId = strtod(start, &end);
      start = end + 1;

      compras[registro].OrdenId = strtod(start, &end);
      start = end + 1;

      sscanf(start, "%49[^,]", compras[registro].PizzaNameId);
      start = strchr(start, ',') + 1;

      compras[registro].Cantidad = strtod(start, &end);
      start = end + 1;

      sscanf(start, "%49[^,]", compras[registro].Fecha);
      start = strchr(start, ',') + 1;

      sscanf(start, "%49[^,]", compras[registro].Hora);
      start = strchr(start, ',') + 1;

      compras[registro].PrecioUnitario = strtod(start, &end);
      start = end + 1;

      compras[registro].PrecioTotal = strtod(start, &end);
      start = end + 1;

      sscanf(start, "%49[^,]", compras[registro].Tamanio);
      start = strchr(start, ',') + 1;

      sscanf(start, "%99[^,]", compras[registro].Categoria);
      start = strchr(start, ',') + 1;

      if (*start == '"') {
         start++; 
         end = strstr(start, "\","); 
         if (end) {
            size_t leng = end - start;
            if (leng >= MAX_STRING_LENGTH) leng = MAX_STRING_LENGTH - 1;
            strncpy(compras[registro].Ingredientes, start, leng);
            compras[registro].Ingredientes[leng] = '\0';
            start = end + 2; 
         } else {
            strcpy(compras[registro].Ingredientes, ""); 
         }
      } else {
         sscanf(start, "%299[^,]", compras[registro].Ingredientes);
         start = strchr(start, ',') + 1;
      }

      sscanf(start, "%99[^\n]", compras[registro].Nombre);
      registro++;
   }
   fclose(data);

   //procesar el(los) input(s) del usuario, y llamar a la(s) funcion(es)
   for (int i = 1; i < args; i++) {
      if (strcmp(argArr[i], "pms") == 0) {
         pms(compras, registro);
      } else if (strcmp(argArr[i], "pls") == 0) {
         pls(compras, registro);
      } else if (strcmp(argArr[i], "dms") == 0) {
         dms(compras, registro);
      } else if (strcmp(argArr[i], "dls") == 0) {
         dls(compras, registro);
      } else if (strcmp(argArr[i], "dmsp") == 0) {
         dmsp(compras, registro);
      } else if (strcmp(argArr[i], "dlsp") == 0) {
         dlsp(compras, registro);
      } else if (strcmp(argArr[i], "apo") == 0) {
         apo();
      } else if (strcmp(argArr[i], "apd") == 0) {
         apd();
      } else if (strcmp(argArr[i], "ims") == 0) {
         ims();
      } else if (strcmp(argArr[i], "hp") == 0) {
         hp();
      }  else {
         printf("%s No es un comando\n", argArr[i]);
      }
   }
   return 0;
}