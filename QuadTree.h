#include <iostream> 
#include <cmath> 
using namespace std; 

struct Ponto
{   
    int latitude;
    int longitude;

    Ponto(int latitude_,int longitude_)
    {
        latitude = latitude_;
        longitude = longitude_;
    }
    
    Ponto()
    {
        latitude = 0;
        longitude = 0;
    }

};

struct No
{
    Ponto position;
    int info;
    
};

