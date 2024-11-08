#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>

using namespace std; 

//ESTRUCTURAS DE DATOS
struct movies
{
    string name, genre;
    int year,time;
    movies*next;
};


struct users
{
    string mail, country;
    int age;
    users*next;
};

//FUNCIONES

void escribirArchivoUsuarios(users**head){
    ofstream archivo;
    users *aux=*head;
    archivo.open("usuarios.txt", ios::out);
    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo."<<endl;
        return ;
    }
    while(aux){
        archivo<<aux->mail<<endl;
        archivo<<aux->country<<endl;
        archivo<<aux->age<<endl;
        aux=aux->next;
    }
    archivo.close();
}

void escribirArchivoPeliculas(movies**head){
    ofstream archivo;
    movies*aux=*head;
    archivo.open("peliculas.txt", ios::out);
    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo."<<endl;
        return ;
    }
    while(aux){
        archivo<<aux->name<<endl;
        archivo<<aux->genre<<endl;
        archivo<<aux->year<<endl;
        archivo<<aux->time<<endl;
        aux=aux->next;
    }
    archivo.close();
}



void insert_movie(movies **head,string name, string genre,int year,int time){ //Inserta por cabeza
    movies *new_node=new movies;
    new_node->name=name;
    new_node->genre=genre;
    new_node->year=year;
    new_node->time=time;
    new_node->next=*head;
    *head=new_node;
    escribirArchivoPeliculas(head);
}

void insert_user(users **head,string mail, string country,int age){ //Inserta por cabeza
    users*new_node=new users;
    new_node->mail=mail;
    new_node->country=country;
    new_node-> age= age;
    new_node->next=*head;
    *head=new_node;
    escribirArchivoUsuarios(head);
}


void delete_movie(movies**head,string name){
    if(head){
        movies*aux;
        movies*prev=NULL;
        aux=*head;
        while((aux)&&(aux->name!=name)){
            prev=aux;
            aux=aux->next;
        }
        if(aux==NULL)cout<<"La pelicula a eliminar no existe";
        else if(prev==NULL){
            *head=aux->next;
            delete aux;
        }
        else{
            prev->next=aux->next;
            delete aux;
        }
        escribirArchivoPeliculas(head);

    }
}

void delete_user(users**head,string mail){
    if(head){
        users*aux;
        users*prev=NULL;
        aux=*head;
        while((aux)&&(aux->mail!=mail)){
            prev=aux;
            aux=aux->next;
        }
        if(aux==NULL)cout<<"El usuario a eliminar no existe";
        else if(prev==NULL){
            *head=aux->next;
            delete aux;
        }
        else{
            prev->next=aux->next;
            delete aux;
        }
        escribirArchivoUsuarios(head);
    }

}


void leerArchivoUsuarios(users **head){
    ifstream archivo;
    string mail, country, age;
    archivo.open("usuarios.txt", ios::out);
    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo."<<endl;
        return;
    }
    while(!archivo.eof()){
        getline(archivo, mail);
        if(!mail.empty()){
            getline(archivo, country);
            getline(archivo, age);
            insert_user(head, mail, country, stoi(age));
        }
            
    }
}


void leerArchivoPeliculas(movies **head){
    ifstream archivo;
    string name, genre, year, time;
    archivo.open("peliculas.txt", ios::out);
    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo."<<endl;
        return;
    }
    while(!archivo.eof()){
        getline(archivo, name);
        if(!name.empty()){
            getline(archivo, genre);
            getline(archivo, year);
            getline(archivo, time);
            insert_movie(head, name, genre, stoi(year),stoi(time));
        }
            
    }
}

void mostrar_movies(movies *head) {
    if (head) {
        movies *actual = head;
        while (actual != NULL) {
            cout << actual->name <<" "<< actual->genre<<"->";
            actual = actual->next;
        }
    }
        cout << "NULL"<<endl;  
}

void mostrar_users(users*head) {
    if (head) {
        users *actual = head;
        while (actual != NULL) {
            cout << actual->mail << "->";
            actual = actual->next;
        }
    }
        cout << "NULL"<<endl;  
}

//validar peliculas
bool is_valid_name(const string &name) {
    if (name.empty()) {
        cout << "Error: El nombre de la pelicula no puede estar vacio." << endl;
        return false; // No es válido
    }
    return true; // Es válido
}

bool is_valid_genre(const string &genre) {
    if (genre.empty()) {
        cout << "Error: El genero de la pelicula no puede estar vacio." << endl;
        return false; // No es válido
    }
    return true; // Es válido
}

bool is_valid_year(int year) {
    if (year <= 1895) {
        cout << "Error: El año de lanzamiento no es valido. Debe ser mayor a 1895." << endl;
        return false; // No es válido
    }
    return true; // Es válido
}

bool is_valid_time(int time) {
    if (time <= 0) {
        cout << "Error: La duracion debe ser un número positivo." << endl;
        return false; // No es válido
    }
    return true; // Es válido
}

void insert_movie_with_validation(movies **head) {
    string name, genre;
    int year = 0, time = 0;

    getline(cin, name);
    // Solicitar el nombre de la película
    while (true) {
        cout << "Ingrese el nombre de la pelicula: ";
        getline(cin, name);
        if (is_valid_name(name)) break; // Salir del bucle si es válido
    }

    // Solicitar el género de la película
    while (true) {
        cout << "Ingrese el genero de la pelicula: ";
        getline(cin, genre);
        if (is_valid_genre(genre)) break; // Salir del bucle si es válido
    }

    // Solicitar el año de lanzamiento
    while (true) {
        cout << "Ingrese el ano de lanzamiento (mayor a 1894): ";
        cin >> year;
        if (is_valid_year(year)) break; // Salir del bucle si es válido
    }

    // Solicitar la duración en minutos
    while (true) {
        cout << "Ingrese la duracion en minutos (numero positivo): ";
        cin >> time;
        cin.ignore(); // Limpiar el buffer de entrada
        if (is_valid_time(time)) break; // Salir del bucle si es válido
    }

    // Inserción si todas las validaciones son correctas
    insert_movie(head,name,genre,year,time);
    cout << "Pelicula '" << name << "' agregada exitosamente." << endl;
}
//validacion usuario
bool is_valid_email(const string &email) {
    const regex pattern(R"((\w+)(\.{1}\w+)*@(\w+)(\.\w+)+)");
    if (!regex_match(email, pattern)) {
        cout << "Error: El correo electronico no es valido." << endl;
        return false; // No es válido
    }
    return true; // Es válido
}

bool is_valid_country(const string &country) {
    if (country.empty()) {
        cout << "Error: El pais no puede estar vacio." << endl;
        return false; // No es válido
    }
    return true; // Es válido
}

bool is_valid_age(int age) {
    if (age < 0) {
        cout << "Error: La edad no puede ser negativa." << endl;
        return false; // No es válido
    }
    return true; // Es válido
}

void insert_user_with_validation(users **head) {
    string mail, country;
    int age = 0;

    // Solicitar el correo del usuario
    getline(cin, mail);
    while (true) {
        cout << "Ingrese el correo electronico del usuario: ";
        getline(cin, mail);
        if (is_valid_email(mail)) break; // Salir del bucle si es válido
    }

    // Solicitar el país del usuario
    while (true) {
        cout << "Ingrese el pais del usuario: ";
        getline(cin, country);
        if (is_valid_country(country)) break; // Salir del bucle si es válido
    }

    // Solicitar la edad del usuario
    while (true) {
        cout << "Ingrese la edad del usuario (numero positivo): ";
        cin >> age;
        if (is_valid_age(age)) break; // Salir del bucle si es válido
    }

    // Inserción si todas las validaciones son correctas
    insert_user(head, mail, country, age);
    cout << "Usuario '" << mail << "' agregado exitosamente." << endl;
}

