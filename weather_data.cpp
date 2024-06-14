#include "weather_data.h"

WeatherData::WeatherData() {
    // Initialize data members if necessary
}

void WeatherData::setCurrentWeather(const std::string& jsonData) {
    try {
        currentWeather = nlohmann::json::parse(jsonData);
    }
    catch (const nlohmann::json::parse_error& e) {
        std::cerr << "JSON parsing error: " << e.what() << std::endl;
        return; // Exit function early on parsing error
    }
    catch (const std::exception& e) {
        std::cerr << "Error parsing JSON: " << e.what() << std::endl;
        return; // Exit function early on other exceptions
    }

    // Optional: Validate the structure of currentWeather JSON object
    if (!currentWeather.is_object()) {
        std::cerr << "Invalid JSON format for current weather data." << std::endl;
        return;
    }
}

void WeatherData::setWeatherForecast(const std::string& jsonData) {
    try {
        weatherForecast = nlohmann::json::parse(jsonData);
        // Example: Assuming the forecast data is within a different JSON structure
        // You should adjust this based on the actual API response
    }
    catch (const nlohmann::json::parse_error& e) {
        std::cerr << "JSON parsing error: " << e.what() << std::endl;
        return; // Exit function early on parsing error
    }
    catch (const std::exception& e) {
        std::cerr << "Error parsing JSON: " << e.what() << std::endl;
        return; // Exit function early on other exceptions
    }

    // Optional: Validate the structure of weatherForecast JSON object
    if (!weatherForecast.is_object()) {
        std::cerr << "Invalid JSON format for weather forecast data." << std::endl;
        return;
    }
}

void WeatherData::displayCurrentWeather() const {
    try {
        if (!currentWeather.empty() && currentWeather.contains("current")) {
            std::string cityName = currentWeather["location"]["name"];
            double temperature = currentWeather["current"]["temp_c"];
            double humidity = currentWeather["current"]["humidity"];
            std::cout << "City: " << cityName << std::endl;
            std::cout << "Temperature: " << temperature << "°C" << std::endl;
            std::cout << "Humidity: " << humidity << "%" << std::endl;
        }
        else {
            std::cerr << "Current weather data is not available or malformed JSON structure." << std::endl;
        }
    }
    catch (const nlohmann::json::type_error& e) {
        std::cerr << "JSON type error: " << e.what() << std::endl;
    }
}

void WeatherData::displayWeatherForecast() const {
    try {
        if (!weatherForecast.empty() && weatherForecast.contains("current")) {
            double temp = weatherForecast["current"]["temp_c"];
            double humidity = weatherForecast["current"]["humidity"];
            std::cout << "Temperature: " << temp << "°C" << std::endl;
            std::cout << "Humidity: " << humidity << "%" << std::endl;
        }
        else {
            std::cerr << "Weather forecast data is not available or malformed JSON structure." << std::endl;
        }
    }
    catch (const nlohmann::json::type_error& e) {
        std::cerr << "JSON type error: " << e.what() << std::endl;
    }
}