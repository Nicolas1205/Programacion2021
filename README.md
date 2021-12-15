
# Trabajo Final Integrado - Programacion

- author : Anachuri Nicolas Daniel 


# Requierements

- GCC (Version used 11.1.0)

# Quick Start 

Download this repo:

```bash
git clone https://github.com/Nicolas1205/Programacion2021.git
```

## If you use Linux based system

Use the binary `app` located in `bin` directory

## Build from source

Alternativaly you can compile from source

Run inside `src` direcotory:

```bash
g++ -o app main.cpp load_teams.cpp show_menus.cpp list_teams.cpp load_players.cpp list_players.cpp show_teams.cpp
```


# Explicacion


## Introduccion {#introduccion}


### Entendiendo la estructura {#entendiendo-la-estructura}

```text
/home/nicolas/me/programmingSchool/finalWork/
├── bin
│   └── app
├── data
│   └── players.txt
├── docs
├── include
│   ├── chose_player.h
│   ├── gen_table.h
│   ├── play.h
│   ├── register_player.h
│   ├── show_menus.h
│   └── sieve.h
├── README.md
└── src
    ├── chose_player.cpp
    ├── gen_table.cpp
    ├── main.cpp
    ├── play.cpp
    ├── register_player.cpp
    ├── show_menus.cpp
    └── sieve.cpp

5 directories, 16 files
```


#### `bin` {#bin}

En este directorio se encuentran los binarios, en otras palabras el codigo ya compilado.


#### `include` {#include}

Se encuentran las definiciones de funciones como tambien de registros.


#### `src` _source_ {#src-source}

El codigo en si, donde se encuentra la implementacion de funciones.


### Probar el programa {#probar-el-programa}


#### Requerimientos {#requerimientos}

-   GCC 7.x o versiones superiores


#### Compilar {#compilar}

Ejecutar desde `src`

```shell
g++  -o app  chose_player.cpp  register_player.cpp sieve.cpp show_menus.cpp main.cpp gen_table.cpp play.cpp -std=c++17
```


## Explicacion  y Conceptos {#explicacion-y-conceptos}


### Para empezar {#para-empezar}

Como se ha visto previamente, el codigo se ha separado en diferentes archivos, con el objetivo de una mayor legibilidad.

Explicitamente estos son:

| Archivos             | Funcion                                  |
|----------------------|------------------------------------------|
| chose\_player.cpp    | Elegir Jugadores                         |
| gen\_table.cpp       | Generar Tabla                            |
| main.cpp             | Iniciar programa                         |
| play.cpp             | Iniciar juego                            |
| register\_player.cpp | Acciones de Jugador )                    |
| show\_menus.cpp      | Mostrar Menus y informacion de Jugadores |
| sieve.cpp            | Generar Criba de Eratostenes             |


### main.cpp {#main-dot-cpp}

Contiene el inicio de programa.

En sintesis, inicia el programa y muestra el **Menu Principal**, Dependiendo de la entrada del jugador se ejecutan las siguientes acciones.


#### Opcion 1 {#opcion-1}

Crear Tablero y obtener via referencia el valor del puntaje dorado.

```c++
if (menu_option == '1') {
      table = gen_table(golden_score);
}
```


#### Opcion 2 {#opcion-2}

Primero comprobamos si la capacidad maxima fue superada, luego ingresamos los datos del nuevo jugador y por ultimo lo registramos.

```c++
if (menu_option == '2') {

      if (players_data.size() == 10)
        continue;

      std::string name, surname, username;
      puts("*************** Registrar Usario **************");
      printf("\nNombre: ");
      std::cin >> name;
      printf("\nApellido: ");
      std::cin >> surname;
      printf("\nNombre de Usario: ");
      std::cin >> username;
      post_player(name, surname, username, players_data);
}
```


#### Opcion 3 {#opcion-3}

Mostramos los datos de los jugadores

```c++
if (menu_option == '3') {
      show_players();
}
```


#### Opcion 4 {#opcion-4}

Ejecuta play desde `play.cpp`

```c++
if (menu_option == '4') {
        play(table, &golden_score);
}
```


### gen\_table.cpp {#gen-table-dot-cpp}

Se genera la tabla, tambien se crea un registro para guardar datos de cada celda del tablero

-   Estructura del registro

<!--listend-->

```c++
typedef struct Cell {
  std::string player_catcher; // Jugador que atrapo este casillero
  int cell_value; // Valor aleatorio de este casillero
  bool is_catched = false; // Si fue atrapado entonces true
  bool specials[5];
  /* specials contiene en orden:
     es prime = false;
     es capicua = false;
     es amigo = false;
     es perfecto= false;
     en diagonal = false;
 */
} Cell;
```

Entonces podemos crear un vector de 10X10 con este registro.

```c++
std::vector<std::vector<Cell>> table(10, std::vector<Cell>(10));
```

Ahora creamos un vector de punteros a nuestras funciones para saber si cierto valor aleatorio es special, si es el caso, entonces specials[i] es **true**

```c++
bool (*ptr_functions[])(int) = {prime_number, palindrome_number,
                                  friend_number, perfect_number};


```

```c++
for (int i = 0; i < COLS; i++) {
    for (int j = 0; j < ROWS; j++) {
      int random = get_random(); // Obtener valor aleatorio
      table[i][j].cell_value = random;
      for (int k = 0; k < 4; k++) {
        table[i][j].specials[k] = (*ptr_functions[k])(random); // Calculos que tipo de valor especial es
      }
      table[i][j].specials[0] && table[i][j].specials[1] ? count_both++ : 0;
      table[i][j].specials[4] = i == j ? 1 : 0; // En diagonal
    }
  }
```

Por ultimo calculamos el puntaje dorado de este tablero.

```c++
golden_score = count_primes + count_palindromes + count_both + 10000;
```


### register\_players.cpp {#register-players-dot-cpp}

Todas las acciones disponibles que esten relacionadas a los jugadores


#### Registro de jugadores {#registro-de-jugadores}

Estructura de nuestro registro de jugadores

```c++
typedef struct {
  std::string name, surname, username; // Datos principales
  bool playing = false; // Jugador en partida
  int points = 0;
  int turns = 1;
  int nothing_catched = 0; // Si no ha atrapado numeros especiales
} Player;
```


#### Obtener datos de jugadores {#obtener-datos-de-jugadores}

Para esta tarea, cambie cree una \*base de datos para guardar la informacion de los jugadores y asi no tener que ingresar cada vez nuevos.

Primero leemos nuestra base de datos.

```c++
std::ifstream i("../data/players.txt");
```

Segundo, recibimos la cantidad de jugadores registrados

```c++
i >> players_sz;
```

Creamos un vector de Jugadores

```c++
std::vector<Player> players_data(players_sz);
```

Por ultimo, obtenemos los datos

```c++
 for (int iter = 0; iter < players_sz; iter++) {
    i >> players_data[iter].username >> players_data[iter].name >>
        players_data[iter].surname;
  }
```


#### Registrar un Jugador {#registrar-un-jugador}

Abrir la base de datos:

```c++
std::ofstream o("../data/players.txt");
```

Registramos al jugador:

```c++
players_data.push_back({name, surname, username});
```

Ordenamos los jugadores

```c++
sort(players_data.begin(), players_data.end(), comp);
```

Sobre escribimos la base de datos con el nuevo orden:

```c++
o << players_data.size() << "\n";

for (int i = 0; i < players_data.size(); i++) {
  o << players_data[i].username << "\n\t";
  o << players_data[i].name << "\n\t";
  o << players_data[i].surname << "\n";
}
```


#### Mostrar Jugadores {#mostrar-jugadores}

Primero, obtemos los datos:

```c++
std::vector<Player> players_data = get_players_data();
```

Segundo, Imprimimos los resultados:

```c++
for (int i = 0; i < players_data.size(); i++) {
    std::cout << "Usuario: " << players_data[i].username << "\n\t";
    std::cout << "Nombre: " << players_data[i].name << "\n\t";
    std::cout << "Apellido: " << players_data[i].surname << "\n";
}
```


### play.cpp {#play-dot-cpp}


#### Elegir Jugadores `chose_players.cpp` {#elegir-jugadores-chose-players-dot-cpp}

Primero, obtemos los datos:

```c++
std::vector<Player> players_data = get_players_data();
```

Creamos un vector con dos posiciones para los jugadores que van a jugar:

```c++
std::vector<Player> players(2);
```

Ahora el usuario elige los jugadores:

```c++
  for (int i = 0; i < 2; i++) {
    bool selected = false;
    while (!selected) { // Hasta que selecciones un jugador

      printf("SELECIONAR JUGADORES\n");
      printf("Ingrese username del jugador %d: ", i + 1);
      std::string username;
      std::cin >> username;
      if (search_player(username, players_data, players, i)) {
        selected = true;
        std::cout << players[i].username << " fue seleccionado!\n";
      }
    }
  }
```


#### Buscar Jugadores {#buscar-jugadores}

Buscamos si el jugador existe, si **true** entonces asignamos al primero o segundo jugador los datos del jugador buscado. De otra forma **false** si, no existe o ya ha sido seleccionado.

```c++
 for (int i = 0; i < players_data.size(); i++) {
    if (players_data[i].username == username) {
      if (!players_data[i].playing) {
        players_data[i].playing = true;
        players[p].name = players_data[i].name;
        players[p].surname = players_data[i].surname;
        players[p].username = players_data[i].username;
        return true; // Jugador encontrado y se puede elegir
      } else if (players_data[i].playing) {
        puts("ESTE JUGADOR YA FUE SELECCIONADO");
        return false;
      }
    }
  }

puts("ESTE JUGADOR NO ESTA REGISTRADO");
return false;

```


#### Empezar el juego {#empezar-el-juego}

Primero definimos las opciones y el menu:

Mostrar Menu de juego:

```c++
show_play_menu(players);
```

<!--list-separator-->

-  Opcion 1 (Elegir Jugadores)

    Asignamos a nuestro vector jugadores los valores resultantes:

    ```c++
    players = chose_players();
    ```

<!--list-separator-->

-  Opcion 2 (Jugar)

    Lanzar Dados es la funcion principal donde el juego se lleva acabo:

    ```c++
    throw_dices(players, table, golden_score);
    ```

    -   Cada turno dura exactamente la cantidad de turnos permitdos de un jugador.

    <!--listend-->

    ```c++
    while (players[player_turn].turns--)
    ```

    -   Obtenemos los dados

    <!--listend-->

    ```c++
    auto [d1, d2] = get_dices();
    ```

    -   Comprobamos si el la casilla ya fue asignada, sino, entonces el jugador que la encontro se convierte en el propietario.

    <!--listend-->

    ```c++
    table[d1][d2].is_catched = true;
    table[d1][d2].player_catcher = players[player_turn].username;
    ```

    De otra forma, mostramos le asignamos un turno mas y mostramos el resultado de esta partida

    ```c++
    show_player_results(&players[player_turn], std::make_pair(d1, d2),
                        table[d1][d2].specials, table[d1][d2].cell_value,
                        score);

    bool property_of = player_turn == 1 ? 0 : 1; // De quien es esta casilla
    std::cout << "\nYA HA SIDO TOMADA POR " << players[property_of].username
              << '\n';
    players[player_turn].turns++;
    ```

    Si es amigo o primo se suman turnos:

    ```c++
    players[player_turn].turns += table[d1][d2].specials[2] ? 1 : 0;
    players[player_turn].turns += table[d1][d2].specials[3] ? 2 : 0;
    ```

    Obtenemos el puntaje y lo sumamos al total:

    ```c++
    score = get_score(table, d1, d2);
    players[player_turn].points += score;
    ```

    Si el numero no es especial, entonces sumamos el contador de turnos sin atrapar especiales:

    ```c++
    players[player_turn].nothing_catched++;
    ```

    Si este contador llega a 3 entonces:

    ```c++
    if (players[player_turn].nothing_catched >= 3) {
            std::cout << players[player_turn].username
                      << " no ha atrapado numeros especiales"
                         " -10 puntos\n";
            players[player_turn].points -= 10;
            players[player_turn].nothing_catched = 0;
    }
    ```

    Si un jugador gana, en otras palabras, supera o iguala el puntaje dorado:

    ```c++
    if (players[player_turn].points >= *golden_score) {
            show_player_winner(&players[player_turn]); // Mostrar resultados del ganador
            return;
    }
    ```
