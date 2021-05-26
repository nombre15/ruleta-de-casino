#include <iostream>
#include <time.h>
#include <string>
#include <chrono>
#include <thread>
#include <windows.h>
using namespace std;

void NUMERO_AZAR(int);
void ELEGIR_NUMERO_AZAR(int);

int main()
{
    SetConsoleTitle("Ruleta");
    string apuesta;
    int NumeroApuesta;
    srand(time(0));
    int numero = rand() % 37;

    cout << "Como quieres apostar?" << endl;
    cout << "\nImpares \nPares \nRojos \nNegros \nUn numero \nNumero del 1 - 18 \nNumero del 19 - 36\n" << endl;

    apostar:
    cin >> apuesta;

    solo:
    if(apuesta == "numero" || apuesta == "Numero"){

    cout << "Escribe el numero con el que quieres apostar" << endl;
    cin >> NumeroApuesta;
    if(NumeroApuesta > 37){
        cout << "Ese no es un numero valido" << endl;
        goto solo;
    }

    ELEGIR_NUMERO_AZAR(numero);

    if(numero == NumeroApuesta){

        cout << "\nGanaste!" << endl;
        cout << "El numero era ";
        NUMERO_AZAR(numero);

  }
    else if(numero != NumeroApuesta){

        cout << "\nPerdiste!" << endl;
        cout << "El numero era ";
        NUMERO_AZAR(numero);
     }
  }

    if(apuesta == "impares" || apuesta == "impar" || apuesta == "Impar" || apuesta == "Impares"){

        ELEGIR_NUMERO_AZAR(numero);

        if (numero % 2 != 0){

            cout << "\nGanador!" << endl;
            cout << "El numero era ";
            NUMERO_AZAR(numero);
        }
        else{

            cout << "\nPerdedorrrr!!" << endl;
            cout << "El numero era ";
            NUMERO_AZAR(numero);
        }
  }
     if(apuesta == "pares" || apuesta == "par" || apuesta == "Pares" || apuesta == "Par"){

       ELEGIR_NUMERO_AZAR(numero);

        if (numero % 2 == 0){

            cout << "\nGanador!" << endl;
            cout << "El numero era ";
            NUMERO_AZAR(numero);
        }
        else{

            cout << "\nperdedorr!!" << endl;
            cout << "El numero era ";
            NUMERO_AZAR(numero);
        }
  }
     if(apuesta == "rojo" || apuesta == "rojos" || apuesta == "Rojo" || apuesta == "Rojos"){

        ELEGIR_NUMERO_AZAR(numero);

        if (numero % 2 == 0  && ((11 < numero && numero < 19) || (29 < numero && numero < 37)))
        {
            cout << "\nGanador!!" <<endl;
            cout << "El numero era ";
            NUMERO_AZAR(numero);
        }
        else if (numero % 2 != 0 && ((0 < numero && numero < 10) || (18 < numero && numero < 28))){

            cout << "\nGanador!!" <<endl;
            cout << "El numero era ";
            NUMERO_AZAR(numero);
        }
        else{

           cout << "\nPerdisteeee" << endl;
           cout << "El numero era ";
           NUMERO_AZAR(numero);
        }
  }
     if(apuesta == "negro" || apuesta == "negros" || apuesta == "Negro" || apuesta == "Negros"){

        ELEGIR_NUMERO_AZAR(numero);

       if (numero % 2 == 0 && ((0 < numero && numero < 11) || (19 < numero && numero < 29)))
        {
            cout << "\nGanador ganador" << endl;
            cout << "El numero era ";
            NUMERO_AZAR(numero);
     }
       else if(numero % 2 != 0 && ((10 < numero && numero < 18) || (28 < numero && numero < 36)))
        {
           cout << "\nGanador" << endl;
            cout << "El numero era ";
            NUMERO_AZAR(numero);
        }
      else{

        cout << "\nPerdisteee" << endl;
           cout << "El numero era ";
           NUMERO_AZAR(numero);
        }
  }

    if(apuesta == "1-18" || apuesta == "numero del 1 - 18" || apuesta == "1al18" || apuesta == "Numero del 1 al 18"){

        ELEGIR_NUMERO_AZAR(numero);

        if(0 < numero && numero < 19){

            cout << "\nGanaste!" << endl;
            cout << "El numero era ";
            NUMERO_AZAR(numero);
        }
      else{

            cout << "\nPerdiste!" << endl;
            cout << "El numero era ";
            NUMERO_AZAR(numero);
        }
  }
    if(apuesta == "19-36" || apuesta == "numero del 19 - 36" || apuesta == "19al36" || apuesta == "numero del 19 al 36"){

        ELEGIR_NUMERO_AZAR(numero);

        if(18 < numero && numero < 37){

            cout << "\nGanaste!" << endl;
            cout << "El numero era ";
            NUMERO_AZAR(numero);
        }
        else{

            cout << "\nPerdiste!" << endl;
            cout << "El numero era ";
            NUMERO_AZAR(numero);
        }
    }

    else{

        cout << "\nJuega otra vez!\n" << endl;
        goto apostar;
    }
}

//elegir color de acuerdo al numero
void NUMERO_AZAR(int numero){

 if(numero == 0)
{
    cout << numero << " verde" << endl; //GREEN
}

        else if (numero % 2 == 0 && ((0 < numero && numero < 11) || (19 < numero && numero < 29))) //even blacks (1 -> 10 & 20 -> 28)
        {
            cout << numero << " negro" << endl;

        }

        else if (numero % 2 == 0 && ((11 < numero && numero < 19) || (29 < numero && numero < 37))) //even reds (12 -> 18 & 30 -> 36)
        {
            cout << numero << " rojo" << endl;
        }

        else if (numero % 2 != 0 && ((0 < numero && numero < 10) || (18 < numero && numero < 28))) //odd reds (1 -> 9 & 19 -> 27)
        {
            cout << numero << " rojo" << endl;
        }

        else if (numero % 2 != 0 && ((10 < numero && numero < 18) || (28 < numero && numero < 36))) //odd blacks (11 -> 17 & 29 -> 35)
        {
            cout << numero << " negro" << endl;
        }

        else
        {
            cout << numero << "ERROR???" << endl; //error?
        }
}

//elegir numero al azar
void ELEGIR_NUMERO_AZAR(int numero){

     cout <<"Girando..." << "\n" << endl;

     for(int x = 0; x < 8; x++){

        numero = rand() % 37;
        this_thread::sleep_for (chrono::milliseconds(500));
        cout << numero << "\r";
     }
}
