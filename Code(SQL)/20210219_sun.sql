/* Weather Observation Station6 */
SELECT DISTINCT CITY
FROM STATION
WHERE LEFT(CITY, 1) IN ('a', 'e', 'i', 'o', 'u');

/* Weather Observation Station8 */
SELECT DISTINCT CITY
FROM STATION
WHERE LEFT(CITY, 1) IN ('a', 'e', 'i', 'o', 'u') 
      AND RIGHT(CITY, 1) IN ('a', 'e', 'i', 'o', 'u');
      
/* Weather Observation Station10 */
SELECT DISTINCT CITY
FROM STATION
WHERE RIGHT(CITY, 1) NOT IN ('a', 'e', 'i', 'o', 'u');

/* Average Population */
SELECT ROUND(AVG(POPULATION))
FROM CITY

/* Revising Aggregations - The Count Function */
SELECT COUNT(*)
FROM CITY
WHERE POPULATION > 100000;

/* Population Density Difference */
SELECT MAX(POPULATION) - MIN(POPULATION)
FROM CITY
