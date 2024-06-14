// Handle user interactions, such as displaying the weather data and accepting user input.
#pragma once
#include <iostream>
#include <string>
#include "weather_data.h"
#include "weather_api.h"  // Include WeatherAPI header
#include "error_handler.h"

class UserInterface {
public: 
	UserInterface();
	void run(); // Main function to start the application

private:
    WeatherData weatherData;
    WeatherAPI weatherAPI; // Declare WeatherAPI object here

    void displayMainMenu();
    void displayCurrentWeather();
    void displayWeatherForecast();
    void displaySettingsMenu();
    void handleUserInput();
};
