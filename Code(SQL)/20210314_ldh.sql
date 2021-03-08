/*
Revising Aggregations
*/
SELECT AVG(POPULATION)
FROM CITY
WHERE DISTRICT='CALIFORNIA';

/*
Weather Observation Station 13
ROUND(숫자, 반올림할 자리수)
TRUNCATE(숫자, 버릴 자리수)
*/
SELECT ROUND(SUM(LAT_N), 4)
FROM STATION
WHERE LAT_N > 38.7880 AND LAT_N < 137.2345;

/*
Average Population of Each Continent
FLOOR(숫자) 소수점이하 버림
*/
SELECT COUNTRY.CONTINENT, FLOOR(AVG(CITY.POPULATION))
FROM COUNTRY JOIN CITY
ON COUNTRY.CODE = CITY.COUNTRYCODE
GROUP BY COUNTRY.CONTINENT;

/*
Revising Aggregations - The Sum Function
*/
SELECT SUM(POPULATION)
FROM CITY
WHERE DISTRICT='CALIFORNIA';

/*
Weather Observation Station 14
ROUND(숫자, 반올림할 자리수)
TRUNCATE(숫자, 버릴 자리수)
*/
SELECT ROUND(MAX(LAT_N), 4)
FROM STATION
WHERE LAT_N < 137.2345;