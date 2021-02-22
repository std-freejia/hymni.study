/* Select By ID */
select * from CITY where ID=1661

/* Revising the Select Query I */
select * from CITY where POPULATION > 100000 && CountryCode='USA'

/* Revising the Select Query II */
select NAME from CITY where POPULATION > 120000 && CountryCode='USA'

/* Select All */
select * from CITY

/* Japanese Cities' Attributes */
select * from CITY where CountryCode='JPN'

/* Japanese Cities' Names */
select NAME from CITY where CountryCode='JPN'