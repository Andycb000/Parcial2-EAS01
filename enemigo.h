#ifndef enemigo_h
#define enemigo_h

#include "jugador.h"

class Base;
class Enemigo, public Base
{
    public:

    Enemigo();
    Enemigo(int hp, int attack, string nom);
    
    void atacarJugador(Jugador j2);
};


#endif

