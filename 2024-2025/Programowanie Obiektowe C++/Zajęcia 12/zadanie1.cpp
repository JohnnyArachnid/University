#include <iostream>
#include <mutex>

class Logger {
private:
    static Logger* instance;
    static std::mutex mutex;

    Logger() {
        std::cout << "Logger initialized.\n";
    }

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

public:
    static Logger* getInstance() {
        std::lock_guard<std::mutex> lock(mutex);
        if (instance == nullptr) {
            instance = new Logger();
        }
        return instance;
    }

    void log(const std::string& message) {
        std::cout << "[LOG]: " << message << std::endl;
    }
};

Logger* Logger::instance = nullptr;
std::mutex Logger::mutex;

int main() {
    Logger* logger1 = Logger::getInstance();
    logger1->log("Pierwsze logowanie");

    Logger* logger2 = Logger::getInstance();
    logger2->log("Drugie logowanie");

    if (logger1 == logger2) {
        std::cout << "logger1 i logger2 to ta sama instancja.\n";
    } else {
        std::cout << "logger1 i logger2 to rożne instancje.\n";
    }

    return 0;
}
