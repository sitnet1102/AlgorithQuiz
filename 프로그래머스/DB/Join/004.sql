SELECt i.animal_id, i.animal_type, i.name
from animal_ins i 
    inner join animal_outs o using (animal_id)
where i.sex_upon_intake like 'Intact%' and o.sex_upon_outcome like ('neutered%' or 'spayed%')
order by i.animal_id