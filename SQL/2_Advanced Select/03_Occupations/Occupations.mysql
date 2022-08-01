/*
Working Platform:- MySQL
*/
SET @r1=0, @r2=0, @r3=0, @r4=0;
SELECT MIN(DOCTOR), MIN(PROFESSOR), MIN(SINGER), MIN(ACTOR)
FROM(
  SELECT CASE WHEN OCCUPATION = 'Doctor' THEN (@r1:=@r1+1)
              WHEN OCCUPATION = 'Professor' THEN (@r2:=@r2+1)
              WHEN OCCUPATION = 'Singer' THEN (@r3:=@r3+1)
              WHEN OCCUPATION = 'Actor' THEN (@r4:=@r4+1) END AS RowNumber,
    CASE WHEN OCCUPATION = 'Doctor' THEN Name END AS Doctor,
    CASE WHEN OCCUPATION = 'Professor' THEN Name END AS Professor,
    CASE WHEN OCCUPATION = 'Singer' THEN Name END AS Singer,
    CASE WHEN OCCUPATION = 'Actor' THEN Name END AS Actor
  FROM OCCUPATIONS
  ORDER BY NAME
) Temp
GROUP BY RowNumber;
