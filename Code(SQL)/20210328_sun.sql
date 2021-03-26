/* Weather Observation Station 2 */
SELECT ROUND(SUM(LAT_N), 2), ROUND(SUM(LONG_W), 2)
FROM STATION;

/* Weather Observation Station 3 */
SELECT DISTINCT CITY
FROM STATION
WHERE (ID % 2) = 0;

/* Weather Observation Station 4 */
SELECT COUNT(CITY) - COUNT(DISTINCT CITY)
FROM STATION;

/* Weather Observation Station 7 */
SELECT DISTINCT CITY
FROM STATION
WHERE RIGHT(CITY, 1) IN ('a', 'e', 'i', 'o', 'u');

/* Japan Population */
SELECT DISTINCT CITY
FROM STATION
WHERE RIGHT(CITY, 1) IN ('a', 'e', 'i', 'o', 'u');
