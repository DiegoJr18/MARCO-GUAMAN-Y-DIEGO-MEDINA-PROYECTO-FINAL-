#ifndef FUNC_H
#define FUNC_H

#define MAX_PRODUCTS 100
#define MAX_CARACTERS 50
#define MAX_CLIENTES 100
#define MAX_FACTURAS 100


extern int numProducts;
extern int products[MAX_PRODUCTS][4]; //son varibles globales es decir se pueden usar en todo el programa.

extern int  numClients;
void createProduct();
void updateProduct();
void deleteProduct();
void readProducts();
void saveProductsToFile();
void createClient();
void updateClient();
void readClient();
void searchClient();
void saveInvoicesToFile();

void facturar();
void buscarfactura();
void verfactura();

#endif /// Esto evita la inclusión de este archivo dos veces o mas.