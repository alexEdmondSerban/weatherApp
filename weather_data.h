//Store and manage the weather data, including current conditions and forecasts.
#pragma once
#include <string>
#include <iostream>
#include <D:\C++ libraries\json-develop\single_include\nlohmann\json.hpp> 

class WeatherData {
public:
	WeatherData();

	// Setters for weather data
	void setCurrentWeather(const std::string& jsonData);
	void setWeatherForecast(const std::string& jsonData);

	// Display functions
	void displayCurrentWeather() const;
	void displayWeatherForecast() const;

private:
	//Define data members to store weather information
	nlohmann::json currentWeather; // Store parsed JSON
	nlohmann::json weatherForecast; // Store parsed JSON

	//Add more data members as needed
};
