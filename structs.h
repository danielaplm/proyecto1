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

struct series
{
    string name, genre;
    int year;
    series*next;
    seasons*season;

};

struct seasons
{
    string name;
    int year;
    seasons*next;
    episodes*episode;
};

struct episodes
{
    string name;
    int year,time,num_episodes;
    episodes*next;
};

struct user
{
    string mail, country;
    int age;
    user*next;
};

struct punctuation
{
    string type,name_content; // "pelicula" o "serie"
    float points;
    punctuation*next;
};

struct review
{
    string type,name_content, text; // "pelicula", "serie", "temporada" o "capitulo"
    review *next;
};
