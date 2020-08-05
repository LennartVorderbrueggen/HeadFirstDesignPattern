#include <iostream>
#include <list>

class IDisplayElement {
public:
	virtual void display() = 0;
};

class IObserver {
public:
	virtual void update(float temp, float humidity, float pressure) = 0;
	virtual void removeMeFromList() = 0;
};


class ISubject{
public:
	virtual void registerObserver(IObserver *o) = 0;
	virtual void unregisterObserver(IObserver *o) = 0;
	virtual void notifyObserver() = 0;
};


class WeatherData : public ISubject{
private:
	float temp;
	float hum;
	float pres;
	std::list<IObserver*> observers;

public:
	WeatherData() {
	}

	void registerObserver(IObserver *o) override {
		observers.push_back(o);
	}
	void unregisterObserver(IObserver *o) override{
		observers.remove(o);
	}
	void notifyObserver() {
		std::list<IObserver*>::iterator iterator = observers.begin();
		while (iterator != observers.end()) {
			(*iterator)->update(temp,hum,pres);
			++iterator;
		}
	}
	
	void measurementChanged() {
		this->notifyObserver();
	}

	void setMeasurements() {
		temp = getTemperature();
		hum = getHumidity();
		pres = getPressure();
		measurementChanged();
	}


	float getTemperature() {
		float temp = 30;
		//std::cout << "Temperature is " << temp << "°C.\n";
		return temp;
	}
	float getHumidity() {
		float hum = 10;
		//std::cout << "Humidity is " << hum << ".\n";
		return hum;
	}
	float getPressure() {
		float pres = 1014;
		//std::cout << "Pressure is " << pres << ".\n";
		return pres;
	}
};

class CurrentConditionsDisplay : public IObserver, public IDisplayElement {
private:
	std::string name = "CurrentConditionsDisplay";
	float temp;
	float hum;
	float pres;
	ISubject* weatherData;

public:
	CurrentConditionsDisplay(ISubject* s) {
		this->weatherData = s;
		this->weatherData->registerObserver(this);
	};
	
	void update(float temp, float humidity, float pressure) {
		this->hum = humidity;
		this->pres = pressure;
		this->temp = temp;
		display();
	}

	void display() {
		std::cout << this->name << "\n";
		std::cout << "Temperature is " << this->temp << "°C.\n";
		std::cout << "Humidity is " << this->hum << ".\n";
		std::cout << "Pressure is " << this->pres << ".\n";
	}

	void removeMeFromList() override {
		weatherData->unregisterObserver(this);
	}
};

class AvgWeatherDisplay : public IObserver, public IDisplayElement {
private:
	std::string name = "AvgWeatherDisplay";
	float temp;
	float hum;
	float pres;
	ISubject* weatherData;

public:
	AvgWeatherDisplay(ISubject* s) {
		this->weatherData = s;
		this->weatherData->registerObserver(this);
	};

	void update(float temp, float humidity, float pressure) override{
		this->hum = humidity;
		this->pres = pressure;
		this->temp = temp;
		this->display();
	}

	void display() override {
		std::cout << this->name << "\n";
		std::cout << "Avg Temperature is " << this->temp/2 << "°C.\n";
	}

	void removeMeFromList() override {
		weatherData->unregisterObserver(this);
	}
};

class HeatIndexDisplay : public IObserver, public IDisplayElement {
private:
	std::string name = "HeatIndexDisplay";
	float temp;
	float hum;
	ISubject* weatherData;

	float computeHeatIndex(float t, float rh) {
		float index = (float)((16.923 + (0.185212 * t) + (5.37941 * rh) - (0.100254 * t * rh) +
			(0.00941695 * (t * t)) + (0.00728898 * (rh * rh)) +
			(0.000345372 * (t * t * rh)) - (0.000814971 * (t * rh * rh)) +
			(0.0000102102 * (t * t * rh * rh)) - (0.000038646 * (t * t * t)) + (0.0000291583 *
				(rh * rh * rh)) + (0.00000142721 * (t * t * t * rh)) +
			(0.000000197483 * (t * rh * rh * rh)) - (0.0000000218429 * (t * t * t * rh * rh)) +
			0.000000000843296 * (t * t * rh * rh * rh)) -
			(0.0000000000481975 * (t * t * t * rh * rh * rh)));
		return index;
	}

public:
	HeatIndexDisplay(ISubject* s) {
		this->weatherData = s;
		this->weatherData->registerObserver(this);
	};

	void update(float temp, float humidity, float pressure) override {
		this->hum = humidity;
		this->temp = temp;
		this->display();
	}
	

	void display() override {
		std::cout << this->name << "\n";
		float heatIndex;
		heatIndex = computeHeatIndex(temp,hum);
		std::cout << "Heat Index is " << heatIndex << "\n";
	}

	void removeMeFromList() override {
		weatherData->unregisterObserver(this);
	}
};