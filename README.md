<h1>🌴 JUNGLA 🏕️</h1>

<h2>📖 Tabla de Contenidos</h2>
<ul>
  <li><a href="#descripcion">Descripción</a></li>
  <li><a href="#como-jugar">Cómo jugar</a></li>
  <li><a href="#controles">Controles</a></li>
  <li><a href="#caracteristicas-del-juego">Características del juego</a></li>
  <li><a href="#funciones-principales">Funciones principales</a></li>
  <li><a href="#compilacion">Compilación</a></li>
  <li><a href="#estructura-del-proyecto">Estructura del proyecto</a></li>
</ul>

<hr>

<h2 id="descripcion">🌟 Descripción</h2>
<p>
"JUNGLA" es un juego de supervivencia donde el jugador debe recolectar alimentos, construir su refugio y una balsa para escapar de la jungla.<br>
Cada decisión diaria afecta el progreso y la supervivencia del jugador, enfrentándolo a desafíos tanto del entorno
</p>

<h2 id="como-jugar">🎮 Cómo jugar</h2>
<p>El juego se desarrolla en varias etapas:</p>
<ol>
  <li>Recolecta alimentos suficientes (2kg por día).</li>
  <li>Construye tu refugio y, en etapas posteriores, una balsa para escapar.</li>
  <li>Toma decisiones estratégicas diariamente sobre tus acciones.</li>
  <li>Sobrevive a los días, administra recursos y compite contra otros jugadores controlados por la computadora.</li>
</ol>
<p><strong>Objetivo:</strong> Llegar a la última etapa y elegir el camino correcto en el río para escapar de la jungla.</p>

<h2 id="controles">🕹️ Controles</h2>
<ul>
  <li><strong>W / Arriba</strong>: Mover selección hacia arriba</li>
  <li><strong>S / Abajo</strong>: Mover selección hacia abajo</li>
  <li><strong>Enter</strong>: Confirmar elección</li>
</ul>

<h2 id="caracteristicas-del-juego">✨ Características del juego</h2>
<ul>
  <li>Multietapa: Refugio, balsa y desafío final del río</li>
  <li>Competencia contra la computadora: Otros jugadores simulan decisiones</li>
  <li>Gestión de recursos: Alimentos, materiales y tiempo</li>
  <li>Sistema de estadísticas diario para evaluar rendimiento y supervivencia</li>
  <li>Mensajes inmersivos y narrativa interactiva</li>
</ul>

<h2 id="funciones-principales">⚙️ Funciones principales</h2>
<ul>
  <li><code>nombreYEdad()</code>: Solicita los nombres y edades de los jugadores</li>
  <li><code>recolectarAlimentos()</code>: Permite recolectar alimentos y registrar progresos</li>
  <li><code>recolectarMateriales()</code>: Permite recolectar materiales para refugio o balsa</li>
  <li><code>recoleccionBots()</code>: Controla la recolección de los jugadores simulados</li>
  <li><code>estadisticasEtapa1()</code> / <code>estadisticasEtapa2()</code> / <code>estadisticasEtapa3()</code>: Muestra estadísticas al final de cada etapa</li>
  <li><code>chequearVivos()</code>: Determina qué jugadores siguen vivos</li>
  <li><code>eleccionFinal()</code> / <code>eleccionFinalBots()</code>: Controlan la decisión final en el río</li>
</ul>

<h2 id="compilacion">Compilación</h2>

<h3>🪟 Windows</h3>
<p>1. Instalar <a href="http://www.mingw.org/">MinGW</a> o usar Visual Studio</p>
<p>2. Abrir la terminal y compilar:</p>
<pre><code>g++ main.cpp Funciones.cpp -o Supervivencia.exe</code></pre>
<p>3. Ejecutar:</p>
<pre><code>Supervivencia.exe</code></pre>

<h3>🐧 Linux</h3>
<p>1. Instalar g++ si no está disponible:</p>
<pre><code>sudo apt update
sudo apt install g++</code></pre>
<p>2. Compilar:</p>
<pre><code>g++ main.cpp Funciones.cpp -o Supervivencia</code></pre>
<p>3. Ejecutar:</p>
<pre><code>./Supervivencia</code></pre>

<h2 id="estructura-del-proyecto">📂 Estructura del proyecto</h2>
<pre><code>SupervivenciaEnLaSelva/
│
├─ main.cpp           # Archivo principal con la lógica del juego
├─ Funciones.h        # Declaración de funciones auxiliares
├─ Funciones.cpp      # Implementación de las funciones del juego
├─ rlutil.h           # Librería externa para control de consola
└─ README.md          # Documentación del proyecto
</code></pre>






