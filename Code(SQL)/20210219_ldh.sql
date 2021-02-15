/* MySQL code, LDH, hackerrank.com */

/*
aeiou로 시작하는 도시를 중복없이 검색
DISTINCT 중복제거
REGEXP(Regular Expression)정규표현식 사용
*/
SELECT DISTINCT CITY 
FROM STATION 
WHERE CITY REGEXP "^[aeiou].*";		/* city컬럼에서 제일 앞글자가 aeiou중 한개 사용된 것 검색 */

/*
aeiou가 시작과 끝에 있는 도시를 중복없이 검색
*/
SELECT DISTINCT CITY 
FROM STATION
WHERE CITY REGEXP '^[aeiou].*[aeiou]$';		/* ^시작, $끝 */

/*
aeiou로 끝나지 않는 도시를 중복없이 검색
*/
SELECT DISTINCT CITY 
FROM STATION 
WHERE CITY NOT REGEXP "[aeiou]$";

/*
도시 테이블의 모든 도시의 평균 인구를 검색(정수로 내림 표현)
CELLING 소수점 올림 처리
FLLOR 소수점 내림 처리
ROUND 반올림 처리
*/
SELECT FLOOR(AVG(POPULATION))
FROM CITY;

/*
인구가 100000보다 큰 도시의 수 검색
*/
SELECT COUNT(*) 
FROM CITY 
WHERE POPULATION > 100000;

/*
도시 인구의 최대값과 최소값의 차를 검색
*/
SELECT (MAX(POPULATION)-MIN(POPULATION)) 
FROM CITY;