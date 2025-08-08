---
layout: post
title: "Mechanika Lagrange'a, część 4: Zasady zachowania"
date: 2025-08-04
categories: Mechanika
katex: true
---

## Uogólnienie na układ wielu cząstek
Do tej pory rozważaliśmy układ złożony jedynie z jednej cząstki. Wprowadzenie większej liczby cząstek daje nam więcej współrzędnych uogólnionych, które definiujemy jako zestaw najmniejszej liczby współrzędnych jednoznacznie określających stan układu. Na przykład, dla 2 cząstek w przestrzeni 3-wymiarowej mamy 6 współrzędnych uogólnionych, a dla wahadła podwójnego - jedynie 2. 

Lagrażjan dla układu $N$ cząstek o $n$ współrzędnych uogólnionych ma postać
\$$ \mathcal{L} = T(\dot{q}\_1, \dot{q}\_2, \dots, \dot{q}\_n, t) - U(q_1, q_2, \dots, q_n, t), \$$
gdzie
\$$ T(\dot{q}\_1, \dot{q}\_2, \dots, \dot{q}\_n, t)=\frac{1}{2}m_1\mathbf{v}\_1+\frac{1}{2}m_2\mathbf{v}\_2+\dots+\frac{1}{2}m_N\mathbf{v}\_N, \$$
przy czym $\mathbf{r}\_\alpha$ to położenie $\alpha$-tej cząstki, a $m\_\alpha$ to jej masa.

Dla każdej ze współrzędnych uogólnionych mamy równanie Lagrange'a:
\$$ \frac{\partial \mathcal{L}}{\partial q_i}-\frac{d}{dt}\frac{\partial \mathcal{L}}{\partial \dot{q_i}} = 0. \$$
<a href="https://bwegrzyn0.github.io/mechanika/mechanika-lagrangea-cz%C4%99%C5%9B%C4%87-3-uk%C5%82ady-nieswobodne" target="_blank">Dowód prawdziwości równań Lagrange'a dla jednej cząstki w układzie nieswobodnym</a> można łatwo uogólnić dla wielu cząstek.

### Przykład
Rozważmy układ przedstawiony na poniższym rysunku.

<p align="center">
<img src="/assets/images/2025-08-04/sprezyny.svg" width="500" />
</p>

Sprężyna o współczynniku sprężystości $k_1$ jest przymocowana do ściany, do niej przymocowany jest bloczek o masie $m_1$, a do niego sprężyna o współczynniku sprężystości $k_2$ z bloczkiem o masie $m_2$. 

Położenie pierwszego bloczka oznaczmy jako $x_1$, a drugiego jako $x_2$. Ich położenia równowagi oznaczmy kolejno jako $x_{01}$ i $x_{02}$. Łatwo zauważyć, że $x_1=x_{01}+\Delta x_{1}$ oraz $x_2=x_{02}+\Delta x_1 + \Delta x_2$, gdzie $\Delta x_1$ oraz $\Delta x_2$ to rozciągnięcia sprężyn.

Energia kinetyczna tego układu to
\$$ T=\frac{1}{2}m_1 \dot{x}\_1^2+\frac{1}{2}m_2 \dot{x}\_1^2=\frac{1}{2}m_1\Delta\dot{x}\_1^2+\frac{1}{2}m_2\left(\Delta \dot{ x}\_1+\Delta \dot{ x}\_2\right)^2, \$$
a energia potencjalna to
\$$ U=\frac{1}{2}k_1\Delta x_1^2+\frac{1}{2}k_2\Delta x_2^2. \$$
Po obliczeniu Lagranżjanu, wstawieniu go do dwóch równań i uproszczeniu wyrażeń otrzymujemy układ
\$$ \begin{cases}
m_1\Delta\ddot{x}\_1=-k_1\Delta x_1+k_2\Delta x_2 \\\\ m_2\Delta \ddot{x}\_2=-k_2\Delta x_2-m_2\Delta \ddot{x}\_1
\end{cases} \$$
W pierwszym równaniu z łatwością można wyróżnić siły pochodzące od obu sprężyn, a w drugim siłę sprężystości i siłę bezwładności.

## Zachowanie pędu
Rozważmy izolowany układ $N$ cząstek o położeniach $\mathbf{r}\_1, \mathbf{r}\_2, \dots, \mathbf{r}\_N$. Przesuńmy wszystkie cząstki o mały wektor $\boldsymbol{\varepsilon}=\left(\varepsilon, \varepsilon, \dots, \varepsilon\right)$ (ma tyle składowych ile jest współrzędnych uogólnionych). 

Ponieważ układ jest izolowany, potencjał pochodzi _wyłącznie_ od cząstek w naszym układzie (nie mamy zewtnętrznych pól). Ponieważ wszystkie cząstki zostały przesunięte, ich względne położenia nie zmieniły się, a co za tym idzie energia potencjalna również. Dlatego mamy $\delta U=0$.

Ponieważ $\boldsymbol{\varepsilon}$ to stały wektor, prędkości cząstek się nie zmieniły, zatem $\delta T=0$.

Zmiana lagranżjanu to
\$$ \delta \mathcal{L}=\delta T -\delta U=0,\$$
ale również
\$$ \delta \mathcal{L}=\frac{\partial \mathcal{L}}{\partial q_1}\varepsilon+\frac{\partial \mathcal{L}}{\partial q_2}\varepsilon+\dots+\frac{\partial \mathcal{L}}{\partial q_n}\varepsilon. \$$
Z powyższych równań wynika, że
\$$ \sum_{i=1}^n \frac{\partial \mathcal{L}}{\partial q_i}\varepsilon = 0, \$$
a ponieważ $\varepsilon\neq 0$
\$$ \sum_{i=1}^n \frac{\partial \mathcal{L}}{\partial q_i}= 0. \$$
Z równania Lagrange'a mamy 
\$$ \frac{\partial \mathcal{L}}{\partial q_i}=\frac{d}{dt}\frac{\partial \mathcal{L}}{\partial \dot{q}\_i}, \$$
czyli
\$$ \frac{d}{dt}\sum_{i=1}^n \frac{\partial \mathcal{L}}{\partial \dot{q}\_i}= 0 \$$
\$$ \sum_{i=1}^n p_i = const. \$$
Jeśli zdefiniujemy wektor $\mathbf{P}=\left(p_1, p_2, \dots, p_n\right)$, to
\$$ \boxed{\mathbf{P}=\mathbf{const.}} \$$
w układzie izolowanym.

## Zachowanie momentu pędu
Rozważmy układ izolowany taki, jak w przypadku zachowania pędu. Tym razem układ obrócimy o mały kąt $\delta\theta$ wokół, powiedzmy, osi $z$. Oznacza to, że wszystkie wektory położeń zostaną przesunięte o $\mathbf{\delta r}\_\alpha$ oraz wektory prędkości o $\mathbf{\delta v}\_\alpha$. 

<p align="center">
<img src="/assets/images/2025-08-04/obrot.svg" width="500" />
</p>

Załóżmy, że wektor $\mathbf{r}\_\alpha$ tworzy kąt $\phi_\alpha$ z osią $z.$ Obrócony wektor to $\mathbf{r}\_\alpha'$ i tworzy on taki sam kąt z osią $z$ (ponieważ wokół niej zachodzi obrót). Odległość wektora $\mathbf{r}\_\alpha$ i $\mathbf{r}\_\alpha'$ od osi $z$ na kierunku do niej prostopadłym to $r_\alpha\sin\phi_\alpha$. Z tego powodu wartość wektora zmiany położenia to 
\$$ \delta r_\alpha=r_\alpha\sin\phi_\alpha\,\delta\theta. \$$
Niech wektor $\delta\boldsymbol{\theta}$ będzie skierowany zgodnie ze zwrotem osi $z$ (reguła prawej ręki). Na podstawie rysunku możemy stwierdzić, że 
\$$ \delta\mathbf{r}\_\alpha=\delta\boldsymbol{\theta}\times\mathbf{r}\_\alpha \$$
i analogicznie dla wektora prędkości:
\$$ \delta\mathbf{v}\_\alpha=\delta\boldsymbol{\theta}\times\mathbf{v}\_\alpha. \$$

Oczekujemy, że przy obrocie lagranżjan układu nie ulegnie zmianie, czyli 
\$$ \delta \mathcal{L}=\sum_\alpha \left[\frac{\partial\mathcal{L}}{\partial \mathbf{r}\_\alpha}\cdot\delta\mathbf{r}\_\alpha + \frac{\partial\mathcal{L}}{\partial \mathbf{v}\_\alpha}\cdot\delta\mathbf{v}\_\alpha\right]=0. \$$
Podstawiając wcześniej obliczone wektory otrzymujemy
\$$ \sum_\alpha \left[\frac{\partial\mathcal{L}}{\partial \mathbf{r}\_\alpha}\cdot\left(\delta\boldsymbol{\theta}\times\mathbf{r}\_\alpha\right) + \frac{\partial\mathcal{L}}{\partial \mathbf{v}\_\alpha}\cdot\left(\delta\boldsymbol{\theta}\times\mathbf{v}\_\alpha\right)\right]=0. \$$
Możemy zamienić wektory w iloczynie wektorowym i wyjąć $\delta\boldsymbol{\theta}$ poza sumę:
\$$ \delta\boldsymbol{\theta}\cdot\sum_\alpha \left[\frac{\partial\mathcal{L}}{\partial \mathbf{r}\_\alpha}\times\mathbf{r}\_\alpha + \frac{\partial\mathcal{L}}{\partial \mathbf{v}\_\alpha}\times\mathbf{v}\_\alpha\right]=0 \$$
i wykorzystajmy fakt, że $\partial\mathcal{L}/\partial \mathbf{r}\_\alpha=\dot{\mathbf{p}}\_\alpha$ oraz $\partial\mathcal{L}/\partial \mathbf{v}\_\alpha=\mathbf{p}\_\alpha$: 
\$$ \delta\boldsymbol{\theta}\cdot\sum_\alpha \left[\dot{\mathbf{p}}\_\alpha\times\mathbf{r}\_\alpha + \mathbf{p}\_\alpha\times\mathbf{v}\_\alpha\right]=0. \$$
W nawiasie kwadratowym rozpoznajemy pochodną iloczynu funkcji:
\$$ \delta\boldsymbol{\theta}\cdot\sum_\alpha \frac{d}{dt} \left[\mathbf{p}\_\alpha\times\mathbf{r}\_\alpha\right]=0. \$$
Ponieważ $\delta\boldsymbol{\theta}\neq 0$, suma wynosi $0$ i sprowadza się do
\$$ \boxed{\mathbf{M}=\sum_\alpha \mathbf{r}\_\alpha\times\mathbf{p}\_\alpha=\mathbf{const.}} \$$
Oznacza to, że całkowity __moment pędu__ jest zachowany w układzie izolowanym.

## Zachowanie energii
Załóżmy, że współrzędne są __naturalne__, to znaczy lagranżjan nie zależy jawnie od czasu, $\partial \mathcal{L}/\partial t=0$. 

Wyznaczmy pochodną lagranżjanu po czasie:
\$$ \frac{d\mathcal{L}}{dt}=\sum_{i=1}^n \frac{\partial\mathcal{L}}{\partial q_i}\dot{q}\_i+\sum_{i=1}^n \frac{\partial\mathcal{L}}{\partial \dot{q}\_i}\ddot{q}\_i+\frac{\partial\mathcal{L}}{\partial t}. \$$
$\partial \mathcal{L}/\partial t=0$, a $\partial \mathcal{L}/\partial q_i$ możemy wyznaczyć z równań Langrange'a. Po podstawieniu dostajemy
\$$ \frac{d\mathcal{L}}{dt}=\sum_{i=1}^n \left[\frac{d}{dt}  \frac{\partial\mathcal{L}}{\partial \dot{q}\_i}\dot{q}\_i +\frac{\partial\mathcal{L}}{\partial \dot{q}\_i}\ddot{q}\_i\right].\$$
Zauważmy, że wyrażenie pod sumą to pochodna iloczynu funkcji, dlatego
\$$ \frac{d\mathcal{L}}{dt}=\sum_{i=1}^n\frac{d}{dt}\left[\frac{\partial\mathcal{L}}{\partial \dot{q}\_i}\dot{q}\_i\right]. \$$
Odejmując obustronnie wyrażenie z prawej strony otrzymujemy 
\$$ \sum_{i=1}^n\frac{d}{dt}\left[\frac{\partial\mathcal{L}}{\partial \dot{q}\_i}\dot{q}\_i\right]-\frac{d\mathcal{L}}{dt}=0\$$
\$$ \sum_{i=1}^n p_i\dot{q}\_i-\mathcal{L}=const.\$$
gdzie skorzystałem z faktu, że $\partial\mathcal{L}/\partial \dot{q}\_i=p_i$. Powyższa wielkość nazywa się __hamiltonianem__ $\mathcal{H}$.
Wart uwagi jest fakt, że powyższe równanie jest takie samo jak <a href="https://bwegrzyn0.github.io/mechanika/mechanika-lagrangea-cz%C4%99%C5%9B%C4%87-1-r%C3%B3wnanie-eulera-lagrangea" target="_blank">całka pierwsza wyprowadzona na przykładzie błony mydlanej w jednym z poprzednich artykułów.</a>

Obliczmy bezpośrednio hamiltonian dla układu $N$ cząstek o $n$ współrzędnych uogólnionych. Aby obliczyć $p_i$ musimy obliczyć pochodną $\partial\mathcal{L}/\partial \dot{q}\_i$, a ponieważ $U$ nie zależy od $\dot{q}\_i$, jest to po prostu $\partial T/\partial \dot{q}\_i$. $T$ jest dane wzorem
\$$ T=\frac{1}{2}\sum_{\alpha=1}^N m_\alpha \mathbf{v}\_{\alpha} \cdot \mathbf{v}\_{\alpha}. \$$
Obliczmy $\mathbf{v}\_\alpha$ za pomocą reguły łańcuchowej:
\$$ \mathbf{v}\_\alpha=\frac{\partial \mathbf{r}\_\alpha}{\partial q_1}\dot{q}\_1+\frac{\partial \mathbf{r}\_\alpha}{\partial q_2}\dot{q}\_2+\dots+\frac{\partial \mathbf{r}\_\alpha}{\partial q_n}\dot{q}\_n=\sum_{j=1}^n \frac{\partial \mathbf{r}\_\alpha}{\partial q_j}\dot{q}\_j \$$
Iloczyn wektorowy będzie równy
\$$ \mathbf{v}\_\alpha\cdot\mathbf{v}\_\alpha=\sum_j \sum_k \frac{\partial \mathbf{r}\_\alpha}{\partial q_j}\cdot\frac{\partial \mathbf{r}\_\alpha}{\partial q_k} \dot{q}\_j \dot{q}\_k. \$$
Pomijam granice sumowania dla przejrzystości zapisu. Zauważmy, że 
\$$ \frac{\partial T}{ \partial \dot{q}\_i}=\frac{1}{2}\sum_{\alpha} m_\alpha\frac{\partial}{\partial \dot{q}\_i} \left(\mathbf{v}\_\alpha\cdot\mathbf{v}\_\alpha\right), \$$
więc obliczmy tę pochodną. Pochodna wszystkich wyrazów dla których $j\neq i$ oraz $k\neq i$ jednocześnie będzie wynosić 0. Pozostają nam wyrazy, dla których $j=i$ oraz $k=i$. To daje nam
\$$\frac{\partial}{\partial \dot{q}\_i} \left(\mathbf{v}\_\alpha\cdot\mathbf{v}\_\alpha\right)=
\frac{\partial}{\partial \dot{q}\_i} \sum_j \sum_k \frac{\partial \mathbf{r}\_\alpha}{\partial q_j}\cdot\frac{\partial \mathbf{r}\_\alpha}{\partial q_k} \dot{q}\_j \dot{q}\_k= \sum_j \frac{\partial \mathbf{r}\_\alpha}{\partial q_j}\cdot\frac{\partial \mathbf{r}\_\alpha}{\partial q_i} \dot{q}\_j+\sum_k \frac{\partial \mathbf{r}\_\alpha}{\partial q_i}\cdot\frac{\partial \mathbf{r}\_\alpha}{\partial q_k} \dot{q}\_k. \$$
Obydwie sumy są dokładnie takie same, więc mamy
\$$ 2\sum_j \frac{\partial \mathbf{r}\_\alpha}{\partial q_j}\cdot\frac{\partial \mathbf{r}\_\alpha}{\partial q_i} \dot{q}\_j.\$$
Po wstawieniu do wyrażenia na pęd otrzymamy
\$$ p_i=\sum_\alpha m_\alpha\sum_j \frac{\partial \mathbf{r}\_\alpha}{\partial q_j}\cdot\frac{\partial \mathbf{r}\_\alpha}{\partial q_i} \dot{q}\_j.\$$
Wstawmy to do hamiltonianu:
\$$ \mathcal{H}=\sum_i  \dot{q}\_i\sum_\alpha m_\alpha\sum_j \frac{\partial \mathbf{r}\_\alpha}{\partial q_j}\cdot\frac{\partial \mathbf{r}\_\alpha}{\partial q_i} \dot{q}\_j  - \mathcal{L}. \$$
$\dot{q}\_i$ możemy przenieść wewnątrz sumy po $j$:
\$$ \mathcal{H}= \sum_\alpha m_\alpha\sum_i\sum_j \frac{\partial \mathbf{r}\_\alpha}{\partial q_j}\cdot\frac{\partial \mathbf{r}\_\alpha}{\partial q_i} \dot{q}\_j \dot{q}\_i - \mathcal{L}. \$$
Podwójną sumę rozpoznajemy jako $\mathbf{v}\_\alpha\cdot\mathbf{v}\_\alpha$. Wtedy cała suma po $\alpha$ to po prostu $2T$. Pamiętając, że $\mathcal{L}=T-U$, otrzymujemy następujący wynik:
\$$ \boxed{\mathcal{H}=T+U=const.} \$$
gdy współrzędne są naturalne (lagranżjan nie zależy jawnie od czasu). 

Oczywistym faktem jest, że jeśli energia potencjalna $U$ zmienia się w czasie (np. z jakiegoś powodu zmienia się przyspieszenie ziemskie), energia w układzie nie będzia zachowana.

$T$ jest zależne od czasu np. w sytuacji, gdy wagon, na którego suficie przyczepione jest wahadło, porusza się z przyspieszeniem $a$ wzdłuż osi $x$. Położenie wahadła względem ziemi charakteryzują wtedy współrzędne $x$ oraz $\theta$. Energia kinetyczna tego wahadła będzie wyrażała się wzorem
\$$ T=\frac{1}{2}ml^2\dot{\theta}^2+\frac{1}{2}ma^2t^2, \$$
gdzie $l$ to długość wahadła, a $m$ to masa zaczepiona na jego końcu. Lagranżjan zależy jawnie od czasu, a energia oczywiście nie jest zachowana, ponieważ wahadło zyskuje wraz z wagonem energię kinetyczną. Bardziej _naturalnym_ wyborem układu współrzędnych w tej sytuacji jest układ związany z wagonem (w tym układzie współrzędne są faktycznie _naturalne_). Siłę bezwładności możemy modelować wtedy jak zadaną potencjałem proporcjonalnym do $x$.

