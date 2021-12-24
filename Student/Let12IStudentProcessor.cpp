#include "pch.h"
#include "../Let12/Let12.h"


TEST(IStudentProcessorTest, AverageAgeTest)
{
	std::string surname1 = "Ermolov";
	size_t marks1[5] = { 5,5,4,5,4 };
	Student student1(surname1, 1999, marks1);

	std::string surname2 = "Antonov";
	size_t marks2[5] = { 2,2,3,3,3 };
	Student student2(surname2, 2001, marks2);

	std::string surname3 = "Vasilevsky";
	size_t marks3[5] = { 5,4,5,5,5 };
	Student student3(surname3, 2000, marks3);

	AverageAgeProcessor count_age;
	count_age.Process(student1);
	count_age.Process(student2);
	count_age.Process(student3);

	ASSERT_NEAR(19, count_age.GetAverageAgeStudent(), 0.1);
}

TEST(IStudentProcessorTest, AverageMarkTest)
{
	std::string surname1 = "Ermolov";
	size_t marks1[5] = { 5,5,4,5,4 };
	Student student1(surname1, 1999, marks1);

	std::string surname2 = "Antonov";
	size_t marks2[5] = { 2,2,3,3,3 };
	Student student2(surname2, 2001, marks2);

	std::string surname3 = "Vasilevsky";
	size_t marks3[5] = { 5,4,5,5,5 };
	Student student3(surname3, 2000, marks3);

	AverageMarkProcessor count_mark;
	count_mark.Process(student1);
	count_mark.Process(student2);
	count_mark.Process(student3);

	ASSERT_NEAR(4, count_mark.GetAverageMarkStudent(), 0.01);
}

TEST(IStudentProcessorTest, AverageAgeAndMarkForGroupOfStudentsTests)
{
	std::string surname1 = "Ermolov";
	size_t marks1[5] = { 3,5,4,5,3 };
	Student student1(surname1, 1973, marks1);

	std::string surname2 = "Antonov";
	size_t marks2[5] = { 2,2,3,2,3 };
	Student student2(surname2, 1988, marks2);

	std::string surname3 = "Vasilevsky";
	size_t marks3[5] = { 5,5,5,5,5 };
	Student student3(surname3, 1991, marks3);


	Student group_of_students[3] = { student1, student2, student3 };
	

	ASSERT_NEAR(35, CalculateAverageAge(group_of_students, 2), 0.1);
	ASSERT_NEAR(3.8, CalculateAverageMark(group_of_students, 2), 0.01);
}

TEST(IStudentProcessorTest, CalculateOlderThenAverageAgeTests)
{
	std::string surname1 = "Ermolov";
	size_t marks1[5] = { 3,3,3,3,3 };
	Student student1(surname1, 2002, marks1);

	std::string surname2 = "Antonov";
	size_t marks2[5] = { 2,2,2,2,2 };
	Student student2(surname2, 2000, marks2);

	std::string surname3 = "Vasilevsky";
	size_t marks3[5] = { 5,5,5,5,5 };
	Student student3(surname3, 2000, marks3);

	Student group_of_students[3] = { student1, student2, student3 };

	ASSERT_DOUBLE_EQ(3.5, CalculateOlderThenAverageAge(group_of_students, 3));
}