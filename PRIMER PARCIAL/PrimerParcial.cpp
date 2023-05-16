#include "PrimerParcial.h"
#include "Estudiante.h"
#include "PagosArchivo.h"
#include "EstudiantesArchivo.h"
#include <iostream>
using namespace std;
//Un método llamado  listarRecaudacion  que muestre para cada curso,
// la recaudación obtenida desde el periodo del 10/05/2020.
void PrimerParcial::listarRecaudacion()
{
    float vecPagosPorCurso[10] = {};
    PagosArchivo pagosArch;
    int largoArchivoPago = pagosArch.getCantidad();

    for ( int i = 0; i < largoArchivoPago; i++  )
    {


        if (       (pagosArch.leer(i).getFecha().getDia() >= 10 && pagosArch.leer(i).getFecha().getMes() == 5 && pagosArch.leer(i).getAnio() == 2020 )  ||
                   (pagosArch.leer(i).getFecha().getAnio() >= 2020  && pagosArch.leer(i).getMes() >= 6)    )
        {

            vecPagosPorCurso [ pagosArch.leer(i).getIdCurso() - 1 ] += pagosArch.leer(i).getMonto();



        }


    }
    cout <<"la recaudacion por curso es la siguiente: "<< endl;
    for(int j = 0; j < 10; j++)
    {
        cout << "curso: " << j+1 << endl;
        cout << vecPagosPorCurso[j] << endl;



    }

}

//Agregar un método llamado  listarAlumnosNoMorosos  y que usando el método del punto anterior,
//muestre los legajos de los alumnos que nunca realizaron un pago vencido.
void PrimerParcial::listarAlumnosNoMorosos()
{
    EstudiantesArchivo estudianteArch;
    PagosArchivo pagosArch;

    int cantidadDeEstudiantes =  estudianteArch.getCantidad();
    int cantidadDePagos = pagosArch.getCantidad();
    int z=0;

    cout <<"legajos de los alumnos que nunca realizaron un pago vencido"<< endl;
    for (int i = 0; i < cantidadDeEstudiantes; i ++ )
    {




        for (int j = 0; j < cantidadDePagos; j++ )
        {

            if  ( estudianteArch.leer(i).getLegajo() == pagosArch.leer(j).getLegajo() )
            {


                if (   pagosArch.leer(j).esPagoVencido() == true   )

                {

                    cout <<"el alumnno con id " << estudianteArch.leer(i).getLegajo()<< " es deudor" << endl;

                    break;
                }

                if ( j == cantidadDePagos - 1)
                {

                    cout <<"el alumnno con id" << estudianteArch.leer(i).getLegajo()<< "  NO    es deudor" << endl;


                }

            }

        }




    }





}











//Un método llamado  soloUnCurso  que muestre el legajo, nombre y apellido de todos los alumnos que pagaron
//solamente un curso del periodo (año período de cursada)  2021 .
void PrimerParcial::soloUnCurso()
{

    EstudiantesArchivo estudianteArch;
    PagosArchivo pagosArch;

    int cantidadDeEstudiantes =  estudianteArch.getCantidad();
    int cantidadDePagos = pagosArch.getCantidad();

//int *cantidadEstudiantesVec = new int [cantidadDeEstudiantes] ;
    cout <<"alumnos que pagaron solo un curso :"<< endl;
    for (int i = 0; i < cantidadDeEstudiantes; i ++ )
    {
        int contadorPagos = 0;

        for (int j = 0; j < cantidadDePagos; j++ )
        {



            if ( estudianteArch.leer(i).getLegajo() == pagosArch.leer(j).getLegajo() && pagosArch.leer(j).getAnio() == 2021   )
            {

                contadorPagos++;



            }



        }

        if (contadorPagos == 1 )
        {

            cout << estudianteArch.leer(i).getLegajo()<< endl;
            cout << estudianteArch.leer(i).getNombres()<< endl;
            cout << estudianteArch.leer(i).getApellidos()<< endl;
            cout <<"-------------------------------------------"<< endl;
        }



    }


}
//Crear un método llamado  cursosPremium  que reciba el legajo de un estudiante y
//muestre el/los id de curso/s al que realizó el mayor pago individual.
void PrimerParcial::cursosPremium()
{
    int legajoEstudiante;

    PagosArchivo pagosArch;


    int cantidadDePagos = pagosArch.getCantidad();
    float maximoPago = 0;
    float vectorPagos[10] = {};

    cout <<"ingrese legajo estudiante: "<< endl;
    cin >> legajoEstudiante;


    for (int i = 0; i < cantidadDePagos; i ++)
    {


        if (  pagosArch.leer(i).getLegajo() == legajoEstudiante  )
        {
            break;
        }

        if ( cantidadDePagos == i - 1  )
        {
            cout <<"no existe ese legajo" << endl;
            exit(33);


        }


    }






        for (int i = 0; i < cantidadDePagos; i ++)
        {


            if ( pagosArch.leer(i).getLegajo() == legajoEstudiante  )
            {
                vectorPagos[  pagosArch.leer(i).getIdCurso() - 1 ] = pagosArch.leer(i).getMonto();



            }




        }




        for (int j = 0; j < 10; j++)
        {

            if (  vectorPagos[j] > maximoPago  )
            {
                maximoPago = vectorPagos[j];

            }

        }

        for (int j = 0; j < 10; j++)
        {

            if (  vectorPagos[j] == maximoPago )
            {
                cout <<"los id de curso/cursos con mayor importe individual de este legajo  son: " << j + 1 << endl;

            }

        }





    }





