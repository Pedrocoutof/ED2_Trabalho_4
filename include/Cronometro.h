#ifndef CRONOMETRO_H
#define CRONOMETRO_H
#include "time.h"


class Cronometro
{
    private:
        double tempoGasto;
        clock_t tempoInicial;
        clock_t tempoFinal;

    public:
        void IniciaCronometro();
        void FinalizaCronometro();
        double getTempoGasto();
        Cronometro();
        virtual ~Cronometro();

};

#endif // CRONOMETRO_H
