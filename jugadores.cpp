#include <iostream>
#include <string>
#include <cstdlib>  // Función rand().
#include <ctime>    // Función time() para generar una nueva seed aleatoria.
using namespace std;

#define log(x) cout << x << endl;

class Jugador{
    public:
    int vida;
    int ataque;
    string nombre;
    string atacadoPor;
    
    /*
        Agrega propiedades para guardar la vida(número entero), ataque(número entero) y nombre del jugador.
        Agrega una propiedad para guardar el jugador que lo atacó por última vez.
    */
    
    Jugador(); 
    Jugador(int hp, int attack, string nom); 
    
    void atacar(Jugador objetivo); 
};

int main()
{
    srand(time(0));  // Seed para generar valores aleatorios

    Jugador j1(150, 5, "primero");
    Jugador j2(80, 20, "segundo");

    while (j1.vida>0 && j2.vida>0)
    {
        j1.atacar(j2);
        if(j2.vida<=0)
        {
            cout << "Felicidades " << j1.nombre << ", ganaste el juego" << endl;
            goto fin;
        }
        j2.atacar(j1);
        if(j1.vida<=0)
        {
            cout << "Felicidades " << j2.nombre << ", ganaste el juego" << endl;
            goto fin;
        }
    }
    /*
        Crear al menos 2 jugadores con diferentes nombres, vida y ataque. 
        Los jugadores deben atacarse entre sí, tomando turnos, hasta que uno pierda toda su vida.
        En cuanto la vida del jugador se reduzca a 0 el programa muestra al ganador y se termina. 
        No importa quien ataca primero.
    */
fin:
    return 0;
}

Jugador::Jugador()
{
    vida=100;
    ataque=5;
    nombre="No definido";
    /*
        Asignar 100 a hp y 5 a attack como valores default.
        Asignar 'No definido' al nombre como default.
    */
}

Jugador::Jugador(int hp, int attack, string nom)
{
    if(hp>0 && hp<=200)
    {
        vida=hp;
    }
    if(attack>0 && attack<=20)
    {
        ataque=attack;
    }
    nombre=nom;
    /*
        Asignar los parámetros recibidos a las propiedades del objeto.
        No se pueden asignar valores negativos a hp y attack.
        Máximo 200 hp y 20 attack
    */
}

void Jugador::atacar(Jugador objetivo)
{
    int x = rand()%1000;
    if (x>200)
    {
        objetivo.vida = objetivo.vida-ataque;
        cout << nombre << " atacó a " << objetivo.nombre << " e hizo " << ataque << " de daño, vida restante de " << objetivo.nombre << "= " << objetivo.vida << endl;
    } 
    else
    {
        cout << nombre << " atacó a " << objetivo.nombre << " pero fallo, vida restante de " << objetivo.nombre << "= " << objetivo.vida << endl;
    }
    objetivo.atacadoPor=nombre;
    /*
        El jugador atacado(el que recibes como parámetro) pierde HP igual al ataque del jugador que ataca.
        Existe un 20% de probabilidad de que el ataque falle y no haga daño.
        Se debe mostrar lo que pasó en cada ataque:
        nombre1 atacó a nombre2 e hizo 5 de daño, vida restante de nombre2 = 95
        nombre2 atacó a nombre1 pero fallo, vida restante de nombre1 = 100
        El jugador que atacó debe quedar guardar en la propiedad atacadoPor del jugador atacado.
    */
    /*
    Nota:
        int x = rand()%1000; asigna un valor aleatorio entre 0 y 999 a x;
        Puedes usar esto para la probabilidad del ataque.
    */
}