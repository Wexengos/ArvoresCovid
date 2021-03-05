#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <sstream>
#include <climits>
#include <stdio.h>
#include <string.h>
#include "RegistroCoordinates.h"

RegistroCoordinates::RegistroCoordinates()
{
    dataCompleta = "";
    cidade_nome = "";
    cidadeCodigo = -1;
    latitude = -1;
    longitude =-1;
    codigoEstado =-1;
   
}
RegistroCoordinates::~RegistroCoordinates() {}

void RegistroCoordinates::leArquivoCoordi(RegistroCoordinates *r,int N)
{
    ifstream arq("brazil_cities_coordinates.csv");

    if(!arq.is_open()){
        cout<<"ERRO LEITURA DE ARQUIVO!"<<endl;
        return;
    }
    string linha,dataCompleta,capital,nom,stringT,stringCodigoCidade,stringT2,stringT3;
    int estadoCodigo;
    float lat,longe, cidadeCodigo;
    int conta = 0;

   //Pula a primeira linha; 
    getline(arq,linha);

    while (getline(arq,linha))
    {
        stringstream ss(linha);
        getline(ss,stringT,',');
        istringstream(stringT)>>estadoCodigo;
        r[conta].setCodigoEstado(estadoCodigo);
        getline(ss,stringCodigoCidade,',');
        istringstream(stringCodigoCidade)>>cidadeCodigo;
        r[conta].setcidadeCodigo(cidadeCodigo);
        getline(ss,nom,',');
        r[conta].setcidade_nome(nom);
        getline(ss,stringT2,',');
        istringstream(stringT2)>>lat;
        r[conta].setLatitude(lat);
        getline(ss,stringT3,',');
        istringstream(stringT3)>>longe;
        r[conta].setLongitude(longe);
        getline(ss,capital,',');
        
        
        
       
        

        if(conta>N)
            break;
        conta++;

    }
    cout<<"Arquivo lido com->"<<conta<<"cidades!"<<endl;
    arq.close();
    

}



void RegistroCoordinates::setcidade_nome(string cidadeNome)
{
    this->cidade_nome =  cidadeNome;
}

string RegistroCoordinates::getcidade_nome()
{
    return cidade_nome;

}
void RegistroCoordinates::setdataCompleta(string dataCompleta)
{
    this->dataCompleta = dataCompleta;
}
string RegistroCoordinates::getdataCompleta()
{
    return dataCompleta;
}

void RegistroCoordinates::setcidadeCodigo(float cidadeCodigo)
{            
    this->cidadeCodigo = cidadeCodigo;
}

float RegistroCoordinates::getcidadeCodigo()
{
    return cidadeCodigo;
}

void RegistroCoordinates::setLatitude(float latitude)
{
    this->latitude = latitude;
}
float RegistroCoordinates::getLatitude()
{
    return latitude;
}
void RegistroCoordinates::setLongitude(float longitude)
{
    this->longitude = longitude;
}
float RegistroCoordinates::getLongitude()
{
    return longitude;
}
void RegistroCoordinates::setCodigoEstado(int codigoEstado)
{
    this->codigoEstado = codigoEstado;
}
int RegistroCoordinates::getcodigoEstado()
{
    return codigoEstado;
}