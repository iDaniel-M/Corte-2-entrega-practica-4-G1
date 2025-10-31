🛒 Sistema de Carrito de Compras y Diagrama UML

Proyecto en C/C++ que implementa un sistema básico de carrito de compras y un diagrama UML de sus clases.

📘 Ejercicio 1: Sistema de Carrito de Compras
🧩 Descripción

Este ejercicio implementa un sistema simple de carrito de compras para una tienda en línea.
Permite agregar, eliminar y calcular el total de los productos seleccionados por el usuario.

⚙️ Clases principales
🧱 Producto

Representa un producto disponible en la tienda.
Atributos:

string nombre

float precio

int stock

🛍️ ItemCarrito

Representa un producto dentro del carrito, junto con la cantidad seleccionada.
Atributos:

Producto producto

int cantidad

🧾 CarritoCompras

Gestiona los productos añadidos por el usuario.
Métodos principales:

agregarProducto(Producto p, int cantidad)

eliminarProducto(string nombre)

calcularTotal()

👤 Usuario

Representa un cliente con historial de compras.
Atributos:

string nombre

vector<CarritoCompras> historialCompras

🧮 Ejercicio 2: Diagrama UML
📊 Descripción

Se elaboró el diagrama UML correspondiente a las clases del sistema de carrito de compras.
El diagrama muestra las relaciones entre:

Usuario

CarritoCompras

ItemCarrito

Producto

📌 El diagrama fue realizado con StarUML
 / Lucidchart
 (u otra herramienta equivalente).
El archivo se encuentra en la carpeta /uml/ con el nombre CarritoCompras_UML.pdf (o formato correspondiente)