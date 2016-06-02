/*
Vstupem je 1 stav, typicky 1 instrukce a všechny související proměné
Výstupem je množina stavů
Nic jiného!

Metaoperace pak obecně vstupem N stavů a výstupem je stav porovnání/spojení (ekvivalence stavů) - viz predator

Používají konkretné domému - paměťovou reprezentaci

V případě štěpění stavu (if)(či jiná operace), na základě constraint na proměné, můžeme danou hodnotu omezit (přidáme constraint)

*/

//metaoperace abstrakce, ideálně možnost zacílit, co / kde abstrahovat
//extra pozice atd...
//
//ladící operace -> výstup je == vstup
//

#include <vector>
#include <tuple>



//
//operací vrací seznam dvojic (stav, lokace)
// u ifu se lokace liší, u ostaní by měli být stejn
//stav jak uniq_ptr 
//finální stavy drží CFG


//vlastní  CFG -?
//je třeba mít v něm basic blocky?
//cílem: LLVM je readonly, pouze v opodstatněných případěch (ladící info)
//ideálně zapouzdřit i lokaci, atd atd
// ----------> NG CFG naše poté už


