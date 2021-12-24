#include "stdafx.h"
#include "Let12.h"
#include<iostream>

Student::Student(std::string surname, size_t year, size_t marks[5])
{
	_surname = surname;
	_year = year;
	for (int i = 0; i < 5; i++)
		_marks[i] = marks[i];
}

double Student::GetAverageMark()
{
	double averageMark = 0;
	double totalMark = 0;
	for (int i = 0; i < 5; i++)
	{
		totalMark += _marks[i];
	}
	return averageMark = totalMark / static_cast <double>(5);
}

void AverageAgeProcessor::Process(Student& student)
{
	++_age_number_processed;
	_summary_age = student.GetAge() + _summary_age;
	_average_age = _summary_age / _age_number_processed;
}

double AverageAgeProcessor::GetAverageAgeStudent() const
{
	return _average_age;
}

void AverageMarkProcessor::Process(Student& student)
{
	++_mark_number_processed;
	_summary_average_marks = student.GetAverageMark() + _summary_average_marks;
	_average_mark = _summary_average_marks / _mark_number_processed;
}

double AverageMarkProcessor::GetAverageMarkStudent() const
{
	return _average_mark;
}

void ProcessStudents(Student * group, size_t count, IStudentProcessor& processor)
{
	for (size_t i = 0; i <= count; i++)
		processor.Process(group[i]);
}

double CalculateAverageAge(Student * group, size_t count)
{
	AverageAgeProcessor age_processor;
	ProcessStudents(group, count, age_processor);
	return age_processor.GetAverageAgeStudent();
}

double CalculateAverageMark(Student * group, size_t count)
{
	AverageMarkProcessor mark_processor;
	ProcessStudents(group, count, mark_processor);
	return mark_processor.GetAverageMarkStudent();
}

 double CalculateOlderThenAverageAge(Student* group,size_t count)
{
	double a = CalculateAverageAge(group, count);
	AverageMarkProcessor meproc;
	for (size_t i = 0; i < count; ++i)
	{
		if (static_cast <double>(group[i].GetAge()) <= a)
			meproc.Process(group[i]);
	}
	std::cout << a<< std::endl;
	return meproc.GetAverageMarkStudent();
}




