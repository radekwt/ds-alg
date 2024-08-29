HEAP

Kopiec działa jako kolejka priorytetowa dla instancji podanej struktury. Początkowo wszystkie instancje struktur powinny być przechowywane z zachowaniem alfabetycznej kolejności imion (tzn. instancja z pierwszym alfabetycznie imieniem powinna być pierwszym elementem (korzeniem) kopca). Program powinien umożliwiać wykonywanie następujących operacji:
Input 

+ n v1 ...vn
dodaj n osób (format: <data> <imię>) do kolejki priorytetowej (kopca). Początkowo, osoba z pierwszym alfabetycznie imieniem powinna być pierwszym elementem (korzeniem) kopca;
- m
usuń m elementów minimalnych (z wierzchu kopca) i wypisz ich dane na ekranie (format: <data> <imię> np. 19-04-2022 Alan);
p
wypisz na ekran wszystkie elementy kopca w kolejności, w jakiej są przechowywane w tablicy;
r
zmień kolejność przechowywania elementów w kolejce priorytetowej na taką, w której element z najwcześniejszą datą jest przechowywany jako pierwszy element (korzeń kopca). Powtórzenia tej operacji powodują zmianę kolejności pomiędzy dwoma wspomnianymi wariantami (imiona alfabetycznie lub daty od najwcześniejszej);
q
wyjdź z programu (i zwolnij pamięć).

Input

Ciąg instrukcji w formacie opisanym powyżej. Ostatnią instrukcją jest q.

Output

Wynik działania instrukcji 'i' i 'p'.
