---
layout: post
title: "Mechanika Lagrange'a, część 1: Równanie Eulera-Lagrange'a"
date: 2025-07-21
categories: Mechanika
katex: true
---

## Motywacja
Rozważmy następujący problem: błonę mydlaną rozpięliśmy między dwoma współosiowymi pierścieniami o promieniach $r_1$ i $r_2$. Wiadomo, że bańka mydlana przyjmuje zawsze taki kształt, aby jej pole powierzchni było jak najmniejsze - ten kształt chcemy znaleźć.

Bańkę mydlaną możemy traktować jak bryłę obrotową opisaną funkcją $f(x)$, przy czym $f(x_1)=r_1$ oraz $f(x_2)=r_2$.
<p align="center">
<img src="/assets/images/2025-07-21/blona_mydlana.svg" width="600"/>
</p>

Aby policzyć powierzchnię bryły obrotowej, podzielmy ją na nieskończenie małe okręgi o promieniach $f(x)$ i o środkach na osi $x$. Obwód takiego okręgu to $2\pi f(x)$. 
<p align="center">
<img src="/assets/images/2025-07-21/bryla_obrotowa.svg" width="500"/>
</p>
Element powierzchni rozciągającej się między dwoma bliskimi okręgami to $2\pi f(x)\,dl$. Jak widać na rysunku, $dl=\sqrt{dx^2+(f'(x)\,dx)^2}=\sqrt{1+f'(x)^2}\,dx$. Zatem element powierzchni to $dS=2\pi f(x)\sqrt{1+f'(x)^2}\,dx$. Całkowita powierzchnia takiej bryły to wtedy
\$$ S=2\pi\int_{x_1}^{x_2}f(x)\sqrt{1+f'(x)^2}\,dx.\$$
Dążymy do zminimalizowania tej całki.

## Wyprowadzenie równania Eulera-Lagrange'a
Rozważmy ogólniejszy przypadek. Chcemy zminimalizować całkę
\$$ S=\int_{x_1}^{x_2}f(Y(x), Y'(x), x)\,dx. \$$

Niech $y(x)$ będzie funkcją minimalizującą całkę $S$. Rozważmy funkcję $Y(x)=y(x)+\alpha \eta(x)$, gdzie $\eta(x)$ to dowolna funkcja, która spełnia warunek $\eta(x_1)=\eta(x_2)=0$. Wtedy $Y(x)$ spełnia te same warunki brzegowe co $y(x)$, lecz jest tą ,,mniej optymalną'', w przypadku błony mydlanej powierzchnią między $x_1$ a $x_2$, powierzchnia dla niej będzie nieco większa niż dla $y(x)$. 

Spodziewamy się, że dla małych wartości $\alpha$, czyli małych odchyleń od optymalnej powierzchni, całka $S$ nie będzie ulegać zmianie (podobnie jest w przypadku zwykłych funkcji - gdy $f(x)$ ma minimum w $x_0$, $f'(x_0)=0$. Oznacza to, że w przybliżeniu dla małych $\varepsilon$ zachodzi $f(x_0+\varepsilon)-f(x_0)=f'(x_0)\varepsilon=0$). Innymi słowy
\$$ \frac{\partial S}{\partial \alpha}=0. \$$
Obliczmy tę pochodną:
\$$ \frac{\partial S}{\partial \alpha}=\int_{x_1}^{x_2}\frac{\partial f}{\partial \alpha}\,dx\$$
Z reguły łańcuchowej dla wielu zmiennych:
\$$ \frac{\partial f}{\partial \alpha}=\frac{\partial f}{\partial Y}\frac{\partial Y}{\partial \alpha}+\frac{\partial f}{\partial Y'}\frac{\partial Y'}{\partial \alpha}+\frac{\partial f}{\partial x}\frac{\partial x}{\partial \alpha}   \$$
Łatwo obliczyć, że $\partial Y/\partial \alpha=\eta(x)$, $\partial Y'/\partial \alpha=\eta'(x)$ oraz $\partial x/\partial\alpha=0$. Daje nam to
\$$ \frac{\partial S}{\partial \alpha}=\int_{x_1}^{x_2}\left[\frac{\partial f}{\partial Y}\eta(x)+\frac{\partial f}{\partial Y'}\eta'(x)\right]\,dx \$$
Aby zamienić $\eta'(x)$ na $\eta(x)$, pocałkujmy przez części:
\$$ \int_{x_1}^{x_2}\frac{\partial f}{\partial Y'}\eta'(x)\,dx = \left[\eta(x)\frac{\partial f}{\partial Y'}\right]\_{x_1}^{x_2}- \int\_{x_1}^{x_2} \eta(x) \frac{d}{dx} \frac{\partial f}{\partial Y'}\,dx\$$
Zauważmy, że ponieważ $\eta(x_1)=\eta(x_2)=0$, pierwszy wyraz z prawej strony się zeruje. To pozostawia nas z 
\$$ \frac{\partial S}{\partial\alpha}=0=\int_{x_1}^{x_2}\eta(x)\left[ \frac{\partial f}{\partial Y}-\frac{d}{dx}\frac{\partial f}{\partial Y'} \right]\,dx\$$
Skoro $\eta(x)$ to dowolna funkcja, wybierzmy $\eta(x)$ takie, że wyrażenie podcałkowe jest zawsze nieujemne. Skoro całka z nieujemnego wyrażenia jest równa $0$, to wyrażenie podcałkowe wynosi 0. Ponieważ $\eta(x)\neq 0$, 
\$$ \frac{\partial f}{\partial y}-\frac{d}{dx}\frac{\partial f}{\partial y'} =0,\$$
gdzie $Y$ zamieniłem na $y$, ponieważ jeżeli $Y$ spełnia powyższe równanie, jest ono ,,optymalną'' funkcją. Jest to równanie Eulera-Lagrange'a.

## Problem błony mydlanej
Powróćmy do wcześniejszego problemu. Doszliśmy do wniosku, że należy znaleźć funkcję $f(x)$, która minimalizuje całkę
\$$ S=2\pi\int_{x_1}^{x_2}f(x)\sqrt{1+f'(x)^2}\,dx.\$$
Niech $F(f(x), f'(x))=f(x)\sqrt{1+f'(x)^2}$. Wtedy równanie Eulera-Lagrange'a przyjmuje postać
\$$ \frac{\partial F}{\partial f}-\frac{d}{dx}\frac{\partial F}{\partial f'} =0 \$$

Zauważmy jednak, że $F(f(x), f'(x))$ nie zależy w jawny sposób od $x$. Pomnóżmy powyższe równanie przez $df/dx$:
\$$ \frac{\partial F}{\partial f}\frac{df}{dx}-f'\frac{d}{dx}\frac{\partial F}{\partial f'}=0\$$
Możemy obliczyć pierwszy wyraz po lewej stronie:
\$$ \frac{\partial F}{\partial f}\frac{df}{dx}=\frac{dF}{dx}-\frac{\partial F}{\partial f'}\frac{df'}{dx}\$$
i wstawić go spowrotem:
\$$ \frac{dF}{dx}-\frac{\partial F}{\partial f'}\frac{df'}{dx}-f'\frac{d}{dx}\frac{\partial F}{\partial f'}=0 \$$
Nietrudno zauważyć, że
\$$-\frac{\partial F}{\partial f'}\frac{df'}{dx}-f'\frac{d}{dx}\frac{\partial F}{\partial f'}=-\frac{d}{dx}\left[f'\frac{\partial F}{\partial f'}\right] \$$
czyli
\$$  \frac{dF}{dx}-\frac{d}{dx}\left[f'\frac{\partial F}{\partial f'}\right]=0 \$$
\$$ \frac{d}{dx}\left[F-f'\frac{\partial F}{\partial f'}\right]=0 \$$
\$$ F-f'\frac{\partial F}{\partial f'}=const. \$$

Ten rezultat możemy uogólnić. Jeśli $f(y(x), y'(x))$ nie zależy jawnie od $x$, to równanie Eulera-Lagrange'a sprowadza się do całki pierwszej:
\$$ f-y'\frac{\partial f}{\partial y'}=const. \$$

Wracając do problemu bańki mydlanej, mamy
\$$ \frac{\partial F}{\partial f'}=f\frac{f'}{\sqrt{1+f'^2}} \$$
Wstawmy to do całki pierwszej:
\$$ f\sqrt{1+f'^2}-\frac{ff'^2}{\sqrt{1+f'^2}} = C \$$
\$$ f(1+f'^2)-ff'^2=C\sqrt{1+f'^2} \$$
Dostajemy równanie różniczkowe 1 rzędu, które można rozwiązać za pomocą separacji zmiennych:
\$$ f=C\sqrt{1+f'^2} \$$
\$$ 1+f'^2=Cf^2 \$$
\$$ \frac{df}{dx}=\sqrt{Cf^2-1} \$$
\$$ x+C_1=\int \frac{df}{\sqrt{C_2f^2-1} }\$$
Całka po prawej stronie sprowadza się do $\frac{1}{C}\cosh^{-1}\left(Cf\right)$, a stąd
\$$ f(x)=\frac{1}{C_1} \cosh (C_1 x+C_2), \$$
gdzie $C_1$ i $C_2$ to pewne stałe.

