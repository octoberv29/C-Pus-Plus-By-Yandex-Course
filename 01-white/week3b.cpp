#include <iostream>
#include <string>
#include <vector>

using namespace std;

int ComputeDistance(const string& source, const string& destination) {
  return source.length() - destination.length();
}

class Route { // class вместо struct (формально ничего не изменилось)
  public: // Публичная секция
    Route() {
      source = "Moscow";
      destination = "Saint Petersburg";
      UpdateLength();
    } // // Constructor (констурктор по умолчанию, оздается без параметров)
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
    string GetSource() const { // cosnst method
      return source;
    }
    string GetDestination() const { //const method
      return destination;
    }
    int GetLength() const { // const method
      return length;
    }

  private: // Приватная секция
    void UpdateLength() {
      length = ComputeDistance(source, destination);
    }
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
