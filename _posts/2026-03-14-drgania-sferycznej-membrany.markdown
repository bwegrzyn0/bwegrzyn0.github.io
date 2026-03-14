---
layout: post
title: "Drgania sferycznej membrany"
date: 2026-03-14
categories: 
katex: true
---

Rozważmy sferycznie symetryczną, płaską membranę, przymocowaną sztywno do pierścienia lub innej okrągłej krawędzi i wykonującą drgania. Membrana leży w jednej płaszczyźnie, więc problem nie zależy od współrzędnej $z$. Rówanie falowe dla membrany będzie miało postać:
\$$ c^2 \nabla^2 u = \frac{\partial^2 u}{\partial t^2} \$$
z warunkiem brzegowym $u(R)=0$, gdzie $R$ to promień membrany (jest ona przymocowana). Laplasjan we współrzędnych biegunowych to
\$$ \nabla^2 u = \frac{1}{r} \frac{\partial}{\partial r}\left( r \frac{\partial u}{\partial r}\right) + \frac{1}{r^2} \frac{\partial^2 u}{\partial \theta^2}, \$$
więc
\$$ \frac{1}{c^2} \frac{\partial^2 u}{\partial t^2}=\frac{1}{r} \frac{\partial}{\partial r}\left( r \frac{\partial u}{\partial r}\right) + \frac{1}{r^2} \frac{\partial^2 u}{\partial \theta^2}, \$$
gdzie $\theta$ to kąt biegunowy.

Równanie rozwiążemy oczywiście speracją zmiennych. Założymy, że rozwiązanie jest postaci $u(r, \theta, t)=Y(r,\theta) T(t)$. Podstawiając,
\$$ \frac{Y(r,\theta)}{c^2} \frac{d^2 T}{dt^2}= \frac{T(t)}{r} \frac{\partial}{\partial r}\left( r \frac{\partial Y}{\partial r}\right)+ \frac{T(t)}{r^2} \frac{\partial ^2 Y}{\partial \theta^2}, \$$
skąd:
\$$ \frac{1}{Y(r,\theta)}\left(\frac{1}{r} \frac{\partial}{\partial r}\left( r \frac{\partial Y}{\partial r}\right)+ \frac{1}{r^2} \frac{\partial ^2 Y}{\partial \theta^2}\right)= \frac{1}{c^2 T(t)} \frac{\partial^2 T}{\partial t^2}. \$$
Obie strony równania zależą od różnych zmiennych, zatem muszą być stałe:
\$$ \frac{1}{c^2 T(t)} \frac{\partial^2 T}{\partial t^2}=-\lambda^2, \$$
\$$ \frac{1}{Y(r,\theta)}\left(\frac{1}{r} \frac{\partial}{\partial r}\left( r \frac{\partial Y}{\partial r}\right)+ \frac{1}{r^2} \frac{\partial ^2 Y}{\partial \theta^2}\right)=-\lambda^2, \$$
gdzie $\lambda\in\mathbb{R}$ to pewna stała separacji. Musi być ona rzeczywista, ponieważ oczekujemy, że ruch *drgającej* membrany będzie miał charakter oscylacyjny.

Pierwsze z równań to wtedy 
\$$ \frac{\partial^2 T}{\partial t^2}=-c^2\lambda^2 T(t), \$$
a jego rozwiązanie, ponieważ $-c^2\lambda^2$ jest ujemną liczbą rzeczywistą, to
\$$ T(t)= A\cos(c\lambda t)+B\sin(c\lambda t), \$$
gdzie $A$ i $B$ to pewne stałe rzeczywiste.

Drugie z równań to
\$$ \frac{1}{r} \frac{\partial}{\partial r}\left( r \frac{\partial Y}{\partial r}\right)+ \frac{1}{r^2} \frac{\partial ^2 Y}{\partial \theta^2}=-\lambda^2 Y(r,\theta). \$$
Założymy, że $Y(r,\theta)=R(r)\Theta(\theta)$. Wtedy
\$$ \frac{\Theta(\theta)}{r} \frac{d}{dr}\left( r\frac{dR}{dr}\right)+ \frac{R(r)}{r^2} \frac{d^2 \Theta}{d\theta^2}=-\lambda^2 R(r)\Theta(\theta), \$$
skąd
\$$ \frac{r}{R(r)} \frac{d}{dr}\left( r \frac{dR}{dr}\right)+\lambda^2 r^2+ \frac{1}{\Theta(\theta)} \frac{d^2 \Theta}{d\theta^2}=0. \$$
Podobnie, jak poprzednio, część równania zależna tylko od $r$ i tylko od $\theta$ musi być stała. Na podstawie tego faktu:
\$$ \frac{1}{\Theta(\theta)} \frac{d^2\Theta}{d\theta^2}=-\alpha^2, \$$
gdzie $\alpha\in \mathbb{R}$. Wynika to z faktu, że funkcja $\Theta(\theta)$ musi spełniać warunek:
\$$ \Theta(\theta)=\Theta(\theta+2\pi k), \tag{1} \$$
gdzie $k\in \mathbb{Z}$, zatem musi być okresowa. Rozwiązaniem tego równania jest wtedy
\$$ \Theta(\theta)=C\cos(\alpha\theta)+D\sin(\alpha\theta), \$$
gdzie $C$ i $D$ to rzeczywiste stałe. Punkt, w którym $\theta=0$ możemy dobrać dowolnie, więc wybierzemy go tak, aby pozbyć się sinusa. Ponadto, ze względu na warunek (1),
\$$ cos(\alpha\theta)=\cos(\alpha\theta+2\pi k), \$$
więc
\$$ \alpha\theta+2\pi n=\alpha(\theta+2\pi k), \, n\in \mathbb{Z}, \$$
\$$ 2\pi n=2\pi \alpha k, \$$
\$$ n=\alpha k. \$$
Powyższe będzie spełnione dla *dowolnych* $n,k\in\mathbb{Z}$, tylko, jeśli $\alpha\in\mathbb{Z}$ (jeśli $\alpha$ byłoby wymierne, ale nie całkowite, to wtedy zawsze możemy znaleźć takie $k$, że nie będzie to prawdziwe, np. $k$ może być liczbą pierwszą niebędącą dzielnikiem mianownika). Mamy zatem
\$$ \Theta(\theta) = C\cos(\alpha\theta), \$$
$C\in\mathbb{R}$, $\alpha\in\mathbb{Z}$.

Równanie na $R(r)$ jest postaci:
\$$\frac{r}{R(r)} \frac{d}{dr}\left( r \frac{dR}{dr}\right)+\lambda^2 r^2=\alpha^2. \$$
Po przeniesieniu wszystkich wyrazów na lewą stronę i rozpisaniu pochodnej mamy:
\$$ r^2 \frac{d^2 R}{dr^2}+ r \frac{dR}{dr}+ (\lambda^2 r^2-\alpha^2)R(r)=0. \$$
Dokonajmy zamiany zmiennych $\lambda r=x$. Wtedy
\$$ x^2 \frac{d^2 R}{dx^2}+ x \frac{dR}{dx}+(x^2-\alpha^2)R(x)=0. \$$
(zamieniając pochodną po $r$ na pochodną po $x$ skracamy $\lambda$ powstałe z podstawienia).
Jest to **równanie Bessela**. Jak widzimy, $x=0$ jest regularnym punktem osobliwym powyższego równania (bo funkcja przy drugiej pochodnej rośnie jak $x^2$, a przy pierwszej, jak $x$), więc będziemy szukać rozwiązań metodą Frobeniusa, czyli postaci:
\$$ R(x) = \sum_{n=0}^\infty a_n x^{n+r}, \$$
gdzie $r$ to pewien parametr. Obliczając pochodne i wstawiając otrzymujemy:
\$$ \sum_{n=0}^\infty a_n(n+r)(n+r-1)x^{n+r}+\sum_{n=0}^\infty a_n(n+r)x^{n+r}+\sum_{n=0}^\infty a_nx^{n+r+2}-\alpha^2 \sum_{n=0}^\infty a_nx^{n+r} = 0. \$$
Chcemy, aby potęga przy $x$ była taka sama dla każdej sumy. Dla trzeciej z nich:
\$$ \sum_{n=0}^\infty a_nx^{n+r+2}=\sum_{n=2}^\infty a_{n-2}x^{n+r}. \$$
Stąd:
\$$ a_0 x^r \left[r(r-1)+r-\alpha^2\right] + a_1 x^{r+1}\left[ r(r+1)+(r+1)-\alpha^2\right]+\\\\ +\sum_{n=2}^\infty \left[a_n\left((n+r)(n+r-1)+(n+r)-\alpha^2\right)+a_{n-2}\right] x^{r+n}=0. \$$
Ponieważ z definicji $a_0$ stoi przy najniższej potędze, nie może być równe $0$ (bo inaczej najniższa potęga nie byłaby najniższa). Z tego powodu:
\$$ r(r-1)+r-\alpha^2 = r^2-\alpha^2 =0, \$$
więc $r=\pm \alpha$. Z drugiego wyrazu albo $a_1=0$, albo:
\$$ r(r+1)+(r+1)-\alpha^2 = (r+1)^2-\alpha^2 =0, \$$
co biorąc pod uwagę fakt, że $\alpha=\pm r$, daje jedynie $\alpha=-1/2\notin\mathbb{Z}$, zatem jedyna możliwość to $a_1=0$. Z ostatniego wyrazu mamy
\$$ a_n\left((n+r)(n+r-1)+(n+r)-\alpha^2\right)+a_{n-2} =0, \$$
skąd
\$$ a_n= \frac{-a_{n-2}}{(n+r)^2-\alpha^2}. \$$
Ponieważ $r=\pm \alpha$, to
\$$ a_n = \frac{a_{n-2}}{\alpha^2 - (n\pm \alpha)^2}= \frac{a_{n-2}}{\pm 2n\alpha-n^2}. \$$
Rozważmy najpierw $+$. Wyrazy dla $n$ nieparzystego będą równe $0$, bo $a_1=0$. Dla $n$ parzystego:
\$$ a_2 = -\frac{a_0}{4(\alpha+1)} \\\\ a_4 = \frac{a_0}{4\cdot 8(\alpha+1)(\alpha+2)} \\\\ \alpha_6 = -\frac{a_0}{4\cdot 8\cdot 12(\alpha+1)(\alpha+2)(\alpha+3)}. \$$
Widzimy, że w ogólności:
\$$ a_{2n} = (-1)^n \frac{a_0 \alpha!}{(\alpha+n)! 2^{2n} n!}. \$$
Stąd pierwsze rozwiązanie to:
\$$ R_1(x) = \sum_{n=0}^\infty (-1)^n \frac{a_0 \alpha!}{(\alpha+n)!2^{2n}n!} x^{2n+\alpha}. \$$ 
W celu uproszczenia zapisu przyjmiemy
\$$ a_0 = \frac{1}{2^\alpha \alpha!}, \$$
skąd
\$$ R_1(x) = \sum_{n=0}^\infty (-1)^n \frac{1}{(\alpha+n)! n!}\left( \frac{x}{2}\right)^{2n+\alpha} = J_\alpha(x). \$$
Jest to **funckja Bessela pierwszego rodzaju rzędu $\alpha$**. Podobnie możemy postąpić dla $-$, skąd dostaniemy $R_2(x)=Y_\alpha(x)$, gdzie $Y_\alpha(x)$ to **funkcja Bessela drugiego rodzaju rzędu $\alpha$**. Okazuje się jednak, że $Y_\alpha(x)$ są rozbieżne dla $x=0$, zatem nie będą one nas interesować.

Rozwiązanie to zatem:
\$$ u(r, \theta, t) = A\cos(c\lambda t)\cos(\alpha\theta) J_\alpha(\lambda r), \$$
gdzie chwilę początkową wybieramy tak, aby $B=0$ oraz wszystkie stałe łączymy w jedną. Pozostaje nam warunek brzegowy:
\$$ u(R, \theta, t)=0, \$$
więc 
\$$ J_\alpha(\lambda R)=0. \$$
Zastąpmy $\alpha$ przez $m$. Jako $\alpha_{mn}$ oznaczymy $n$-te miejsce zerowe $J_n(x)$. Wtedy
\$$ \lambda R=\alpha_{mn}, \$$
skąd
\$$ \lambda = \frac{\alpha_{mn}}{R}. \$$
Ostateczne rozwiązanie to:
\$$ \boxed{ u_{mn}(r,\theta, t)=A\cos\left( \frac{c\alpha_{mn}}{R}t\right)\cos(m\theta)\, J_m\left( \frac{\alpha_{mn}r}{R}\right).} \$$
Są to **mody normalne** cylindrycznej membrany. Kilka modów normalnych jest przedstawionych na poniższych animacjach.

| $u_{01}$ | $u_{02}$  | $u_{03}$ |
| :-: | :-: | :-: |
| <img src="/assets/videos/2026-03-14/u01.gif" width=200/> | <img src="/assets/videos/2026-03-14/u02.gif" width=200/> | <img src="/assets/videos/2026-03-14/u03.gif" width=200/> |
| $u_{11}$ | $u_{12}$  | $u_{13}$ |
| :-: | :-: | :-: |
| <img src="/assets/videos/2026-03-14/u11.gif" width=200/> | <img src="/assets/videos/2026-03-14/u12.gif" width=200/> | <img src="/assets/videos/2026-03-14/u13.gif" width=200/> |
| $u_{21}$ | $u_{22}$  | $u_{23}$ |
| :-: | :-: | :-: |
| <img src="/assets/videos/2026-03-14/u21.gif" width=200/> | <img src="/assets/videos/2026-03-14/u22.gif" width=200/> | <img src="/assets/videos/2026-03-14/u23.gif" width=200/> |
