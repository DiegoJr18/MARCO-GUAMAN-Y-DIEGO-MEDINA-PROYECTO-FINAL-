#include <stdio.h>
#include "lectu.h"
#include "menu.h"
#include "func.h"
#define MAX_PRODUCTS 100
#define MAX_CLIENTES 100



int main(){
    int opt;
    do
    {
        opt=menuOpcion();
        switch (opt)
        {
            //vamos a simular un CRUD de una base de datos.
            case 1:
                createProduct();
                saveProductsToFile();
                break;
            case 2:
                updateProduct();
                saveProductsToFile();
                break;
            case 3:
                deleteProduct();
                saveProductsToFile();
                break;
            case 4:
                readProducts();
                break;
            case 5:
                createClient();
                break;
            case 6:
                updateClient();
                break;
            case 7:
                searchClient();
                break;
            case 8:
                readClient();
                break;
            case 9:
                facturar();
                saveInvoicesToFile(); 
                break;
            case 10:
                buscarfactura();
                break;
            case 11:
              verfactura();
                break;
            case 12:
            printf("Hasta luego !!\n");
            break;
            default:
                printf("Opcion no valida. Por favor, ingrese una opcion correcta.\n");
                break;
        }
    } while (opt != 12);

    return 0;
}