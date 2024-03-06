#ifndef enemigo_h
#define enemigo_h

#include "jugador.h"

class Enemigo
{
    public:
    int vida;
    int ataque;
    string nombre;

    Enemigo();
    Enemigo(int hp, int attack, string nom);
    
    void atacarJugador(Jugador j2);
};


#endif

