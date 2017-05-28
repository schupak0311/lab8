#include <place.h>
#include <vector>

Place::Place(){
    _id = 0;
    _name = "";
    _city = "";
    _year = 0;
}

Place::~Place() {}

Place::Place(int id, string name, string city, int year){
    _id = id;
    _name = name;
    _city = city;
    _year = year;
}

int Place::id(){ return _id; }

string Place::name(){ return _name; }

string Place::city(){ return _city; }

int Place::year(){ return _year; }

string Place::valueByField(string field){
    if(field == "id") return to_string(_id);
    if(field == "year") return to_string(_year);
    if(field == "name") return _name;
    if(field == "city") return _city;
    return "NOT FIELD";
}


vector<Place*> createPlaces(void){
    vector<Place*> places = {};
    places.push_back(new Place(123, "Statue of Liberty", "New York", 1875));
    places.push_back(new Place(342, "The Eiffel Tower", "Paris", 1889));
    places.push_back(new Place(36, "Lviv High Castle", "Lviv", 1250));
    places.push_back(new Place(456, "The Taj Mahal", "India", 1632));
    places.push_back(new Place(752, "Big Ben", "London", 1859));
    places.push_back(new Place(285, "Sofiyivsky Park", "Uman", 1796));
    places.push_back(new Place(902, "NSC Olimpiyskiy", "Kyiv", 1923));
    return places;
}

void clearPlaces(vector<Place*> places){
    for(Place *place : places) delete place;
}

