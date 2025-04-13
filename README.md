# R-Combinaciones-Lexicográficas

Este proyecto en C++ genera todas las **r-combinaciones** posibles del conjunto `{1, 2, ..., n}`, las ordena de forma **lexicográfica** y las guarda en un archivo `.csv`. Al finalizar, valida que el número total de combinaciones coincida con el valor teórico `C(n, r)`.

---

## 👤 Autor(a)

**Nombre del estudiante:** [Carlos Jareth Garcia Ramirez]

---

## 🖥️ Requisitos del sistema

- Compilador compatible con **C++17** o superior.
- Sistemas compatibles: Windows, Linux, macOS.
- Editor de código o entorno como Code::Blocks, Visual Studio, VS Code o terminal con `g++`.

---

## ⚙️ Instrucciones de compilación y ejecución

1. Abre una terminal o consola.
2. Navega a la carpeta `/src` que contiene `main.cpp`.
3. Compila el archivo usando:

    ```bash
    g++ -std=c++17 -o combinaciones main.cpp
    ```

4. Ejecuta el programa:

    ```bash
    ./combinaciones
    ```

5. El programa solicitará los valores de `n` y `r`, generará las combinaciones y las guardará en un archivo CSV.

---

## 🧠 Explicación del algoritmo

Se utiliza **backtracking** (búsqueda recursiva) para generar todas las combinaciones posibles de tamaño `r` a partir del conjunto `{1, 2, ..., n}`:

- A cada paso, se agrega un nuevo número mayor al anterior.
- Cuando la combinación alcanza longitud `r`, se guarda.
- El proceso asegura que no haya repeticiones ni permutaciones redundantes.

El algoritmo explora en forma ascendente y sistemática, garantizando orden lexicográfico.

---

## 🔤 Orden Lexicográfico

El **orden lexicográfico** es similar al orden del diccionario. En este contexto:

- Las combinaciones se generan comenzando por las que contienen números más pequeños.
- Por ejemplo, para `n = 4`, `r = 3`, el orden correcto sería:

    ```
    1,2,3
    1,2,4
    1,3,4
    2,3,4
    ```

Nuestro algoritmo lo garantiza comenzando desde el número mínimo posible en cada nivel de recursión.

---

## ✅ Validación de entrada

El programa verifica:

- Que `n` sea un número entero **mayor o igual a 1**.
- Que `r` sea un número entero **mayor o igual a 0**.
- Que `r` no sea mayor que `n`.

Si se ingresan valores inválidos, el programa lo notifica y solicita una nueva entrada.

---

## 📄 Formato de salida

El archivo `.csv` generado se llama:
[`resultados/ejemplo.csv`](resultados/ejemplo.csv)


- Cada línea representa una combinación.
- Los elementos están separados por comas.
- Se guarda automáticamente en el mismo directorio donde se ejecutó el programa.

---

## 📏 Verificación de C(n, r)

El programa:

- Calcula el número de combinaciones generadas.
- Calcula el valor teórico `C(n, r)` usando la fórmula del coeficiente binomial:

    C(n, r) = n! / [r! × (n - r)!]

- Compara ambos resultados y muestra un mensaje indicando si coinciden o no.

---

