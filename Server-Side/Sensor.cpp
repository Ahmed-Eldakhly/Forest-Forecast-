// headers
#include "Sensor.h"

Sensor::Sensor() {

}

void Sensor::setSensorName(std::string sensorName) {
	this->sensorName = sensorName;
}

std::string Sensor::getSensorName() {
	return this->sensorName;
}

void Sensor::setSensorSerialNumber(std::string sensorSerialNumber) {
	this->sensorSerialNumber = sensorSerialNumber;
}

std::string Sensor::getSensorSerialNumber() {
	return this->sensorSerialNumber;
}

void Sensor::setSensorReading(float sensorReading) {
	this->sensorReading = sensorReading;
}

float Sensor::getSensorReading() {
	return this->sensorReading;
}