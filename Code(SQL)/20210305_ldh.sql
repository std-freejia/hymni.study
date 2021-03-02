/*
Weather Observation Station 11
시작과 끝 둘 중 하나라도 모음이면서 중복을 포함하지 않는 도시 이름을 검색
*/
SELECT DISTINCT CITY FROM STATION
WHERE CITY NOT REGEXP '^[aieou]' OR CITY NOT REGEXP '[aieou]$';	/* 정규표현식 사용 */

/*
Weather Observation Station 12
시작과 끝 둘 다 모음이면서 중복을 포함하지 않는 도시 이름을 검색
*/
SELECT DISTINCT CITY FROM STATION
WHERE CITY NOT REGEXP '^[aieou]' AND CITY NOT REGEXP '[aieou]$';	/* 정규표현식 사용 */

/*
The Blunder
제대로된 계산 평균 - 잘못된 계산 평균, 소수점 제외
*/
SELECT CEIL(AVG(SALARY) - AVG(REPLACE(SALARY, '0', '')))
FROM EMPLOYEES;

/*
Asian Population
아시아 대륙의 인구 총 합을 검색
*/
SELECT SUM(CITY.POPULATION)
FROM CITY, COUNTRY
WHERE CITY.COUNTRYCODE = COUNTRY.CODE AND COUNTRY.CONTINENT = 'ASIA';

/*
Type of Triangle
세변의 길이를 사용해 삼각형의 유형을 분류해 검색
*/
SELECT CASE 
            WHEN A + B <= C OR A + C <= B OR B + C <= A THEN 'Not A Triangle'
            WHEN A = B AND B = C THEN 'Equilateral'
            WHEN A = B OR A = C OR B = C THEN 'Isosceles'
            ELSE 'Scalene'
        END
FROM TRIANGLES;