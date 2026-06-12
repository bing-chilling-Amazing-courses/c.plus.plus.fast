#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Uso: " << argv[0] << " <ruta>\n";
        return 1;
    }

    fs::path ruta = argv[1];

    if (!fs::exists(ruta)) {
        std::cout << "La ruta no existe.\n";
    } else if (fs::is_symlink(ruta)) {
        std::cout << "Es un enlace simbolico.\n";
    } else if (fs::is_regular_file(ruta)) {
        std::cout << "Es un archivo.\n";
    } else if (fs::is_directory(ruta)) {
        std::cout << "Es un directorio.\n";
    } else {
        std::cout << "Existe, pero es de otro tipo.\n";
    }

    return 0;
}
