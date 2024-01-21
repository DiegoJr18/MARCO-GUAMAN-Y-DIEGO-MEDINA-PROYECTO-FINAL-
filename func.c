#include <stdio.h>
#include <string.h>
#include "func.h"
#include "lectu.h"
#include "menu.h"

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_CLIENTES 100
#define MAX_FACTURAS 100

char productos[MAX_PRODUCTS][4][MAX_NAME_LENGTH];
int numProductos = 0;
int numClientes =0;
char clientes[MAX_CLIENTES][3][MAX_NAME_LENGTH];
char facturas[MAX_FACTURAS][6][MAX_NAME_LENGTH];
int numFacturas = 0;
void createProduct() {
    int numProductsToAdd;
    printf("Ingrese la cantidad de productos que desea agregar: ");
    scanf("%d", &numProductsToAdd);
    for (int i = 0; i < numProductsToAdd; i++) {
        static int id = 1;
        if (numProductos < MAX_PRODUCTS) {
            sprintf(productos[numProductos][0], "%d", id);
            printf("Ingrese el nombre del producto: ");
            getchar(); 
            fgets(productos[numProductos][1], sizeof(productos[numProductos][1]), stdin);
            productos[numProductos][1][strcspn(productos[numProductos][1], "\n")] = '\0';
            printf("Ingrese la cantidad del producto: ");
            scanf("%s", productos[numProductos][2]);
            printf("Ingrese el precio del producto: ");
            scanf("%s", productos[numProductos][3]);
            id++;
            numProductos++;
            printf("Producto agregado correctamente.\n");
        } else {
            printf("No se pueden agregar más productos, límite alcanzado.\n");
            break;  // Exit the loop if the maximum number of products is reached
        }
    }
}
void saveProductsToFile() {
    FILE *file = fopen("productos.txt", "w");  // Open the file in write mode (will overwrite existing content)
    if (file == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }
    for (int i = 0; i < numProductos; i++) {
        fprintf(file, "%s,%s,%s,%s\n", productos[i][0], productos[i][1], productos[i][2], productos[i][3]);
    }
    fclose(file);  // Close the file after writing
}
void createClient() {
    static int idCliente = 1;
    if (numClientes < MAX_CLIENTES) {
        sprintf(clientes[numClientes][0], "%d", idCliente);
        printf("Ingrese el nombre del cliente: ");
        getchar(); 
        fgets(clientes[numClientes][1], sizeof(clientes[numClientes][1]), stdin);
        clientes[numClientes][1][strcspn(clientes[numClientes][1], "\n")] = '\0';
        // Validación de la cédula con un bucle
        int cedulaValida = 0;
        while (!cedulaValida) {
            printf("Ingrese la cédula del cliente (10 dígitos numéricos): ");
            fgets(clientes[numClientes][2], sizeof(clientes[numClientes][2]), stdin);
            clientes[numClientes][2][strcspn(clientes[numClientes][2], "\n")] = '\0';
            // Verificar que la cédula tiene exactamente 10 caracteres numéricos
            int i, cedulaLen = strlen(clientes[numClientes][2]);
            cedulaValida = 1; // Suponemos que la cédula es válida
            if (cedulaLen != 10) {
                cedulaValida = 0;
            } else {
                for (i = 0; i < cedulaLen; i++) {
                    if (!isdigit(clientes[numClientes][2][i])) {
                        cedulaValida = 0;
                        break;
                    }
                }
            }
            // Check for duplicate cedulas
            for (int i = 0; i < numClientes; i++) {
                if (strcmp(clientes[i][2], clientes[numClientes][2]) == 0) {
                    cedulaValida = 0;
                    printf("La cédula ya existe para otro cliente. Ingrese una cédula distinta.\n");
                    break;
                }
            }
            if (!cedulaValida) {
                printf("La cédula ingresada no es válida. Debe tener exactamente 10 dígitos numéricos.\n");
                // No almacenar la cédula en el arreglo si no es válida
            }
        }
        if (cedulaValida) {
            idCliente++;
            numClientes++;
            printf("Cliente agregado correctamente.\n");
        }
    } else {
        printf("No se pueden agregar más clientes, límite alcanzado.\n");
    }
}

void readProducts() {
    if (numProductos == 0) {
        printf("No hay productos para mostrar.\n");
    } else {
        printf("     Listado de productos:\n");
        printf("ID\tNombre\t\t\tCantidad\tPrecio\n");
        for (int i = 0; i < numProductos; i++) {
            printf("%s\t%-20s\t%s\t\t$%s\n", productos[i][0], productos[i][1], productos[i][2], productos[i][3]);
        }
    }
}
void readClient(){
    if(numClientes ==0){
        printf("No hay Clientes para mostrar.\n");
    }   else {
        printf("     Listado de Clientes:\n");
        printf("ID\tNombre\t\t\tCedula\t\n");
        for (int i = 0; i < numClientes; i++) {
            printf("%s\t%-20s\t%-10s\n", clientes[i][0], clientes[i][1], clientes[i][2]);
        }
    } 

}

void updateProduct() {
    char id[MAX_NAME_LENGTH];
    printf("Ingrese el ID del producto a editar: ");
    scanf("%s", id);

    int indice = -1;
    for (int i = 0; i < numProductos; i++) {
        if (strcmp(productos[i][0], id) == 0) {
            int opcion;
            opcion = menuEdit();
            switch (opcion) {
                case 1:
                    printf("Ingrese el nuevo nombre del producto: ");
                    getchar(); // Limpiar el buffer
                    fgets(productos[i][1], sizeof(productos[i][1]), stdin);
                    productos[i][1][strcspn(productos[i][1], "\n")] = '\0'; // Eliminar el salto de línea
                    printf("Nombre actualizado correctamente.\n");
                    break;
                case 2:
                    printf("Ingrese la nueva cantidad del producto: ");
                    scanf("%s", productos[i][2]);
                    printf("Cantidad actualizada correctamente.\n");
                    break;
                case 3:
                    printf("Ingrese el nuevo precio del producto: ");
                    scanf("%s", productos[i][3]);
                    printf("Precio actualizado correctamente.\n");
                    break;
                default:
                    printf("Opción no válida.\n");
                    break;
            }
            return;
        }
    }
    printf("Producto no encontrado.\n");
}
void updateClient() {
    char id[MAX_NAME_LENGTH];
    printf("Ingrese el ID del cliente a editar: ");
    scanf("%s", id);

    int indice = -1;
    for (int i = 0; i < numClientes; i++) {
        if (strcmp(clientes[i][0], id) == 0) {
            int opcion;
            opcion = menuEditClient();
            switch (opcion) {
                case 1:
                    printf("Ingrese el nuevo nombre del cliente: ");
                    getchar(); 
                    fgets(clientes[i][1], sizeof(clientes[i][1]), stdin);
                    clientes[i][1][strcspn(clientes[i][1], "\n")] = '\0';
                    printf("Nombre actualizado correctamente.\n");
                    break;
                case 2:
                    printf("Ingrese la nueva cédula del cliente: ");
                    getchar(); 
                    fgets(clientes[i][2], sizeof(clientes[i][2]), stdin);
                    clientes[i][2][strcspn(clientes[i][2], "\n")] = '\0';
                    printf("Cédula actualizada correctamente.\n");
                    break;
                default:
                    printf("Opción no válida.\n");
                    break;
            }
            return;
        }
    }
    printf("Cliente no encontrado.\n");
}



void deleteProduct() {
    char id[MAX_NAME_LENGTH];
    printf("Ingrese el ID del producto a eliminar: ");
    scanf("%s", id);

    int indice = -1;
    for (int i = 0; i < numProductos; i++) {
        if (strcmp(productos[i][0], id) == 0) {
            indice = i;
            break;
        }
    }

    if (indice != -1) {
        for (int i = indice; i < numProductos - 1; i++) {
            strcpy(productos[i][0], productos[i + 1][0]);
            strcpy(productos[i][1], productos[i + 1][1]);
            strcpy(productos[i][2], productos[i + 1][2]);
            strcpy(productos[i][3], productos[i + 1][3]);
        }
        numProductos--;
        printf("Producto eliminado correctamente.\n");
    } else {
        printf("Producto no encontrado.\n");
    }
}
void searchClient() {
    char cedula[MAX_NAME_LENGTH];
    printf("Ingrese la cédula del cliente que desea buscar: ");
    getchar(); 
    fgets(cedula, sizeof(cedula), stdin);
    cedula[strcspn(cedula, "\n")] = '\0';

    int encontrado = 0;

    for (int i = 0; i < numClientes; i++) {
        if (strcmp(clientes[i][2], cedula) == 0) {
            printf("Cliente encontrado:\n");
            printf("ID: %s\n", clientes[i][0]);
            printf("Nombre: %s\n", clientes[i][1]);
            printf("Cédula: %s\n", clientes[i][2]);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("No se encontró ningún cliente con la cédula proporcionada.\n");
    }
}
void facturar() {
    if (numClientes == 0 || numProductos == 0) {
        printf("No hay clientes o productos para facturar.\n");
        return;
    }

    char cedula[MAX_NAME_LENGTH];
    printf("Ingrese la cédula del cliente: ");
    getchar(); 
    fgets(cedula, sizeof(cedula), stdin);
    cedula[strcspn(cedula, "\n")] = '\0';

    int indiceCliente = -1;
    for (int i = 0; i < numClientes; i++) {
        if (strcmp(clientes[i][2], cedula) == 0) {
            indiceCliente = i;
            break;
        }
    }

    if (indiceCliente == -1) {
        printf("Cliente no encontrado.\n");
        return;
    }

    char fecha[MAX_NAME_LENGTH];
    printf("Ingrese la fecha de la factura (DD/MM/YYYY): ");
    fgets(fecha, sizeof(fecha), stdin);
    fecha[strcspn(fecha, "\n")] = '\0';

    char valorPagado[MAX_NAME_LENGTH];
    printf("Ingrese el valor total pagado: ");
    scanf("%s", valorPagado);

    int cantidadProductos;
    printf("Ingrese la cantidad de productos comprados: ");
    scanf("%d", &cantidadProductos);

    if (numFacturas < MAX_FACTURAS) {
        strcpy(facturas[numFacturas][0], cedula);
        strcpy(facturas[numFacturas][1], clientes[indiceCliente][1]);
        strcpy(facturas[numFacturas][2], fecha);
        strcpy(facturas[numFacturas][3], valorPagado);
        sprintf(facturas[numFacturas][4], "%d", cantidadProductos);

        numFacturas++;
        printf("Factura generada correctamente.\n");
    } else {
        printf("No se pueden generar más facturas, límite alcanzado.\n");
    }
}

void buscarfactura() {
    if (numFacturas == 0) {
        printf("No hay facturas para buscar.\n");
        return;
    }

    char cedula[MAX_NAME_LENGTH];
    printf("Ingrese la cédula del cliente: ");
    getchar(); 
    fgets(cedula, sizeof(cedula), stdin);
    cedula[strcspn(cedula, "\n")] = '\0';

    int encontradas = 0;

    for (int i = 0; i < numFacturas; i++) {
        if (strcmp(facturas[i][0], cedula) == 0) {
            printf("Cédula: %s\n", facturas[i][0]);
            printf("Nombre: %s\n", facturas[i][1]);
            printf("Fecha: %s\n", facturas[i][2]);
            printf("Valor Pagado: $%s\n", facturas[i][3]);
            printf("Cantidad de Productos Comprados: %s\n", facturas[i][4]);
            encontradas++;
        }
    }

    if (encontradas == 0) {
        printf("No se encontraron facturas para el cliente con la cédula proporcionada.\n");
    }
}

void verfactura() {
    if (numFacturas == 0) {
        printf("No hay facturas para mostrar.\n");
        return;
    }

    printf("     Listado de Facturas:\n");
    printf("Cédula\tNombre\t\t\tFecha\t\tValor Pagado\tCantidad de Productos\n");
    for (int i = 0; i < numFacturas; i++) {
        printf("%s\t%-20s\t%s\t$%s\t\t%s\n", facturas[i][0], facturas[i][1], facturas[i][2], facturas[i][3], facturas[i][4]);
    }
}

void saveInvoicesToFile() {
    FILE *file = fopen("facturas.txt", "w");  // Open the file in write mode (will overwrite existing content)
    if (file == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }
    for (int i = 0; i < numFacturas; i++) {
        fprintf(file, "%s,%s,%s,%s,%s\n", facturas[i][0], facturas[i][1], facturas[i][2], facturas[i][3], facturas[i][4]);
    }
    fclose(file);  // Close the file after writing
}
