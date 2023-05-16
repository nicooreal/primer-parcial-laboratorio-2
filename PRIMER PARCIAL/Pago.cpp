#include "Pago.h"
#include <iostream>
#include "Fecha.h"
using namespace std;


Pago::Pago()
{
    _id = 0;
    _monto = 0;
    _legajo = 0;
    _idCurso = 0;
    _fecha = Fecha();
    _mes = 0;
    _anio = 0;
    _idMetodoPago = 0;
}

//Agregar a la clase  Pago un método llamado  esPagoVencido   que determine si el pago fue un pago vencido o no.

bool Pago::esPagoVencido()
{


    if( _fecha.getAnio() >  _anio  || ( _fecha.getAnio() == _anio  &&  _fecha.getMes() > _mes  ))
    {

  //  cout <<"es pago vencido"<< endl;
        return true;
    }
    else
    {

    //cout <<"no es pago vencido"<< endl;
        return false;
    }



}

Pago::Pago(int id, float monto, int legajo, int idCurso, Fecha fecha, int mes, int anio, int idMetodoPago)
{
    _id = id;
    _monto = monto;
    _legajo = legajo;
    _idCurso = idCurso;
    _fecha = fecha;
    _mes = mes;
    _anio = anio;
    _idMetodoPago = idMetodoPago;
}


int Pago::getId()
{
    return _id;
}

float Pago::getMonto()
{
    return _monto;
}

int Pago::getLegajo()
{
    return _legajo;
}

int Pago::getIdCurso()
{
    return _idCurso;
}

Fecha Pago::getFecha()
{
    return _fecha;
}

int Pago::getMes()
{
    return _mes;
}

int Pago::getAnio()
{
    return _anio;
}

int Pago::getIdMetodoPago()
{
    return _idMetodoPago;
}

void Pago::setId(int id)
{
    _id = id;
}

void Pago::setMonto(float monto)
{
    _monto = monto;
}

void Pago::setLegajo(int legajo)
{
    _legajo = legajo;
}

void Pago::setIdCurso(int idCurso)
{
    _idCurso = idCurso;
}

void Pago::setFecha(Fecha fecha)
{
    _fecha = fecha;
}

void Pago::setMes(int mes)
{
    _mes = mes;
}

void Pago::setAnio(int anio)
{
    _anio = anio;
}

void Pago::setIdMetodoPago(int idMetodoPago)
{
    _idMetodoPago = idMetodoPago;
}

void Pago::mostrarTodo(){
  cout << "el id es: "   <<_id <<endl;
  cout << "el monto es: "   <<_monto <<endl;
  cout << "el legajo es: "  <<_legajo<<endl;
  cout << "el ide curso es: "  <<_idCurso<<endl;
  cout << "el mes es: "  <<_mes <<endl;
  cout << "el anio es: "  <<_anio<<endl;
  cout << "el id metodo de pago es: "  << _idMetodoPago <<endl;

  cout <<"la fecha del pago es: " <<_fecha.getDia() << "/"<<_fecha.getMes()<<"/" <<  _fecha.getAnio() << endl;


}



std::string Pago::toString()
{
    std::string pago;
    pago = "Id: " + std::to_string(_id) + " Monto: " + std::to_string(_monto) + " Legajo: " + std::to_string(_legajo) + " IdCurso: " + std::to_string(_idCurso) + " Fecha: " + _fecha.toString() + " Mes: " + std::to_string(_mes) + " Anio: " + std::to_string(_anio) + " IdMetodoPago: " + std::to_string(_idMetodoPago);
    return pago;
}


