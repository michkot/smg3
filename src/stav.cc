/*
Stav je reprezentace paměti==pamětový model, vč. mapování na proměné, stack frame (SPC)
Obsahuje odkaz na následující lokaci
Ideálně i další informace, anotace / případně dekorátorem / odkud kam sem přišel

Umí:
Přidání globální proměné (jméno prom, typ)
Přidání lokální proměné (--||--)
pushFrame(informace o funkci: předávané argumenty, návratový typ, návratová lokace/instrukce)
popFrame(proměnou kterou vrácíme) -- pozn lokace návratu musí být uložena ve stavu, na adekvátní urovni, přilepena na stack frame
Odebrání lokální proměné () - pro dead value analysis / memory leaks 

*/

