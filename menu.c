#include <stdio.h>
#include "lectu.h"
#include "menu.h"

int menuOpcion(){
    printf("Bienvenido a LIBSTOCK\nMenú:\n1. Registro de Productos\n2. Actualizar Productos\n3. Eliminar Productos\n4. Listar Productos\n5. Ingresar Cliente\n6. Modificar Cliente\n7. Buscar Cliente\n8. Listar Clientes\n9. Facturar\n10. Buscar Factura\n11. Ver Facturas\n12. Salir\n");
    int opt=leerEnteroEntre("Ingrese Opcion: ",1,12);
    return opt;
}

int menuEdit(){
    printf("Sel el campo a editar:\n1. Nombre\n2. Cantidad\n3. Precio\n4. Cancelar\n");
    int opt=leerEnteroEntre("Ingrese Opcion: ",1,4);
    return opt;
}

int menuEditClient() {
    printf("Seleccione el campo a editar:\n1. Nombre\n2. Cédula\n3. Cancelar\n");
    int opt = leerEnteroEntre("Ingrese Opción: ", 1, 3);
    return opt;
}

