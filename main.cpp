#include <iostream>
#include <time.h>
#include <string>
#include <chrono>
#include <thread>
#include <windows.h>
#include <conio.h>
using namespace std;

void ELEGIR_NUMERO_AZAR(int&);
void ELEGIR_COLOR(int&, string&);
void CONTINUAR();

int main(){

    do{
        SetConsoleTitle("Ruleta");
        string apuesta, color, colorNumero;
        int NumeroApuesta;
        srand(time(0));
        int random;

        cout << "Como quieres apostar?" << endl;
        cout << "\nImpares \nPares \nRojos \nNegros \nUn numero \nNumero del 1 - 18 \nNumero del 19 - 36\n" << endl;

        cin >> apuesta;

        system("CLS");

//un solo numero
        if(apuesta == "numero" || apuesta == "Numero" || apuesta == "NUMERO"){

            solo:
            cout << "Escribe el numero con el que quieres apostar" << endl;
            cin >> NumeroApuesta;

            if(NumeroApuesta > 37){
                cout << "\El " << apuesta << " es mayor a 37, no es un numero valido\n" << endl;
                goto solo;
            }

            system("CLS");

            ELEGIR_NUMERO_AZAR(random);

            if(random == NumeroApuesta){

                cout << "Ganaste!" << endl;
                cout << "\nNumero ganador: "; ELEGIR_COLOR(random, color);
            }

            else {

                cout << "Perdiste!" << endl;
                cout << "\nNumero ganador: "; ELEGIR_COLOR(random, color);
            }

             cout << "\n\nTu apuesta: "; ELEGIR_COLOR(NumeroApuesta, color);
        }
//fin un solo numero

//impares
        else if(apuesta == "impares" || apuesta == "impar" || apuesta == "Impar" || apuesta == "Impares" || apuesta == "IMPAR" || apuesta == "IMPARES"){

            ELEGIR_NUMERO_AZAR(random);

            if (random % 2 != 0){

                cout << "Ganador!" << endl;
                cout << "\nNumero ganador: "; ELEGIR_COLOR(random, color);
            }

            else{

                cout << "\nPerdedorrrr!!" << endl;
                cout << "\nNumero ganador: "; ELEGIR_COLOR(random, color);
            }

            cout << "\n\nApostaste por los impares" << endl;
        }
//fin impares

//pares
        else if(apuesta == "pares" || apuesta == "par" || apuesta == "Pares" || apuesta == "Par" || apuesta == "PAR" || apuesta == "PARES"){

            ELEGIR_NUMERO_AZAR(random);

            if (random % 2 == 0){

                cout << "Ganador!" << endl;
                cout << "\nNumero ganador: "; ELEGIR_COLOR(random, color);
            }

            else{

                cout << "Perdedorr!!" << endl;
                cout << "\nNumero ganador: "; ELEGIR_COLOR(random, color);
            }

            cout << "\n\nApostaste por los pares" << endl;
        }
//fin pares

//rojos
        else if(apuesta == "rojo" || apuesta == "rojos" || apuesta == "Rojo" || apuesta == "Rojos" || apuesta == "ROJO" || apuesta == "ROJOS"){

            ELEGIR_NUMERO_AZAR(random);
            ELEGIR_COLOR(random, color);
            system("CLS");

            if (color == "rojo"){

                cout << "Ganador!!" <<endl;
                cout << "\nNumero ganador: "; ELEGIR_COLOR(random, color);
            }

            else{

                cout << "Perdisteeee" << endl;
                cout << "\nNumero ganador: "; ELEGIR_COLOR(random, color);
            }

            cout << "\n\nApostaste por los rojos" << endl;
        }
//fin rojos

//negros
        else if(apuesta == "negro" || apuesta == "negros" || apuesta == "Negro" || apuesta == "Negros" || apuesta == "NEGRO" || apuesta == "NEGROS"){

            ELEGIR_NUMERO_AZAR(random);
            ELEGIR_COLOR(random, color);
            system("CLS");

            if (color == "negro"){

                cout << "Ganador ganador" << endl;
                cout << "\nNumero ganador: "; ELEGIR_COLOR(random, color);
            }

            else{

                cout << "Perdisteee" << endl;
                cout << "\nNumero ganador: "; ELEGIR_COLOR(random, color);
            }

            cout << "\n\nApostaste por los negros" << endl;
        }
//fin negros

//1 al 18
        else if(apuesta == "1-18" || apuesta == "numero del 1 - 18" || apuesta == "1al18" || apuesta == "Numero del 1 al 18"){

            ELEGIR_NUMERO_AZAR(random);

            if(0 < random && random < 19){

                cout << "Ganaste!" << endl;
                cout << "\nNumero ganador: "; ELEGIR_COLOR(random, color);
            }

            else{

                cout << "Perdiste!" << endl;
                cout << "\nNumero ganador: "; ELEGIR_COLOR(random, color);
            }

            cout << "\n\nApostaste del 1 al 18" << endl;
        }
//fin 1 al 18

//19 al 36
        else if(apuesta == "19-36" || apuesta == "numero del 19 - 36" || apuesta == "19al36" || apuesta == "numero del 19 al 36"){

            ELEGIR_NUMERO_AZAR(random);

            if(18 < random && random < 37){

                cout << "Ganaste!" << endl;
                cout << "\nNumero ganador: "; ELEGIR_COLOR(random, color);
            }

            else{

                cout << "Perdiste!" << endl;
                cout << "\nNumero ganador: "; ELEGIR_COLOR(random, color);
            }

            cout << "\n\nApostaste del 19 al 36" << endl;
        }
//fin 19 al 36

//un solo numero 
        else if(stoi(apuesta) >= 0 && stoi(apuesta) < 38){

            ELEGIR_NUMERO_AZAR(random);
            NumeroApuesta = stoi(apuesta);

            if(NumeroApuesta == random){

                cout << "Ganaste!" << endl;
                cout << "\nNumero ganador: "; ELEGIR_COLOR(random, color);
            }

            else{

                cout << "Perdiste!" << endl;
                cout << "\nNumero ganador: "; ELEGIR_COLOR(random, color);
            }

            cout << "\n\nTu apuesta: "; ELEGIR_COLOR(NumeroApuesta, color);
        }
//fin un solo numero

//excepcion
        else if(stoi(apuesta) > 37){

            cout << "El " << stoi(apuesta) << " es mayor a 37, no es un numero valido\n" << endl;
            goto solo;
        }
//fin excepcion

        CONTINUAR();
        system("CLS");

    }while(1==1);
}

//elegir color de acuerdo al numero
void ELEGIR_COLOR(int &numero, string &id){

    if(numero == 0){

        cout << numero << " verde" << endl; //SOY DEL VERDE SOY FELIZ
        id = "verde";
    }

    else if (numero % 2 == 0 && (( 1 <= numero && numero <= 10) || (20 <= numero && numero <= 28))){ //negros pares (1 -> 10 & 20 -> 28)

        cout << numero << " negro" << endl;
        id = "negro";
    }

    else if (numero % 2 == 0 && ((12 <= numero && numero <= 18) || (30 <= numero && numero <= 36))){ //rojos pares (12 -> 18 & 30 -> 36)

        cout << numero << " rojo" << endl;
        id = "rojo";
    }

    else if (numero % 2 != 0 && ((1 <= numero && numero <= 9) || (19 <= numero && numero <= 27))){ //rojos impares (1 -> 9 & 19 -> 27)

        cout << numero << " rojo" << endl;
        id = "rojo";
    }

    else if (numero % 2 != 0 && ((11 <= numero && numero <= 17) || (29 <= numero && numero <= 35))){ //negros impares (11 -> 17 & 29 -> 35)

        cout << numero << " negro" << endl;
        id = "negro";
    }

    else{

        cout << numero << "ERROR???" << endl; //error?
    }
}
//fin elegir color de numero

//elegir numero al azar
void ELEGIR_NUMERO_AZAR(int &numero){

     cout <<"Girando..." << "\n" << endl;

     for(int x = 0; x < 8; x++){

        numero = rand() % 37;
        this_thread::sleep_for (chrono::milliseconds(500));
        cout << numero << "\r";
     }

    system("CLS");
}
//fin elegir numero al azar

//jugar otra vez
void CONTINUAR(){

    int c;
    printf( "\n\n\n\nPresiona cualquier tecla para jugar de nuevo");
    c = getch();
    if (c == 0 || c == 224) getch();
}
//fin jugar otra vez
