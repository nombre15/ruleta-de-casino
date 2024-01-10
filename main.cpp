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
    int dinero = 0;

    //Inicio del juego
    do{

        string tipoApuesta, colorNumero;
        int numeroApuesta, numero;
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
            cout << "   / --|--------------------------------------------------------------------| \n"
                    "  /    | 3 | 6 | 9 | 12 | 15 | 18 | 21 | 24 | 27 | 30 | 33 | 36 | Columna 3 | \n"
                    " /     |----------------|-------------------|-------------------|-----------| \n"
                    "|   0  | 2 | 5 | 8 | 11 | 14 | 17 | 20 | 23 | 26 | 29 | 32 | 35 | Columna 2 | \n"
                    " \\     |----------------|-------------------|-------------------|-----------| \n"
                    "  \\    | 1 | 4 | 7 | 10 | 13 | 16 | 19 | 22 | 25 | 28 | 31 | 34 | Columna 1 | \n"
                    "   \\___|----------------|-------------------|-------------------|-----------| \n"
                    "       |    1a Docena   |     2a Docena     |     3a Docena     | \n"
                    "       |--------------------------------------------------------| \n"
                    "       |  1-18  |  Par  |   Rojo  |  Negro  | Impar |   19-36   | \n"
                    "       |________|_______|_________|_________|_______|___________|" << endl;
            cout << "\n1.Un numero \n2.Columna 3 \n3.Columna 2 \n4.Columna 1 \n5.1a docena \n6.2a docena \n7.3a docena \n8.Numero del 1 al 18 \n9.Par \n10.Rojo \n11.Negro \n12.Impar \n13.Numero del 19 al 36" << endl << endl;

            cin >> tipoApuesta;

            transform(tipoApuesta.begin(), tipoApuesta.end(), tipoApuesta.begin(),[](unsigned char c) { return tolower(c); }); // Convierte el string a minusculas

            system("CLS");

            //un solo numero
            if(tipoApuesta == "numero" || tipoApuesta == "1"){

                const int MAX_NUM_APUESTA = 36;
                const int MIN_NUM_APUESTA = 0;

                do{

                    cout << "Escribe el numero con el que quieres apostar" << endl;
                    cin >> numeroApuesta;

                    if(numeroApuesta > MAX_NUM_APUESTA){

                        cout << numeroApuesta << " es mayor a 36, no es un numero valido\n" << endl;
                    }

                    else if(numeroApuesta < MIN_NUM_APUESTA){

                        cout << numeroApuesta << " es menor a 0, no es un numero valido\n" << endl;
                    }

                    while(cin.fail() || cin.peek() != '\n') {

                        system("cls");
                        cout << "Ingrese un numero valido: ";
                        cin.clear();
                        cin.ignore(256,'\n');
                        cin >> numeroApuesta;
                    }
                }while(numeroApuesta > MAX_NUM_APUESTA || numeroApuesta < MIN_NUM_APUESTA);

                system("CLS");
                elegirNumeroAzar(numero);

                if(numero == numeroApuesta){

                    jugadorGana(numero, dinero, colorNumero);
                }

                else {

                    jugadorPierde(numero, dinero, colorNumero);
                }

                elegirColor(numeroApuesta, colorNumero);
                cout << "\n\nTu apuesta: " << numeroApuesta << " " << colorNumero << endl;
                break;
            }

            //columna 3
            else if(tipoApuesta == "3a columna" || tipoApuesta == "tercera columna" || tipoApuesta == "columa 3" || tipoApuesta == "2"){

                elegirNumeroAzar(numero);

                if(numero % 3 == 0 && numero != 0){

                    jugadorGana(numero, dinero, colorNumero);
                }
                else{

                    jugadorPierde(numero, dinero, colorNumero);
                }

                cout << "\n\nApostaste por la 3a columna" << endl;
                break;
            }

            //columna 2
            else if(tipoApuesta == "2a columna" || tipoApuesta == "segunda columna" || tipoApuesta == "columa 2" || tipoApuesta == "3"){

                elegirNumeroAzar(numero);

                if((numero-1) % 3 == 0 && numero != 0){

                    jugadorGana(numero, dinero, colorNumero);
                }
                else{

                    jugadorPierde(numero, dinero, colorNumero);
                }

                cout << "\n\nApostaste por la 2a columna" << endl;
                break;
            }

            //columna 1
            else if(tipoApuesta == "1a columna" || tipoApuesta == "primera columna" || tipoApuesta == "columa 1" || tipoApuesta == "4"){

                elegirNumeroAzar(numero);

                if((numero-2) % 3 == 0 && numero != 0){

                    jugadorGana(numero, dinero, colorNumero);
                }
                else{

                    jugadorPierde(numero, dinero, colorNumero);
                }

                cout << "\n\nApostaste por la 1a columna" << endl;
                break;
            }

            //primera docena
            else if(tipoApuesta == "1a docena" || tipoApuesta == "primera docena" || tipoApuesta == "5"){

                elegirNumeroAzar(numero);

                if(numero >= 1 && numero <= 12){

                    jugadorGana(numero, dinero, colorNumero);
                }
                else{

                    jugadorPierde(numero, dinero, colorNumero);
                }

                cout << "\n\nApostaste por la 1a docena" << endl;
                break;
            }

            //segunda docena
            else if(tipoApuesta == "2a docena" || tipoApuesta == "segunda docena" || tipoApuesta == "6"){

                elegirNumeroAzar(numero);

                if(numero >= 13 && numero <= 24){

                    jugadorGana(numero, dinero, colorNumero);
                }
                else{

                    jugadorPierde(numero, dinero, colorNumero);
                }

                cout << "\n\nApostaste por la 2a docena" << endl;
                break;
            }

            //tercera docena
            else if(tipoApuesta == "3a docena" || tipoApuesta == "tercera docena" || tipoApuesta == "7"){

                elegirNumeroAzar(numero);

                if(numero >= 25 && numero <= 36){

                    jugadorGana(numero, dinero, colorNumero);
                }
                else{

                    jugadorPierde(numero, dinero, colorNumero);
                }

                cout << "\n\nApostaste por la 3a docena" << endl;
                break;
            }

            //1 al 18
            else if(tipoApuesta == "1 al 18" || tipoApuesta == "8"){

                elegirNumeroAzar(numero);

                if(1 <= numero && numero <= 18){

                    jugadorGana(numero, dinero, colorNumero);
                }

                else{

                    jugadorPierde(numero, dinero, colorNumero);
                }

                cout << "\n\nApostaste del 1 al 18" << endl;
                break;
            }

            //pares
            else if(tipoApuesta == "pares" || tipoApuesta == "par" || tipoApuesta == "9"){

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
            else if(tipoApuesta == "rojo" || tipoApuesta == "rojos" || tipoApuesta == "10"){

                elegirNumeroAzar(numero);
                elegirColor(numero, colorNumero);

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
            else if(tipoApuesta == "negro" || tipoApuesta == "negros" || tipoApuesta == "11"){

                elegirNumeroAzar(numero);
                elegirColor(numero, colorNumero);

                if (colorNumero == "negro"){

                    jugadorGana(numero, dinero, colorNumero);
                }

                else{

                    jugadorPierde(numero, dinero, colorNumero);
                }

                cout << "\n\nApostaste por los negros" << endl;
                break;
            }

            //impares
            else if(tipoApuesta == "impares" || tipoApuesta == "impar" || tipoApuesta == "12"){

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

            //19 al 36
            else if(tipoApuesta == "19 al 36" || tipoApuesta == "13"){

                elegirNumeroAzar(numero);

                if(19 <= numero && numero <= 36){

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
    cout << "Te vas con $" << dinero << endl;
    cout << "Gracias por jugar!" << endl;
    return 0;
}

//elegir color de acuerdo al numero
void elegirColor(int &numero, string &color){

    int rojos[18] = {1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
    int negros[18] = {2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35};

    if(numero == 0){

        cout << numero << " verde" << endl; //SOY DEL VERDE SOY FELIZ
        color = "verde";
    }

    for(int i = 0; i < 19; i++){

        if(numero == rojos[i]){

            color = "rojo";
        }

        else if(numero == negros[i]){

            color = "negro";
        }
    }
}

void elegirNumeroAzar(int &numero){

     cout <<"Girando..." << "\n" << endl;

     int max = 50;
     int min = 15;
     int azar = rand()%(max-min + 1) + min;
     int tiempo;
     int temp1 = rand() % 50;
     int temp2 = rand() % 20;

     for(int x = 0; x < azar; x++){

        numero = rand() % 37;
        tiempo = temp1 + temp2 * x;
        this_thread::sleep_for (chrono::milliseconds(tiempo));
        cout << numero << "\r";
     }

    system("CLS");
}

//TODO: sumar la cantidad de dinero adecuada segun el tipo de apuesta
void jugadorGana(int numero,  int& dinero, string& colorNumero){

    cout << "Ganador!" << endl;
    elegirColor(numero, colorNumero);
    cout << "\nNumero ganador: " << numero << " " << colorNumero << endl;

    dinero = dinero + (dinero * 0.5);

    cout << "\nAhora tienes $" << dinero;
}

void jugadorPierde(int numero, int& dinero, string& colorNumero){

    cout << "Perdedorrrr!!" << endl;
    elegirColor(numero, colorNumero);
    cout << "\nNumero ganador: " << numero << " " << colorNumero << endl;

    dinero = 0;

    cout << "\nAhora tienes $" << dinero;
}
