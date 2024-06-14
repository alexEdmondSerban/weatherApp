#pragma once
#include <string>
#include "D:\C++ libraries\curl-8.8.0_2-win64-mingw\include\curl\curl.h"
#include "constants.h"

class WeatherAPI {
public:
	WeatherAPI();
	~WeatherAPI();

	//Fetch weather data for a given location
	std::string fetchCurrentWeather(const std::string& location);
	std::string fetchWeatherForecast(const std::string& location);

private:
	//Helper function to make an HTTP request
	std::string makeHTTPRequest(const std::string& url);

	//CURL handle
	CURL* curl;
};