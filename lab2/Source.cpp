#include "NumberList.h"
#include "Student.h"
#include "StudentGlobal.h"
#include <iostream>
using namespace std;

int main(){
	/*NumberList l;
	l.Init();
	
	l.Add(1);
	l.Add(2);
	l.Add(3);
	l.Add(6);
	l.Add(4);
	l.Print();
	l.Sort();
	l.Print();*/
	Student s1, s2;
	s1.SetName("ana", 3);
	s2.SetName("bana", 4);
	s1.SetMathGrade(7.8);
	s2.SetMathGrade(8.8);
	s1.SetEnglishGrade(9);
	s2.SetEnglishGrade(7.8);
	s1.SetHistoryGrade(9);
	s2.SetHistoryGrade(9);
	printf("%0.1f \n", s1.GetAverage());
	printf("%0.1f \n", s2.GetAverage());
	StudentGlobal s3;
	printf("%d \n", s3.CompareEnglishGrade(s1, s2));
	printf("%d \n", s3.CompareAverage(s1, s2));
	printf("%d \n", s3.CompareName(s1, s2));
	printf("%d \n", s3.CompareMathGrade(s1, s2));
	printf("%d \n", s3.CompareHistoryGrade(s1, s2));




	return 0;
}