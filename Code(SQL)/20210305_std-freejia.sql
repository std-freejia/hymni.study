
/* Weather Observation Station 11   MySQL */
SELECT DISTINCT CITY
FROM STATION
WHERE LEFT(CITY, 1) NOT IN ('A', 'E', 'I', 'O', 'U') 
OR RIGHT(CITY, 1) NOT IN ('a', 'e', 'i', 'o', 'u');

/* Weather Observation Station 12   MySQL  */
SELECT DISTINCT CITY
FROM STATION
WHERE LEFT(CITY, 1) NOT IN ('A', 'E', 'I', 'O', 'U') 
AND RIGHT(CITY, 1) NOT IN ('a', 'e', 'i', 'o', 'u');


SELECT DISTINCT CITY
FROM STATION
WHERE REGEXP_LIKE(CITY, '^[^aeiou].*[^aeiou]$', 'i');

/*  
^는 첫글자,  $는 끝글자를 의미함
[...]  는 괄호 안 모든 글자에 해당한다는 뜻
[^...] 는 괄호 안 모든 글자에 해당하지 않는다는 뜻.
. 글자 1개
* 0개 이상의 글자 

참고 https://www.tutorialspoint.com/mysql/mysql-regexps.htm  */


/* The Blunder  MySQL */
SELECT CEIL(AVG(SALARY)-AVG(REPLACE(SALARY, '0', '')))
FROM EMPLOYEES ;

/* 평균 월급 구하기. 단, 숫자 0을 전부 지운 숫자로 계산하기. 올림. 

REPLACE('문자열' OR 열 이름, '바꾸려는 문자열', '바뀔 문자열') 
CEIL() 올림 함수 

 */


/*  Asian Population   MySQL  */
SELECT SUM(CITY.POPULATION)
FROM CITY
JOIN COUNTRY
ON CITY.COUNTRYCODE = COUNTRY.CODE
WHERE COUNTRY.CONTINENT = 'Asia';


/* JOIN 참고 
 https://www.geeksforgeeks.org/sql-join-set-1-inner-left-right-and-full-joins/ */ 


/* Type of Triangle  */ 

/* 삼각형이 아닌 것부터 걸러낸다. 
삼각형을 만족시키되, 두 변이 같으면, 나머지 한 변까지 똑같은 것이니까  'Equilateral'  */
SELECT CASE 
		WHEN A+B <= C OR B+C <= A OR A+C <= B  THEN  'Not A Triangle'
		WHEN A=B AND B=C THEN 'Equilateral'
		WHEN A=B OR B=C OR A=C THEN 'Isosceles'
		ELSE 'Scalene'
	END
FROM TRIANGLES;


