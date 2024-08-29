HashTable
Zlicz liczbę wystąpień każdego słowa występującego w tekście zadanym na wejściu. Przechowuj te liczby w swoim programie w tablicy hashowanej: każde słowo powinno być kluczem (typ: string), a liczba wystąpień danego słowa wartością (typ: int). Zaimplementuj metodę rozwiązywania kolizji zaproponowaną przez prowadzącego.

Możesz użyć tablicy o stałym rozmiarze, ale mimo wszystko zaalokuj pamięć dynamicznie! Maksymalna liczba elementów w testach to 100000. Wybierz odpowiedni rozmiar tablicy (możesz skorzystać ze slajdów z wykładu).

Input 

Tekst (dowolna liczba słów zapisanych małymi literami, rozdzielonych znakami spacji lub nowej linii). Słowa zaczynające się od znaków '?' lub '-' oraz słowo "q" powinny być interpretowane jako komendy:
'?': wypisz liczbę wystąpień danego słowa,
'-': usuń informację o danym słowie ze swojej tablicy hashowanej (od tego momentu zliczaj kolejne wystąpienia tego słowa od 0),
'q': wyjście.
