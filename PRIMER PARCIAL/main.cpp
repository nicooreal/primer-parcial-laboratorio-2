
#include "PrimerParcial.h"
#include "Estudiante.h"
#include "PagosArchivo.h"
#include "Pago.h"

#include <iostream>
using namespace std;

int main() {
PrimerParcial primerparcial;
PagosArchivo pagoArc;
Pago pago;

primerparcial.cursosPremium();





primerparcial.listarRecaudacion();
cout <<"-----------------------------------------------"<< endl;
primerparcial.soloUnCurso();
cout <<"-----------------------------------------------"<< endl;
primerparcial.cursosPremium();
cout <<"-----------------------------------------------"<< endl;
primerparcial.listarAlumnosNoMorosos();



  return 0;
}
