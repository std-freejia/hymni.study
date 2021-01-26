#Employee Salaries  (MySQL)

select name
from Employee
where months < 10 and salary > 2000;


#Employee Names (MySQL)

select name
from Employee
order by name;



#African Cities (MySQL)
-- 대륙이 'Africa'인 도시 이름 조회 
-- Note: CITY.CountryCode and COUNTRY.Code are matching key columns.

select CITY.name
from CITY join COUNTRY on COUNTRY.code = CITY.countrycode
where COUNTRY.CONTINENT = 'Africa';



#Higher Than 75 Marks (MySQL)

select name 
from students
where marks > 75
order by SUBSTRING(name, -3), ID ASC;

/*
SUBSTRING(컬럼 or 문자열, 뒤에서 시작위치)
SUBSTRING(컬럼 or 문자열, 시작위치, 길이)
*/


#Top Earners (MySQL)
총 수입이 최대인 직원 조회 
수입, 그리고 최대수입을 가진 직원 수를 조회.

select (salary * months)as earnings, count(*)
from Employee
group by earnings  -- 중복 없이 유일한 값 조회 
order by earnings desc -- 최대값 출력을 위해 내림차순 
limit 1;  -- 레코드 1개만 출력 제한 

# limit : 출력되는 레코드 개수를 제한 
# group by : 특정 컬럼의 unique한 값에 따라 데이터를 그룹짓고 중복은 제거.















