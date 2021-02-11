
/* Weather Observation Station6  (Oracle)*/
select distinct(city)
from station
where lower(substr(city, 1, 1)) in ('a', 'e', 'i', 'o', 'u')
;

/* Weather Observation Station8  (Oracle)*/
--Oracle
select distinct(city)
from station
where lower(substr(city, 1, 1)) in ('a', 'e', 'i', 'o', 'u') 
and lower(substr(city, length(city), 1)) in ('a', 'e', 'i', 'o', 'u')
;

-- MySQL 
select distinct(city)
from station
where lower(left(city, 1)) in  ('a', 'e', 'i', 'o', 'u') 
and lower(right(city, 1)) in  ('a', 'e', 'i', 'o', 'u')
;



/* Weather Observation Station10  (Oracle)*/
--Oracle
select distinct city 
from station
where lower(substr(city, length(city), 1)) not in ('a', 'e', 'i', 'o', 'u')
;

--MySQL 
select distinct(city)
from station
where lower(right(city, 1)) not in  ('a', 'e', 'i', 'o', 'u')
;


/* Average Population (Oracle)  */
select floor(avg(population))
from city
;

select round(avg(population))
from city
;


/*Revising Aggregations - The Count Function (Oracle)  */ 
select count(unique(name))
from city
where population > 100000
;

/* Population Density Difference (Oracle) */

select MAX(population)-MIN(population)
from city
;

