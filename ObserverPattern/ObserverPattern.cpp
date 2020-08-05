// ObserverPattern.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "WeatherService.h"
#include <Windows.h>

void weatherService() {
    WeatherData* weatherCenter = new WeatherData();
    AvgWeatherDisplay* display1 = new AvgWeatherDisplay(weatherCenter);
    CurrentConditionsDisplay* display2 = new CurrentConditionsDisplay(weatherCenter);
    CurrentConditionsDisplay* display3 = new CurrentConditionsDisplay(weatherCenter);
    HeatIndexDisplay* display4;

    weatherCenter->setMeasurements();
    display1->removeMeFromList();
    Sleep(5000);
    weatherCenter->setMeasurements();
    display4 = new HeatIndexDisplay(weatherCenter);
    weatherCenter->setMeasurements();

    delete display3;
    delete display2;
    delete display1;
    delete weatherCenter;
}

int main()
{
    weatherService();
}


