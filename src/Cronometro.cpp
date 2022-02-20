#include "Cronometro.h"

Cronometro::Cronometro()
{
    this->tempoGasto = 0;
}

Cronometro::~Cronometro() {}

void Cronometro::IniciaCronometro(){
    this->tempoGasto = 0;
    this->tempoInicial = clock();
}

void Cronometro::FinalizaCronometro(){
    this->tempoFinal = clock();
    this->tempoGasto += (double) (this->tempoFinal - this->tempoInicial) / CLOCKS_PER_SEC;
}

double Cronometro::getTempoGasto(){
    return this->tempoGasto;
}
