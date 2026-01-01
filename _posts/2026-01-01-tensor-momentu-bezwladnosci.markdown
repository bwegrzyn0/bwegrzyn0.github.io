---
layout: post
title: "Tensor momentu bezwładności"
date: 2026-01-01
categories: Mechanika
katex: true
---

## Ruch ciała sztywnego
Niech $\mathbf{R}$ będzie wektorem położenia środka masy ciała sztywnego, a $\mathbf{r_i}$ położeniem elementu masy $m_i$ wchodzącego w jego skład. Niech $\mathbf{r_i}'=\mathbf{r_i}-\mathbf{R}$ będzie położeniem $m_i$ względem środka masy. Niech ciało wykonuje obrót wokół osi $z$ z prędkością kątową $\mathbf{\Omega}$ oraz porusza się z prędkością $\mathbf{V}$. Po pewnym krótkim czasie $dt$ ciało obróci się o kąt $d\theta$ i przemieści o wektor $\mathbf{dR}$. 

<p align="center">
<img src="/assets/images/2026-01-01/fig1.svg" width="500" />
</p>

Wyznaczmy wynikające z tego obrotu przesunięcie $\mathbf{dr_i}'$ elementu masy $m_i$. Jeśli poprzez $\phi_i$ oznaczymy kąt tworzony przez $\mathbf{r_i}'$ i oś $z$, to widzimy, że $dr_i'$ to długość łuku okręgu o promieniu $r_i'\sin\phi_i$ określonego przez kąt $d\theta$. Dlatego:
\$$ dr_i'=r_i'\sin\phi_i\,d\theta. \$$
Niech wektor $\mathbf{d\theta}$ będzie skierowany tak, jak $\mathbf{\Omega}$. Ponieważ obrót zachodzi w płaszczyźnie prostopadłej zarówno do wektora kąta, jak i wektora położenia $\mathbf{r_i}'$, a wartość wektora $\mathbf{dr}$ jest taka sama, jak ich iloczynu wektorowego, możemy określić go jako ich iloczyn wektorowy:
\$$ \mathbf{dr_i}'=\mathbf{d\theta}\times\mathbf{r_i}', \$$
gdzie kolejność mnożenia wynika z reguły prawej dłoni - przyjmujemy, że jeśli $\mathbf{\Omega}$ jest skierowane zgodnie z osią $z$, to obrót następuje przeciwnie do ruchu wskazówek zegara. Całkowite przesunięcie, biorąc pod uwagę ruch środka masy, to
\$$ \mathbf{dr_i}=\mathbf{dr_i}'+\mathbf{dR}=\mathbf{d\theta}\times\mathbf{r_i}'+\mathbf{dR}. \$$
Po podzieleniu powyższego wyrażenia przez $dt$ otrzymujemy
\$$ \mathbf{v_i}=\mathbf{\Omega}\times \mathbf{r_i}'+\mathbf{V}. \$$
Wynika z tego, że ruch ciała sztywnego możemy zawsze rozpatrywać jako ruch obrotowy wokół środka masy oraz ruch postępowy środka masy.

## Energia kinetyczna ciała sztywnego
Obliczmy teraz energię kinetyczną ciała sztywnego. Będzie ona oczywiście równa sumie energii kinetycznych wszystkich jego elementów:
\$$ T=\frac{1}{2}\sum_i m_i\left|\mathbf{v_i}\right|^2. \$$
Skorzystamy z wyprowadzonego wcześniej wzoru na $\mathbf{v_i}$:
\$$ T=\frac{1}{2}\sum_i m_i \left(\mathbf{\Omega}\times \mathbf{r_i}'+\mathbf{V}\right)^2. \$$
Rozpiszmy wyrażenie w nawiasie:
\$$  \left(\mathbf{\Omega}\times \mathbf{r_i}'+\mathbf{V}\right)^2=\left|\mathbf{\Omega}\times\mathbf{r_i}'\right|^2r+2\mathbf{V}\cdot\left(\mathbf{\Omega}\times\mathbf{r_i}'\right)+V^2. \$$
W drugim członie możemy cyklicznie przestawić wyrazy:
\$$ \mathbf{V}\cdot\left(\mathbf{\Omega}\times\mathbf{r_i}'\right)=\mathbf{r_i}'\cdot\left(\mathbf{V}\times\mathbf{\Omega}\right), \$$
a w pierwszym członie możemy obliczyć wartość iloczynu wektorowego:
\$$ \left|\mathbf{\Omega}\times\mathbf{r_i}'\right|^2=\Omega^2r_i'^2\sin^2\phi=\Omega^2r_i'^2-\Omega^2r_i'^2\cos^2\phi=\Omega^2r_i'^2-\left(\mathbf{\Omega}\cdot\mathbf{r_i}'\right)^2. \$$
Wracając do $T$, dostajemy
\$$ T=\frac{1}{2}V^2\sum_i m_i+\left(\mathbf{V}\times\mathbf{\Omega}\right)\cdot\sum_i m_i\mathbf{r_i}'+\frac{1}{2}\sum_i m_i\left[\Omega^2r_i'^2-\left(\mathbf{\Omega}\cdot\mathbf{r_i}'\right)^2\right]. \$$
Suma w pierwszym członie to oczywiście masa całkowita ciała, czyli $M$. Suma w drugim członie to
\$$ \sum_i m_i\mathbf{r_i}'=\sum_i m_i \left(\mathbf{r_i}-\mathbf{R}\right)=\sum_i m_i\mathbf{r_i}-M\mathbf{R}. \$$
Pierwszy wyraz rozpoznajemy jako definicję środka masy pomnożoną razy $M$, więc suma wynosi $M\mathbf{R}-M\mathbf{R}=0$. 

Ostatni człon przepiszemy następująco. Niech indeksy $1,2,3$ oznaczają kolejne składowe wektora. Składowe $\mathbf{r_i}'$ będziemy oznaczać jako $x_i$. Wtedy pierwszy wyraz w nawiasie kwadratowym to
\$$ \left(\sum_j \Omega_j^2\right)\left(\sum_k x_k^2\right)=\Omega_j^2 x_k^2 \$$
Dla przejrzystości zapisu będziemy pomijać symbole sumy, wiedząc że sumowanie odbywa się po wskaźnikach $1,2,3$. Podobnie w przypadku iloczynu wektorowego:
\$$ \mathbf{\Omega}\cdot\mathbf{r_i}'=\sum_l \Omega_l x_l=\Omega_l x_l, \$$
a jego kwadrat to $\Omega_l \Omega_m x_l x_m$. Zauważmy, że $\Omega_j^2$ możemy przepisać jako
\$$ \Omega_l \Omega_m \delta_{lm}, \$$
gdzie $\delta_{lm}$ to delta Kroneckera.
Możemy teraz przepisać wyrażenie w nawiasie kwadratowym jako
\$$ \Omega_l\Omega_m \delta_{lm}x_k^2 -\Omega_l\Omega_m x_l x_m = \Omega_l\Omega_m\left(x_k^2\delta_{lm}-x_l x_m\right). \$$
Cała suma to teraz
\$$ \frac{1}{2}\Omega_l \Omega_m \sum_i m_i\left(x_k^2\delta_{lm}-x_l x_m\right), \$$
gdzie $\Omega_l \Omega_m$ wyciągnęliśmy przed sumę, ponieważ jest to wielkość niezależna od $i$. 

Energia kinetycza to
\$$ \boxed{T=\frac{1}{2}MV^2+\frac{1}{2}\Omega_l\Omega_m I_{lm},} \$$
gdzie $I_{lm}$ to **tensor momentu bezwładności**. Możemy zapisać go w postaci macierzy:
\$$ \mathbf{I}=\begin{pmatrix}
\sum_i m_i(y^2+z^2) & -\sum_i m_ixy & -\sum_i m_ixz \\\\ -\sum_i m_ixy & \sum_i m_i(x^2+z^2) & -\sum_i m_iyz \\\\ -\sum_i m_ixz & -\sum_i m_iyz & \sum_i m_i(x^2+y^2)
\end{pmatrix}. \$$
Widzimy, że tensor jest symetryczny, tzn. $I_{lm}=I_{ml}$. Oczywiście, dla ciał rozciągłych sumę zastępujemy całką.

## Moment pędu ciała sztywnego
Za pomocą tensora bezwładności możemy również wyrazić wektor momentu pędu ciała sztywnego. Moment pędu to z definicji
\$$ \mathbf{L}=\sum_i m_i \mathbf{r_i}'\times \mathbf{v_i}. \$$
Korzystając ze wcześniejszych wyników, możemy postawić za $ \mathbf{v_i}$:
\$$ \mathbf{L}=\sum_i m_i \mathbf{r_i}'\times\left(\mathbf{V}+ \mathbf{\Omega}\times \mathbf{r_i}'\right). \$$
Pierwszy człon sumy daje 
\$$ \left(\sum_i m_i \mathbf{r_i}'\right)\times \mathbf{V}=0 \$$
(wyrażenie w nawiasie zostało obliczone wcześniej), a wyraz z drugiego możemy przepisać, korzystając ze wzoru na potrójny iloczyn wektorowy:
\$$ \mathbf{r_i}'\times\left(\mathbf{\Omega}\times \mathbf{r_i}'\right)= \mathbf{\Omega}\left( \mathbf{r_i}'\cdot \mathbf{r_i}'\right)- \mathbf{r_i}'\left( \mathbf{r_i}'\cdot \mathbf{\Omega}\right). \$$
$k$-ta składowa wektora momentu pędu to wtedy
\$$ L_k=\sum_i m_i\left(\Omega_k x_j^2-x_k x_j\Omega_j \right). \$$
Zauważmy, że $\Omega_k=\Omega_j\delta_{jk}$, więc
\$$ L_k=\Omega_j\sum_i m_i\left(x_j^2\delta_{jk}-x_jx_k\right). \$$
Sumę rozpoznajemy jako tensor momentu bezwładności. Ostatecznie,
\$$ \boxed{L_k=\Omega_j I_{jk}} \$$
lub
\$$ \boxed{ \mathbf{L}= \mathbf{I}\cdot \mathbf{\Omega}.} \$$

## Tensor symetryczny
Tensor $ \mathbf{I}$ jest symetryczną macierzą kwadratową, więc możemy wyznaczyć jego wartości i wektory własne. Będą one odpowiadać kierunkom, dla których zwrot wektora momentu pędu będzie taki sam, jak zwrot wektora prędkości kątowej. 

Tensory symetryczne mają wiele użytecznych własności. Pierwsza z nich to fakt, że wszystkie rzeczywiste tensory symetryczne mają rzeczywiste wartości własne. Aby to udowodnić, zapiszmy zagadnienie własne dla macierzy $ \mathbf{A}$:
\$$ A_{ij} v_j=\lambda v_i. \$$
Weźmy teraz sprzężenie zespolone obu stron i skorzystajmy z własności $(ab)^\*=a^\*b^\*$:
\$$ A_{ij} v_j^\*=\lambda^\* v_i^\*, \$$
gdzie skorzystaliśmy również z faktu, że tensor $ \mathbf{A}$ jest rzeczywisty.
Weźmy teraz iloczyn skalarny $ \mathbf{v}^\* $ i pierwszego równania oraz $ \mathbf{v}$ i drugiego równania:
\$$ v_i^\* A_{ij}v_j=\lambda v_i^\*v_i \text{, } v_i A_{ij}v_j^\*=\lambda^\* v_iv_i^\*.\$$
Korzystając z faktu, że $A_{ij}=A_{ji}$, $\lambda v_i^\*v_i=v_i^\* A_{ij}v_j=v_i^\* A_{ji}v_j=v_jA_{ji}v_i^\*$, a zamiania miejscami wskaźników $i$ oraz $j$ (co nic nie zmienia) daje $v_iA_{ij}v_j^\*=\lambda^\* v_iv_i^\*$. Stąd
\$$ \lambda^\* v_iv_i^\*=\lambda v_i^\*v_i. \$$
$v_iv_i^\*=v_i^\*v_i$, więc $\lambda=\lambda^\*$, a to jest możliwe tylko, gdy $ \text{Im }\lambda=0$.

Druga z własności to fakt, że wszystkie wektory własne, odpowiadające różnym wartością własnym są ortogonalne. Załóżmy, że mamy różne wartości własne $\lambda$ i $\mu$ oraz wektory własne $ \mathbf{x}$ oraz $ \mathbf{y}$. Odpowiadające im równania to
\$$ A_{ij}x_j=\lambda x_i \text{ oraz } A_{ij}y_j=\mu y_i. \$$
Aby udowodnić ortogonalność, musimy udowodnić, że $x_i y_i=0$. Aby to uczynić, przekształćmy następujące wyrażenie:
\$$ \lambda x_i y_i=A_{ij}x_j y_i, \$$
a korzystając z $A_{ij}=A_{ji}$:
\$$ =x_jA_{ji}y_i=x_j\mu y_j. \$$
Doszliśmy do związku:
\$$ \lambda x_i y_i=\mu x_j y_j. \$$
Ponieważ $\lambda\neq\mu$, a $x_iy_i=x_jy_j$, to iloczyn skalarny jest równy $0$.

Łatwo jest zauważyć, dlaczego powyższa zależność jest prawdziwa, patrząc na przekształcenie wektorów na płaszczyźnie. Wiemy, że pierwsza kolumna macierzy wskazuje, gdzie po transformacji "idzie" wektor jednostkowy osi $x$, a druga - $y$. Ponieważ macierz jest symetryczna, wektory jednostkowe są swoimi odbiciami względem prostej $y=x$. Zauważmy teraz, że wszystkie wektory leżące na prostej $y=x$ są złożone z takiej samej liczby wektorów jednostkowych $x$ oraz $y$, co pozostaje prawdą po transformacji. Zauważmy również, że suma dwóch wektorów, będących swoimi odbiciami względem prostej $y=x$ zawsze ląduje na tej prostej (niech będą to wektory $(a,b)$ oraz $(b,a)$. Widzimy, że ich suma to $(a+b,a+b)$, więc $y=x$). Wektory wchodzące w skład wektora leżącego na $y=x$ możemy pogrupować parami, a każda z nich daje wektor leżący na $y=x$, zatem kierunek wszystkich wektorów na tejże prostej się nie zmienia - są to wektory własne przypadające pierwszej wartości własnej. Dla wektorów leżących na $y=-x$ możemy przeprowadzić podobne rozumowanie i dojść do wniosku, że one również są wektorami własnymi przypadającymi drugiej wartości własnej. Teraz widzimy, że oczywiście proste $y=x$ i $y=-x$ są prostopadłe, więc wektory własne również.

Często macierze przybierają o wiele prostszą postać w innych układach współrzędnych. Okazuje się, że istnieje taki wybór osi układu współrzędnych, dla którego macierz symetryczna staje się diagonalna. Innymi słowy,
\$$ \mathbf{A}= \mathbf{P}^{-1} \mathbf{B} \mathbf{P}, \$$
gdzie $ \mathbf{B}$ to macierz diagonalna, a macierz $ \mathbf{P}$ jest macierzą ortogonalną, tzn. złożoną z wektorów ortogonalnych (np. wektorów wskazujących osie kartezjańskiego układu współrzędnych). Wyrażenie po prawej stronie odpowiada transformacji układu współrzędnych, następnie zastosowaniu transformacji macierzy $ \mathbf{B}$, która odpowiada transformacji $ \mathbf{A}$, lecz ma prostszą postać, a następnie powrotowi do pierwotnego układu współrzędnych (macierz odwrotna do $ \mathbf{P}$). Zastanówmy się, dla jakiej macierzy $ \mathbf{P}$, czyli wyboru osi układu współrzędnych, macierz $ \mathbf{B}$ zmienia jedynie długość wektorów jednostkowych osi (ponieważ $ \mathbf{B}$ jest diagonalna, a takie macierze zmieniają tylko długość wektorów jednostkowych wskazujących osie układu współrzędnych). Własność taką mają oczywiście wektory własne macierzy $ \mathbf{A}$, więc spodziewamy się, że $ \mathbf{P}$ będzie właśnie z nich złożona. Z kolei, wektory własne są wydłużane o czynnik wartości własnej, więc na przekątnej $ \mathbf{B}$ będą wartości własne odpowiadające każdemu z wektorów własnych. Innymi słowy,
\$$ \mathbf{B}=\begin{pmatrix}
\lambda_1 & \cdots & 0 \\\\ \vdots & \ddots & \vdots \\\\ 0 & \cdots & \lambda_n \end{pmatrix}
\$$
oraz 
\$$ \mathbf{P} = \begin{pmatrix} \mathbf{x_1} & \cdots &  \mathbf{x_n} \end{pmatrix}, \$$
gdzie $ \mathbf{x}\_i$ to wektory własne odpowiadające wartościom własnym $\lambda_i$. Jak udowodniono wcześniej, wektory własne są ortogonalne, więc $ \mathbf{P}$ jest macierzą ortogonalną.

Wracając do tensora momentu bezwładności, możemy wyznaczyć jego wektory własne, które będą wskazywać kierunki nazywane **głównymi osiami bezwładności**. Zauważmy, że jeśli kierunek wektora prędkości kątowej $ \mathbf{\Omega}$ będzie pokrywał się z kierunkiem którejkolwiek z głównych osi bezwładności (czyli $ \mathbf{\Omega}$ jest wektorem własnym tensora bezwładności) wektor momentu pędu również będzie pokrywał się z tą osią.

Przy wyborze osi wskazywanych przez wektory własne tensora bezwładności, wyrażenia na energię i moment pędu przybierają prostą postać:
\$$ \boxed{T=\frac{1}{2}I_i\Omega_i^2,} \$$
gdzie $I_i=I_{ij}\delta_{ij}$ (w przekształconym układzie współrzędnych) oraz
\$$ \boxed{L_i=I_i\Omega_i.} \$$

## Precesja regularna bąka symetrycznego
**Bąkiem symetrycznym** nazywamy ciało, dla którego dwa główne momenty bezwładności są równe, $I_1=I_2\neq I_3$. Oznacza to, że płaszczyzna, w której zawierają się wektory własne $ \mathbf{x}\_1$ oraz $ \mathbf{x}\_2$, jest "rozciągana" przez macierz (tensor) $ \mathbf{I}$ równomiernie w dwóch prostopadłych kierunkach. W takim przypadku, oczywiste jest, że zmieniają się jedynie długości wektorów, a ich kierunki pozostają stałe - i jest to prawdziwe dla wszystkich wektorów w płaszczyźnie. Zatem dowolna para prostopadłych wektorów $ \mathbf{x}\_1'$ oraz $ \mathbf{x}\_2'$ w rozważanej płaszczyźnie może służyć za kierunki osi układu współrzędnych.

W ogólności wektor $ \mathbf{L}$ nie będzie miał zwrotu zgodnego z którąkolwiek z głównych osi bezwładności. Skorzystajmy ze swobody wyboru osi prostopadłych do $x_3$ i wybierzmy oś $x_2$ taką, że jest ona prostopadła do płaszczyzny, w której zawiera się $x_3$ oraz $ \mathbf{L}$. Wtedy $L_2=0$ i z wcześniejszych rozważań, $\Omega_2=0$. Wiemy więc, że wektory $ \mathbf{L}$, $ \mathbf{\Omega}$ i oś $x_3$, będącą osią symetrii bąka, leżą w jednej płaszczyźnie. Rozważmy teraz prędkości punktów leżących na osi $x_3$. Są one dane wzorem
\$$ \mathbf{v}\_i= \mathbf{\Omega}\times \mathbf{r}\_i'. \$$
Widzimy więc, że prędkości będą zwrócone prostopadle do tej płaszczyny, a co za tym idzie, oś bąka będzie obracać się jednostanie wokół wektora $ \mathbf{L}$. Wyznaczmy prędkość kątową obrotu i precesji bąka. Niech $\theta$ oznacza kąt między $ \mathbf{L}$ a $x_3$. Ze wcześniejszych zależności
\$$ \Omega_3=\Omega_{obr}= \frac{M_3}{I_3}, \$$
a $M_3=M\cos\theta$, więc
\$$ \Omega_{obr}= \frac{M}{I_3}\cos\theta. \$$
Z kolei, z rysunku widzimy, że po rozłożeniu wektora $ \mathbf{\Omega}$ na składową w kierunku $x_3$ (oznaczoną znakiem prim, ponieważ nie jest ona tym samym, co $ \mathbf{\Omega_3}$!) oraz na składową w kierunku $ \mathbf{L}$, $\Omega_{pr}\sin\theta=\Omega_1$, więc
\$$ \Omega_{pr}= \frac{\Omega_1}{\sin\theta}= \frac{M_1}{I_1\sin\theta}= \frac{M\sin\theta}{I_1\sin\theta}= \frac{M}{I_1}. \$$

<p align="center">
<img src="/assets/images/2026-01-01/fig2.svg" width="500" />
</p>
