//HERNANDEZ LOPEZ RAPHAEL DE JHESUS
//CRUZ AGUILAR BRAYAN KHOTAN
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ART 10
#define MAX_TICKETS 5

struct Producto {
    char nombre[100];
    float precio;
};

struct Ticket {
    int numeroTicket;
    struct Producto articulos[MAX_ART];
    int totalProductos;
    float totalCompra;
};

void agregarProducto(struct Ticket *ticket) {
    if (ticket->totalProductos >= MAX_ART) {
        printf("No se pueden agregar más productos. Límite alcanzado.\n");
        return;
    }
    struct Producto producto;
    printf("Seleccione un producto:\n");
    printf("1. Maruchan de pollo\n");
    printf("2. Maruchan de res\n");
    printf("3. Maruchan de camarón\n");
    printf("4. Maruchan de queso\n");
    printf("5. Maruchan de habanero\n");
    printf("6. Maruchan de chili\n");
    printf("7. Maruchan bowl\n");
    printf("8. Sopa nissin camarón\n");
    printf("9. Sopa nissin habanero\n");
    printf("10. Sopa nissin res\n");
    printf("11. Sopa nissin ostras\n");
    printf("12. Cup noodles diablo\n");
    printf("13. Cup noodles camarón picante\n");
    printf("14. Cup noodles fuego\n");
    printf("15. UFO res teriyaki\n");

    int opcion;
    printf("Ingrese el número del producto: ");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            strcpy(producto.nombre, "Maruchan de pollo");
            producto.precio = 17.00;
            break;
        case 2:
            strcpy(producto.nombre, "Maruchan de res");
            producto.precio = 17.00;
            break;
        case 3:
            strcpy(producto.nombre, "Maruchan de camarón");
            producto.precio = 17.00;
            break;
        case 4:
            strcpy(producto.nombre, "Maruchan de queso");
            producto.precio = 15.00;
            break;
        case 5:
            strcpy(producto.nombre, "Maruchan de habanero");
            producto.precio = 17.00;
            break;
        case 6:
            strcpy(producto.nombre, "Maruchan de chili");
            producto.precio = 17.00;
            break;
        case 7:
            strcpy(producto.nombre, "Maruchan bowl");
            producto.precio = 23.00;
            break;
        case 8:
            strcpy(producto.nombre, "Sopa nissin camarón");
            producto.precio = 16.00;
            break;
        case 9:
            strcpy(producto.nombre, "Sopa nissin habanero");
            producto.precio = 16.00;
            break;
        case 10:
            strcpy(producto.nombre, "Sopa nissin res");
            producto.precio = 16.00;
            break;
        case 11:
            strcpy(producto.nombre, "Sopa nissin ostras");
            producto.precio = 16.00;
            break;
        case 12:
            strcpy(producto.nombre, "Cup noodles diablo");
            producto.precio = 20.00;
            break;
        case 13:
            strcpy(producto.nombre, "Cup noodles camarón picante");
            producto.precio = 20.00;
            break;
        case 14:
            strcpy(producto.nombre, "Cup noodles fuego");
            producto.precio = 20.00;
            break;
        case 15:
            strcpy(producto.nombre, "UFO res teriyaki");
            producto.precio = 24.00;
            break;
        default:
            printf("Opción inválida.\n");
            return;
    }

    ticket->articulos[ticket->totalProductos] = producto;
    ticket->totalProductos++;
    ticket->totalCompra += producto.precio;
    printf("Producto agregado correctamente.\n");
}

void quitarProducto(struct Ticket *ticket) {
    if (ticket->totalProductos == 0) {
        printf("No hay productos en el ticket.\n");
        return;
    }

    char nombreProducto[100];
    printf("Ingrese el nombre del producto a quitar: ");
    scanf("%s", nombreProducto);

    int i;
    for (i = 0; i < ticket->totalProductos; i++) {
        if (strcmp(ticket->articulos[i].nombre, nombreProducto) == 0) {
            ticket->totalCompra -= ticket->articulos[i].precio;
            ticket->totalProductos--;

            int j;
            for (j = i; j < ticket->totalProductos; j++) {
                ticket->articulos[j] = ticket->articulos[j + 1];
            }

            printf("Producto quitado correctamente.\n");
            return;
        }
    }

    printf("El producto no se encuentra en el ticket.\n");
}

void mostrarTotalProductos(struct Ticket *ticket) {
    printf("Total de productos comprados: %d\n", ticket->totalProductos);
}

void buscarTicket(struct Ticket *tickets) {
    int numeroTicket;
    printf("Ingrese el número de ticket a buscar: ");
    scanf("%d", &numeroTicket);

    int i;
    for (i = 0; i < MAX_TICKETS; i++) {
        if (tickets[i].numeroTicket == numeroTicket) {
            printf("Número de Ticket: %d\n", tickets[i].numeroTicket);
            printf("Artículos comprados y su total por artículo:\n");
            int j;
            for (j = 0; j < tickets[i].totalProductos; j++) {
                printf("%s - %.2f\n", tickets[i].articulos[j].nombre, tickets[i].articulos[j].precio);
            }
            printf("Total gastado: %.2f\n", tickets[i].totalCompra);
            printf("Total de productos comprados: %d\n", tickets[i].totalProductos);
            return;
        }
    }

    printf("Ticket no encontrado.\n");
}

void mostrarTicket(struct Ticket *ticket) {
char nombreArchivo[50];
    sprintf(nombreArchivo, "ticket%d.txt", ticket->numeroTicket);
    FILE *archivo = fopen(nombreArchivo, "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }
 fprintf(archivo, "Número de Ticket: %d\n", ticket->numeroTicket);
    fprintf(archivo, "Artículos comprados y su total por artículo:\n");
 int i;
    for (i = 0; i < ticket->totalProductos; i++) {
        fprintf(archivo, "%s - %.2f\n", ticket->articulos[i].nombre, ticket->articulos[i].precio);
    }
    fprintf(archivo, "Total gastado: %.2f\n", ticket->totalCompra);
    fprintf(archivo, "Total de productos comprados: %d\n", ticket->totalProductos);

    fclose(archivo);

    printf("Ticket guardado en el archivo %s\n", nombreArchivo);
}

void actualizarNumeroProductos(struct Ticket *ticket) {
    int nuevoNumProductos;
    printf("Ingrese el nuevo número de productos: ");
    scanf("%d", &nuevoNumProductos);

    ticket->totalProductos = nuevoNumProductos;
    printf("Número de productos actualizado correctamente.\n");
}

void mostrarTotalCompra(struct Ticket *ticket) {
    printf("El total de su compra es: %.2f\n", ticket->totalCompra);
}

//fin de las funciones.
//inicio de la ejecucion del programa principal.
//HERNANDEZ LOPEZ RAPHAEL DE JHESUS
//CRUZ AGUILAR BRAYAN KHOTAN
int main() {
    struct Ticket tickets[MAX_TICKETS];
    int i;
    for (i = 0; i < MAX_TICKETS; i++) {
        tickets[i].numeroTicket = i + 1;
        tickets[i].totalProductos = 0;
        tickets[i].totalCompra = 0.0;
    }

    int opcion;
    int numeroTicket;
    do {
        printf("===== SISTEMA DE TICKETS DE COMPRAS =====\n");
        printf("1. AGREGAR PRODUCTOS\n");
        printf("2. QUITAR PRODUCTOS\n");
        printf("3. ACTUALIZAR TICKET\n");
        printf("4. EL TOTAL DE SU COMPRA\n");
        printf("5. MOSTRAR TOTAL DE PRODUCTOS\n");
        printf("6. Buscar ticket\n");
        printf("7. Mostrar ticket\n");
        printf("8. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el número del ticket: ");
                scanf("%d", &numeroTicket);
                if (numeroTicket < 1 || numeroTicket > MAX_TICKETS) {
                    printf("Número de ticket inválido.\n");
                    break;
                }
                agregarProducto(&tickets[numeroTicket - 1]);
                break;
            case 2:
                printf("Ingrese el número del ticket: ");
                scanf("%d", &numeroTicket);
                if (numeroTicket < 1 || numeroTicket > MAX_TICKETS) {
                    printf("Número de ticket inválido.\n");
                    break;
                }
                quitarProducto(&tickets[numeroTicket - 1]);
                break;
            case 3:
                printf("Ingrese el número del ticket: ");
                scanf("%d", &numeroTicket);
                if (numeroTicket < 1 || numeroTicket > MAX_TICKETS) {
                    printf("Número de ticket inválido.\n");
                    break;
                }
                actualizarNumeroProductos(&tickets[numeroTicket - 1]);
                break;
            case 4:
                printf("Ingrese el número del ticket: ");
                scanf("%d", &numeroTicket);
                if (numeroTicket < 1 || numeroTicket > MAX_TICKETS) {
                    printf("Número de ticket inválido.\n");
                    break;
                }
                mostrarTotalCompra(&tickets[numeroTicket - 1]);
                break;
            case 5:
                printf("Ingrese el número del ticket: ");
                scanf("%d", &numeroTicket);
                if (numeroTicket < 1 || numeroTicket > MAX_TICKETS) {
                    printf("Número de ticket inválido.\n");
                    break;
                }
                mostrarTotalProductos(&tickets[numeroTicket - 1]);
                break;
            case 6:
                buscarTicket(tickets);
                break;
            case 7:
                printf("Ingrese el número del ticket: ");
                scanf("%d", &numeroTicket);
                if (numeroTicket < 1 || numeroTicket > MAX_TICKETS) {
                    printf("Número de ticket inválido.\n");
                    break;
                }
                mostrarTicket(&tickets[numeroTicket - 1]);
                break;
            case 8:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción inválida. Intente nuevamente.\n");
                break;
        }
    } while (opcion != 8);
//se acaba.
    return 0;
}