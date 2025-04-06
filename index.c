#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STRING_LENGTH 300

//Un struct por cada linea que tenga el csv, cada atributo del struct es una columna del csv
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
} order;

//Segmento 1: 10 distintas metricas:

//Pizza mas vendida
void pms( order orders[], int registro) {
    typedef struct {
        char nombre[50];
        double total_vendida;
    } PizzaVentas;

    PizzaVentas ventas[100];
    int total_pizzas = 0;
    for (int i = 0; i < registro; i++) {
        int encontrada = 0;
        for (int j = 0; j < total_pizzas; j++) {
            if (strcmp(orders[i].PizzaNameId, ventas[j].nombre) == 0) {
                ventas[j].total_vendida += orders[i].Cantidad;
                encontrada = 1;
                break;
            }
        }
        if (!encontrada) {
            strcpy(ventas[total_pizzas].nombre, orders[i].PizzaNameId);
            ventas[total_pizzas].total_vendida = orders[i].Cantidad;
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
//Pizza menos vendida
void pls(order orders[], int registro) {
    typedef struct {
        char nombre[50];
        double total_vendida;
    } PizzaVentas;

    PizzaVentas ventas[100];
    int total_pizzas = 0;
    for (int i = 0; i < registro; i++) {
        int encontrada = 0;
        for (int j = 0; j < total_pizzas; j++) {
            if (strcmp(orders[i].PizzaNameId, ventas[j].nombre) == 0) {
                ventas[j].total_vendida += orders[i].Cantidad;
                encontrada = 1;
                break;
            }
        }
        if (!encontrada) {
            strcpy(ventas[total_pizzas].nombre, orders[i].PizzaNameId);
            ventas[total_pizzas].total_vendida = orders[i].Cantidad;
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
//Fecha con mas ventas
void dms(order orders[], int registro) {
    typedef struct {
        char fecha[50];
        double total_dinero;
    } VentasFecha;

    VentasFecha ventas[100];
    int total_fechas = 0;
    for (int i = 0; i < registro; i++) {
        int encontrada = 0;
        for (int j = 0; j < total_fechas; j++) {
            if (strcmp(orders[i].Fecha, ventas[j].fecha) == 0) {
                ventas[j].total_dinero += orders[i].PrecioTotal;
                encontrada = 1;
                break;
            }
        }
        if (!encontrada) {
            strcpy(ventas[total_fechas].fecha, orders[i].Fecha);
            ventas[total_fechas].total_dinero = orders[i].PrecioTotal;
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
//Fecha con menos ventas
void dls(order orders[], int registro) {
    typedef struct {
        char fecha[50];
        double total_dinero;
    } VentasFecha;

    VentasFecha ventas[100];
    int total_fechas = 0;
    for (int i = 0; i < registro; i++) {
        int encontrada = 0;
        for (int j = 0; j < total_fechas; j++) {
            if (strcmp(orders[i].Fecha, ventas[j].fecha) == 0) {
                ventas[j].total_dinero += orders[i].PrecioTotal;
                encontrada = 1;
                break;
            }
        }
        if (!encontrada) {
            strcpy(ventas[total_fechas].fecha, orders[i].Fecha);
            ventas[total_fechas].total_dinero = orders[i].PrecioTotal;
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
//Fecha con mas cantidad de pizzas vendidas
void dmsp(order orders[], int registro) {
    typedef struct {
        char fecha[50];
        double total_pizzas;
    } VentasFecha;

    VentasFecha ventas[100];
    int total_fechas = 0;
    for (int i = 0; i < registro; i++) {
        int encontrada = 0;
        for (int j = 0; j < total_fechas; j++) {
            if (strcmp(orders[i].Fecha, ventas[j].fecha) == 0) {
                ventas[j].total_pizzas += orders[i].Cantidad;
                encontrada = 1;
                break;
            }
        }
        if (!encontrada) {
            strcpy(ventas[total_fechas].fecha, orders[i].Fecha);
            ventas[total_fechas].total_pizzas = orders[i].Cantidad;
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
//Fecha con menor cantidad de pizzas vendidas
void dlsp(order orders[], int registro) {
    typedef struct {
        char fecha[50];
        double total_pizzas;
    } VentasFecha;

    VentasFecha ventas[100];
    int total_fechas = 0;
    for (int i = 0; i < registro; i++) {
        int encontrada = 0;
        for (int j = 0; j < total_fechas; j++) {
            if (strcmp(orders[i].Fecha, ventas[j].fecha) == 0) {
                ventas[j].total_pizzas += orders[i].Cantidad;
                encontrada = 1;
                break;
            }
        }
        if (!encontrada) {
            strcpy(ventas[total_fechas].fecha, orders[i].Fecha);
            ventas[total_fechas].total_pizzas = orders[i].Cantidad;
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
//Promedio de pizzar por orden
void apo(order orders[], int registro) {
    typedef struct {
        int id_orden;
        double cantidad_total;
    } OrdenPizzas;

    OrdenPizzas ordenes[200];
    int total_ordenes = 0;
    for (int i = 0; i < registro; i++) {
        int encontrada = 0;
        for (int j = 0; j < total_ordenes; j++) {
            if ((int)orders[i].OrdenId == ordenes[j].id_orden) {
                ordenes[j].cantidad_total += orders[i].Cantidad;
                encontrada = 1;
                break;
            }
        }
        if (!encontrada) {
            ordenes[total_ordenes].id_orden = (int)orders[i].OrdenId;
            ordenes[total_ordenes].cantidad_total = orders[i].Cantidad;
            total_ordenes++;
        }
    }

    // Calcular promedio
    double suma_total = 0;
    for (int i = 0; i < total_ordenes; i++) {
        suma_total += ordenes[i].cantidad_total;
    }
    double promedio = suma_total / total_ordenes;
    printf("Promedio de pizzas por orden: %.2f\n", promedio);
}
//Promedio pizzas por dia
void apd(order orders[], int registro) {
    typedef struct {
        char fecha[50];
        double cantidad_total;
    } PizzasPorDia;

    PizzasPorDia dias[200];
    int total_dias = 0;
    for (int i = 0; i < registro; i++) {
        int encontrada = 0;
        for (int j = 0; j < total_dias; j++) {
            if (strcmp(orders[i].Fecha, dias[j].fecha) == 0) {
                dias[j].cantidad_total += orders[i].Cantidad;
                encontrada = 1;
                break;
            }
        }
        if (!encontrada) {
            strcpy(dias[total_dias].fecha, orders[i].Fecha);
            dias[total_dias].cantidad_total = orders[i].Cantidad;
            total_dias++;
        }
    }

    // Sumar todas las cantidades
    double suma_total = 0;
    for (int i = 0; i < total_dias; i++) {
        suma_total += dias[i].cantidad_total;
    }
    double promedio = suma_total / total_dias;
    printf("Promedio de pizzas vendidas por día: %.2f\n", promedio);
}
//Ingrediente mas vendido
void ims(order orders[], int registro) {
    typedef struct {
        char nombre[50];
        int cantidad;
    } Ingrediente;

    Ingrediente ingredientes[500];
    int total_ingredientes = 0;
    for (int i = 0; i < registro; i++) {
        // Copiamos los ingredientes porque strtok modifica el string
        char copia[300];
        strcpy(copia, orders[i].Ingredientes);
        char *token = strtok(copia, ",");
        while (token != NULL) {
            // Limpiar espacios al inicio
            while (*token == ' ') {
                token++;
            }
            int encontrado = 0;
            for (int j = 0; j < total_ingredientes; j++) {
                if (strcmp(token, ingredientes[j].nombre) == 0) {
                    ingredientes[j].cantidad++;
                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado) {
                strcpy(ingredientes[total_ingredientes].nombre, token);
                ingredientes[total_ingredientes].cantidad = 1;
                total_ingredientes++;
            }
            token = strtok(NULL, ",");
        }
    }

    // Buscar el ingrediente más repetido
    int max = 0;
    char mas_usado[50];
    for (int i = 0; i < total_ingredientes; i++) {
        if (ingredientes[i].cantidad > max) {
            max = ingredientes[i].cantidad;
            strcpy(mas_usado, ingredientes[i].nombre);
        }
    }
    printf("Ingrediente más vendido: %s (apareció %d veces)\n", mas_usado, max);
}
//Cantidad de pizzas por categoria vendidas
void hp(order orders[], int registro) {
    typedef struct {
        char categoria[100];
        double total_vendida;
    } CategoriaVentas;

    CategoriaVentas categorias[50];
    int total_categorias = 0;
    for (int i = 0; i < registro; i++) {
        int encontrada = 0;
        for (int j = 0; j < total_categorias; j++) {
            if (strcmp(orders[i].Categoria, categorias[j].categoria) == 0) {
                categorias[j].total_vendida += orders[i].Cantidad;
                encontrada = 1;
                break;
            }
        }
        if (!encontrada) {
            strcpy(categorias[total_categorias].categoria, orders[i].Categoria);
            categorias[total_categorias].total_vendida = orders[i].Cantidad;
            total_categorias++;
        }
    }

    printf("Cantidad de pizzas vendidas por categoría:\n");
    for (int i = 0; i < total_categorias; i++) {
        printf("- %s: %.0f pizzas\n", categorias[i].categoria, categorias[i].total_vendida);
    }
}

int main(int argc, char *argv[]) {
    //Segmento 2:
    /*Proceso para leer cada linea del csv, parsear inteligentemente
    y almacenarlas en structs, donde cada atributo del mismo es una columna del csv*/

    //Declaracion de variables
    int args = argc;
    char **argArr = argv;
    char lenLinea[2048];
    int registro = 0;
    order orders[5000];

    //Se imprime la primera linea del csv
    FILE *datos = fopen(argArr[1],"r");
    if (fgets(lenLinea, sizeof(lenLinea), datos) == NULL) {
        perror("Intento Fallido al leer el csv");
        fclose(datos);
        return -1;
    }
    //Parseo para cada una de las 12 variables (o columnas) del csv
    while (fgets(lenLinea, 2048, datos)) {
        char *inicioPars = lenLinea;
        char *finPars;

        orders[registro].PizzaId = strtod(inicioPars, &finPars);
        inicioPars = finPars + 1;

        orders[registro].OrdenId = strtod(inicioPars, &finPars);
        inicioPars = finPars + 1;

        sscanf(inicioPars, "%49[^,]", orders[registro].PizzaNameId);
        inicioPars = strchr(inicioPars, ',') + 1;

        orders[registro].Cantidad = strtod(inicioPars, &finPars);
        inicioPars = finPars + 1;

        sscanf(inicioPars, "%49[^,]", orders[registro].Fecha);
        inicioPars = strchr(inicioPars, ',') + 1;

        sscanf(inicioPars, "%49[^,]", orders[registro].Hora);
        inicioPars = strchr(inicioPars, ',') + 1;

        orders[registro].PrecioUnitario = strtod(inicioPars, &finPars);
        inicioPars = finPars + 1;

        orders[registro].PrecioTotal = strtod(inicioPars, &finPars);
        inicioPars = finPars + 1;

        sscanf(inicioPars, "%49[^,]", orders[registro].Tamanio);
        inicioPars = strchr(inicioPars, ',') + 1;

        sscanf(inicioPars, "%99[^,]", orders[registro].Categoria);
        inicioPars = strchr(inicioPars, ',') + 1;

        if (*inicioPars == '"') {
            inicioPars++; 
            finPars = strstr(inicioPars, "\","); 
            if (finPars) {
                size_t leng = finPars - inicioPars;
                if (leng >= MAX_STRING_LENGTH) {
                    leng = MAX_STRING_LENGTH - 1;
                }
                strncpy(orders[registro].Ingredientes, inicioPars, leng);
                orders[registro].Ingredientes[leng] = '\0';
                inicioPars = finPars + 2; 
            } else {
                strcpy(orders[registro].Ingredientes, ""); 
            }
        } else {
            sscanf(inicioPars, "%299[^,]", orders[registro].Ingredientes);
            inicioPars = strchr(inicioPars, ',') + 1;
        }
        sscanf(inicioPars, "%99[^\n]", orders[registro].Nombre);
        registro++;
    } fclose(datos);

    //Segmento 3:
    //procesar el(los) input(s) del usuario, y llamar a la(s) funcion(es)
    for (int i = 2; i < args; i++) {
        if (strcmp(argArr[i], "pms") == 0) {
            pms(orders, registro);
        } else if (strcmp(argArr[i], "pls") == 0) {
            pls(orders, registro);
        } else if (strcmp(argArr[i], "dms") == 0) {
            dms(orders, registro);
        } else if (strcmp(argArr[i], "dls") == 0) {
            dls(orders, registro);
        } else if (strcmp(argArr[i], "dmsp") == 0) {
            dmsp(orders, registro);
        } else if (strcmp(argArr[i], "dlsp") == 0) {
            dlsp(orders, registro);
        } else if (strcmp(argArr[i], "apo") == 0) {
            apo(orders, registro);
        } else if (strcmp(argArr[i], "apd") == 0) {
            apd(orders, registro);
        } else if (strcmp(argArr[i], "ims") == 0) {
            ims(orders, registro);
        } else if (strcmp(argArr[i], "hp") == 0) {
            hp(orders, registro);
        }  else {
            printf("%s No es un comando\n", argArr[i]);
        }
    }
    return 0;
}