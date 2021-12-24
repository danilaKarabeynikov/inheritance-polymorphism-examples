#pragma once
#include "Let12Api.h"
#include <string>

class Student
{
public:
	LET12_API Student(std::string surname, size_t year, size_t marks[5]);
	LET12_API size_t GetAge() { return 2019 - _year; };
	LET12_API double GetAverageMark();
private:
	std::string _surname;
	size_t _year;
	unsigned int _marks[5];
};

class IStudentProcessor
{
public:
	LET12_API virtual ~IStudentProcessor() {};
	LET12_API void virtual Process(Student& student) = 0;
};

class AverageAgeProcessor : public  IStudentProcessor
{
public:
	AverageAgeProcessor() { _summary_age = 0; _age_number_processed = 0; _average_age = 0; };
	LET12_API void Process(Student& student) override;
	LET12_API double GetAverageAgeStudent() const;
private:
	double _summary_age; //накопление общей суммы
	size_t _age_number_processed; // количество обработанных методом Process студентов
	double _average_age;
};


class AverageMarkProcessor : public IStudentProcessor
{
public:
	AverageMarkProcessor() { _summary_average_marks = 0; _mark_number_processed = 0; _average_mark = 0; }
	LET12_API void Process(Student& student) override;
	LET12_API double GetAverageMarkStudent() const;
private:
	double _summary_average_marks;//накопление общей суммы
	size_t _mark_number_processed; // количество обработанных методом Process студентов
	double _average_mark;
};

LET12_API void ProcessStudents(Student *group, size_t count, IStudentProcessor& processor);
LET12_API double CalculateAverageAge(Student *group, size_t count);
LET12_API double CalculateAverageMark(Student *group, size_t count);
LET12_API double CalculateOlderThenAverageAge(Student* group, size_t count);
