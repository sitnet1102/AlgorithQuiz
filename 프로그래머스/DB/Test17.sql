-- 중성화 여부 파악하기 

-- 코드를 입력하세요
SELECT animal_id, name, if((sex_upon_intake like "%neutered%") or (sex_upon_intake like "%spayed%"), 'O', 'X') as "중성화"
from animal_ins
order by animal_id