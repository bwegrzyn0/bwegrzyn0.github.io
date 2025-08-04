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
\$$ \mathbf{F}_{cał.}=\mathbf{F}+\mathbf{F}_R=-\nabla U+\mathbf{F}\_R, \$$
gdzie $\mathbf{F}\_R$ to siła reakcji, a $\mathbf{F}\_{cał.}$ to siła całkowita działająca na cząstkę.

Chcielibyśmy udowodnić, że to sformułowanie jest równoważne sformułowaniu newtonowskiemu.

### Dowód
Rozważmy ruch cząstki w czasie od $t_1$ do $t_2$ po torze $\mathbf{r}$.
Powyższe twierdzenie jest równoważne temu, że wariacja działania wynosi 0:
\$$ \delta S=\delta \int\_{t_1}^{t_2}\mathcal{L}(\mathbf{r}, \dot{\mathbf{r}}, t)\,dt =0\$$
Rozważmy zatem tor $\mathbf{R}=\mathbf{r}+\boldsymbol{\varepsilon}$, gdzie $\boldsymbol{\varepsilon}$ wynosi $\mathbf{0}$ dla $t_1$ i $t_2$ oraz nie wychodzi poza powierzchnię ruchu cząstki (cząstka dalej pozostaje ograniczona). Zostało to zilustrowane na poniższym rysunku, gdzie kolorem białym została oznaczona prawdziwa trajektoria cząstki, a niebieskim $\mathbf{R}$. Ruch cząstki jest ograniczony do zielonej płaszczyzny.

<p align="center">
<img src="/assets/images/2025-07-25/wykres_powierzchnia.svg" width="500"/>
</p>

Wariacja działania to wtedy
\$$ \delta S=\int\_{t_1}^{t_2}\left[\mathcal{L}(\mathbf{R}, \dot{\mathbf{R}}, t)-\mathcal{L}(\mathbf{r}, \dot{\mathbf{r}}, t)\right]\,dt\$$
Obliczmy różnicę znajdującą się pod całką:
\$$ \mathcal{L}(\mathbf{R}, \dot{\mathbf{R}}, t)-\mathcal{L}(\mathbf{r}, \dot{\mathbf{r}}, t)=T(\dot{\mathbf{R}})-U(\mathbf{R}, t)-T( \dot{\mathbf{r}})+U(\mathbf{r}, t)\$$
Wyznaczmy poszczególne wyrazy:
\$$ T(\dot{\mathbf{R}})=\frac{1}{2}m\dot{R}^2=\frac{1}{2}m\left(\dot{\mathbf{r}}+\dot{\boldsymbol{\varepsilon}}\right)^2=\frac{1}{2}m\left(\dot{r}^2+2\dot{\mathbf{r}}\cdot\dot{\boldsymbol{\varepsilon}}+\dot{\varepsilon}^2\right)\$$
\$$ T(\dot{\mathbf{R}})-T( \dot{\mathbf{r}})=\frac{1}{2}m\left(\dot{r}^2+2\dot{\mathbf{r}}\cdot\dot{\boldsymbol{\varepsilon}}+\dot{\varepsilon}^2\right)-\frac{1}{2}m\dot{r}^2=m\dot{\mathbf{r}}\cdot\dot{\boldsymbol{\varepsilon}}+\frac{1}{2}m\dot{\varepsilon}^2\$$
Ponieważ $\varepsilon$ oraz $\dot{\varepsilon}$ są małe
\$$ T(\dot{\mathbf{R}})-T(\dot{\mathbf{r}})\approx m\dot{\mathbf{r}}\cdot\dot{\boldsymbol{\varepsilon}}.\$$
Obliczmy teraz różnicę 
\$$ -U(\mathbf{R}, t)+U(\mathbf{r}, t)=-\left[ U(\mathbf{r}+\boldsymbol{\varepsilon}, t)-U(\mathbf{r}, t) \right]\approx-\left[ U(\mathbf{r}, t)+\boldsymbol{\varepsilon}\cdot\nabla U(\mathbf{r}, t)-U(\mathbf{r}, t)\right]=-\boldsymbol{\varepsilon}\cdot\nabla U(\mathbf{r}, t)\$$
Wracając, mamy
\$$ \mathcal{L}(\mathbf{R}, \dot{\mathbf{R}}, t)-\mathcal{L}(\mathbf{r}, \dot{\mathbf{r}}, t)\approx m\dot{\mathbf{r}}\cdot\dot{\boldsymbol{\varepsilon}}-\boldsymbol{\varepsilon}\cdot\nabla U(\mathbf{r}, t)\$$
Wstawmy to do całki:
\$$ \delta S=\int\_{t_1}^{t_2}\left[ m\dot{\mathbf{r}}\cdot\dot{\boldsymbol{\varepsilon}}-\boldsymbol{\varepsilon}\cdot\nabla U(\mathbf{r}, t) \right]\,dt \$$
Aby pozbyć się $\dot{\boldsymbol{\varepsilon}}$, pocałkujmy pierwszy wyraz przez części:
\$$ \int\_{t_1}^{t_2} m\dot{\mathbf{r}}\cdot\dot{\boldsymbol{\varepsilon}} \,dt =\underbrace{\left[m\dot{\mathbf{r}}\cdot\boldsymbol{\varepsilon} \right]\_{t_1}^{t_2}}\_{=0} -\int\_{t_1}^{t_2} m\ddot{\mathbf{r}}\cdot\boldsymbol{\varepsilon}\,dt, \$$
co daje nam 
\$$ \delta S=\int\_{t_1}^{t_2}\boldsymbol{\varepsilon}\cdot\left[-m\ddot{\mathbf{r}} -\nabla U(\mathbf{r}, t) \right]\,dt. \$$
Zauważmy teraz, że $m\ddot{\mathbf{r}}=\mathbf{F}\_{cał.}$ oraz $-\nabla U(\mathbf{r}, t)=\mathbf{F}$:
\$$ \delta S=\int\_{t_1}^{t_2}\boldsymbol{\varepsilon}\cdot\left[-\mathbf{F}\_{cał.}+\mathbf{F}\right]\,dt\$$
Wiemy, że $-\mathbf{F}\_{cał.}+\mathbf{F}=-\mathbf{F}-\mathbf{F}\_R+\mathbf{F}=-\mathbf{F}\_R$, zatem
\$$ \delta S =-\int\_{t_1}^{t_2}\boldsymbol{\varepsilon}\cdot\mathbf{F}\_R\,dt. \$$
Jak wspomnieliśmy wcześniej, siły reakcji są **zawsze prostopadłe** do powierzchni ruchu cząstki, a $\boldsymbol{\varepsilon}$ wybraliśmy takie, aby w tej powierzchni leżało. Oznacza to, że $\boldsymbol{\varepsilon}\cdot\mathbf{F}\_R=0$, a co za tym idzie
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

