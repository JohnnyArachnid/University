#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class IObserver {
public:
    virtual void update(const std::string& message) = 0;
    virtual ~IObserver() {}
};

class ISubject {
public:

    virtual void attach(IObserver* observer) = 0;

    virtual void detach(IObserver* observer) = 0;

    virtual void notify() = 0;
    virtual ~ISubject() {}
};

class NewsAgency : public ISubject {
private:
    std::vector<IObserver*> observers;
    std::string latestNews;

public:
    void attach(IObserver* observer) override {
        observers.push_back(observer);
    }

    void detach(IObserver* observer) override {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notify() override {
        for (IObserver* observer : observers) {
            observer->update(latestNews);
        }
    }

    void addNews(const std::string& news) {
        latestNews = news;
        notify();
    }
};

class NewsReader : public IObserver {
private:
    std::string name;

public:
    NewsReader(const std::string& readerName) : name(readerName) {}

    void update(const std::string& message) override {
        std::cout << name << " otrzymal wiadomosc: " << message << std::endl;
    }
};

int main() {
    NewsAgency agency;

    NewsReader reader1("Jan");
    NewsReader reader2("Anna");
    NewsReader reader3("Tomasz");

    agency.attach(&reader1);
    agency.attach(&reader2);

    agency.addNews("Nowe wiadomosci: kurs C++ ruszyl!");

    std::cout << "---\n";

    agency.detach(&reader1);
    agency.attach(&reader3);

    agency.addNews("Aktualizacja: C++ 26 w przygotowaniu!");

    return 0;
}
