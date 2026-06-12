#include <iostream>
#include <fstream>
#include <string>
#include <sys/utsname.h>
#include <unistd.h>

std::string readFirstLine(const std::string& path) {
    std::ifstream file(path);
    std::string line;

    if (file && std::getline(file, line)) {
        return line;
    }

    return "No disponible";
}

void showSystemInfo() {
    struct utsname sysInfo;

    if (uname(&sysInfo) == 0) {
        std::cout << "Sistema operativo: " << sysInfo.sysname << std::endl;
        std::cout << "Nombre del kernel: " << sysInfo.release << std::endl;
        std::cout << "Version del kernel: " << sysInfo.version << std::endl;
        std::cout << "Arquitectura: " << sysInfo.machine << std::endl;
    } else {
        std::cout << "No se pudo obtener informacion del sistema." << std::endl;
    }
}

void showCpuInfo() {
    std::cout << "Modelo de CPU: "
              << readFirstLine("/proc/cpuinfo")
              << std::endl;
}

void showMemoryInfo() {
    std::cout << "Memoria total: "
              << readFirstLine("/proc/meminfo")
              << std::endl;
}

void showHostname() {
    char hostname[256];

    if (gethostname(hostname, sizeof(hostname)) == 0) {
        std::cout << "Hostname: " << hostname << std::endl;
    } else {
        std::cout << "Hostname: No disponible" << std::endl;
    }
}

int main() {
    std::cout << "Informacion basica del equipo" << std::endl;
    std::cout << "-----------------------------" << std::endl;

    showSystemInfo();
    showHostname();
    showCpuInfo();
    showMemoryInfo();

    return 0;
}
