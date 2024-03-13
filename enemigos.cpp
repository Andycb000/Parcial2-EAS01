#include "jugador.h"
#include "enemigo.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;


Enemigo::Enemigo()
{
    this->vida = 100;
    this->ataque = 5;
    this->nombre = "No definido";
}

Enemigo::Enemigo(int vida, int attack, string nombre)
{
    this->vida = vida;
    if (vida > 200)
        this->vida = 200;
    if (vida <= 0)
        this->vida = 1;

    this->ataque = attack;
    if (ataque > 200)
        this->ataque = 200;
    if (attack <= 0)
        this->ataque = 1;

    this->nombre = nombre;
}

void Enemigo::atacarJugador(Jugador j2)
{
    int ran = rand() % 5;
    if (ran == 0)
    {
        cout << this->nombre << " ataco a " << j2.nombre << " pero fallo, vida restante de " << j2.nombre << " = " << j2.vida << endl;
    }
    else
    {
        j2.vida -= this->ataque;
        cout << this->nombre << " ataco a " << j2.nombre << " e hizo " << this->ataque << " de danio, vida restante de " << j2.nombre << " = " << j2.vida << endl;
    }

    j2.atacadoPor = this;
}