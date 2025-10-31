<div align="right">
<img width="32px" src="img/algo2.svg">
</div>

# TDA HASH

## Repositorio de Leon Acosta - 113246 - leacosta@fi.uba.ar

- Para la compilacion y ejecucion del programa se provee un **makefile**.

  - Compilar:

    ```bash
    # compilar el programa
    make hash
    # compilar las pruebas
    make pruebas_alumno
    ```

  - Ejecutar:

    ```bash
    # correr el programa
    make ejecutar PARAMETROS="<parametros>"
    # correr con el programa valgrind
    make valgrind PARAMETROS="<parametros>"
    # correr las pruebas
    make valgrind-alumno
    ```

> [!IMPORTANT]
> Los parametros que se deben pasar entre "" corresponden al nombre de un archivo con pokemones, y tres parametros extra los cuales son busqueda, nombre o id, nombre del pokemon buscado o ID del pokemon buscado.
>
> Ejemplo: `make ejecutar PARAMETROS="./ejemplos/normal.csv buscar nombre Pikachu"` O `make ejecutar PARAMETROS="./ejemplos/normal.csv buscar id 1"`

--- 

##  Funcionamiento


---

## Respuestas a las preguntas teóricas

### Diccionarios

Un diccionario es un tipo de dato abstracto (TDA) el cual nos permite almacenar informacion, esta informacion denominada _valores_ la almacenamos en conjunto con identificadores unicos llamados _claves_, este conjunto de claves y valores nos permiten construir la estructura de un Diccionario.
Un ejemplo podria ser el de el almacenamiento de la informacion de los Alumnos, en donde podriamos establecer un diccionario en el que almacenar, Nombre, Apellido, Datos de Contacto, y demas informacion como los **valores** asociados a cada alumno y luego utilizar el Numero de Padron de cada alumno como este identificador unico _clave_.

En base a esto podemos encontrar diferentes formas de implementarlo.

#### Formas de Implementacion

Una implementacion sencilla seria la de utilizar un **vector** (puede ser dinamico o estatico), en donde se almacenen punteros/direcciones de memoria, en donde almacenamos los pares de clave, valor que deseamos almacenar.
	- INSERTAR IMAGEN!

Otra manera de implementar seria a partir de la implementacion de alguno de los TDA, realizada en los TPs anteriores, como lo podrian ser por ejemplo utilizando una **Lista de Nodos Enlazados**, o un **Arbol Binario de Busqueda** (ABB).
En particular si utilizamos un Arbol Binario de Busqueda, en donde cada Nodo del arbol almacenaria una referencia al par clave y valor del diccionario.
	- INSERTAR IMAGEN!

##### Tabla de Hash

Tambien podemos implementar un Diccionario a partir de una Tabla de Hash.
La Tabla de Hash es una estructura la cual almacena valores, y podemos acceder a esos valores de manera mas directa dentro de la estructura.
Utiliza una **Funcion de Hash** para establecer los indices dentro de la estructura a los que se correponde cada clave.
La _funcion de Hash_ se encarga de transformar la clave que buscamos en un valor asociado a la misma (puede ser una cadena de caracteres, un numero) asociado a la misma, lo cual permite ubicarlo de manera simplificada dentro de la Tabla de Hash.
En nuestro problema en particular, la funcion de Hash convierte un string en un numero asociado, ese numero se correponde a un indice dentro de la Tabla.

Sin embargo, pueden haber Claves que luego de aplicarles esta funcion de Hash devuelvan el mismo valor, esto resulta en que, al querer acceder a ese valor, obtenegamos resultado erroneos.
A este resultado de que mas de una Clave se corresponda con el mismo indice dentro de la Tabla de Hash se lo conoce como **"Colisiones"**, y dependiendo del tipo Tabla de Hash que se este tratando es que tenemos distintas maneras de solucionarlas. 

**Tipos de Hash**

- **Hash Abierto**: Se caracteriza por tener un _Direccionamiento Cerrado_, lo cual implica que mas alla de las colisiones generadas, la clave se va a encontrar dentro de la tabla siempre en la posicion obtenida de la funcion de Hash. Se lo denomina _"Hash Abierto"_ ya que se utiliza una estructura de soporte para almacenar los pares clave y valor en la tabla, y no directamente dentro de la misma.
Para la resolucion de las colisiones se suele almacenar el par clave valor, a continuacion del valor que ya se encontraba previamente en la Tabla de Hash, a este metodo se lo llama de _Encadenamiento_, ya que vamos enlazando pares de claves y valores, dentro de un mismo indice de la Tabla.

	- INSERTAR IMAGEN!

- **Hash Cerrado**: En este otro tipo de Hash el _Direccionamiento_ decimos que es _Abierto_, esto se da ya que los valores son almacenados directamente en la tabla de hash, en el indice resultante de aplicar la funcion de hash a la clave.
En este tipo de Tabla se establece que su _tamaño_ debe ser mayor o igual que el numero claves.
Las colisiones en este tipo de Hash se resuelven recorriendo la tabla hasta encontrar el proximo espacio disponible en el que almacenar el valor, (aunque esta manera de recorrer puede variar).
Esta metodologia a la hora de resolver colisiones genera que al buscar una clave dentro de la Tabla de Hash, el indice que accedamos obtenido de la funcion de Hash no contenga el valor que buscamos, sino que el mismo haya sido desplazado dentro de la tabla.

	- INSERTAR IMAGEN!

**Tipos de Metodos de Busqueda**

- **"Probing Lineal"**: consiste en buscar el siguiente espacio libre inmediato.
- **"Probing Cuadratico"**: (intentos falidos)^2 para intentar insertar.
- **Hash Doble**: aplicar una segunda funcion de hash a la clave cuando hay colision.
