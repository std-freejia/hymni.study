

/* Revising Aggregations- Averages  (MySQL) */
select avg(population)
from city
where district = 'California';

/* Weather Observation Station 13  */
select truncate(sum(LAT_N), 4)
from station
where LAT_N > 38.7880 and LAT_N < 137.2345
;

select truncate(sum(LAT_N), 4)
from station
where LAT_N between 38.7880 and 137.2345
;
/* 반올림  round(숫자, 반올림 할 자릿수) 
   버림   truncate(숫자, 버릴 자릿수) 
*/

/* Average Population of Each Continent (MySQL)  */
/* 모든 대륙의 이름들 조회. 그들의 각각의 평균 인구. 정수에 가깝게 반올림. */
select country.continent, floor(avg(city.population))
from city inner join country
on country.code = city.countrycode
group by country.continent
;

/* Revising Aggregations - The Sum Function  */
/* 모든 도시들의 총 인구  단, 캘리포니아. */

select sum(population)
from city
where district = 'california'
;

/* Weather Observation Station 14  */
/* 137.2345 보다 작은 LAT_N 중에서, 최대값을 찾고 소수점 아래 4자리까지 표현하도록 버림함수 적용하기  */
/* truncate(123.01, n) 함수는 소수점 아래 숫자가 n까지 표현되도록 버림한 값을 반환한다. */ 
select truncate(max(LAT_N), 4) 
from station
where LAT_N < 137.2345
;





