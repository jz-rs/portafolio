# Proyecto de Criptografía y Compresión en C++

Aplicación de consola en C++ que implementa varios algoritmos clásicos utilizados en búsqueda de patrones, cifrado y compresión de texto. El usuario puede elegir el algoritmo desde un menú interactivo.

## Qué hace este programa

Permite ejecutar distintos algoritmos sobre cadenas ingresadas por el usuario. Funciona completamente desde consola y cada opción ejecuta un algoritmo real.

### Algoritmos incluidos

* **Fuerza Bruta**
* **KMP** (Knuth–Morris–Pratt)
* **ZLW / LZW** (compresión)
* **Cifrado Afin**
* **Cifrado César (cifrar/descifrar)**
* **Playfair**
* **Huffman** (compresión de texto)
* **Vigenere**
* **Hill Cipher**

Estos algoritmos funcionan para cifrar, comprimir, buscar patrones y transformar mensajes usando distintas técnicas. Cada uno está implementado en una función diferente y accesible desde el menú principal.

## Ejemplo del menú

```cpp
cout<<"1) Fuerza Bruta"<<endl;
cout<<"2) KMP"<<endl;
cout<<"3) ZLW"<<endl;
cout<<"4) Afin"<<endl;
cout<<"5) Cesar"<<endl;
cout<<"6) PLAYFAIR"<<endl;
cout<<"7) Huffman"<<endl;
cout<<"8) Vigenere"<<endl;
cout<<"9) Hill"<<endl;
```

## Cómo ejecutarlo

1. Compilar:

```
g++ criptografia_y_seguridad.cpp -o crypto
```

2. Correr el ejecutable:

```
./crypto
```

3. Elegir un algoritmo del menú e ingresar el texto a procesar.

## Tecnologías utilizadas

* C++
* Manejo de cadenas
* Árboles binarios (Huffman)
* Estructuras de datos (`vector`, `unordered_map`, `queue`)
* Modularidad usando funciones

## Qué se practica en este proyecto

* Compresión y descompresión de texto
* Cifrado clásico
* Búsqueda y coincidencia de patrones
* Algoritmos fundamentales de seguridad y compresión
* Estructuras y funciones en C++