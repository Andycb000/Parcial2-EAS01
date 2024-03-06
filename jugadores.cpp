#include "jugador.h"
#include "enemigo.h"
#include <iostream>
#include <string>
#include <cstdlib> // Función rand().
#include <ctime>   // Función time() para generar una nueva seed aleatoria.
using namespace std;

#define log(x) cout << x << endl;

int main()
{
    srand(time(0)); // Seed para generar valores aleatorios

    /*
        Crear al menos 2 jugadores con diferentes nombres, vida y ataque.
        Los jugadores deben atacarse entre sí, tomando turnos, hasta que uno pierda toda su vida.
        En cuanto la vida del jugador se reduzca a 0 el programa muestra al ganador y se termina.
        No importa quien ataca primero.
    */

    Jugador j1(100, 10, "Mario");
    Jugador j2(100, 10, "Carlos");

    while (j1.vida > 0 && j2.vida > 0)
    {
        j1.atacarJugador(j2);
        if (j2.vida <= 0)
        {
            cout << j1.nombre << " es el ganador" << endl;
            break;
        }

        j2.atacarJugador(j1);
        if (j1.vida <= 0)
        {
            cout << j2.nombre << " es el ganador" << endl;
            break;
        }
    }

    return 0;
}