#include <iostream>
#include "structs.h"
#include "functions.h"



using namespace std;

int main() {
	int resp;
    movies*head = NULL;
    users*head_user=NULL;
    leerArchivoUsuarios(&head_user);
    leerArchivoPeliculas(&head);
	do {
		cout << "MENU\n\n";
		cout << "1) Isertar usuario\n";
		cout << "2) Insertar peliculas\n";
        cout << "3) Eliminar pelicula \n";
        cout << "4) Eliminar usuario \n";
		cout << "5) Mostrar peliculas\n";
		cout << "6) Mostar usuario \n";
		cout << "5) Eliminar elemento\n";
		cout << "0) Salir\n\n";
		cout << "\tMarque su opcion: ";
		cin >> resp;
        switch (resp) {
            case 0: {
                cout << "Finalizando programa";            
            } break;


            case 1: {
                string mail,country;
                int age;
                cout << "Ingrese el mail del usuario:\n";
                cin>>mail;
                cout << "\tIngrese el pais: ";
                cin >> country;
                cout << "\tIngrese la edad: ";
                cin >> age;
                insert_user(&head_user,mail,country,age);
                
            } break;

            case 2: {
                string name, genre;
                int year,time;
                cout << "\tIngrese el nombre de la pelicula: ";
                cin >> name;
                cout << "\tIngrese el genero de la pelicula: ";
                cin >> genre;
                cout << "\tIngrese año de estreno: ";
                cin >> year;
                cout << "\tIngrese la duracion de la pelicula en minutos: ";
                cin >> time;
                insert_movie(&head,name,genre,year,time);
            } break;
            case 3: {
                string mail;
                cout << "\tIngrese el correo del usuario a eliminar: ";
                cin >> mail;
                delete_user(&head_user,mail);
            } break;
            case 4: {
                string name;
                cout << "\tIngrese el nombre de la peliculam a eliminar: ";
                cin >> name;
                delete_movie(&head,name);
            } break;
            
            
            default:
                cout << "Opción no valida";
                break;
        }
		
    } while(resp);
    return 0;
}