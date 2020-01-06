#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ---------| Class |--------- //
// ---------| Methods |--------- //
// ---------| Constructor |--------- //
// ---------| Destructor |--------- //
// ---------| Public method, Private, Const method |--------- //


/*
    Struct - набор публичных полей
    - используется, если контролировать консистентность не нужно

    Class - скрывает данные, предоставляя определенный интерфейс доступа к ним
    - используется, если поля связаны друг с другом и эту связь нужно контролировать

    Поля делаются приватными, чтобы использование класса было более безопасным

    Смысловая связб между полями класса контролируется в методах

    Методы - вызываются в контексте конкретного объекта
    + имеют доступ к приватным полям

    Constructor - функция, создающая объект / дефолтный объект

*/


int ComputeDistance(const string& source, const string& destination) {
  return source.length() - destination.length();
}

// class вместо struct (формально ничего не изменилось)
class Route {
  public: // Публичная секция
    // Default Constructor (констурктор по умолчанию, без параметров)
    Route() {}
    // Default Constructor (констурктор по умолчанию, с параметрами)
    Route() {
      source = "Moscow";
      destination = "Saint Petersburg";
      UpdateLength();
    }
    // Constructor (параметризованный констурктор, параметры обязательны)
    Route(const string& new_source, const string& new_destination) {
      source = new_source;
      destination = new_destination;
      UpdateLength();
    }

    // Public methods
    void SetSourse(const string& new_source) {
      source = new_source;
      UpdateLength();
    }

    void SetDestintaion(const string& new_destination) {
      destination = new_destination;
      UpdateLength();
    }

    // const methods (+public)
    string GetSource() const { return source; }
    string GetDestination() const { return destination; }
    int GetLength() const { return length; }

  private: // Приватная секция
    void UpdateLength() { length = ComputeDistance(source, destination); }
    string source;
    string destination;
    int length;
 };

void PrintRoute(const Route& route) {
  cout << route.GetSource() << " -> "<< route.GetDestination() << endl;
}

void ReverserRoute(Route& route) {
  string temp = route.GetSource();
  route.SetSourse(route.GetDestination());
  route.SetDestintaion(temp);
}

int main() {
  // Route route;
  // route.SetSourse("Moscow");
  // route.SetDestintaion("Vologda");
  Route route2("Moscow", "Vologda");
  ReverserRoute(route2);
  PrintRoute(route2);
  Route route1;
  PrintRoute(route1);
  PrintRoute(Route()); // по умолчанию
  // PrintRoute({}); // почему-то не работает

  return 0;
}
