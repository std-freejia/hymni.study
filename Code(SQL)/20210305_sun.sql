/* Weather Observation Station 11 */
SELECT DISTINCT CITY
FROM STATION
WHERE LEFT(CITY, 1) NOT IN ('a', 'e', 'i', 'o', 'u') 
      OR RIGHT(CITY, 1) NOT IN ('a', 'e', 'i', 'o', 'u');

/* Weather Observation Station 12 */
SELECT DISTINCT CITY
FROM STATION
WHERE LEFT(CITY, 1) NOT IN ('a', 'e', 'i', 'o', 'u') 
      AND RIGHT(CITY, 1) NOT IN ('a', 'e', 'i', 'o', 'u');

/* The Blunder */
SELECT CEIL(AVG(Salary) - AVG(REPLACE(Salary, '0', '')))
FROM EMPLOYEES;

/* Asian Population */
SELECT SUM(CITY.POPULATION)
FROM CITY, COUNTRY
WHERE CITY.COUNTRYCODE = COUNTRY.CODE
      AND COUNTRY.CONTINENT = 'Asia';

/* Type of Triangle */
SELECT CASE
        WHEN A + B <= C OR B + C <= A OR A + C <= B
        THEN "Not A Triangle"
        
        WHEN A = B AND B = C AND A = C 
        THEN "Equilateral"
        
        WHEN A = B OR B = C OR A = C
        THEN "Isosceles"
        
        ELSE "Scalene"
    END
FROM TRIANGLES;
