#include <iostream>
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
		cout << "0) Salir\n\n";
		cout << "\tMarque su opcion: ";
		cin >> resp;
        switch (resp) {
            case 0: {
                cout << "Finalizando programa";            
            } break;


            case 1: {
                insert_user_with_validation(&head_user);
                
            } break;

            case 2: {
                insert_movie_with_validation(&head);
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
            case 5: {
                cout << "\tEstas son las peliculas: ";
                mostrar_movies(head);
            } break;
            case 6: {
                cout << "\t Estas son los usuarios: ";
                mostrar_users(head_user); //es para que vea como se agg a la lista
            } break;
            
            
            
            default:
                cout << "Opción no valida";
                break;
        }
		
    } while(resp);
    return 0;
}