---
layout: post
title: "fraktale-obrazy: Program umożliwiąjący generowanie fraktali"
date: 2025-07-31
categories: [Programowanie]
katex: true
---

<p align="center">
<img src="/assets/images/2025-07-31/readme_image.jpg" width="700" />
<br>
<em>Obraz wygenerowany z użyciem programu</em>
</p>


# fraktale-obrazy
Prosty program napisany w C++ z użyciem biblioteki SDL2, który umożliwia generowanie i zapisywanie obrazów fraktali.

> **Uwaga!** <br>
> Początkowo miał być to mały projekt, lecz nieco się rozrósł. Program może być niewydajny i zbugowany.

Jest to <a href="https://github.com/bwegrzyn0/fraktale-obrazy" target="_blank">plik README z repozytorium GitHub</a> przetłumaczony na język polski.

## Instalacja programu 
Zklonuj repozytorium GitHub:
```
git clone https://github.com/bwegrzyn0/fraktale-obrazy
```
i uruchom program za pomocą komendy `./run.out`.

## Użytkowanie 
W oknie zobaczysz następujący interfejs:

<p align="center">
<img src="/assets/images/2025-07-31/interface_image.jpg" width="600" />
</p>

Radzę samodzielnie wypróbować poszczególne opcje aby zobaczyć ich efekt na obrazie. Tutaj po krótce omówię każdą z nich:
- __Brightness multiplier__: mnoży jasność wszystkich pikseli przez zadaną wartość. 
- __Resolution__: liczba pikseli na jednostkę długosci. Na przykład, jeśli szerokość obszaru (omawiana dalej) wynosi 10, a rozdzielczość wynosi 100, obraz będzie miał szerokość 100 * 10 = 1000 pikseli. Bardzo duże wartości negatywnie wpływają na wydajność programu. Z tego powodu przy oddalaniu widoku rozdzielczość jest dynamicznie zminiejszana (nie ma to wpływu na zapisywany obraz).
- __Number of iterations__: liczba iteracji algorytmu IFSP.
- __Number of points__: liczba punktów w algorytmie IFSP.
- __Area X and Area Y__: współrzędne X i Y obszaru generacji fraktala.
- __Area width and Area height__: szerokość i wysokość obszaru generacji fraktala.
- __Show area border__: pozwala przełączać widoczność czerwonej granicy wokół obszaru generacji fraktala.
- __Transformation parameters__: maksymalnie można mieć 4 transformacje. Każdą z nich charakteryzuje 7 liczb. Współrzędne są transformowane według następujących zależności:

  ```
  transformowane_x = a_x * x + b_x * y + c_x
  transformowane_y = a_y * x + b_y * y + c_y
  ```
  Każda transformacja ma swoje prawdopodobieństwo, które nie wpływa na kształt fraktala. Zmienia ono jedynie gęstość rozłożenia punktów na nim.
  > **Wskazówka** <br>
  > Jeśli potrzebne są jedynie np. 2 transformacje, należy ustawić prawdopodobieństwa pozostałych dwóch na zero.
- __Image file name__: nazwa pliku z obrazem fraktala (bez rozszerzenia).

Obrazy są zapisywane w formacie `.bmp` w katalogu, w którym znajduje się program.

Można poruszać się i przybliżać obraz fraktala w programie za pomocą strzałek i scrolla.

## Jak działa ten program?
Wybrana liczba puntków jest jednorodnie rozłożona w kwadracie, po czym są one poddawane algorytmowi IFSP. Każdy piksel posiada gęstość równą liczbie punktów, która w nim wylądowała. Jego jasność jest ustalana na podstawie gęstości - piksele z 0 punktami są czarne, a piksele z największą ich liczbą białe.

## Przykładowe obrazy 
<p align="center">
<img src="/assets/images/2025-07-31/bazia.jpg" width="600" />
</p>
<p align="center">
<img src="/assets/images/2025-07-31/choinka.jpg" width="600" />
</p>
<p align="center">
<img src="/assets/images/2025-07-31/sierpinsk.jpg" width="600" />
</p>
<p align="center">
<img src="/assets/images/2025-07-31/dragon.jpg" width="600" />
</p>

## Licencja 
Program nie posiada licencji i może być używany w dowolny sposób.
  
  
  
