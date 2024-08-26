#include <iostream>
#include <string>

bool encontrarContrasena(std::string actual, int variarDigito, const std::string contrasena, std::string& solucion, int& nIntentos){
    if (variarDigito == 4) {
        if (contrasena == actual){
            solucion = actual;
            return true;
        }
        return false;
    }

    for (int i = 0; i <= 9; i++){
        actual[variarDigito] = char(i + 48);
        // std::cout << "vd: " << variarDigito << " ? " << actual << " | ";
        nIntentos++;
        if (encontrarContrasena(actual, variarDigito + 1, contrasena, solucion, nIntentos)) {
            return true;
        }
    }

    return false;
}

std::string contrasenaAleatoria(){
    std::string contrasena = "";
    for (int i = 0; i < 4; i++){
        contrasena += char(rand() % 10 + 48);
    }
    return contrasena;
}

int main() {
    srand(time(NULL));
    std::string contrasena = contrasenaAleatoria();

    std::string solucion = "0000";
    int nIntentos = 0;
    bool contrasenaEncontrada = encontrarContrasena(solucion, 0, contrasena, solucion, nIntentos);
    if (contrasenaEncontrada) {
        std::cout << "contrasena encontrada en " << nIntentos << " intentos: " << solucion << std::endl;
    }
}
