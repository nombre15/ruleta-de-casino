#include <iostream>
#include <time.h>
#include <string>
#include <chrono>
#include <thread>
#include <windows.h>
#include <algorithm>
#include <conio.h>
using namespace std;

//TODO: separar por clases si es posible, agregar documentacion y eliminar codigo innecesario

void elegirNumeroAzar(int&);
void elegirColor(int&, string&);
void jugadorGana(int, int&, string&);
void jugadorPierde(int, int&, string&);

int main(){

    SetConsoleTitle("Ruleta");
    char tecla;

    //Inicio del juego
    do{

        string tipoApuesta, colorNumero;
        int numeroApuesta, numero, dinero = 0;
        srand(time(0));

        cout << "Ingrese la cantidad de dinero a apostar: $";
        cin >> dinero;

        //Si se ingresa un valor no numerico
         while(cin.fail() || cin.peek() != '\n') {

            system("cls");
            cout << "Ingrese una cantidad de dinero valida\n" << endl;
            cin.clear();
            cin.ignore(256,'\n');
            cout << "$";
            cin >> dinero;
        }

        system("cls");

        do{
            cout << "Elige el tipo de apuesta" << endl;
            cout << "\n1.Impares \n2.Pares \n3.Rojos \n4.Negros \n5.Un numero \n6.Numero del 1 al 18 \n7.Numero del 19 al 36\n" << endl;

            cin >> tipoApuesta;

            transform(tipoApuesta.begin(), tipoApuesta.end(), tipoApuesta.begin(),[](unsigned char c) { return tolower(c); }); // Convierte el string a minusculas

            system("CLS");

            //impares
            if(tipoApuesta == "impares" || tipoApuesta == "impar" || tipoApuesta == "1"){

                elegirNumeroAzar(numero);

                if (numero % 2 != 0){

                    jugadorGana(numero, dinero, colorNumero);
                }
                else{

                    jugadorPierde(numero, dinero, colorNumero);
                }

                cout << "\n\nApostaste por los impares" << endl;
                break;
            }

            //pares
            else if(tipoApuesta == "pares" || tipoApuesta == "par" || tipoApuesta == "2"){

                elegirNumeroAzar(numero);

                if (numero % 2 == 0){

                    jugadorGana(numero, dinero, colorNumero);
                }
                else{

                    jugadorPierde(numero, dinero, colorNumero);
                }

                cout << "\n\nApostaste por los pares" << endl;
                break;
            }

            //rojos
            else if(tipoApuesta == "rojo" || tipoApuesta == "rojos" || tipoApuesta == "3"){

                elegirNumeroAzar(numero);
                elegirColor(numero, colorNumero);
                system("CLS");

                if (colorNumero == "rojo"){

                    jugadorGana(numero, dinero, colorNumero);
                }
                else{

                    jugadorPierde(numero, dinero, colorNumero);
                }

                cout << "\n\nApostaste por los rojos" << endl;
                break;
            }

            //negros
            else if(tipoApuesta == "negro" || tipoApuesta == "negros" || tipoApuesta == "4"){

                elegirNumeroAzar(numero);
                elegirColor(numero, colorNumero);
                system("CLS");

                if (colorNumero == "negro"){

                    jugadorGana(numero, dinero, colorNumero);
                }

                else{

                    jugadorPierde(numero, dinero, colorNumero);
                }

                cout << "\n\nApostaste por los negros" << endl;
                break;
            }

            //un solo numero
            else if(tipoApuesta == "numero" || tipoApuesta == "5"){

                do{
                    cout << "Escribe el numero con el que quieres apostar" << endl;
                    cin >> numeroApuesta;

                    if(numeroApuesta > 37){

                        cout << numeroApuesta << " es mayor a 37, no es un numero valido\n" << endl;
                    }

                    else if(numeroApuesta < 0){

                        cout << numeroApuesta << " es menor a 0, no es un numero valido\n" << endl;
                    }

                    while(cin.fail() || cin.peek() != '\n') {

                        system("cls");
                        cout << "Ingrese un numero valido: ";
                        cin.clear();
                        cin.ignore(256,'\n');
                        cin >> numeroApuesta;
                    }
                }while(numeroApuesta > 37 || numeroApuesta < 0);

                system("CLS");
                elegirNumeroAzar(numero);

                if(numero == numeroApuesta){

                    jugadorGana(numero, dinero, colorNumero);
                }

                else {

                    jugadorPierde(numero, dinero, colorNumero);
                }

                 cout << "\n\nTu apuesta: "; elegirColor(numeroApuesta, colorNumero);
                 break;
            }

            //1 al 18
            else if(tipoApuesta == "1 al 18" || tipoApuesta == "6"){

                elegirNumeroAzar(numero);

                if(0 < numero && numero < 19){

                    jugadorGana(numero, dinero, colorNumero);
                }

                else{

                    jugadorPierde(numero, dinero, colorNumero);
                }

                cout << "\n\nApostaste del 1 al 18" << endl;
                break;
            }

            //19 al 36
            else if(tipoApuesta == "19 al 36" || tipoApuesta == "7"){

                elegirNumeroAzar(numero);

                if(18 < numero && numero < 37){

                    jugadorGana(numero, dinero, colorNumero);
                }

                else{

                    jugadorPierde(numero, dinero, colorNumero);
                }

                cout << "\n\nApostaste del 19 al 36" << endl;
                break;
            }

            //opcion invalida
            else{

                cout << tipoApuesta << " no es una opcion valida." << endl;
            }
        }
        while(true);

        cout << "\n\nPresione E para jugar otra vez o X para salir" << endl;
        tecla = getch();

        while(tecla != 'e' && tecla != 'x'){

            system("CLS");
            cout << "La tecla ingresada no es valida." << endl;
            cout << "Presione E para jugar otra vez o X para salir" << endl;
            tecla = getch();
        }
        system("CLS");

    }while(tecla == 'e');

    system("CLS");
    cout << "Gracias por jugar!" << endl;
    return 0;
}

//elegir color de acuerdo al numero
void elegirColor(int &numero, string &color){

    if(numero == 0){

        cout << numero << " verde" << endl; //SOY DEL VERDE SOY FELIZ
        color = "verde";
    }

    else if (numero % 2 == 0 && (( 1 <= numero && numero <= 10) || (20 <= numero && numero <= 28))){ //negros pares (1 -> 10 & 20 -> 28)

        cout << numero << " negro" << endl;
        color = "negro";
    }

    else if (numero % 2 == 0 && ((12 <= numero && numero <= 18) || (30 <= numero && numero <= 36))){ //rojos pares (12 -> 18 & 30 -> 36)

        cout << numero << " rojo" << endl;
        color = "rojo";
    }

    else if (numero % 2 != 0 && ((1 <= numero && numero <= 9) || (19 <= numero && numero <= 27))){ //rojos impares (1 -> 9 & 19 -> 27)

        cout << numero << " rojo" << endl;
        color = "rojo";
    }

    else if (numero % 2 != 0 && ((11 <= numero && numero <= 17) || (29 <= numero && numero <= 35))){ //negros impares (11 -> 17 & 29 -> 35)

        cout << numero << " negro" << endl;
        color = "negro";
    }

    else{

        cout << numero << "ERROR???" << endl; //error?
    }
}

void elegirNumeroAzar(int &numero){

     cout <<"Girando..." << "\n" << endl;

     int max = 50;
     int min = 15;
     int azar = rand()%(max-min + 1) + min;
     int tiempo;
     int temp1 = rand() % 50;
     int temp2 = rand() % 50;

     for(int x = 0; x < azar; x++){

        numero = rand() % 37;
        tiempo = temp1 + temp2 * x;
        this_thread::sleep_for (chrono::milliseconds(tiempo));
        cout << numero << "\r";
     }

    system("CLS");
}

void jugadorGana(int numero,  int& dinero, string& colorNumero){

    cout << "Ganador!" << endl;
    cout << "\nNumero ganador: "; elegirColor(numero, colorNumero);

    dinero = dinero + (dinero * 0.5);

    cout << "\nAhora tienes $" << dinero;
}

void jugadorPierde(int numero, int& dinero, string& colorNumero){

    cout << "\nPerdedorrrr!!" << endl;
    cout << "\nNumero ganador: "; elegirColor(numero, colorNumero);

    dinero = 0;

    cout << "\nAhora tienes $" << dinero;
}


