#include <iostream>
#include <time.h>
#include <string>
#include <chrono>
#include <thread>
#include <windows.h>
#include <conio.h>
using namespace std;

void ELEGIR_NUMERO_AZAR(int&);
void NUMERO_AZAR(int&, int&);
void CONTINUAR();

int main()
{
    do{
        SetConsoleTitle("Ruleta");
        string apuesta;
        int color = 0;
        string colorNumero;
        int NumeroApuesta;
        srand(time(0));
        int random;

        cout << "Como quieres apostar?" << endl;
        cout << "\nImpares \nPares \nRojos \nNegros \nUn numero \nNumero del 1 - 18 \nNumero del 19 - 36\n" << endl;

        cin >> apuesta;
        system("CLS");

        solo:
        if(apuesta == "numero" || apuesta == "Numero"){

            cout << "Escribe el numero con el que quieres apostar" << endl;
            cin >> NumeroApuesta;

            if(NumeroApuesta > 37){
                cout << "\nEse no es un numero valido\n" << endl;
                goto solo;
            }

            ELEGIR_NUMERO_AZAR(random);

            if(random == NumeroApuesta){

                cout << "Ganaste!" << endl;
                cout << "\nNumero ganador: "; NUMERO_AZAR(random, color);
            }

            else {

                cout << "Perdiste!" << endl;
                cout << "\nNumero ganador: "; NUMERO_AZAR(random, color);
            }

            if(color == 0) {

                colorNumero = "negro";
            }

            else{

                colorNumero = "rojo";
            }

            cout << "\n\nTu apuesta: " << NumeroApuesta << " " << colorNumero;
        }

        if(apuesta == "impares" || apuesta == "impar" || apuesta == "Impar" || apuesta == "Impares"){

            ELEGIR_NUMERO_AZAR(random);

            if (random % 2 != 0){

                cout << "Ganador!" << endl;
                cout << "\nNumero ganador: "; NUMERO_AZAR(random, color);
            }

            else{

                cout << "\nPerdedorrrr!!" << endl;
                cout << "\nNumero ganador: "; NUMERO_AZAR(random, color);
            }
        }

        if(apuesta == "pares" || apuesta == "par" || apuesta == "Pares" || apuesta == "Par"){

        ELEGIR_NUMERO_AZAR(random);

            if (random % 2 == 0){

                cout << "Ganador!" << endl;
                cout << "\nNumero ganador: "; NUMERO_AZAR(random, color);
            }

            else{

                cout << "Perdedorr!!" << endl;
                cout << "\nNumero ganador: "; NUMERO_AZAR(random, color);
            }
        }

        if(apuesta == "rojo" || apuesta == "rojos" || apuesta == "Rojo" || apuesta == "Rojos"){

            ELEGIR_NUMERO_AZAR(random);

            if (random % 2 == 0  && ((11 < random && random < 19) || (29 < random && random < 37))){

                cout << "\nGanador!!" <<endl;
                cout << "\nNumero ganador: "; NUMERO_AZAR(random, color);
            }

            else if (random % 2 != 0 && ((0 < random && random < 10) || (18 < random && random < 28))){

                cout << "Ganador!!" <<endl;
                cout << "\nNumero ganador: "; NUMERO_AZAR(random, color);
            }

            else{

                cout << "Perdisteeee" << endl;
                cout << "\nNumero ganador: "; NUMERO_AZAR(random, color);
            }
        }

        if(apuesta == "negro" || apuesta == "negros" || apuesta == "Negro" || apuesta == "Negros"){

            ELEGIR_NUMERO_AZAR(random);

            if (random % 2 == 0 && ((0 < random && random < 11) || (19 < random && random < 29))){

                cout << "Ganador ganador" << endl;
                cout << "\nNumero ganador: "; NUMERO_AZAR(random, color);
            }

            else if(random % 2 != 0 && ((10 < random && random < 18) || (28 < random && random < 36))){

                cout << "Ganador" << endl;
                cout << "\nNumero ganador: "; NUMERO_AZAR(random, color);
            }

            else{

                cout << "Perdisteee" << endl;
                cout << "\nNumero ganador: "; NUMERO_AZAR(random, color);
            }
        }

        if(apuesta == "1-18" || apuesta == "numero del 1 - 18" || apuesta == "1al18" || apuesta == "Numero del 1 al 18"){

            ELEGIR_NUMERO_AZAR(random);

            if(0 < random && random < 19){

                cout << "Ganaste!" << endl;
                cout << "\nNumero ganador: "; NUMERO_AZAR(random, color);
            }

            else{

                cout << "Perdiste!" << endl;
                cout << "\nNumero ganador: "; NUMERO_AZAR(random, color);
            }
        }

        if(apuesta == "19-36" || apuesta == "numero del 19 - 36" || apuesta == "19al36" || apuesta == "numero del 19 al 36"){

            ELEGIR_NUMERO_AZAR(random);

            if(18 < random && random < 37){

                cout << "Ganaste!" << endl;
                cout << "\nNumero ganador: "; NUMERO_AZAR(random, color);
            }

            else{

                cout << "Perdiste!" << endl;
                cout << "\nNumero ganador: "; NUMERO_AZAR(random, color);
            }
        }

        if(apuesta != "numero" || apuesta != "Numero"){

            cout << "\n\nTu apuesta: " << apuesta << endl;
        }

        CONTINUAR();
        system("CLS");

    }while(1==1);
}

//elegir color de acuerdo al numero
void NUMERO_AZAR(int &numero, int &id){

    if(numero == 0){
        
        cout << numero << " verde" << endl; //SOY DEL VERDE SOY FELIZ
    }

    else if (numero % 2 == 0 && ((0 < numero && numero < 11) || (19 < numero && numero < 29))){ //negros pares (1 -> 10 & 20 -> 28)
            
        cout << numero << " negro" << endl;
        id = 0;
    }

    else if (numero % 2 == 0 && ((11 < numero && numero < 19) || (29 < numero && numero < 37))){ //rojos pares (12 -> 18 & 30 -> 36)

        cout << numero << " rojo" << endl;
        id = 1;
    }

    else if (numero % 2 != 0 && ((0 < numero && numero < 10) || (18 < numero && numero < 28))){ //rojos impares (1 -> 9 & 19 -> 27)

        cout << numero << " rojo" << endl;
        id = 1;
    }

    else if (numero % 2 != 0 && ((10 < numero && numero < 18) || (28 < numero && numero < 36))){ //negros impares (11 -> 17 & 29 -> 35)

        cout << numero << " negro" << endl;
        id = 0;
    }

    else{

        cout << numero << "ERROR???" << endl; //error?
    }
}

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

void CONTINUAR(){

    int c;
    printf( "\n\n\n\nPresiona cualquier tecla para jugar de nuevo");
    c = getch();
    if (c == 0 || c == 224) getch();
}
