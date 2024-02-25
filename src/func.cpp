#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <iomanip>
#include <sstream>

#include "func.hpp"

namespace Func {
	std::string getLastLine(std::string fileName) {
		std::ifstream file(fileName);
    	std::string line = "";
		if (file.is_open()) {
			while (getline(file, line)) {
			}
			file.close();
			if (line.length() == 0) {
				std::cout << "Пустая строка" << std::endl;
				return "";
			}
			return line;
		} else {
			std::cout << "Файл не найден" << std::endl;
			return "";
		}
	}	
	
	int getFirstNumber(std::string line) {
		size_t pos = line.find('-');
		if (pos <= 0) {
			return -1;
		}
		line = line.substr(0, pos);
		if (line.length() == 0) {
			return -1;
		}
		int num = std::atoi(line.c_str());
		if (num == 0) {
			return -1;
		}
		return num;
	}

	int getLastRunNumber(std::string fileName) {
		auto line = getLastLine(fileName);
		if (line.length() == 0) {
			return -1;
		}
		return getFirstNumber(line);
    }
	
	std::string getDebugLine(int num) {
		// Получаем текущее время в виде std::chrono::system_clock::time_point
		auto now = std::chrono::system_clock::now();
		// Преобразуем время в std::time_t для получения структуры tm
		std::time_t t = std::chrono::system_clock::to_time_t(now);
		// Преобразуем time_t в tm как локальное время
		std::tm tm = *std::localtime(&t);

		// Создаем поток для формирования строки
		std::ostringstream oss;

		// Записываем данные в поток в нужном формате
		oss << num << "-" 
			<< tm.tm_year + 1900 << "-" // Год
			<< std::setfill('0') << std::setw(2) << tm.tm_mon + 1 << "-" // Месяц
			<< std::setfill('0') << std::setw(2) << tm.tm_mday << "-" // День
			<< std::setfill('0') << std::setw(2) << tm.tm_hour << "-" // Час
			<< std::setfill('0') << std::setw(2) << tm.tm_min << "-" // Минута
			<< std::setfill('0') << std::setw(2) << tm.tm_sec; // Секунда

		// Преобразуем поток в строку
		std::string date_time_str = oss.str();
		return date_time_str;
	}
	
	void appendStringToFile(std::string fileName, std::string line) {
		// Открываем файл в режиме добавления (std::ios::app)
		std::ofstream file(fileName, std::ios::app);

		// Проверяем, успешно ли открылся файл
		if (!file.is_open()) {
			throw std::runtime_error("Не удалось открыть файл: " + fileName);
		}

		// Добавляем строку в конец файла и новую строку после неё
		file << std::endl << line;

		// Закрываем файл
		file.close();

	}
}