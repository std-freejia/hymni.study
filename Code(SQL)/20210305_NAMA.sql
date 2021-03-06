/*
Weather Observation Station 11
*/
select distinct CITY from STATION where CITY not regexp "^[aieou]" or CITY not regexp "[aieou]$"

/*
Weather Observation Station 12
*/
select distinct CITY from STATION where CITY not regexp "^[aieou]" and CITY not regexp "[aieou]$"

/*
The Blunder
*/
select ceil(avg(SALARY) - avg(replace(SALARY,0,''))) from EMPLOYEES

/*
Asian Population
*/
select sum(CITY.POPULATION) from CITY, COUNTRY where CITY.COUNTRYCODE = COUNTRY.CODE and COUNTRY.CONTINENT = 'ASIA'

/*
Type of Triangle
*/
select case
    when A + B <= C or A + C <= B or B + C <= A
    then 'Not A Triangle'
    when A = B and B = C
    then 'Equilateral'
    when A = B or A = C or B = C
    then 'Isosceles'
    else 'Scalene'
    end
from triangles