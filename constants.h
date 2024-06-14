//Define constants used throughout the application, such as API keys or default settings.
#pragma once
#include <string>
#include <sstream>

namespace Constants {
    // OpenWeatherMap API key
    const std::string API_KEY = "107aa776b1234c699f162226241406";

    // Base URL for OpenWeatherMap API
    const std::string API_BASE_URL = "http://api.weatherapi.com/v1";

    //Function to construct the URL for current weather data
    inline std::string getWeatherURL(const std::string& location) {
        std::ostringstream url;
        url << API_BASE_URL << "/current.json?key=" << API_KEY << "&q=" << location;
        return url.str();
    }

    // Function to construct the URL for forecast weather data
    inline std::string getForecastURL(const std::string& location) {
        std::ostringstream url;
        url << API_BASE_URL << "/forecast.json?key=" << API_KEY << "&q=" << location;
        return url.str();
    }

}
