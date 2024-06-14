#include "user_interface.h"

UserInterface::UserInterface() {
    // Initialize any members if necessary
}

void UserInterface::run() {
    // Implement the main application loop
    displayMainMenu();
    handleUserInput();
}

void UserInterface::displayMainMenu() {
    std::cout << "=== Weather Forecast Application ===" << std::endl;
    std::cout << "1. Display Current Weather" << std::endl;
    std::cout << "2. Display Weather Forecast" << std::endl;
    std::cout << "3. Settings" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "===================================" << std::endl;
}

void UserInterface::displayCurrentWeather() {
    try {
        std::string location;
        std::cout << "Enter location (e.g., London): ";
        std::cin >> location;

        std::string weatherDataJson = weatherAPI.fetchCurrentWeather(location);
        weatherData.setCurrentWeather(weatherDataJson);
        weatherData.displayCurrentWeather();
    }
    catch (const std::exception& e) {
        ErrorHandler::handleException(e);
    }
}

void UserInterface::displayWeatherForecast() {
    try {
        std::string location;
        std::cout << "Enter location (e.g., London): ";
        std::cin >> location;

        std::string weatherForecastJson = weatherAPI.fetchWeatherForecast(location);
        weatherData.setWeatherForecast(weatherForecastJson);
        weatherData.displayWeatherForecast();
    }
    catch (const std::exception& e) {
        ErrorHandler::handleException(e);
    }
}

void UserInterface::displaySettingsMenu() {
    // Implement settings menu (if needed)
}

void UserInterface::handleUserInput() {
    int choice = 0;
    while (choice != 4) {
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            displayCurrentWeather();
            break;
        case 2:
            displayWeatherForecast();
            break;
        case 3:
            displaySettingsMenu();
            break;
        case 4:
            std::cout << "Exiting application..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}