/*


-- 코드를 입력하세요
SELECt i.animal_id, i.animal_type, i.name
from animal_ins i 
    inner join animal_outs o using (animal_id)
where i.sex_upon_intake like 'Intact%' and o.sex_upon_outcome like ('neutered%' or 'spayed%')
order by i.animal_id


-- 코드를 입력하세요
SELECt i.animal_id, i.animal_type, i.name
from animal_ins i 
    inner join animal_outs o using (animal_id)
where i.sex_upon_intake like 'Intact%' 
    and o.sex_upon_outcome regexp 'Spayed|Neutered'
order by i.animal_id;
*/

SELECt i.animal_id, i.animal_type, i.name
from animal_ins i 
    inner join animal_outs o using (animal_id)
where i.sex_upon_intake like 'Intact%' 
    and (o.sex_upon_outcome like 'Spayed%' or o.sex_upon_outcome like 'Neutered%')
order by i.animal_id;