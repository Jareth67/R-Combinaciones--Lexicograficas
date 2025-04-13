#include <iostream>     
#include <vector>       // Uso de vectores dinámicos
#include <fstream>      // Para escribir archivos
#include <string>       // Manejo de cadenas
#include <limits>       // Validación robusta de entrada

using namespace std;

//----------------------------------------
// Calcula el factorial de un número (n!)
//----------------------------------------
unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i)
        result *= i;
    return result;
}

//-----------------------------------------------------------
// Calcula el coeficiente binomial C(n, r) = n! / (r!(n−r)!)
//-----------------------------------------------------------
unsigned long long combinacionesTeoricas(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

//---------------------------------------------------------------------------------
// Genera todas las r-combinaciones del conjunto {1, 2, ..., n} usando backtracking
//---------------------------------------------------------------------------------
void generarCombinaciones(int n, int r, int inicio, vector<int>& actual, vector<vector<int>>& resultado) {
    // Si ya se tiene una combinación de tamaño r, la agregamos al resultado
    if (actual.size() == r) {
        resultado.push_back(actual);
        return;
    }

    // Recorremos desde el valor actual hasta n
    for (int i = inicio; i <= n; ++i) {
        actual.push_back(i);  // Agregamos el número actual a la combinación
        generarCombinaciones(n, r, i + 1, actual, resultado);  // Recursión al siguiente nivel
        actual.pop_back();  // Retroceso (backtrack) para probar otro número
    }
}

//-----------------------------------------------------------------
// Solicita un entero al usuario con validación de entrada robusta
//-----------------------------------------------------------------
int leerEnteroPositivo(const string& mensaje, int minimo = 0) {
    int valor;
    while (true) {
        cout << mensaje;
        cin >> valor;

        if (cin.fail() || valor < minimo) {
            cout << "❌ Entrada inválida. Intenta de nuevo.\n";
            cin.clear(); // Limpia el estado de error de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Elimina lo que quedó en el buffer
        } else {
            break; // Entrada válida
        }
    }
    return valor;
}

//==============
// Función main
//==============
int main() {
    cout << "=== Generador de r-combinaciones lexicográficas de {1, ..., n} ===\n";

    // Solicitar n y r al usuario
    int n = leerEnteroPositivo("Ingrese el valor de n (>= 1): ", 1);
    int r = leerEnteroPositivo("Ingrese el valor de r (>= 0): ", 0);

    // Validar que r no sea mayor que n
    while (r > n) {
        cout << "❌ Error: r no puede ser mayor que n.\n";
        r = leerEnteroPositivo("Ingrese un valor válido para r (>= 0): ", 0);
    }

    // Generar combinaciones
    vector<vector<int>> combinaciones;
    vector<int> actual;
    generarCombinaciones(n, r, 1, actual, combinaciones);

    // Crear archivo de salida CSV
    string nombreArchivo = "combinaciones_n" + to_string(n) + "_r" + to_string(r) + ".csv";
    ofstream archivo(nombreArchivo);

    // Escribir cada combinación en una línea del CSV
    for (const auto& comb : combinaciones) {
        for (size_t i = 0; i < comb.size(); ++i) {
            archivo << comb[i];
            if (i != comb.size() - 1) archivo << ","; // Separar por comas
        }
        archivo << "\n";
    }
    archivo.close(); // Cerrar archivo

    // Calcular el número teórico de combinaciones
    unsigned long long teorico = combinacionesTeoricas(n, r);

    // Mostrar resumen al usuario
    cout << "\n✅ Combinaciones generadas correctamente.\n";
    cout << "📊 Total generadas: " << combinaciones.size() << "\n";
    cout << "📚 Total teóricas:  " << teorico << "\n";

    // Comparar y mostrar si coinciden
    if (combinaciones.size() == teorico)
        cout << "✅ Coinciden los conteos.\n";
    else
        cout << "❌ ¡Los conteos NO coinciden!\n";

    // Mostrar ruta absoluta del archivo generado
    string rutaCompleta = filesystem::absolute(nombreArchivo).string();
    cout << "📁 Archivo CSV guardado en:\n" << rutaCompleta << "\n";

    return 0;
}
