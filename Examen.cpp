#include <iostream>
#include<set>
#include"../lib/Color.h"
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>

using namespace std;
#define color SetConsoleTextAttribute  
const string JTNOMBRE = "Jhoel Wladimir Tulcan Caicedo";
const int JTCEDULA = 1725417544;

struct jtCoordenada
{
    int jtCapacidadBelica;
    string jtGeoLocalizacion;
    string jtArsenal;
    struct jtCoordenada *izq, *der;
};
typedef struct jtCoordenada *ABB;


void jtCrearArchivo(string jtPathFile) {
    ofstream jtf(jtPathFile);
     
    if (jtf.is_open()) {
           
       
         // Escribir las coordenadas en el archivo de texto
            jtf<< "Capacidad belica | Geolocalización | Detalle Arsenal" << endl;
            jtf<<" 5,  GPS5,  bct"<<endl;       
            jtf<<" 4,  GPS4,  acd"<<endl;  
            jtf<<" 5,  GPS5,  bct"<<endl; 
            jtf<<" 7,  GPS7,  aaabbct"<<endl;
            jtf<<" 1,  GPS1,  bc"<<endl;  
            jtf<<" 4,  GPS4,  acd"<<endl;
            jtf<<" 5,  GPS5,  bct"<<endl;
            jtf<<" 2,  GPS2,  ac"<<endl; 
            jtf<<" 7,  GPS7,  aaabbct"<<endl;
            jtf<<" 1,  GPS1,  bc"<<endl;  
    
        jtf.close();
        setColor(0,2);
        cout << "[+] Archivo creado exitosamente" << endl;
    } else {
        setColor(0,4);
        cout << "[-] Error de crear el archivo." << endl;
    }
}

void jtLoading()
{
    int jtind =0;
    string jtc= "\\|/-|";
    for(int jti=0; jti<= 100; jti++)
    {  
        //updateBar(i);
        if(jti % 4 ==0)
            jtind =0;
        cout    << "\r" << jtc[jtind++]  
                << " " << jti << "%";
        usleep(10000);
    }
}

void jtLeerArchivo(string pathFile)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    string jts;
    fstream jtf;
    jtf.open(pathFile, ios_base::in);
    if ( !jtf.is_open() )
        cout << "Error de abrir el archivo." << endl;
    else {

        cout<<"[+] Leyendo coordenadas..."<< endl;
        set<string> lines_read;
        do
        {
            getline( jtf, jts);
            if (lines_read.count(jts) > 0) {
                continue;
            }
            lines_read.insert(jts);
            if(jts[0]=='C')
            {
           
               //Función propia de la librería windows.h 
            color(hConsole, 4);  
                cout<<"Error: ";
                cout <<" "<< jts << "->stoi"<<endl;
            }else{
                color(hConsole, 2);  
                jtLoading();
                cout <<"  "<< jts<< endl;
            }
           

        } while ( !jtf.eof() );
    }
    jtf.close();
}



int main()
{


    jtCrearArchivo("coordenadas.txt");
    jtLeerArchivo("coordenadas.txt");
    return 0;
}


