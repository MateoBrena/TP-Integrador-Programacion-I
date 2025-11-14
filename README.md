# 🌴 Supervivencia en la Selva 🏕️

## 📖 Tabla de Contenidos
1. [🌟 Descripción](#descripción)
2. [🎮 Cómo jugar](#cómo-jugar)
3. [🕹️ Controles](#controles)
4. [✨ Características del juego](#características-del-juego)
5. [⚙️ Funciones principales](#funciones-principales)
6. [💻 Compilación](#compilación)
7. [📂 Estructura del proyecto](#estructura-del-proyecto)

---

## 🌟 Descripción
"Supervivencia en la Selva" es un juego de supervivencia donde los jugadores deben recolectar alimentos, construir refugios y una balsa para escapar de la jungla.  
Cada decisión diaria afecta el progreso y la supervivencia del jugador, enfrentándolo a desafíos tanto del entorno como de otros jugadores controlados por la computadora.

---

## 🎮 Cómo jugar
El juego se desarrolla en varias etapas:  

1. Recolecta alimentos suficientes (2kg por día).  
2. Construye tu refugio y, en etapas posteriores, una balsa para escapar.  
3. Toma decisiones estratégicas diariamente sobre tus acciones.  
4. Sobrevive a los días, administra recursos y compite contra otros jugadores simulados.  

**Objetivo:** Llegar a la última etapa y elegir el camino correcto en el río para escapar de la jungla.

---

## 🕹️ Controles
- **W / Arriba**: Mover selección hacia arriba  
- **S / Abajo**: Mover selección hacia abajo  
- **Enter**: Confirmar elección

---

## ✨ Características del juego
- Multietapa: Refugio, balsa y desafío final del río  
- Competencia contra bots: Otros jugadores simulan decisiones  
- Gestión de recursos: Alimentos, materiales y tiempo  
- Sistema de estadísticas diario para evaluar rendimiento y supervivencia  
- Mensajes inmersivos y narrativa interactiva  

---

## ⚙️ Funciones principales
- `nombreYEdad()`: Solicita los nombres y edades de los jugadores  
- `recolectarAlimentos()`: Permite recolectar alimentos y registrar progresos  
- `recolectarMateriales()`: Permite recolectar materiales para refugio o balsa  
- `recoleccionBots()`: Controla la recolección de los jugadores simulados  
- `estadisticasEtapa1() / estadisticasEtapa2() / estadisticasEtapa3()`: Muestra estadísticas al final de cada etapa  
- `chequearVivos()`: Determina qué jugadores siguen vivos  
- `eleccionFinal() / eleccionFinalBots()`: Controlan la decisión final en el río

---

## 💻 Compilación
Se necesita un compilador de C++ compatible con C++11 o superior.

### 🪟 Windows
1. Instalar [MinGW](http://www.mingw.org/) o usar Visual Studio  
2. Abrir la terminal y compilar:

bash
g++ main.cpp Funciones.cpp -o Supervivencia.exe
Ejecutar:

bash
Supervivencia.exe

### 🐧 Linux
Instalar g++ si no está disponible:

bash
sudo apt update
sudo apt install g++

Compilar:

bash
g++ main.cpp Funciones.cpp -o Supervivencia
Ejecutar:

bash
./Supervivencia

## 📂 Estructura del proyecto
bash
Copiar código
SupervivenciaEnLaSelva/
│
├─ main.cpp           # Archivo principal con la lógica del juego
├─ Funciones.h        # Declaración de funciones auxiliares
├─ Funciones.cpp      # Implementación de las funciones del juego
├─ rlutil.h           # Librería externa para control de consola
└─ README.md          # Documentación del proyecto

