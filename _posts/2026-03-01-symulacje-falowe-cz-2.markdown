---
layout: post
title: "Symulacje falowe, część 2"
date: 2026-03-01
categories: Programowanie 
katex: true
---

## Absorbujące warunki brzegowe (Engquist-Majda)
W poprzedniej części artykułu dostrzegliśmy problem związany z warunkami brzegowymi Dirichleta, tzn. $u=0$ na brzegach obszaru symulacji - fale odbijały się od nich, co było często niepożądanym zachowaniem. W celu zapobiegnięcia temu zjawisku, zaimplementujemy **absorbujące warunki brzegowe**, a konkretnie <a href="https://en.wikipedia.org/wiki/Engquist%E2%80%93Majda_absorbing_boundary_condition" target="blank">warunki brzegowe Engquista-Majdy</a>.

Jednowymiarowe równanie falowe ma postać:
\$$ \partial_t^2u - c^2 \partial_x^2 u=0, \$$
gdzie $\partial_x$ oznacza operator pochodnej cząstkowej po $x$ (podniesiony do kwadratu oznacza drugą pochodną). Powyższe wyrażenie przypomina wzór skróconego mnożenia:
\$$ (\partial_t -c\partial_x) (\partial_t +c\partial_x) u=(\partial_t +c\partial_x)(\partial_t -c\partial_x)u=0. \$$  
Widzimy zatem, że aby równanie falowe było spełnione, to 
\$$ (\partial_t -c\partial_x)u=0 \vee (\partial_t +c\partial_x)u =0, \tag{1} \$$
gdzie warunek lub nie wyklucza oczywiście obu możliwości jednocześnie.

Rozwiążmy każde z tych równań separując zmienne. Załóżmy, że $u(x,t)=X(x)T(t)$, skąd:
\$$ X(x) \frac{dT}{dt}\pm cT(t)\frac{dX}{dx}=0, \$$
zatem
\$$ \frac{1}{T} \frac{dT}{dt}\pm\frac{c}{X} \frac{dX}{dx}=0. \$$
Wyraz pierwszy nie zależy od $x$ a drugi od $t$, więc oba muszą być stałe:
\$$ \frac{dT}{dT}=kT \wedge \pm \frac{dX}{dx}=- \frac{k}{c}X \iff \frac{dX}{dx}=\mp \frac{k}{c}X. \$$
Oczekujemy, że rozwiązania równania *falowego* będą okresowe, więc $k$ powinno być liczbą zespoloną. Niech $k=i\omega$, gdzie $\omega\in\mathbb{R}$. Wtedy
\$$ T(t) = Ae^{i\omega t} \wedge X(x) =Be^{\mp i\omega x/c}. \$$
Stąd mamy
\$$ u(x, t) = u_0 e^{i(\omega t\mp \omega x/c)}. \$$
Jest to równanie fali rozchodzącej się dla $-$ w prawo, a dla $+$ w lewo. Widzimy zatem, że operator $\partial_-=(\partial_t -c\partial_x)$ reprezentuje fale rozchodzące się w lewo, a $\partial_+=(\partial_t +c\partial_x)$ rozchodzące się w prawo (znaki są na odwrót, bo mamy $\mp$, a nie $\pm$).

Ponieważ przynajmniej jedno z równań (1) musi być spełnione, każda funkcja spełniająca równanie falowe składa się z fal rozchodzących się w prawo lub w lewo, lub z obu naraz. Chcemy, aby fale padające na lewą krawędź obszaru były przez nią absorbowane, czyli poruszały się dalej, tak, jakby tej krawędzi nie było. Dlatego dla niej postawimy warunek $\partial_- u=0$, czyli przepuszcza ona składową fali poruszającą się w lewo. Podobnie dla prawej krawędzi, $\partial_+ u=0$.

Powyższe rozumowanie ugólnimy dla dwuwymiarowego równania falowego. Dla fal poruszających się wzdłuż osi x:
\$$ (c^2\partial_x^2+c^2\partial_y^2-\partial_t^2)=c^2\left(\partial_x-\frac{\partial_t}{c}\sqrt{1- \frac{\partial_y^2}{\partial_t^2}}\right)\left(\partial_x+\frac{\partial_t}{c}\sqrt{1- \frac{\partial_y^2}{\partial_t^2}}\right). \$$
W pierwszym przybliżeniu $\partial_y u\approx 0$, czyli fale padające prostopadle na krawędź będą w całości przepuszczane. W dalszych przybliżeniach pierwiastek możemy rozrzeszać korzystając z $(1+x)^\alpha\approx 1+\alpha x+\cdots$ dla małych $x$, co w szczególności polepszy warunki brzegowe dla fal padających na krawędź pod dużym kątem. W naszym przybliżeniu mamy zatem:
\$$ (\partial_t -c\partial_x)u=0 \vee (\partial_t +c\partial_x)u =0 \tag{2} \$$
i analogicznie dla fal poruszających się wzdłuż osi $y$:
\$$ (\partial_t -c\partial_y)u=0 \vee (\partial_t +c\partial_y)u =0 \tag{3}. \$$
Warunek (2.1) zastosujemy na lewej krawędzi obszaru (fale poruszające się w lewo), warunek (2.2) na krawędzi prawej, (3.1) na górnej, a (3.2) na dolnej.

Aby zaimplementować warunki (2) i (3) musimy jednak doprowadzić je do postaci dyskretnej. Na krawędziach nie obliczymy pochodnych cząstkowych korzystając ze wzoru
\$$ \frac{df}{dx}\approx \frac{f(x+h)-f(x-h)}{2h}, \$$
ponieważ poza krawędzią nie ma już kolejnych komórek. Zastosujemy więc wzór:
\$$ \frac{df}{dx}\approx \frac{f(x+h)-f(x)}{h} \$$
lub jego wersję z $f(x-h)$. 

Warunek (2) przyjmuje więc postać:
\$$ \frac{u(x,t) - u(x,t-dt)}{dt}\mp c\left( \pm\frac{u(x\pm dx, t) - u(x, t)}{dx}\right) = 0, \$$
gdzie $+$ mamy dla ścianki lewej, a $-$ dla ścianki prawej. $\pm\cdot \mp$ daje zawsze $-$, więc
\$$ \frac{u(x,t) - u(x,t-dt)}{dt}- c\left(\frac{u(x\pm dx, t) - u(x, t)}{dx}\right) = 0, \$$
skąd
\$$ u(x,t) = \frac{u(x\pm dx, t)c\,dt+u(x, t-dt) dx}{c\,dt + dx}. \$$
Przekształcając to na notację używaną we <a href="https://bwegrzyn0.github.io/programowanie/symulacje-falowe-cz-1" target="blank">wcześniejszym artykule</a>:
\$$ u_{ij}(t) = \frac{u_{(i\pm 1)j}(t)c\Delta t+u_{ij}(t-\Delta t)\Delta x}{c\Delta t+\Delta x}. \tag{4} \$$
Analogicznie mamy dla ścianek górnej ($+$) i dolnej ($-$):
\$$ u_{ij}(t) = \frac{u_{i(j\pm 1)}(t)c\Delta t+u_{ij}(t-\Delta t)\Delta x}{c\Delta t+\Delta x}. \tag{5} \$$

## Implementacja w C++
Za każdym razem uruchamiając funkcję `calculate_u()` obliczającą wartości $u$ dla całej siatki współrzędnych w kolejnej iteracji, najpierw wywołamy następującą funkcję:
```cpp
void boundary_conditions(std::string type) {
	double div = dx + c * dt;
	// góra / dół
	for(int i = 0; i < size_x+2; i++) {
		if (type == "dirichlet") {
			u[i][0] = 0;
			u[i][size_y+1] = 0;
		} else if (type == "abs") {
			u[i][0] = (old_u[i][0] * dx + u[i][1] * c * dt) / div; 
			u[i][size_y+1] = (old_u[i][size_y+1] * dx + u[i][size_y] * c * dt) / div; 
		}
	}
	// prawo / lewo
	for(int i = 0; i < size_y+2; i++) {
		if (type == "dirichlet") {
			u[0][i] = 0;
			u[size_x+1][i] = 0;
		} else if (type == "abs") {
			u[0][i] = (old_u[0][i] * dx + u[1][i] * c * dt) / div; 
			u[size_x+1][i] = (old_u[size_x+1][i] * dx + u[size_x][i] * c * dt) / div; 
		}
	}
}
```
`div` to stały dzielnik, więc obliczamy go raz. Następnie iterujemy po krawędziach górnych i dolnych, stosując wybrane warunki brzegowe: `"dirichlet"` lub `"abs"` (*absorbing boundary conditions*). Warunki brzegowe `"abs"` obliczamy zgodnie ze wzorami (4) i (5). Oprócz tego przeniesiono zapisywanie wartości `u` do pliku z oddzielnej pętli w `main()` do pętli w `calculate_u()`, co znacznie przyspieszyło program. Dodając na środku siatki sinusoidalne źródło fal otrzymujemy następujący rezultat:
<p align="center">
<video width="800" controls="controls">
<source src="/assets/videos/2026-03-01/anim_pktowe.mp4" type="video/mp4">
</video>
</p>
Widzimy, że zgodnie z oczekiwaniami fale są pochłaniane przez ścianki. Możemy również zaobserwować niewielkie odbicia, tym bardziej widoczne, pod im większym kątem fala pada na brzeg obszaru symulacji. Wynikają one z naszego przybliżenia $\partial_y u\approx 0$ lub analogicznie $\partial_x u\approx 0$. 

## Plamka Arago
Gdy niewielki idealnie okrągły obiekt zostanie oświetlony równoległą wiązką światła, w samym środku jego cienia pojawia się jasny punkt, nazywany plamką Arago. Zjawisko to było jednym z kluczowych dowodów przemawiających za falową naturą światła. Aby je zasymulować, zaimplementujemy najpierw ściany, które nie odbijają fal tak bardzo, jak po prostu warunek $u=0$. 

```cpp
double wall(int x_center, int y_center, int x_half_size, int y_half_size, int i, int j, double damping) {
	if (i >= (x_center - x_half_size) && i <= (x_center + x_half_size) && j >= (y_center - y_half_size) && j <= (y_center + y_half_size))
		return 1.0 - damping;
	else
		return 1.0;
}
```
Przez funkcję `wall()` mnożymy $u_{ij}(t+\Delta t)$ w funkcji `calculate_u()`. W miejscach, gdzie nie ma ściany, fala zostanie niezmieniona, a w miejscach, w których jest, fala będzie tłumiona w zależności od współczynnika `damping`. Argumenty funkcji `wall()` obejmują również położenie jej środka, jej połówkowe wymiary i numery komórki w celu sprawdzenia jej położenia. Im mniejszy współczynnik `damping`, tym grubsza musi być ściana, aby nie przepuszczała fal, ale również tym mniejsze będą odbicia. Wymiary ściany i `damping` należy tak dobrać, aby uzyskać odpowiednią równowagę pomiędzy odbiciami a tłumieniem.

Dodajemy w obszarze symulacji szeroką i mocno tłumiącą ścianę, pełniącą funkcję okrągłej przesłony. Następnie na całym brzegu symulacji wywołujemy zaburzenie reprezentujące prostopadle padającą wiązkę światła. Jeśli wykonamy animację, tym razem nanosząc na wykres natężenie fali (światła), czyli $u^2$, otrzymamy następujący rezultat:
<p align="center">
<video width="800" controls="controls">
<source src="/assets/videos/2026-03-01/arago_spot.mp4" type="video/mp4">
</video>
</p>
Widzimy, że po przejściu przez ścianę fala zostaje mocno wygaszona. Jednak po pewnym czasie w samym środku cienia pojawia się jasny obszar, będący omawianym zjawiskiem.
<p align="center">
<video width="800" controls="controls">
<source src="/assets/videos/2026-03-01/arago_spot_2.mp4" type="video/mp4">
</video>
</p>
Dla szerszej ściany obserwujemy takie same zjawisko, plamka, widoczna szczególnie na końcu animacji, jest jednak mniejsza i słabsza.

## Szklana kulka
Aby dodać szklaną kulkę, utworzymy funkcję `glass_bulb()`:
```cpp
double glass_bulb(int x_center, int y_center, int radius_squared, int i, int j, double n) {
	double distance_squared = (x_center - i) * (x_center - i) + (y_center - j) * (y_center - j);
	if (distance_squared <= radius_squared)
		return 1/n;
	else
		return 1;
}
```
Przyjmuje ona jako argumenty rozmiary i położenie kulki oraz jej współczynnik załamania. Dla wszystkich punktów wewnątrz niej zwraca $1/n$, a dla reszty $1$. W funkcji `calculate_u()` wszystkie `c` mnożymy razy `glass_bulb()`, co da efekt zmniejszenia prędkości fali wewnątrz kulki. Ustawiając ją na drodze wiązki światła otrzymujemy efekt załamania i skupienia w ognisku kulki:
<p align="center">
<video width="800" controls="controls">
<source src="/assets/videos/2026-03-01/glass_bulb.mp4" type="video/mp4">
</video>
</p>
