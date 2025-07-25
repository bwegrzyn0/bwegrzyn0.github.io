---
layout: post
title: "Mechanika Lagrange'a, część 3: Układy nieswobodne"
date: 2025-07-25
categories: Mechanika
katex: true
---

## Układ nieswobodny
Do tej pory opisywalśmy ruch cząstki przy założeniu, że jej ruch jest swobodny. Teraz zajmiemy się przypadkiem, gdy jej ruch jest ograniczony **więzami**.

Rozważmy cząstkę poruszającą się w 3 wymiarach, której ruch jest ograniczony do pewnej powierzchni (na przykład kula znajdująca się między dwoma płytkami uniemożliwiającymi jej ruch w kierunku prostopadłym do ich powierzchni). W mechanice Newtona oznacza to, że na kulę działa siła reakcji prostopadła do powierzchni ograniczającej jej ruch, jak zostało pokazane na rysunku. $\hat{T}$ oznacza wektor styczny do kierunku ruchu i zarazem płaszczyzny.

<p align="center">
<img src="/assets/images/2025-07-25/siła_reakcji.svg" width="500"/>
</p>

Mimo tego, że cząstka porusza się w przestrzeni 3-wymiarowej, do opisania jej położenia potrzebujemy jedynie 2 współrzędnych $q_1$ i $q_2$ (ponieważ jej ruch jest ograniczony do powierzchni). Spodziewamy się zatem, że jej ruch będą w pełni opisywać równania Lagrange'a
\$$ \frac{\partial\mathcal{L}}{\partial q_i}-\frac{d}{dt}\frac{\partial\mathcal{L}}{\partial \dot{q_i}}=0, \$$
dla których lagranżjan jest dany wzorem
\$$ \mathcal{L}=T-U, \$$
gdzie $U$ jest energią potencjalną wszystkich sił (przy założeniu, że da się je zapisać jako jej gradient) **oprócz sił reakcji**. Innymi słowy
\$$ \vec{F}_{cał.}=\vec{F}+\vec{F}_R=-\nabla U+\vec{F}\_R, \$$
gdzie $\vec{F}\_R$ to siła reakcji, a $\vec{F}\_{cał.}$ to siła całkowita działająca na cząstkę.

Chcielibyśmy udowodnić, że to sformułowanie jest równoważne sformułowaniu newtonowskiemu.

### Dowód
Rozważmy ruch cząstki w czasie od $t_1$ do $t_2$ po torze $\vec{r}$.
Powyższe twierdzenie jest równoważne temu, że wariacja działania wynosi 0:
\$$ \delta S=\delta \int\_{t_1}^{t_2}\mathcal{L}(\vec{r}, \dot{\vec{r}}, t)\,dt =0\$$
Rozważmy zatem tor $\vec{R}=\vec{r}+\vec{\varepsilon}$, gdzie $\vec{\varepsilon}$ wynosi $\vec{0}$ dla $t_1$ i $t_2$ oraz nie wychodzi poza powierzchnię ruchu cząstki (cząstka dalej pozostaje ograniczona). Zostało to zilustrowane na poniższym rysunku, gdzie kolorem białym została oznaczona prawdziwa trajektoria cząstki, a niebieskim $\vec{R}$. Ruch cząstki jest ograniczony do zielonej płaszczyzny.

<p align="center">
<img src="/assets/images/2025-07-25/wykres_powierzchnia.svg" width="500"/>
</p>

Wariacja działania to wtedy
\$$ \delta S=\int\_{t_1}^{t_2}\left[\mathcal{L}(\vec{R}, \dot{\vec{R}}, t)-\mathcal{L}(\vec{r}, \dot{\vec{r}}, t)\right]\,dt\$$
Obliczmy różnicę znajdującą się pod całką:
\$$ \mathcal{L}(\vec{R}, \dot{\vec{R}}, t)-\mathcal{L}(\vec{r}, \dot{\vec{r}}, t)=T(\vec{R}, \dot{\vec{R}}, t)-U(\vec{R}, t)-T(\vec{r}, \dot{\vec{r}}, t)+U(\vec{r}, t)\$$
Wyznaczmy poszczególne wyrazy:
\$$ T(\vec{R}, \dot{\vec{R}}, t)=\frac{1}{2}m\dot{R}^2=\frac{1}{2}m\left(\dot{\vec{r}}+\dot{\vec{\varepsilon}}\right)^2=\frac{1}{2}m\left(\dot{r}^2+2\dot{\vec{r}}\cdot\dot{\vec{\varepsilon}}+\dot{\varepsilon}^2\right)\$$
\$$ T(\vec{R}, \dot{\vec{R}}, t)-T(\vec{r}, \dot{\vec{r}}, t)=\frac{1}{2}m\left(\dot{r}^2+2\dot{\vec{r}}\cdot\dot{\vec{\varepsilon}}+\dot{\varepsilon}^2\right)-\frac{1}{2}m\dot{r}^2=m\dot{\vec{r}}\cdot\dot{\vec{\varepsilon}}+\frac{1}{2}m\dot{\varepsilon}^2\$$
Ponieważ $\varepsilon$ oraz $\dot{\varepsilon}$ są małe
\$$ T(\vec{R}, \dot{\vec{R}}, t)-T(\vec{r}, \dot{\vec{r}}, t)\approx m\dot{\vec{r}}\cdot\dot{\vec{\varepsilon}}.\$$
Obliczmy teraz różnicę 
\$$ -U(\vec{R}, t)+U(\vec{r}, t)=-\left[ U(\vec{r}+\vec{\varepsilon}, t)-U(\vec{r}, t) \right]\approx-\left[ U(\vec{r}, t)+\vec{\varepsilon}\cdot\nabla U(\vec{r}, t)-U(\vec{r}, t)\right]=-\vec{\varepsilon}\cdot\nabla U(\vec{r}, t)\$$
Wracając, mamy
\$$ \mathcal{L}(\vec{R}, \dot{\vec{R}}, t)-\mathcal{L}(\vec{r}, \dot{\vec{r}}, t)\approx m\dot{\vec{r}}\cdot\dot{\vec{\varepsilon}}-\vec{\varepsilon}\cdot\nabla U(\vec{r}, t)\$$
Wstawmy to do całki:
\$$ \delta S=\int\_{t_1}^{t_2}\left[ m\dot{\vec{r}}\cdot\dot{\vec{\varepsilon}}-\vec{\varepsilon}\cdot\nabla U(\vec{r}, t) \right]\,dt \$$
Aby pozbyć się $\dot{\vec{\varepsilon}}$, pocałkujmy pierwszy wyraz przez części:
\$$ \int\_{t_1}^{t_2} m\dot{\vec{r}}\cdot\dot{\vec{\varepsilon}} \,dt =\underbrace{\left[m\dot{\vec{r}}\cdot\vec{\varepsilon} \right]\_{t_1}^{t_2}}\_{=0} -\int\_{t_1}^{t_2} m\ddot{\vec{r}}\cdot\vec{\varepsilon}\,dt, \$$
co daje nam 
\$$ \delta S=\int\_{t_1}^{t_2}\vec{\varepsilon}\cdot\left[-m\ddot{\vec{r}} -\nabla U(\vec{r}, t) \right]\,dt. \$$
Zauważmy teraz, że $m\ddot{\vec{r}}=\vec{F}\_{cał.}$ oraz $-\nabla U(\vec{r}, t)=\vec{F}$:
\$$ \delta S=\int\_{t_1}^{t_2}\vec{\varepsilon}\cdot\left[-\vec{F}\_{cał.}+\vec{F}\right]\,dt\$$
Wiemy, że $-\vec{F}\_{cał.}+\vec{F}=-\vec{F}-\vec{F}\_R+\vec{F}=-\vec{F}\_R$, zatem
\$$ \delta S =-\int\_{t_1}^{t_2}\vec{\varepsilon}\cdot\vec{F}\_R\,dt. \$$
Jak wspomnieliśmy wcześniej, siły reakcji są **zawsze prostopadłe** do powierzchni ruchu cząstki, a $\vec{\varepsilon}$ wybraliśmy takie, aby w tej powierzchni leżało. Oznacza to, że $\vec{\varepsilon}\cdot\vec{F}\_R=0$, a co za tym idzie
\$$ \delta S = 0, \$$
co kończy dowód.

Analogiczny dowód można przeprowadzić dla cząstki ograniczonej do ruchu jedynie po krzywej.

## Przykład
Rozważmy piłkę toczącą się po równi pochyłej. Jej położenie można jednoznacznie określić za pomocą jednej zmiennej $x$. Jeśli oś $x$ wybierzemy tak, aby przebiegała równolegle do równi oraz $x=0$, gdy piłka jest u podstawy równi, jej energia potencjalna będzie dana wzorem
\$$ U=mgh=mgx\sin\theta, \$$
gdzie $\theta$ to kąt nachylenia równi (patrz rysunek poniżej).

<p align="center">
<img src="/assets/images/2025-07-25/równia.svg" width="300"/>
</p>

W tym przypadku cząstka poruszająca się w 2 wymiarach jest ograniczona do 1 wymiaru poprzez siłę reakcji równi.
Lagranżjan piłki będzie wynosił
\$$ \mathcal{L}=\frac{1}{2}m\dot{x}^2-mgx\sin\theta, \$$
co po wstawieniu do równania Lagrange'a da nam
\$$ m\ddot{x}=-mg\sin\theta. \$$

## Przykład
Rozważmy wahadło matematyczne o długości $l$, na którego końcu jest zawieszona masa $m$ o energii potencjalnej $U=-mgy=-mgl\cos{\theta}$ (patrz rysunek).

<p align="center">
<img src="/assets/images/2025-07-25/wahadło.svg" width="600"/>
</p>

Masa jest ograniczona siłą reakcji linki i jej ruch można opisać za pomocą tylko zmiennej $\theta$. Lagranżjan tego wahadła to
\$$ \mathcal{L}=\frac{1}{2}ml^2\dot{\theta}^2+mgl\cos{\theta}, \$$
a wynikające z niego równanie ruchu to
\$$ ml^2\ddot{\theta}+mgl\sin{\theta}=0. \$$

