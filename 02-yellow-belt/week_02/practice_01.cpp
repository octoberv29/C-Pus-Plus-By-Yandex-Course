#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};

// TODO: WTF?
istream& operator >> (istream& is, Query& q) {
  // Реализуйте эту функцию
    string type, bus, stop;
    is >> type;
    if (type == "NEW_BUS") {
        size_t stop_count;
        is >> bus >> stop_count;
        vector<string> stops(stop_count);
        for (string& stop_name : stops) {
            is >> stop_name;
        }
        q.type = QueryType::NewBus;
        q.bus = bus;
        q.stops = stops;
    } else if (type == "BUSES_FOR_STOP") {
        is >> stop;
        q.type = QueryType::BusesForStop;
        q.stop = stop;
    } else if (type == "STOPS_FOR_BUS") {
        is >> bus;
        q.type = QueryType ::StopsForBus;
        q.bus = bus;
    } else if (type == "ALL_BUSES") {
        q.type = QueryType::AllBuses;
    }

    return is;
}

struct BusesForStopResponse {
  vector<string> buses_for_stop;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
  if (r.buses_for_stop.empty()) os << "No stop";
  else {
    for (const string& bus_item : r.buses_for_stop) {
      os << bus_item << " ";
    }
  }
  return os << endl;
}

struct StopsForBusResponse {
  string bus;
  vector<string> stops_for_bus;
  map<string, vector<string>> stops_to_buses;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
  if (r.stops_for_bus.empty()) os << "No bus";
  else {
    for (const string& stop_item : r.stops_for_bus) {
      os << "Stop " << stop_item << ":";
      if (r.stops_to_buses.at(stop_item).size() == 1) os << "no interchange";
      else {
        for (const string& bus_item : r.stops_to_buses.at(stop_item)) {
          if (bus_item != r.bus) os << " " << bus_item;
        }
      }
    }
  }

  return os << endl;
}

struct AllBusesResponse {
  map<string, vector<string>> buses_to_stops;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
  if (r.buses_to_stops.empty()) os << "No buses";
  else {
    for (const auto& bus_item : r.buses_to_stops) {
      os << "\nBus " << bus_item.first << ":";
      for (const string& stop_item : bus_item.second) {
        os << " " << stop_item;
      }
    }
  }
  return os << endl;
}

class BusManager {
public:
  void AddBus(const string& bus, const vector<string>& stops) {
    // buses_to_stops.insert(bus, stops);
    for (const auto& stop_item : stops) {
      buses_to_stops[bus].push_back(stop_item);
      stops_to_buses[stop_item].push_back(bus);
    }
  }

  BusesForStopResponse GetBusesForStop(const string& stop) const {
    BusesForStopResponse response;
    if (stops_to_buses.count(stop) != 0) {
      // response.buses_for_stop = stops_to_buses.at(stop);
      for (const auto& bus : stops_to_buses.at(stop)) {
        response.buses_for_stop.push_back(bus);
      }
    }
    return response;
  }

  StopsForBusResponse GetStopsForBus(const string& bus) const {
    StopsForBusResponse response;
    if (buses_to_stops.count(bus) != 0) {
      response.bus = bus;
      for (const auto& stop : buses_to_stops.at(bus)) {
        response.stops_for_bus.push_back(stop);
      }
      response.stops_to_buses = stops_to_buses;
    }
    return response;
  }

  AllBusesResponse GetAllBuses() const {
    return AllBusesResponse{buses_to_stops};
  }
private:
  map<string, vector<string>> buses_to_stops;
  map<string, vector<string>> stops_to_buses;
};


int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager manager;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      manager.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << manager.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << manager.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << manager.GetAllBuses() << endl;
      break;
    }
  }

  return 0;
}
