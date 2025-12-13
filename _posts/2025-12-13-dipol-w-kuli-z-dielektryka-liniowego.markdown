---
layout: post
title: "Dipol w kuli z dielektryka liniowego"
date: 2025-12-13
categories: Elektromagnetyzm
katex: true
---

Rozważmy kulę wykonaną z dielektryka liniowego o względnej przenikalności $\varepsilon_r$ i promieniu $R$. W środku kuli zostaje umiejscowiony dipol o momencie $\mathbf{p}$. Chcemy wyznaczyć potencjał w środku i na zewnątrz kuli. 

Poprzez $V_z$ oznaczamy potencjał zewnętrzny, a $V_w$ wewnętrzny.

Rozpoczniemy od zadania warunków brzegowych. Jedynym źródłem potencjału jest kula, więc w nieskończoności potencjał powinien zanikać:
\$$ r\to \infty\implies V_{z}\to 0. \$$

Potencjał musi być również ciągły na powierzchni kuli:
\$$ V_{z}(R)=V_{w}(R). \$$

Chcemy również, aby na powierzchni kuli było spełnione prawo Gaussa:
\$$ \oint_\mathcal{S}\mathbf{D}\cdot \hat{\mathbf{n}}\,dS=Q_{sw}, \$$
a ponieważ jedyne ładunki swobodne w układzie wchodzą w skład dipola, na powierzchni kuli możemy mieć tylko ładunki związane. Z tego powodu
\$$  \oint_\mathcal{S}\mathbf{D}\cdot \hat{\mathbf{n}}\,dS=0, \$$
gdzie $\mathcal{S}$ to powierzchnia pudełka Gaussa znajdującego się częściowo wewnątrz i częściowo na zewnątrz kuli. Ponieważ jest to dielektryk liniowy, $\nabla\times\mathbf{P}=0$, a zatem również $\nabla\times\mathbf{D}=0$, więc nie musimy martwić się składową $\mathbf{D}$ styczną do powierzchni kuli. Jeśli uczynimy pudełko Gaussa bardzo małym, warunek przybiera postać
\$$ D_{wew}(R)=D_{zew}(R). \$$
Pamiętając, że $D=\varepsilon E$, a $E=\frac{\partial V}{\partial n}=\frac{\partial V}{\partial r}$ (bo $\hat{\mathbf{n}}=\hat{\mathbf{r}}$), otrzymujemy
\$$ \varepsilon_r \left.\frac{\partial V_w}{\partial r}\right|\_R =\left.\frac{\partial V_z}{\partial r}\right|\_R, $$
ponieważ wewnątrz $\varepsilon=\varepsilon_0\varepsilon_r$, a na zewnątrz $\varepsilon=\varepsilon_0$.

Pozostaje nam wziąć pod uwagę obecność dipola wewnątrz kuli. Wyznaczmy najpierw gęstość ładunku związanego w zależności od gęstości ładunków swobodnych. Z definicji mamy
\$$ \rho_{zw}=-\nabla\cdot\mathbf{P}. \$$
W dielektrykach
\$$ \mathbf{P}=\varepsilon_0\chi_e \mathbf{E}=\varepsilon_0(\varepsilon_r-1)\mathbf{E}=\varepsilon_0(\varepsilon_r-1)\frac{\mathbf{D}}{\varepsilon_0\varepsilon_r}=\mathbf{D}\left(\frac{\varepsilon_r-1}{\varepsilon_r}\right),\$$
więc
\$$ \rho_{zw}=-\left(\frac{\varepsilon_r-1}{\varepsilon_r}\right)\nabla\cdot\mathbf{D}=-\left(\frac{\varepsilon_r-1}{\varepsilon_r}\right)\rho_{sw}.\$$

Widzimy zatem, że dwa ładunki wchodzące w skład dipola $\mathbf{p}$ wyindukują w swoich położeniach ładunki o przeciwnych znakach i mniejsze o czynnik w powyższym wzorze. Dwa wyindukowane ładunki wytworzą związany moment dipolowy:
\$$ \mathbf{p}\_{zw}=-\mathbf{p}\left(\frac{\varepsilon_r-1}{\varepsilon_r}\right). \$$
Całkowity moment dipolowy wewnątrz kuli to
\$$ \mathbf{p}\_c=\mathbf{p}+\mathbf{p}\_{zw}=\frac{1}{\varepsilon_r}\mathbf{p}. \$$

Przejdźmy do wyznaczenia potencjału. Wiemy, że potencjał wewnątrz kuli w najogólniejszej postaci to
\$$ V_{wew}=\sum_{l=0}^\infty \left(A_l r^l +\frac{B_l}{r^{l+1}}\right)P_l(\cos\theta). \$$
Osobliwość potencjału w $r=0$ nie może pochodzić od powierzchniowych ładunków związanych, a tylko i wyłącznie od całkowitego momentu dipolowego. Dlatego wszystkie człony potencjału, dla których potęga $r$ jest mniejsza od $0$ muszą pochodzić tylko od dipola. Potencjał dipola to
\$$ V_{dip}=\frac{p_c\cos\theta}{4\pi\varepsilon_0 r^2}=\frac{p\cos\theta}{4\pi\varepsilon r^2}, \$$
więc widzimy, że
\$$ B_l=\begin{cases}
0\text{, jeśli } l\neq 1 \\\\ \frac{p}{4\pi\varepsilon}\text{, jeśli } l=1. \end{cases} \$$

Potencjał na zewnątrz kuli jest podobnie opisany równaniem
\$$ V_{zew}=\sum_{l=0}^\infty \left(C_l r^l +\frac{D_l}{r^{l+1}}\right)P_l(\cos\theta). \$$
Ponieważ $V\to 0$ jak $r\to\infty$, $C_l=0$ dla wszystkich $l$.

Rozpatrzmy przypadek $l\neq 1$. Warunek ciągłości potencjału daje nam ($B_l=0$ dla $l\neq 1$):
\$$ \frac{D_l}{R^{l+1}}=A_l R^l, \$$
a warunek wynikający z prawa Gaussa
\$$ -\frac{D_l(l+1)}{R^{l+2}}=\varepsilon_r A_l lR^{l-1}. \$$
Pierwsze z równań daje nam
\$$ D_l=A_l R^{2l+1}, \$$
a drugie
\$$ D_l=-\varepsilon_r A_l \frac{l}{l+1} R^{2l+1}. \$$
Ponieważ $R,l, \varepsilon_r>0$, pierwsze równanie oznacza, że $A_l$ i $D_l$ mają ten sam znak, a równanie drugie, że mają przeciwny. Obywda warunki oczywiście mogą być spełnione jedynie, gdy $D_l=A_l=0$.

Rozważmy teraz przypadek $l=1$. Warunek ciągłości:
\$$ \frac{D_1}{R^{2}}=A_1 R+\frac{p}{4\pi\varepsilon R^2}\rightarrow D_1=A_1R^3+\frac{p}{4\pi\varepsilon}. \$$
Warunek prawa Gaussa:
\$$ -\frac{2D_1}{R^3}=\varepsilon_r A_1-\frac{2p\varepsilon_r}{4\pi\varepsilon R^3}\rightarrow D_1=\frac{p}{4\pi\varepsilon_0}-\frac{A_1\varepsilon_r R^3}{2}.\$$
Z równań tych dostajemy
\$$ A_1=\frac{2p}{4\pi\varepsilon R^3}\left(\frac{\varepsilon_r-1}{\varepsilon_r+2}\right) \$$
oraz
\$$ D_1=\frac{p}{4\pi\varepsilon_0}\left(\frac{3}{\varepsilon_r+2}\right). \$$

Ostatecznie, potencjał wewnątrz kuli to dla $r\le R$:
\$$ V=\frac{p\cos\theta}{4\pi\varepsilon r^2}\left[1+\frac{2r^3}{R^3}\left(\frac{\varepsilon_r-1}{\varepsilon_r+2}\right)\right], \$$ 
a dla $r\ge R$:
\$$ V=\frac{p\cos\theta}{4\pi\varepsilon_0 r^2}\left(\frac{3}{2+\varepsilon_r}\right). \$$
