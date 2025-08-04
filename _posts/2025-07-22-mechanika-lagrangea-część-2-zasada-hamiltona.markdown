---
layout: post
title: "Mechanika Lagrange'a, część 2: Zasada Hamiltona"
date: 2025-07-22
categories: Mechanika
katex: true
---

## Zasada Hamiltona 
Rozważmy swobodną cząstkę poruszającą się między punktami $1$ i $2$ w czasie od $t_1$ do $t_2$. Droga $\mathbf{r}(t)$, którą wybiera cząstka jest taka, że całka działania
\$$ S=\int_{t_1}^{t_2}\mathcal{L}(\mathbf{r}, \dot{\mathbf{r}}, t)\,dt \$$
jest minimalna (stacjonarna). $\mathcal{L}$ to **lagranżjan** układu zdefiniowany jako
\$$ \mathcal{L}(\mathbf{r}, \dot{\mathbf{r}}, t)=T-U, \$$
gdzie $T$ to energia kinetyczna cząstki, a $U$ to jej energia potencjalna.

### Przykład - cząstka swobodna w przestrzeni 3-wymiarowej
Rozważmy cząstkę o położeniu $\mathbf{r}=(x,y,z)$ oraz prędkości $\dot{\mathbf{r}}=(\dot{x}, \dot{y}, \dot{z})$. Jej energia potencjalna w danej chwili to $U=mgz$, a energia kinetyczna to $T=\frac{1}{2}m\left( \dot{x}^2+\dot{y}^2+\dot{z}^2 \right)$. Wyznaczmy jej równania ruchu.

Funkcja Lagrange'a (lagranżjan) dla tej cząstki to
\$$ \mathcal{L}=\frac{1}{2}m\left( \dot{x}^2+\dot{y}^2+\dot{z}^2 \right)-mgz \$$
<a href="https://bwegrzyn0.github.io/mechanika/mechanika-lagrangea-cz%C4%99%C5%9B%C4%87-1-r%C3%B3wnanie-eulera-lagrangea" target="_blank">W poprzednim artykule</a> dowiedzieliśmy się, że jeśli funkcja $\mathcal{L}$ sprawia, że całka jest minimalna, to spełnia ona równanie Eulera-Lagrange'a. W naszym przypadku mamy do czynienia z trzema zmiennymi, $x$, $y$ i $z$, więc potrzebujemy trzech równań:
\$$ \frac{\partial \mathcal{L}}{\partial x}-\frac{d}{dt}\frac{\partial \mathcal{L}}{\partial\dot{x}}=0\$$
\$$ \frac{\partial \mathcal{L}}{\partial y}-\frac{d}{dt}\frac{\partial \mathcal{L}}{\partial\dot{y}}=0\$$
\$$ \frac{\partial \mathcal{L}}{\partial z}-\frac{d}{dt}\frac{\partial \mathcal{L}}{\partial\dot{z}}=0\$$
Obliczmy wszystkie pochodne:
\$$ \frac{\partial \mathcal{L}}{\partial x}=\frac{\partial \mathcal{L}}{\partial y}=0 \$$
\$$ \frac{\partial \mathcal{L}}{\partial z}=mg \$$
\$$ \frac{d}{dt}\frac{\partial \mathcal{L}}{\partial\dot{x}}=\frac{d}{dt}\left(m\dot{x}\right)=m\ddot{x} \$$
i analogicznie dla $y$ i $z$. Po wstawieniu mamy:
\$$ m\ddot{x}=0 \$$
\$$ m\ddot{y}=0 \$$
\$$ m\ddot{z}=mg \$$
Widzimy, że otrzymujemy 3 równania ruchu, takie same jak otrzymalibyśmy w przypadku użycia mechaniki Newtona. Zauważmy również, że pochodna $\mathcal{L}$ po współrzędnej jest równa dokładnie składowej siły działającej na cząstkę, a pochodna po składowej prędkości to składowa pędu:
\$$\frac{\partial \mathcal{L}}{\partial x}=F_x\$$
\$$\frac{\partial \mathcal{L}}{\partial \dot{x}}=p_x\$$
i analogicznie dla $y$ i $z$. Możemy wstawić to do równania Lagrange'a i otrzymamy dobrze znany wzór
\$$ F_x=\frac{d}{dt}p_x, \$$
co pokazuje, że w tym przypadku sformułowanie mechaniki Lagrange'a jest równoważne sformułowaniu Newtona.

### Przykład - cząstka poruszająca się pod wpływem potencjału centralnego
Rozważmy cząstkę swobodną o masie $m$ poruszającą się w potencjale $U=-GMm/r$, gdzie $r$ to odległość cząstki od początku układu współrzędnych. W tym przypadku najwygodniej będzie posłużyć się współrzędnymi biegunowymi (nie potrzebujemy wsp. sferycznych, ponieważ wiadomo że ruch będzie ograniczony do płaszczyzny) $r$ i $\theta$. Okazuje się, że mimo tego, że $\theta$ jest kątem, wciąż możemy traktować go jak inne współrzędne, np. $x$. Oznacza to, że 2 równania Lagrange'a, które otrzymamy to
\$$ \frac{\partial \mathcal{L}}{\partial r}-\frac{d}{dt}\frac{\partial \mathcal{L}}{\partial\dot{r}}=0\$$
\$$ \frac{\partial \mathcal{L}}{\partial \theta}-\frac{d}{dt}\frac{\partial \mathcal{L}}{\partial\dot{\theta}}=0\$$
Obliczmy lagranżjan. Energia kinetyczna to
\$$ T=\frac{1}{2}m\left[\dot{r}^2+(r\dot{\theta})^2\right], \$$
a energię potencjalną znamy. Zatem
\$$ \mathcal{L}=T-U=\frac{1}{2}m\left[\dot{r}^2+(r\dot{\theta})^2\right]+GMm\frac{1}{r}.\$$
Obliczmy pochodne:
\$$ \frac{\partial \mathcal{L}}{\partial r}=mr\dot{\theta}^2-GMm\frac{1}{r^2} \$$
\$$ \frac{\partial \mathcal{L}}{\partial \theta}=0\$$
\$$ \frac{d}{dt}\frac{\partial \mathcal{L}}{\partial \dot{r}}=m\ddot{r} \$$
\$$ \frac{d}{dt}\frac{\partial \mathcal{L}}{\partial \dot{\theta}}=mr^2\ddot{\theta} \$$
i wstawmy je do naszych równań:
\$$ m\ddot{r}=mr\dot{\theta}^2-GMm\frac{1}{r^2} \$$
\$$ mr^2\ddot{\theta}=0 \$$
Otrzymujemy ponownie wyniki zgodne z mechaniką Newtona. Zauważmy, że ponownie 
\$$\frac{\partial \mathcal{L}}{\partial r}=F_r, \$$
gdzie $F_r$ to suma wszystkich sił radialnych działających na cząstkę. Możemy rozpoznać w niej siłę grawitacji oraz fikcyjną siłę odśrodkową.
\$$ \frac{\partial \mathcal{L}}{\partial \dot{r}}=p_r,\$$
gdzie $p_r$ to radialna składowa pędu cząstki. W przypadku kąta mamy
\$$ \frac{\partial \mathcal{L}}{\partial \theta}=\Gamma, \$$
gdzie $\Gamma$ to moment siły działający na cząstkę (w tym przypadku 0) oraz 
\$$ \frac{\partial \mathcal{L}}{\partial \dot{\theta}}=L, \$$
gdzie $L$ to moment pędu cząstki. Ponownie otrzymujemy dobrze znane równania
\$$ F_r =\frac{d}{dt}p_r\$$
\$$ \Gamma = \frac{d}{dt} L. \$$

Poprzednie 2 przykłady pokazały nam, że wielkości $\partial\mathcal{L}/\partial q_i$ oraz $\partial\mathcal{L}/\partial \dot{q}\_i$, gdzie $q_i$ to pewna **współrzędna uogólniona** (np. $x$, $r$, $\theta$, $\varphi$) pełnią role kolejno siły oraz pędu. Dlatego są one nazywane **siłą uogólnioną** oraz **pędem uogólnionym**.  
