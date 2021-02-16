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

/* Revising Aggregations - The Count Function */

/* Population Density Difference */
