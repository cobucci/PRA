#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

typedef struct {

    double latitude;
    double longitude;
    int peso;
} Aviao;

Aviao *criaAviao();
void registroAviao(Aviao *ponteiroAviao);

int main(int argc, char *argv[]){

        int i=0;
        Aviao *ponteiroAviao;
        ponteiroAviao = criaAviao();
        ponteiroAviao->latitude = 0;
        ponteiroAviao->longitude = 0;
        ponteiroAviao->peso = 0;

        double vetorLongitude[3];
        double vetorLatitude[3];
        for(i=0 ; i<3 ; i++){
            registroAviao(ponteiroAviao);
            vetorLatitude[i] = ponteiroAviao->latitude;
            vetorLongitude[i] = ponteiroAviao->longitude;
        }

        for(i=0 ; i<3 ; i++){
            printf("LATITUDE %d = %.5lf | LONGITUDE %d = %.5lf\n", i, vetorLatitude[i], i, vetorLongitude[i]);
        }

        cout << "PESO FINAL = " << ponteiroAviao->peso << endl;

        free(ponteiroAviao);
    return 0;
}

void registroAviao(Aviao *ponteiroAviao){

    double latitude;
    double longitude;
    int peso;

    cout << "DIGITE A LATITUDE, LONGITUDE, PESO" << endl;
    cin >> latitude >> longitude;
    cin >> peso;

    ponteiroAviao->latitude = latitude;
    ponteiroAviao->longitude = longitude;
    if(peso > 0){
        ponteiroAviao->peso += peso;
    }
    else{
        ponteiroAviao->peso -= peso;
    }
}

Aviao *criaAviao(){

    Aviao *ponteiroAviao;
    ponteiroAviao = (Aviao *) malloc(sizeof(Aviao));
    if(ponteiroAviao == NULL){
        cout << "ERRO AO ALOCAR" << endl ;
        return 0;
    }

  return ponteiroAviao;
}
