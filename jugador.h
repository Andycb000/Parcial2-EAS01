#ifndef jugador_h
#define jugador_h
#include <string>
using namespace std;

class Base;
class Enemigo;

class Jugador, public Base
{
public:
    Jugador *atacadoPor;

    Jugador();
    Jugador(int vida, int attack, string nombre);

    void atacarJugador(Jugador &j2);
    void atacarEnemigo(Enemigo &en);
};



#endif