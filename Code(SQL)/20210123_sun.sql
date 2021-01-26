/* Employee Salaries */
SELECT name
FROM Employee
WHERE salary > 2000 AND months < 10;

/* Employee Names */
SELECT name
FROM Employee
ORDER BY name

/* African Cities */
SELECT CITY.NAME
FROM CITY, COUNTRY
WHERE CITY.CountryCode = COUNTRY.Code AND COUNTRY.CONTINENT = 'Africa';

/* Higher Than 75 Marks */
SELECT Name
FROM STUDENTS
WHERE Marks > 75
ORDER BY RIGHT(Name, 3), ID ASC

/* Top Earners */
SELECT salary * months AS earnings, COUNT(*)
FROM Employee
GROUP BY earnings
ORDER BY earnings DESC
LIMIT 1;
