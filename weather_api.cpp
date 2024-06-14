#include "weather_api.h"
#include <iostream>
#include <sstream>

WeatherAPI::WeatherAPI() {
	//Initialize CURL
	curl = curl_easy_init();
	if (!curl) {
		throw std::runtime_error("Failed to initialize CURL");
	}
}

WeatherAPI::~WeatherAPI() {
	// Cleanup CURL
	if (curl) {
		curl_easy_cleanup(curl);
	}
}

std::string WeatherAPI::fetchCurrentWeather(const std::string& location) {
	curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
	curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
	std::string url = Constants::getWeatherURL(location);
	return makeHTTPRequest(url);
}

std::string WeatherAPI::fetchWeatherForecast(const std::string& location) {
	curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
	curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
	std::string url = Constants::getForecastURL(location);
	return makeHTTPRequest(url);
}

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}

std::string WeatherAPI::makeHTTPRequest(const std::string& url) {
	if (!curl) {
		throw std::runtime_error("CURL not initialized");
	}

	std::string response;
	curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
	curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

	CURLcode res = curl_easy_perform(curl);
	if (res != CURLE_OK) {
		std::ostringstream errorMsg;
		errorMsg << "curl_easy_perform() failed: " << curl_easy_strerror(res);
		throw std::runtime_error(errorMsg.str());
	}

	return response;
}