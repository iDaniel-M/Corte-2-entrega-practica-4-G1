#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Producto {
private:
    string nombre;
    float precio;
    int stock;

public:
    Producto(string n, float p, int s) : nombre(n), precio(p), stock(s) {}

    string getNombre() const { return nombre; }
    float getPrecio() const { return precio; }
    int getStock() const { return stock; }

    void reducirStock(int cantidad) {
        if (cantidad <= stock) stock -= cantidad;
    }

    void aumentarStock(int cantidad) {
        if (cantidad > 0) stock += cantidad;
    }

    void mostrarInfo() const {
        cout << "Producto: " << nombre << " | Precio: $" << precio 
             << " | Stock: " << stock << endl;
    }
};

class ItemCarrito {
private:
    Producto* producto;
    int cantidad;

public:
    ItemCarrito(Producto* p, int c) : producto(p), cantidad(c) {}

    float calcularSubtotal() const {
        return producto->getPrecio() * cantidad;
    }

    string getNombreProducto() const { return producto->getNombre(); }
    Producto* getProducto() const { return producto; }
    int getCantidad() const { return cantidad; }

    void mostrarItem() const {
        cout << "- " << producto->getNombre() << " x" << cantidad 
             << " = $" << calcularSubtotal() << endl;
    }
};

class CarritoCompras {
private:
    vector<ItemCarrito> items;

public:
    void agregarProducto(Producto& p, int cantidad) {
        if (cantidad > 0 && cantidad <= p.getStock()) {
            p.reducirStock(cantidad);
            items.push_back(ItemCarrito(&p, cantidad));
            cout << "Producto agregado al carrito: " << p.getNombre() << endl;
        } else {
            cout << "No hay stock suficiente de " << p.getNombre() << endl;
        }
    }

    void eliminarProducto(const string& nombre) {
        for (auto it = items.begin(); it != items.end(); ++it) {
            if (it->getNombreProducto() == nombre) {
                // Restaurar stock del producto
                Producto* prod = it->getProducto();
                int cantidad = it->getCantidad();
                if (prod) prod->aumentarStock(cantidad);

                items.erase(it);
                cout << "Producto eliminado: " << nombre << endl;
                return;
            }
        }
        cout << "Producto no encontrado en el carrito." << endl;
    }

    float calcularTotal() const {
        float total = 0;
        for (const auto& item : items) {
            total += item.calcularSubtotal();
        }
        return total;
    }

    void mostrarCarrito() const {
        if (items.empty()) {
            cout << "El carrito está vacío.\n";
            return;
        }
        cout << "\nCarrito de Compras:\n";
        for (const auto& item : items) {
            item.mostrarItem();
        }
        cout << "----------------------\n";
        cout << "TOTAL: $" << calcularTotal() << endl;
    }

    bool estaVacio() const { return items.empty(); }
};

class Usuario {
private:
    string nombre;
    vector<CarritoCompras> historialCompras;

public:
    Usuario(string n) : nombre(n) {}

    void comprar(CarritoCompras carrito) {
        if (!carrito.estaVacio()) {
            historialCompras.push_back(carrito);
            cout << "\nCompra realizada por " << nombre << ". Total: $"
                 << carrito.calcularTotal() << endl;
        } else {
            cout << "No se puede realizar una compra con el carrito vacío.\n";
        }
    }

    void mostrarHistorial() const {
        cout << "\nHistorial de compras de " << nombre << ":\n";
        if (historialCompras.empty()) {
            cout << "Sin compras registradas.\n";
        } else {
            int i = 1;
            for (const auto& carrito : historialCompras) {
                cout << "Compra #" << i++ << ":\n";
                carrito.mostrarCarrito();
                cout << endl;
            }
        }
    }
};

int main() {
    Producto p1("Laptop", 1200.0, 5);
    Producto p2("Mouse", 25.0, 20);
    Producto p3("Teclado", 45.0, 10);

    cout << "Productos disponibles:\n";
    p1.mostrarInfo();
    p2.mostrarInfo();
    p3.mostrarInfo();

    Usuario user("Daniel");

    CarritoCompras carrito;
    carrito.agregarProducto(p1, 1);
    carrito.agregarProducto(p2, 2);
    carrito.mostrarCarrito();

    carrito.eliminarProducto("Mouse");
    carrito.mostrarCarrito();

    user.comprar(carrito);
    user.mostrarHistorial();

    return 0;
}
