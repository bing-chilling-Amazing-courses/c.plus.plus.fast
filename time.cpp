#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <stdexcept>
#include <cstdlib>

void showExecutionTime() {
    std::time_t now = std::time(nullptr);
    std::tm localTime{};

    localtime_r(&now, &localTime);

    std::cout << "Hora de ejecucion: "
              << std::put_time(&localTime, "%Y-%m-%d %H:%M:%S")
              << std::endl;
}
int main() {
    showExecutionTime();
    return 0;
}