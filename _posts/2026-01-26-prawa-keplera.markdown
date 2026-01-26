---
layout: post
title: "Prawa Keplera"
date: 2026-01-26
categories: Mechanika
katex: true
---

## Problem dwóch ciał 
Rozważmy dwa ciała oddziałujące ze sobą klasycznym potencjałem grawitacyjnym, tzn. ich energia potencjalna wzajemnych oddziaływań to
\$$ U(r)= -\frac{Gm_1m_2}{r}, \$$
gdzie wprowadzamy oznaczenia $ \mathbf{r}\equiv \mathbf{r_1}- \mathbf{r_2}$, $ \mathbf{r_1}$ - wektor wodzący ciała o masie $m_1$ i analogicznie dla $m_2$. Zapiszemy lagranżjan dla układu:
\$$ \mathcal{L} = \frac{1}{2}m_1v_1^2+ \frac{1}{2}m_2 v_2^2+ \frac{Gm_1m_2}{r}, \$$
gdzie $v_1=|\dot{ \mathbf{r}}\_1|$ i analogicznie dla 2.

Oznaczymy jako $\mathbf{R}$ wektor wodzący środka masy dwóch ciał, który jest zdefiniowany jako
\$$ \mathbf{R}= \frac{1}{M}\left(m_1 \mathbf{r_1}+m_2 \mathbf{r_2}\right), \$$
gdzie $M=m_1+m_2$. Powyższe równanie i definicja $ \mathbf{r}$ tworzą układ dwóch równań, które możemy rozwiązać, aby otrzymać $ \mathbf{r_1}$ i $ \mathbf{r_2}$:
\$$ \begin{cases} \mathbf{r_1} = \mathbf{R} + \frac{m_2}{M} \mathbf{r} \\\\ \mathbf{r_2}= \mathbf{R} - \frac{m_1}{M} \mathbf{r}. \end{cases} \$$
Obliczając pochodne i wstawiając do lagranżjanu otrzymujemy:
\$$ \mathcal{L} = \frac{1}{2}m_1\left(\mathbf{\dot{R}} + \frac{m_2}{M} \mathbf{\dot{r}}\right)^2+ \frac{1}{2}m_2 \left(\mathbf{\dot{R}} - \frac{m_1}{M} \mathbf{\dot{r}}\right)^2+ \frac{Gm_1 m_2}{r}. \$$
Po rozpisaniu i wymnożeniu nawiasów środkowe wyrazy się skracają, co pozostawia nas z 
\$$ \mathcal{L} = \frac{1}{2}M\mathbf{\dot{R}}^2+ \frac{1}{2} \frac{m_1 m_2}{M} \mathbf{\dot{r}}^2+ \frac{Gm_1m_2}{r}. \$$
Widzimy, że ruch możemy rozpatrywać jako ruch środka masy (jednostajny i prostoliniowy) oraz ruch masy zredukowanej $\mu\equiv m_1m_2/M$ wokół środka masy. Iloczyn $m_1m_2$ możemy wyrazić jako $\mu M$, a wybierając inercjalny układ odniesienia związany ze środkiem masy, czyli $ \mathbf{\dot{R}}=0$, lagranżjan przyjmie najprostszą postać
\$$ \mathcal{L} = \frac{1}{2}\mu \mathbf{\dot{r}}^2+ \frac{GM\mu}{r}. \$$
Wektor $ \mathbf{\dot{r}}$ możemy rozdzielić na składową radialną i styczną, a z twierdzenia Pitagorasa $ \mathbf{\dot{r}}^2=\dot{r}^2+r^2\dot{\theta}^2$, gdzie $\theta$ to kąt azymutalny tworzony przez wektor $ \mathbf{r}$ z pewnym kierunkiem odniesienia, a więc
\$$ \mathcal{L} = \frac{1}{2}\mu \dot{r}^2 + \frac{1}{2}\mu r^2\dot{\theta}^2+ \frac{GM\mu}{r}. \$$
Lagranżjan nie zależy od kąta biegunowego, więc moment pędu z nim związany jest równy zero ($ L_\phi=\partial\mathcal{L}/\partial \dot{\phi}=0$). Z tego powodu ruch odbywa się w jednej płaszczyźnie. Zachodzi również zależność
\$$ L_\theta= \frac{\partial \mathcal{L}}{\partial \dot{\theta}}=\mu r^2\dot{\theta}=const. \$$
która wynika bezpośrednio z <a href="https://bwegrzyn0.github.io/mechanika/mechanika-lagrangea-cz%C4%99%C5%9B%C4%87-2-zasada-hamiltona" target=_blank>równania Eulera-Lagrange'a</a> dla współrzędnej $\theta$.

## Pierwsze prawo Keplera 
Chcielibyśmy znaleźć teraz ogólne wyrażenie na kształt toru cząstki. W tym celu naszym punktem wyjścia nie będzie równanie ruchu wynikające bezpośrednio z równania Eulera-Lagrange'a, a zasada zachowania energii. Zamieniając drugi znak plus na minus w lagranżjanie otrzymamy całkowitą energię:
\$$ E=\frac{1}{2}\mu \dot{r}^2 + \frac{1}{2}\mu r^2\dot{\theta}^2- \frac{GM\mu}{r}. \$$
Korzystając z zachowania momentu pędu (gdzie $L_\theta$ to od teraz po prostu $L$):
\$$ \dot{\theta}= \frac{L}{\mu r^2}, \$$
oraz z reguły łańcuchowej
\$$ \dot{r}= \frac{dr}{d\theta} \dot{\theta}= \frac{L}{\mu r^2} \frac{dr}{d\theta}. \$$
Wstawiając to do energii otrzymujemy
\$$ \frac{1}{2}\mu \left( \frac{L}{\mu r^2} \frac{dr}{d\theta} \right)^2=E- \frac{1}{2}\mu r^2 \left( \frac{L}{mr^2}\right)^2+ \frac{GM\mu}{r}. \$$
Przekształcając,
\$$ \frac{L}{\mu r^2} \frac{dr}{d\theta}= \sqrt{ \frac{2}{\mu}\left(E- \frac{1}{2}\mu r^2 \left( \frac{L}{\mu r^2}\right)^2+ \frac{GM\mu}{r}\right)}, \$$
separując zmienne i całkując:
\$$ \theta=\int \frac{L\,dr}{\mu r^2 \sqrt{ \frac{2}{\mu}\left(E-\frac{L^2}{2\mu r^2}+ \frac{GM\mu}{r}\right)}}. \$$
Widzimy, że mamy wiele wyrazów postaci $1/r$, a $dr/r^2=-d(1/r)$. Dlatego wykonamy podstawienie $u=-1/r$, co da nam
\$$ \theta=-\int \frac{L\,du}{\mu \sqrt{ \frac{2}{\mu}\left(E-\frac{L^2}{2\mu} u^2- GM\mu u\right)}}. \$$
Wyrażenie pod pierwiastkiem dopełnimy do kwadratu:
\$$ E-\frac{L^2}{2\mu} u^2- GM\mu u=E+ \frac{G^2 M^2 \mu^3}{2L^2}- \left( \frac{L}{\sqrt{2\mu}}u+ \frac{GM\mu^{3/2}}{L\sqrt{2}}\right)^2, \$$
więc
\$$ \theta=-\int\frac{L\,du}{\mu \sqrt{ \frac{2}{\mu}\left(E+ \frac{G^2 M^2 \mu^3}{2L^2}- \left( \frac{L}{\sqrt{2\mu}}u+ \frac{GM\mu^{3/2}}{L\sqrt{2}}\right)^2\right)}}. \$$
Podstawimy
\$$ v=\frac{1}{\sqrt{E+ \frac{G^2 M^2 \mu^3}{2L^2}}}\left(\frac{L}{\sqrt{2\mu}}u+ \frac{GM\mu^{3/2}}{L\sqrt{2}}\right), \$$
skąd
\$$ \theta=-\int \frac{L}{\sqrt{2\mu\left(E+ \frac{G^2 M^2 \mu^3}{2L^2}\right)}} \frac{1}{\sqrt{1-v^2}} \frac{\sqrt{2\mu\left(E+ \frac{G^2 M^2 \mu^3}{2L^2}\right)}\,dv}{L}=-\int \frac{dv}{\sqrt{1-v^2}}=\arccos{v}+\theta_0, \$$ 
gdzie $\theta_0$ to stała całkowania. Przekształcając i wstawiając definicję $v$ i $u$:
\$$ r= \frac{p}{1-e\cos\left(\theta-\theta_0\right)}, \$$
gdzie $p$ wynosi
\$$ \boxed{p= \frac{L^2}{GM\mu^2}} \$$
oraz
\$$ \boxed{e= \sqrt{1+ \frac{2EL^2}{G^2 M^2 \mu^3}}.} \$$
Równanie to jest oczywiście definicją elipsy o mimośrodzie $e$ i _semilatus rectum_ $p$ we współrzędnych biegunowych. W ognisku elipsy znajduje się zatem środek masy dwóch ciał. Jeśli chcemy, aby $\theta=0$ w perygeum (najniższym punkcie orbity), mianownik musi być jak największy, więc $\cos\theta_0$ musi wynosić $-1$, skąd $\theta_0=\pi$. Wtedy
\$$ \boxed{r= \frac{p}{1+e\cos\theta}.} \$$

W przypadku ciał Układu Słonecznego, $m_1\gg m_2$, gdzie $m_1$ to masa Słońca, a $m_2$ to masa planety. Wtedy $M=m_1+m_2\approx m_1$, $\mu\approx m_2$, a środek masy układu leży w Słońcu, zatem Słońce leży w ognisku orbity planety. Daje nam to **I prawo Keplera**:
> **Wszystkie planety poruszają się po elipsach ze Słońcem w jednym z ognisk.**

## Drugie prawo Keplera
<p align="center">
<img src="/assets/images/2026-01-26/2prawokeplera.svg" width="500" />
</p>
Obliczmy, jakie pole elipsy zakreśla wektor wodzący ciała w przedziale czasu $dt$. Z powyższego rysunku widzimy, że zakreślone pole to w przybliżeniu pole sektora okręgu o promieniu $r$ i kącie rozwarcia $d\theta$, ponieważ $r(\theta+d\theta)\approx r(\theta)$. Pole takie wyraża się wzorem
\$$ dA= \frac{1}{2}r^2\,d\theta. \$$
Dzieląc przez $dt$ otrzymamy:
\$$ \dot{A}= \frac{1}{2}r^2\dot{\theta}= \frac{1}{2}r^2 \frac{L}{\mu r^2}= \frac{L}{2\mu}=const.\$$
ponieważ jak przekonaliśmy się wcześniej,
\$$ L=\mu r^2\dot{\theta}=const. \$$
Fakt, że wielkość $\dot{A}$ jest stała, jest równoważny z **II prawem Keplera**:
> **W jednakowych przedziałach czasu wektor wodzący planety zakreśla jednakowe pole powierzchni.**

## Trzecie prawo Keplera
### Pierwsza metoda
Jak wyprowadziliśmy wcześniej, 
\$$ \frac{dA}{dt}= \frac{L}{2\mu}. \$$
Możemy rodzielić zmienne i pocałkować obustronnie:
\$$ \int dA = \int \frac{L}{2\mu}\,dt. \$$
Jeśli pocałkujemy po przedziale $t\in\langle 0,P\rangle$, gdzie $P$ to okres orbity, to całka po $dA$ to po prostu pole całej elipsy, które wynosi $\pi ab$, gdzie $a$ to półoś wielka, a $b$ to półoś mała:
\$$ \pi ab= \frac{L}{2\mu}P. \$$
Półoś mała elipsy to
\$$ b=a\sqrt{1-e^2}. \$$
Jak obliczyliśmy wcześniej,
\$$ p= \frac{L^2}{GM\mu^2}, \$$
więc
\$$ L=\mu\sqrt{GMp}. \$$
_Semilatus rectum_ elipsy to
\$$ p=a(1-e^2), \$$
więc łącząc to wszystko:
\$$ \pi a^2\sqrt{1-e^2}= \frac{\mu \sqrt{GMa(1-e^2)}}{2\mu}P. \$$
Podnosząc obustronnie do kwadratu i skracając wyrazy otrzymujemy
\$$ \boxed{P^2 = \frac{4\pi^2}{GM}a^3,} \$$
więc
\$$ \boxed{P^2\propto a^3.} \$$
**III prawo Keplera** brzmi zatem następująco:
> **Kwadraty okresów orbitalnych planet mają się do siebie jak sześciany półosi wielkich orbit tych planet.**

### Druga metoda
Istnieje inna metoda wyprowadzenia III prawa Keplera, opierająca się na podobieństwie mechanicznym.

Zauważmy, że pomnożenie lagranżjanu przez stały czynnik nie zmienia w żaden sposób równań ruchu, ponieważ jeśli do równania Eulera-Lagrange'a wstawimy $a\mathcal{L}$ zamiast $\mathcal{L}$, stały czynnik $a$ skraca się.

Zauważmy teraz, że grawitacyjna energia potencjalna jest funkcją jednorodną stopnia $k=-1$, tzn.
\$$ U(\alpha r)= \alpha^{k} U(r). \$$
Jeśli dokonamy zamiany zmiennych, tak, że $r$ zamieniamy na $\alpha r$, a czas zamieniamy na $\beta t$, gdzie $\beta$ to inna stała, wszystkie prędkości zostaną pomnożone przez czynnik $\alpha/\beta$, energie kinetyczne ($\propto v$) razy $\alpha^2/\beta^2$, a energia potencjalna razy $1/\alpha$. Da nam to lagranżjan
\$$ \mathcal{L}= \frac{\alpha^2}{\beta^2}T- \frac{1}{\alpha}U. \$$
Aby równania ruchu były nienaruszone, musimy być w stanie wyciągnąć stały czynnik przed nawias, co jest możliwe tylko wtedy, gdy
\$$ \frac{\alpha^2}{\beta^2}= \frac{1}{\alpha} \$$
lub równoważnie:
\$$ \alpha^3=\beta^2. \$$

Rozważymy teraz dwie cząstki poruszające się na dwóch geometrycznie podobnych torach. Na podstawie wcześniejszego rozumowania możemy stwierdzić, że czasy ruchu na tych torach mają się do siebie jak
\$$ \frac{t_2}{t_1}=\left( \frac{l_2}{l_1}\right)^{3/2}, \$$
gdzie $l$ to miara liniowych rozmiarów toru. Miarą liniowych rozmiarów toru jest półoś wielka, a czasem ruchu jest okres orbitalny, więc powyższe stwierdzenie jest równoważne z III prawem Keplera.


