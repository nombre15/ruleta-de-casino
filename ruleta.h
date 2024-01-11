#include <iostream>
#include <string>
using namespace std;

class ruleta {

    public:

        ruleta();
        int jugar();
        void elegirNumeroAzar(int &numero);
        void elegirColor(int numero, int rojos[], int negros[], string &color);
        void jugadorGana(int numero,  int sumaApuesta, int rojos[], int negros[], int& dinero, string& colorNumero);
        void jugadorPierde(int numero, int rojos[], int negros[], int& dinero, string& colorNumero);

    private:
        int dinero;
        int rojos[18] = {1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
        int negros[18] = {2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35};

};
