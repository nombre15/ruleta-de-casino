#include <iostream>
#include <time.h>
#include <string>
#include <chrono>
#include <thread>
using namespace std;

void NUMBER (int);

int main()
{
    string bet;
    int BetNumber;
    cout << "como quieres apostar?" << endl;
    cout << " impares \n pares \n rojos \n negros \n un solo numero \n numero del 1 - 18 \n numero del 19 - 36" << endl;
    cin >> bet;

    single:
    if(bet == "numero"){

    cout << "escribe un numero para apostar" << endl;
    cin >> BetNumber;
    if(BetNumber > 37){
        cout << "ese no es un numero valido" << endl;
        goto single;
    }

    srand(time(0));

    cout <<"girando..." << endl;
    this_thread::sleep_for (chrono::seconds(2));

        int number = rand() % 37;
        if(number == BetNumber){

            cout << "\nganaste!" << endl;
            cout << "el numero era ";
            NUMBER(number);

        }
        else if(number != BetNumber){

            cout << "\nperdiste!" << endl;
            cout << "el numero era ";
            NUMBER(number);
        }
    }

     if(bet == "impares" || bet == "impar"){

        srand(time(0));
        cout <<"girando..." << endl;
    this_thread::sleep_for (chrono::seconds(2));
        int number = rand() % 37;

        if (number % 2 != 0){

            cout << "\nganador!" << endl;
            cout << "el numero era ";
            NUMBER(number);
        }
        else{

            cout << "\nperdedorrr!!" << endl;
            cout << "el numero era ";
            NUMBER(number);
        }
     }
     if(bet == "pares" || bet == "par"){

        srand(time(0));
        cout <<"girando..." << endl;
    this_thread::sleep_for (chrono::seconds(2));
        int number = rand() % 37;

        if (number % 2 == 0){

            cout << "\nganador!" << endl;
            cout << "el numero era ";
            NUMBER(number);
        }
        else{

            cout << "\nperdedorrr!!" << endl;
            cout << "el numero era ";
            NUMBER(number);
        }
     }
     if(bet == "red"){

        srand(time(0));
        cout <<"girando..." << endl;
    this_thread::sleep_for (chrono::seconds(2));
        int number = rand() % 37;

        if (number % 2 == 0  && ((11 < number && number < 19) || (29 < number && number < 37)))
        {
            cout << "\nganador!!" <<endl;
            cout << "el numero era ";
            NUMBER(number);
        }
        else if (number % 2 != 0 && ((0 < number && number < 10) || (18 < number && number < 28))){

            cout << "\nganador!!" <<endl;
            cout << "el numero era ";
            NUMBER(number);
        }
        else{

           cout << "\nperdistee" << endl;
           cout << "el numero era ";
           NUMBER(number);
        }
     }
     if(bet == "negros" || bet == "negro" ){

        srand(time(0));
        cout <<"girando..." << endl;
    this_thread::sleep_for (chrono::seconds(2));
        int number = rand() % 37;

      if (number % 2 == 0 && ((0 < number && number < 11) || (19 < number && number < 29)))
        {
            cout << "\nganador ganador" << endl;
            cout << "el numero era ";
            NUMBER(number);
     }
       else if(number % 2 != 0 && ((10 < number && number < 18) || (28 < number && number < 36)))
        {
           cout << "\nganador ganador" << endl;
            cout << "el numero era ";
            NUMBER(number);
        }
    else{

        cout << "\nperdistee" << endl;
           cout << "el numero era ";
           NUMBER(number);
        }
    }

    if(bet == "1-18" || bet == "numero del 1 - 18" || bet == "1al18" || bet == "numero del 1 al 18"){

        srand(time(0));
        cout <<"girando..." << endl;
    this_thread::sleep_for (chrono::seconds(2));
        int number = rand() % 37;

        if(0 < number && number < 19){

            cout << "\nganaste!" << endl;
            cout << "el numero era ";
            NUMBER(number);
        }
        else{

            cout << "\nperdiste!" << endl;
            cout << "el numero era ";
            NUMBER(number);
        }
    }
    if(bet == "19-36" || bet == "numero del 19 - 36" || bet == "19al36" || bet == "numero del 19 al 36"){

        srand(time(0));
        cout <<"girando..." << endl;
    this_thread::sleep_for (chrono::seconds(2));
        int number = rand() % 37;

        if(18 < number && number < 37){

            cout << "\nganaste!" << endl;
            cout << "el numero era ";
            NUMBER(number);
        }
        else{

            cout << "\nperdiste!" << endl;
            cout << "el numero era ";
            NUMBER(number);
        }
    }

}

void NUMBER(int number){
 if(number == 0)
        {
            cout << number << " verde" << endl;
        }

        /*even blacks (1 -> 10 & 20 -> 28)*/
        else if (number % 2 == 0 && ((0 < number && number < 11) || (19 < number && number < 29)))
        {
            cout << number << " negro" << endl;

        }

        /*even reds (12 -> 18 & 30 -> 36)*/
        else if (number % 2 == 0 && ((11 < number && number < 19) || (29 < number && number < 37)))
        {
            cout << number << " rojo" << endl;
        }

        /*odd reds (1 -> 9 & 19 -> 27)*/
        else if (number % 2 != 0 && ((0 < number && number < 10) || (18 < number && number < 28)))
        {
            cout << number << " rojo" << endl;
        }

        /*odd blacks (11 -> 17 & 29 -> 35)*/
        else if (number % 2 != 0 && ((10 < number && number < 18) || (28 < number && number < 36)))
        {
            cout << number << " negro" << endl;
        }

        /*error?*/
        else
        {
            cout << number << "error???" << endl;
        }
}


