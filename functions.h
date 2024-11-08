#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

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
            cout << actual->name << actual->genre<<"->";
            actual = actual->next;
        }
    }
        cout << "NULL"<<endl;  
}

void mostar_users(users*head) {
    if (head) {
        users *actual = head;
        while (actual != NULL) {
            cout << actual->mail << "->";
            actual = actual->next;
        }
    }
        cout << "NULL"<<endl;  
}