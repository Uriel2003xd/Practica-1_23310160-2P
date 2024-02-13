#include <iostream>
#include <string.h>

using namespace std;

class Usuario {
protected: //Acceso a las subclases
    char nombre[50];
    char telefono[15];
    int edad;
    char loginNombre[20];
    char loginContrasena[20];

public:

    Usuario(const char* _nombre, const char* _telefono, int _edad, const char* _loginNombre, const char* _loginContrasena) { //puntero * no se puede modificar.
        strcpy(nombre,_nombre); //strcpy nos permite copiar una cadena el contenido de otra.
        strcpy(telefono, _telefono);
        edad = _edad;
        strcpy(loginNombre, _loginNombre);
        strcpy(loginContrasena, _loginContrasena);
        
        printf("Bienvenido %s.\n", nombre);
        printf("Telefono del usuario: %s.\n", telefono);
        printf("Edad del usuario: %i.\n", edad);
        printf("Introduce el nombre de usuario: %s.\n", loginNombre);
        printf("Introduce la contraseña: %s.\n", loginContrasena);
    }

    void logout() {
        printf("El Usuario %s ha cerrado sesión.\n", nombre);
    }

    void cambiarContrasena(const char* nuevaContrasena) {
        strcpy(loginContrasena, nuevaContrasena);
        printf("La contraseña ha sido cambiada con éxito para el usuario %s\n", nombre);
        printf("Se ha cambiado por %s\n", nuevaContrasena);
    }
};

class Cliente : public Usuario {
public:
    Cliente(const char* _nombre, const char* _telefono, int _edad, const char* _loginNombre, const char* _loginContrasena)//puntero * no se puede modificar.
        : Usuario(_nombre, _telefono, _edad, _loginNombre, _loginContrasena) {}

    void comprar() {
        printf("Cliente %s ha realizado una compra.\n", nombre);
    }

    void reclamar() {
        printf("Cliente %s ha realizado una reclamación.\n", nombre);
    }

    void devolucion() {
        printf("Cliente %s ha realizado una devolución.\n", nombre);
    }
};

class Vendedor : public Usuario {
public:
    Vendedor(const char* _nombre, const char* _telefono, int _edad, const char* _loginNombre, const char* _loginContrasena)
        : Usuario(_nombre, _telefono, _edad, _loginNombre, _loginContrasena) {}

    void vender() {
        printf("El vendedor %s ha realizado una venta.\n", nombre);
    }

    void actualizar() {
        printf("EL vendedor %s ha actualizado información.\n", nombre);
    }
};

int main() {
    Cliente cliente("Uriel Arriaga", "3312511181", 20, "UrielCeti160", "contra123");
    Vendedor vendedor("Marcelo", "123456789", 21, "MarceloBee", "Abejas123");

    cliente.comprar();
    cliente.reclamar();
    cliente.devolucion();
    cliente.cambiarContrasena("NewContra123");
    cliente.logout();

    vendedor.vender();
    vendedor.actualizar();
    vendedor.cambiarContrasena("NewAbejas123");
    vendedor.logout();

    return 0;
}