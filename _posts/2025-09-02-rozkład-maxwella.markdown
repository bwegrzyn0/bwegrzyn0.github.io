---
layout: post
title: "Rozkład Maxwella"
date: 2025-09-02
categories: Termodynamika 
katex: true
---

## Wzór barometryczny

<p align="center">
<img src="/assets/images/2025-09-02/cisnienie.svg" width="500" />
</p>

Rozważmy gaz doskonały znajdujący się w jednorodnym polu grawitacyjnym o natężeniu $g$. Gaz ma stałą temperaturę $T$.  Rozważmy ciśnienie $p$ w punkcie na wysokości $h$ względem pewnego poziomu odniesienia, na którym $h=0$ oraz $p=p_0$ (np. powierzchni ziemi). W punkcie znajdującym się niżej o $dh$ ciśnienie będzie wynosić:
\$$ p(h-dh)=p(h)+p_{gazu}, \$$
gdzie $p_{gazu}$ to ciśnienie wynikające z masy gazu znajdującego się między wysokościami $h$ a $h-dh$. 
Z definicji ciśnienia mamy
\$$ p_{gazu}=\frac{dF}{dS}=g\frac{dm}{dS}, \$$
gdzie $dS$ to powierzchnia, na którą napiera element gazu o masie $dm$. Skorzystałem z faktu, że ciężar gazu wyraża się wzorem $g\,dm$. Wstawmy ten wynik do wcześniejszego równania:
\$$ p(h-dh)=p(h)+g\frac{dm}{dS}. \$$
Ponieważ $dp=p(h)-p(h-dh)$, możemy zapisać 
\$$ dp=-g\frac{dm}{dS}. \$$
Zauważmy, że $dm$ możemy wyrazić jako $\rho dV$, gdzie $\rho$ to gęstość elementu gazu:
\$$ dp=-g\rho\frac{dV}{dS}. \$$
Ponieważ $dV=dS\,dh$, 
\$$ dp=-g\rho\,dh \$$

Chcielibyśmy wyrazić $\rho$ poprzez $p$. Aby to uczynić, posłużymy się równaniem stanu gazu idealnego:
\$$ pV=nRT \$$
lub przekształcając
\$$ p=\frac{nRT}{V}. \$$
Liczbę moli możemy wyrazić poprzez gęstość, korzystając z faktu, że $n=m/\mu$ (gdzie $\mu$ to masa molowa gazu) oraz $m=\rho V$:
\$$ n=\rho V/\mu. \$$
Wstawmy to do wcześniejszego równania:
\$$ p=\frac{\rho RT}{\mu} \$$
i przekształćmy
\$$ \rho=\frac{p\mu}{RT}. \$$

Możemy powrócić do równania na $dp$:
\$$ dp=-\frac{g\mu}{RT}p\,dh \$$
\$$ \frac{dp}{p}=-\frac{g\mu}{RT}\,dh. \$$
Pocałkujmy obustronnie:
\$$ \int \frac{dp}{p}=\int -\frac{g\mu}{RT}\,dh \$$
\$$ \ln p=-\frac{g\mu}{RT}h+C \$$
i przekształćmy aby otrzymać wyrażenie na $p$:
\$$ p=\exp\left(-\frac{g\mu}{RT}h+C\right)=C\exp\left(-\frac{g\mu}{RT}h\right). \$$
Chcemy, aby $p=p_0$, gdy $h=0$, dlatego $C=p_0$. W ten sposób otrzymujemy __wzór barometryczny__:
\$$ \boxed{p=p_0\exp\left(-\frac{g\mu}{RT}h\right)} \$$

Teraz za pomocą wzoru barometrycznego wyrazimy gęstość gazu jako funkcję wysokości. Z poprzednich rozważań wiemy, że
\$$ \rho=\frac{p\mu}{RT}, \$$
czyli 
\$$ p=\rho\frac{RT}{\mu}. \$$
Jeśli ograniczymy się do jednej cząstki o masie $m$, możemy zapisać 
\$$ RT=\frac{nRT}{n}=\frac{NkT}{n}=\frac{kT}{n}, \$$
ponieważ $N=1$. Wstawmy to do wzoru barometrycznego:
\$$ \rho\frac{RT}{\mu}=\rho_0\frac{RT}{\mu}\exp\left(-\frac{g\mu n}{kT}h\right), \$$
a ponieważ $\mu n=m$:
\$$ \rho=\rho_0\exp\left(-\frac{mgh}{kT}\right). \$$
Gęstość malejąca wykładniczo z wysokością oznacza również wykładniczo malejącą liczbę cząstek, ponieważ te dwie wielkości są wprost proporcjonalne.

Wzór barometryczny pozwala nam oszacować gęstość różnych gazów na różnych wysokościach w naszej atmosferze, przy założeniu stałej temperatury. Poniższy wykres przedstawia znormalizowane gęstości dla azotu, tlenu i wodoru. Warto zauważyć, że gazy lżejsze, takie jak wodór, na dużych wysokościach występują względnie częściej niż gazy cięższe, np. tlen i azot.

<p align="center">
<img src="/assets/images/2025-09-02/gazyatm.svg" width="700" />
</p>

Założenie stałej temperatury (w tym przypadku $T=288\text{K}$) oczywiście nie jest poprawne na skali wysokości $0-100\text{km}$, ale daje w przybliżeniu poprawne wyniki dla wysokościach do $10\text{km}$.

## Rozkład prędkości pionowych

Naszym obecnym celem jest znalezienie rozkładu prędkości pionowych cząsteczek. Wiemy, że cząsteczki _muszą_ mieć różne prędkości pionowe, ponieważ zgodnie ze wzorem barometrycznym, niektóre z nich nie mają wystarczającej prędkości (energii), aby wznieść się na wysokość $h$.
W tym celu rozważmy dwie płaszczyzny, jedną na poziomie $h=0$, a drugą na poziomie $h=H$. Zakładamy w tej chwili, że zderzenia nie mają wpyłwu na pionowy ruch cząsteczek. Zauważmy, że liczba cząstek o prędkości pionowej $v_z>v_{min}=\sqrt{2gH}$ i przebiegających w pewnym czasie przez dolną płaszczyznę _jest równa_ liczbie cząstek przebiegających przez górą płaszczyznę i o prędkości pionowej $v_z>0$. Wszystkie cząstki spełniające warunek $v_z>v_{min}$ w $h=0$ po pewnej chwili znajdą się w $h=H$ kosztem wytracenia energii $\frac{1}{2}m v_{min}^2$. Ponieważ $\rho$ jest stałe, liczba cząstek przebiegających przez płaszczyzny musi być stała (wtedy liczba cząstek poruszających się w górę jest równa liczbie tych poruszających się w dół i wypadkowy strumień cząstek jest równy zeru).

<p align="center">
<img src="/assets/images/2025-09-02/rozmax1.svg" width="700" />
</p>

Niech $n(v_z^2, h)$ będzie funkcją liczącą średnią liczbę cząstek o danym kwadracie prędkości na pewnej wysokości $h$. Zauważmy, że 
\$$n(v_z^2, H)=n(v_z^2+v_{min}^2, 0), \$$
ponieważ na wysokości $h=H$ wszystkie kwadraty prędkości zostają pomniejszone o $v_{min}^2$ (patrz wykres powyżej). Wykres $n(v_z^2, 0)$ zostaje "przesunięty" w lewo, aby "obciąć" te cząstki, które nie miały wystarczającej energii, oraz aby "przesunąć" pozostałe. Ponieważ na wysokości $H$ całkowita liczba cząstek jest mniejsza o czynnik z funkcją wykładniczą niż na wysokości $h=0$, możemy stwierdzić, że 
\$$ n(v_z^2, H)=\exp\left(-\frac{mgH}{kT}\right)n(v_z^2, 0). \$$
Wstawmy to do wcześniejszego równania:
\$$ \exp\left(-\frac{mgH}{kT}\right)n(v_z^2, 0)=n(v_z^2+v_{min}^2, 0) \$$
i zamieńmy $H$ na $v_{min}^2/2g$:
\$$ \exp\left(-\frac{mv_{min}^2}{2kT}\right)n(v_z^2, 0)=n(v_z^2+v_{min}^2, 0). \$$
Niech $v_{min}^2$ będzie bardzo małe. Oznaczmy $v_z^2$ jako $u$, a $v_{min}^2$ jako $du$. Wtedy, jeśli rozwiniemy funkcję wykładniczą w szereg:
\$$ \left(1-\frac{m}{2kT}\,du\right)n(u,0)=n(u+du,0) \$$
\$$ -\frac{m}{2kT}n(u,0)\,du=n(u+du,0)-n(u,0) \$$
\$$ -\frac{m}{2kT}n(u,0)\,du=dn \$$
\$$ \frac{dn}{du}=-\frac{m}{2kT}n(u,0). \$$
Rozwiązując to równanie otrzymujemy
\$$ n(u, 0)=n_0\exp\left(-\frac{mu}{2kT}\right) \$$
lub 
\$$ n(v_z^2, 0)=n_0\exp\left(-\frac{mv_z^2}{2kT}\right), \$$
gdzie $n_0$ to pewna stała. Zauważmy, że powyższy wynik jest prawdziwy nie tylko dla małych, ale dla _wszystkich_ $du$. Oznaczmy przez $n_c(0)$ całkowitą liczbę cząstek na poziomie $h=0$. Wtedy gęstość prawdopodobieństwa wylosowania cząstki o prędkości $v_z$ to
\$$ f(v_z)=\frac{n(v_z^2,0)}{n_c(0)}=f_{0z} \exp\left(-\frac{mv_z^2}{2kT}\right), \$$
gdzie $f_{0z}$ to pewna stała normalizująca. Funkcja $f$ przestaje być funkcją $v_z^2$, a $v_z$, ponieważ znak składowej prędkości nie ma znaczenia. Warto zauważyć, że rozkład jest symetryczny. Prawdopodobieństwo wylosowania cząstki o prędkości w przedziale $\left[v_{z0}, v_{z1}\right]$ to 
\$$ p_z=\int_{v_{z1}}^{v_{z2}} f(v_z)\,dv_z. \$$
Zauważmy, że rozkład _nie zależy_ od wysokości ani wartości przyspieszenia grawitacyjnego. Jest on w ogólności prawdziwy dla _wszystkich gazów doskonałych_.

## Rozkład prędkości cząsteczkowych w gazie
Aby rozszerzyć prawdopodobieństwo na wartość wektora prędkości, a nie tylko jego składową w kierunku $z$, posłużymy się zasadą ekwipartycji energii. Na jej podstawie możemy stwierdzić, że 
\$$ v_x^2=v_y^2=v_z^2, \$$
dlatego
\$$ p_x=\int_{v_{0x}}^{v_{1x}}f_{0x}\exp\left(-\frac{mv_x^2}{2kT}\right)\,dv_x, \$$
\$$ p_y=\int_{v_{0y}}^{v_{1y}}f_{0y}\exp\left(-\frac{mv_y^2}{2kT}\right)\,dv_y. \$$
Całkowite prawdopodobieństwo, że wartość prędkości zawiera się w pewnym przedziale $\left[v_0,v_1\right]$, to iloczyn prawdopodobieństw, że składowe wektora prędkości zawierają się w takich przedziałach, że wektor $\mathbf{v}$ ma odpowiednią długość:
\$$ p=\iiint_V f_0\exp\left(-\frac{m(v_x^2+v_y^2+v_z^2)}{2kT}\right)\,dv_x\,dv_y\,dv_z=\iiint_V f_0\exp\left(-\frac{mv^2}{2kT}\right)\,dv_x\,dv_y\,dv_z, \$$
gdzie $V$ to pewna objętość w przestrzeni $(v_x, v_y, v_z)$, dla której $v$ zawiera się w odpowiednim przedziale, a stała $f_0$ jest dobrana tak, że całkowite prawdopodobieństwo po całej przestrzeni wynosi $1$.

Łatwo jest dostrzec analogię między współrzędnymi $(v_x, v_y, v_z)$ oraz $(x, y, z)$. Wtedy $v$ pełni rolę odległości od środka układu współrzędnych $r$. Z tego powodu możemy dokonać zamiany zmiennych, a mianowicie podobnie, jak we współrzędnych sferycznych $dx\,dy\,dz=4\pi r^2\,dr$, u nas $dv_x\,dv_y\,dv_z=4\pi v^2\,dv$:
\$$ p=\int_{v_0}^{v_1}4\pi f_0 v^2\exp\left(-\frac{mv^2}{2kT}\right)\,dv. \$$
Funkcja
\$$ \boxed{f(v)=4\pi f_0v^2\exp\left(-\frac{mv^2}{2kT}\right)} \$$
to __rozkład Maxwella__. Aby wyznaczyć stałą $f_0$ pocałkujmy na przedziale $\left[0,\infty\right]$:
\$$ \int_{0}^{\infty}4\pi f_0 v^2\exp\left(-\frac{mv^2}{2kT}\right)\,dv=1.\$$
Aby obliczyć całkę, podstawmy $z=mv^2/(2kT)$, skąd $dz=mv/(kT)\,dv=\sqrt{2mz/(kT)}\,dv$:
\$$ 4\pi f_0 \int_0^\infty \frac{2kT}{m}z\exp\left(-z\right)\sqrt{\frac{kT}{2mz}}\,dz=4\sqrt{2}\pi f_0\left(\frac{kT}{m}\right)^{3/2}\int_0^\infty z^{1/2}e^{-z}\,dz.  \$$
Całkę rozpoznajemy jako funkcję gamma:
\$$ \int_0^\infty z^{1/2}e^{-z}\,dz=\Gamma(\frac{3}{2})=\frac{1}{2}\Gamma(\frac{1}{2})=\frac{\sqrt{\pi}}{2}, \$$
a więc
\$$ f_0\left(\frac{2\pi kT}{m}\right)^{3/2}=1,\$$
\$$ \boxed{f_0=\left(\frac{m}{2\pi kT}\right)^{3/2}} \$$
Funkcja rozkładu Maxwella dla różnych temperatur dla tego samego gazu została przedstawiona na poniższym wykresie.
<p align="center">
<img src="/assets/images/2025-09-02/rozmax2.svg" width="700" />
</p>



