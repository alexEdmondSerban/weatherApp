// Handle errors that might occur during the application's execution, such as invalid input or network issues.
#pragma once
#include <iostream>
#include <stdexcept>

class ErrorHandler {
public : 
	static void handle(const std::string& errorMessage) {
		std::cerr << "Error: " << errorMessage << std::endl;
	}

	static void handleException(const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
};
