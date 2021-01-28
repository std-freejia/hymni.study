/*
Employee Salaries
10개월 미만, 월수입 2000 이상 직원이름 검색
*/
SELECT Name
FROM Employee 
WHERE Months < 10 AND Salary > 2000;

/*
Employee Names
직원이름 오름차순 정렬 검색
*/
SELECT Name
FROM Employee
ORDER BY Name ASC;	/* ASC(오름차순, 기본값), DESC(내림차순)*/

/*
African Cities
두 개의 테이블(City, Country)에서 Africa대륙의 도시를 검색
*/
SELECT City.Name
FROM City, Country
WHERE Country.Code = City.CountryCode AND Country.Continent = 'Africa';

/*
Higher Than 75 Marks
학생 중 75점 이상이면서 철자 뒤3자리 오름차순으로 이름 검색
철자 뒤 3자리가 같을 경우 ID 오름차순 정렬
*/
SELECT Name
FROM STUDENTS
WHERE Marks > 75
ORDER BY SUBSTR(Name, -3, 3), ID;	/*SUBSTR("문자열or컬럼", "시작위치", "길이")*/

/*
Top Earners
최고 연봉 액수와 최고 연봉을 받는 사람의 수 검색
*/
SELECT Salary * Months AS earn, COUNT(*)
FROM Employee
GROUP BY earn
ORDER BY earn DESC
LIMIT 1;	/*LIMIT 반환개수 or LIMIT 시작위치, 반환개수*/